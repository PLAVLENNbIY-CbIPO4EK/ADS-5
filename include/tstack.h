// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int kSize>
class TStack {
 private:
  int index;
  T data[kSize];

 public:
  TStack() {
    index = -1;
  }

  void push(T x) {
    if (index < kSize - 1) {
      index++;
      data[index] = x;
    }
  }

  void pop() {
    if (index >= 0) {
      index--;
    }
  }

  T top() {
    return data[index];
  }

  bool isEmpty() {
    return index == -1;
  }
};

#endif  // INCLUDE_TSTACK_H_
