#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{
	if(tail_ == NULL)
	{
		tail_ = new Item();
		head_ = tail_;
		tail_->val[tail_->last] = val;
		tail_->last++;
		size_++;
		return;
	}

	//item can expend to right
	if( (tail_->last) < ARRSIZE)
	{
		//add to end of tail
		tail_->val[tail_->last] = val;
		++tail_->last;
	}
	else
	{
		//create new tail and add to begining on new tail
		Item* new_tail = new Item();

		// // set new tail properties
		// new_tail->val[new_tail->last] = val;
		// ++new_tail->last;
		
		// new_tail->prev = tail_;
		// new_tail->next = NULL;

		// //update linked list about new tail
		// tail_->next = new_tail;
		// tail_ = new_tail;



		new_tail->prev = tail_;
		tail_ = new_tail;
	
		tail_->next = NULL;
		tail_->prev->next = tail_;
		tail_->val[tail_->last] = val;
		++tail_->last;
	}
	++size_;
}


void ULListStr::push_front(const std::string& val)
{
	if(head_ == NULL)
	{
		head_ = new Item();
		tail_ = head_;
		head_->first = ARRSIZE -1;
		head_->last = ARRSIZE;
		head_->val[head_->first] = val;
		size_++;
		return;
	}

	//item not full
	if( (head_->first) != 0)
	{
		//add to front of head
		--head_->first;
		head_->val[head_->first] = val;
	}
	else
	{
		//create new head and add to end of new tail
		Item* new_head = new Item;
		// set new head properties
		// new_head->first = ARRSIZE - 1;
		// new_head->last = ARRSIZE;
		// new_head->val[new_head->first] = val;
		// new_head->prev = NULL;
		// new_head->next = head_;
		//update linked list about new head

		new_head->next = head_;
		head_ = new_head;
	
		head_->prev = NULL;
		head_->next->prev = head_;

		head_->first = ARRSIZE - 1;
		head_->last = ARRSIZE;
		head_->val[head_->first] = val;


		// head_->prev = new_head;
		// head_ = new_head;
	}
	++size_;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
	// if (loc > size_){
	// 	return NULL;
	// }

	// Item* currNode = head_;
	// int count = 0;

	// for(int i=0; i<loc; i++){
	// 	if(count > (currNode->last - currNode->first ))
	// 	{
	// 		currNode = currNode->next;
	// 		count = 0;
	// 	}
	// 	if(i == loc){
	// 		return currNode->val[count];
	// 	}
	// 	count++;
	// }


	// for(int i=0; i < loc; i++){
	// 	if(localIndex  == ARRSIZE){
	// 		localIndex = 0;
	// 		currNode = currNode->next;
	// 	}
	// 	if(currNode[localIndex])

	// }
	std::string* pow = new std::string("cow");
	return pow;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
