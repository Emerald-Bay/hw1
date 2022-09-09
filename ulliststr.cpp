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

    tail_->first = ARRSIZE / 2 - 1;
    tail_->last = ARRSIZE / 2;
    tail_->val[tail_->first] = val;
  }
  else if(tail_->last != ARRSIZE) {
    tail_->val[tail_->last] = val;
    ++tail_->last;
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

    head_->first = ARRSIZE / 2 - 1;
    head_->last = ARRSIZE / 2;
    head_->val[head_->first] = val;
  }
  else if(head_->first != 0) {
    --head_->first;
    head_->val[head_->first] = val;
  }
  else {
    Item* temp = head_;
    head_ = new Item;
    temp->prev = head_;
    head_->next = temp;

    head_->first = ARRSIZE - 1;
    head_->last = ARRSIZE;
    head_->val[ARRSIZE - 1] = val;
  }

  size_++;
}

void ULListStr::pop_back() {
  if(ULListStr::empty()) {
    return;
  }

  if (size_ == 1) {
    delete head_;
    head_ = tail_ = nullptr;
  }
  else {
    if(tail_->last != 1) {
      --tail_->last;
    }
    else {
      Item* temp;
      temp = tail_->prev;
      delete tail_;
      tail_ = temp;
      tail_->next = nullptr;
    }
  }

  size_--;
}
void ULListStr::pop_front() {
  if(ULListStr::empty()) {
    return;
  }

  if (size_ == 1) {
    delete head_;
    head_ = tail_ = nullptr;
  }
  else {
    if(head_->first != 9) {
      ++head_->first;
    }
    else {
      Item* temp;
      temp = head_->next;
      delete head_;
      head_ = temp;
      head_->prev = nullptr;
    }
  }

  size_--;
}

std::string const & ULListStr::front() const {
  return (head_->val[head_->first]);
}

std::string const & ULListStr::back() const {
  return (tail_->val[tail_->last - 1]);
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

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc > size_) {
    return nullptr;
  }
  
  Item* buffer = head_;
  
  while (true) {
    size_t distance = buffer->last - buffer->first;

    if (distance <= loc) {
      loc -= distance;
      buffer = buffer->next;
    }
    else {
      return &(buffer->val[buffer->first + loc]);
    }
  }

  return nullptr;
}
