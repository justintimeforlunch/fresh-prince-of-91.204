//Justin Nguyen
//Project: ps5a (RingBuffer)
//3-30-2015
//ps5a-readme.txt

In this assignment I used a vector container and it's member functions to build the RingBuffer.

In particular:
RingBuffer::RingBuffer -> reserve();
RingBuffer::size -> size();
RingBuffer::isEmpty -> size();
RingBuffer::isFull -> capacity();
RingBuffer::enqueue -> push_back();
RingBuffer::dequeue -> front(), erase(), begin();
RingBuffer::peek -> front();

I tested my implementation by just calling it I knew it took in the call and had a seperate main to test the output of each function. I also made sure it would fail if it did reach the case.
eg. RingBuffer rb(0) would throw 
 std::invalid_argument
    ("RB constructor: capacity must be greater than zero.");

eg. enqueue would throw
std::runtime_error("enqueue: can't enqueue to a full ring.");
if the buffer was full.

For the exceptions, I just had if/else statements to determine if the program should throw a exception.

eg. dequeue()
if(NOT EMPTY)
//do code
else
//throw exception

eg. peek()
if(NOT EMPTY)
//do code
else
//throw exception

The time the implemention takes is O(1) because when an buffer is constructed, It has a fixed capacity, and what you're doing is either , checking it (isEmpty() and isFull()adding things into it (enqueue), deleting things in it or returning a int16_t value (dequeue and peek).
The space it takes is O(N) because of much you put into the buffer and if it is large enough, it can end up taking a considerable about to space in the buffer.
