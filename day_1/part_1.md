# Day 1 - Part 1
Let the current lock value be 50. Parse each string into a direction (first character) and number of turns (the rest of the string). If left, subtract from the original value; else right, add to the original value. If the lock value is divisible by 100, increase the count by 1.

#### Time: O(1) for each string, O(n) for n as number of entries
#### Space: O(1)