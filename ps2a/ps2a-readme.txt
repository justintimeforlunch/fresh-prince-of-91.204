Name: Justin Nguyen

Explanation: The representation I used for the register bits was that a string is an array of characters. I know that in that array, it goes from left to right(starting at 0) to whatever element, but in the LFSR, it goes the opposite way and goes from right to left, so I had to calculate the tap in the way so it would put the tap in the right place as in LFSR. After I xor'd the front of the array(left) and whereever the tap was, I looked up how to change an integer into a string. Next I erased the leftmost digit in the array and put together the xor'd value and the seed.

In my two additional Boost unit tests, I used one long binary string and a shorter string and tested it the same way the one given to us is tested, to see if (1) it would run, and (2) if it worked the way I thought it would.
