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
void ULListStr::push_back(const std::string& val) {
  if (ULListStr::empty()) {
    head_ = tail_ = new Item;

    tail_->first = 4;
    tail_->last = 5;
    tail_->val[4] = val;
  }
  else if(tail_->last != 10) {
    tail_->val[tail_->last++] = val;
  }
  else {
    Item* temp = tail_;
    tail_ = new Item;
    temp->next = tail_;
    tail_->prev = temp;

    tail_->first = 0;
    tail_->last = 1;
    tail_->val[0] = val;
  }

  size_++;
}

void ULListStr::push_front(const std::string& val) {
  if (ULListStr::empty()) {
    head_ = tail_ = new Item;

    head_->first = 4;
    head_->last = 5;
    head_->val[4] = val;
  }
  else if(head_->first != 0) {
    head_->val[--head_->first] = val;
  }
  else {
    Item* temp = head_;
    head_ = new Item;
    temp->prev = head_;
    head_->next = temp;

    tail_->first = 9;
    tail_->last = 10;
    tail_->val[9] = val;
  }

  size_++;
}

void ULListStr::pop_back() {
  if(ULListStr::empty()) {
    return;
  }
  else if(tail_->last != 1) {
    tail_->last--;
  }
  else {
    Item* temp;
    temp = tail_->prev;
    delete tail_;
    tail_ = temp;
    tail_->next = nullptr;
  }
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
