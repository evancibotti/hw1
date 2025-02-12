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
/** 1
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::push_back(const std::string& val){
  // check if the node is full or there are no nodes in list
  if (tail_ == nullptr || tail_->last == ARRSIZE){
    // create nextnode
    Item* nextnode = new Item();
    nextnode->first = 0;
    nextnode->last = 0;
    // check if the list is not empty then link if so
    if (tail_ != nullptr){
      // update tail next to link to end
      tail_->next = nextnode;
      // update nextnode prev to link to end
      nextnode->prev = tail_;
    }
    // set nextnode to tail
    tail_ = nextnode;
    // update head to tail if the list was previously empty
    if(head_ == nullptr){
      head_ = tail_;
    }
    // add value to new node
    tail_->first = 0;
    tail_->last = 1;
    tail_->val[0] = val;
  } else { 
    // set value to end of list if list wasn't empty
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  // increment size
  size_++;
}

/** 2
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_back(){
  // if list is empty return
  if (tail_ == nullptr){
    return;
  }
  // check if the list has elements
  if(tail_->last > tail_->first){
    // change the last to last used index
    tail_->last = tail_->last - 1;
    // edit size to match removed element
    size_--;
  }
  // check if list is now empty (tail->last is 1 after last element which is always nullptr)
  if(tail_->last == tail_->first){
    // store current tail to be deleted
    Item* currenttail = tail_;
    // change tail to prev node
    tail_ = tail_->prev;
    // check if new tail doesn't exist
    if(tail_ == nullptr){
      // list is empty update head
      head_ = nullptr;
    } else {
      // update next if new tail exists
      tail_->next = nullptr;
    }
    delete currenttail;
  }
}

/** 3
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
void ULListStr::push_front(const std::string& val){
  // check if the first node or there are no nodes in list
  if (head_ == nullptr || head_->first == 0){
    // create firstnode
    Item* firstnode = new Item();
    firstnode->first = 0;
    firstnode->last = 0;
    // check if the list is not empty then link if so
    if (head_ != nullptr){
      // update head prev to link to start
      head_->prev = firstnode;
      // update firstnode next to link to start
      firstnode->next = head_;
    }
    // set firstnode to head
    head_ = firstnode;
    // update tail to head if the list was previously empty
    if(head_ == nullptr){
      tail_ = head_;
    }
    // add value to new node
    head_->first = 0;
    head_->last = 1;
    head_->val[0] = val;
  } else { 
    // set value to beginning of list if list wasn't empty
    head_->val[--head_->first] = val;
  }
  // increment size
  size_++;
}

/** 4
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_front(){
  // if list is empty return
  if (head_ == nullptr){
    return;
  }
  // check if the list has elements
  if(head_->first < head_->last){
    // change the first to the second
    head_->first = head_->first + 1;
    // edit size to match removed element
    size_--;
  }
  // check if list is now empty (head->last is 1 after last element which is always nullptr)
  if(head_->first == head_->last){
    // store current head to be deleted
    Item* currenthead = head_;
    // change head to next node
    head_ = head_->next;
    // check if new head doesn't exist
    if(head_ == nullptr){
      // list is empty update tail
      tail_ = nullptr;
    } else {
      // update prev if new head exists
      head_->prev = nullptr;
    }
    delete currenthead;
  }
}

/** 5 DONE
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::back() const{
  return tail_->val[tail_->last - 1];
}

/** 6 DONE
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

/** 7
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
std::string* ULListStr::getValAtLoc(size_t loc) const{
  if(loc >= size_){
    return nullptr;
  }
  // save desired loc
  size_t location = loc;
  // create starting point/node to traverse
  Item* currnode = head_;
  // create loop to run through nodes
  while(currnode != nullptr){
    // find amt of element in nodes list
    size_t length = (currnode->last - currnode->first);
    // check if the location is in the currnode
    if(location < length){
      return &(currnode->val[currnode->first + location]);
    } else {
      // edit location to parse through
      location = location - length;
      // move to next node
      currnode = currnode->next;
    }
  }
  // return null if the val isnt found
  return nullptr;
}

// Prewritten implementations
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
