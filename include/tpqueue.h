// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <cassert>

template<typename T, int size>
class TPQueue {
 private:
  T* box;
  int capacity;
  int first, last;
  int currSize;

 public:
  TPQueue() :capacity(size), first(0), last(0), currSize(0) {
    box = new T[capacity + 1];
  }

  void push(const T& value) {
    assert(currSize < capacity);
    if (currSize == 0) {
      box[last++] = value;
      currSize++;
    } else {
      int i = last - 1;
      bool f = 0;
      while (i >= first && value.prior > container[i].prior) {
        f = 1;
        box[i + 1] = box[i];
        box[i] = value;
        i--;
      }
      if (f == 0) {
        box[last] = value;
      }
      last++;
      currSize++;
    }
    if (last > capacity) {
      last -= capacity + 1;
    }
  }

  const T& pop() {
    assert(currSize > 0);
    currSize--;
    if (first > capacity) {
      first -= capacity + 1;
    }
    return box[first++];
  }

  char get() {
    assert(currSize > 0);
    return box[first].ch;
  }

  bool isFull() const {
    return currSize == capacity;
  }

  bool isEmpty() const {
    return currSize == 0;
  }

  ~TPQueue() {
    delete[] box;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
