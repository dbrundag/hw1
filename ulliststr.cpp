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
		new_head->next = head_;
		head_ = new_head;
	
		head_->prev = NULL;
		head_->next->prev = head_;

		head_->first = ARRSIZE - 1;
		head_->last = ARRSIZE;
		head_->val[head_->first] = val;
	}
	++size_;
}

void ULListStr::pop_back(){
	//no value has been added to list
	if(size_ == 0)
	{
		return;
	}
	//about to remove only element in item
	if((tail_->last - tail_->first) == 1) //math to get number of elements to account for different item starting points
	{
		tail_->val[tail_->last-1] = "";
		Item* tmp = tail_;

		if(head_ == tail_) //only item in list
		{
			head_ = tail_ = NULL;
		}
		else
		{
			tail_ = tail_->prev;
			tail_->next = NULL;
		}
		delete tmp;
		//tail is now prev item so don't need to decrement last val
		--size_;
		return;
	}

	//common case, removing element from item with multiple elements
	tail_->val[tail_->last-1] = "";
	--tail_->last;
	--size_;
}

void ULListStr::pop_front(){
	//no value has been added to list
	if(size_ == 0)
	{
		return;
	}
	//about to remove only element in item
	if((head_->last - head_->first) == 1) //math to get number of elements to account for different item starting points
	{
		head_->val[head_->first] = "";
		Item* tmp = head_;

		if(head_ == tail_) //only item in list
		{
			head_ = tail_ = NULL;
		}
		else
		{
			head_ = head_->next;
			head_->prev = NULL;
		}
		delete tmp;
		//head is now next item so don't need to increment first val
		--size_;
		return;
	}

	//common case, removing element from item with multiple elements
	head_->val[head_->first] = "";
	++head_->first;
	--size_;
}

std::string const & ULListStr::back() const{
	if(tail_ == NULL)
	{
		throw std::invalid_argument("List is empty. No front or back.");
	}
	return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const{
	if(head_ == NULL)
	{
		throw std::invalid_argument("List is empty. No front or back.");
	}
	return head_->val[head_->first];
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
	if(loc > size_){
		return NULL;
	}

	Item* currNode = head_;
	size_t nodeIndex = currNode->first;

	for(size_t i=0; i<=loc; i++)
	{
		if( i == loc){
			break;
		}
		
		if (currNode->next == NULL){
			++nodeIndex;
			continue;
		}
		if(nodeIndex == currNode->last -1)
		{
			currNode = currNode->next;
			nodeIndex = currNode->first;
			continue;
		}
		++nodeIndex;
	}
	return currNode->val + nodeIndex;
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
