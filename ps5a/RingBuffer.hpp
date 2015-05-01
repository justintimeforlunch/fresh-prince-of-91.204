// Copyright [2015] Justin Nguyen  [legal/copyright]

#ifndef RB_HPP_
#define RB_HPP_

#include <stdint.h>
#include <vector>

class RingBuffer {
 public:
  explicit RingBuffer(int capacity);
  int size();
  bool isEmpty();
  bool isFull();
  void enqueue(int16_t x);
  int16_t dequeue();
  int16_t peek();

 private:
  std::vector<int16_t> ringBuffer;
};

#endif
