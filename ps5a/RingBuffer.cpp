// Copyright [2015] Justin Nguyen  [legal/copyright]

#include <stdint.h>
#include <vector>
#include <iostream>
#include <stdexcept>
#include "RingBuffer.hpp"

RingBuffer::RingBuffer(int capacity) {
  if (capacity < 1) {
    throw std::invalid_argument
    ("RB constructor: capacity must be greater than zero.");
  }
  ringBuffer.reserve(capacity);
}

int RingBuffer::size() {
  return ringBuffer.size();
}

bool RingBuffer::isEmpty() {
  if (size() == 0)
    return 1;
  else
    return 0;
}

bool RingBuffer::isFull() {
  int cur_cap = ringBuffer.capacity();
  if (size() == cur_cap)
    return 1;
  else
    return 0;
}

void RingBuffer::enqueue(int16_t x) {
  if (!isFull())
    ringBuffer.push_back(x);
  else
    throw std::runtime_error("enqueue: can't enqueue to a full ring.");
}

int16_t RingBuffer::dequeue() {
  int16_t temp;
  temp = ringBuffer.front();
  if (!isEmpty())
    ringBuffer.erase(ringBuffer.begin(), ringBuffer.begin() + 1);
  else
    throw std::runtime_error("dequeue: can't dequeue to a empty ring.");
  return temp;
}

int16_t RingBuffer::peek() {
  if (!isEmpty())
    return ringBuffer.front();
  else
    throw std::runtime_error("peek: can't dequeue to a empty ring.");
}
