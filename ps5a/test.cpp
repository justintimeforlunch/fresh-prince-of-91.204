// Copyright [2015] Justin Nguyen  [legal/copyright]

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main

#include <stdint.h>
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include "RingBuffer.hpp"


BOOST_AUTO_TEST_CASE(RBcontructor) {
  // normal constructor
  BOOST_REQUIRE_NO_THROW(RingBuffer rb(100));

  // this should fail
  BOOST_REQUIRE_THROW(RingBuffer rb(0), std::exception);
  BOOST_REQUIRE_THROW(RingBuffer rb(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(RBenque_dequeue) {
  RingBuffer rb(100);
  rb.enqueue(2);
  rb.enqueue(1);
  rb.enqueue(0);
  BOOST_REQUIRE(rb.dequeue() == 2);
  BOOST_REQUIRE(rb.dequeue() == 1);
  BOOST_REQUIRE(rb.dequeue() == 0);

  BOOST_REQUIRE_THROW(rb.dequeue(), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(RBenqueue) {
  RingBuffer rb(3);
  for (int i = 0; i < 3; i++)
    rb.enqueue(i);
  BOOST_REQUIRE_THROW(rb.enqueue(rb.isFull()), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(RBpeek) {
  RingBuffer rb(100);
  rb.enqueue(2);
  rb.enqueue(1);
  rb.enqueue(0);
  BOOST_REQUIRE(rb.peek() == 2);
}

BOOST_AUTO_TEST_CASE(RBpeek_empty) {
  RingBuffer rb(100);
  BOOST_REQUIRE_THROW(rb.peek(), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(RBis_empty) {
  RingBuffer rb(100);
  BOOST_REQUIRE(rb.isEmpty() == 1);
}

BOOST_AUTO_TEST_CASE(RBis_full) {
  RingBuffer rb(3);
  rb.enqueue(2);
  rb.enqueue(1);
  rb.enqueue(0);

  BOOST_REQUIRE(rb.isFull() == 1);
}
