# Day 1 - Part 2
Extending from part 1, we'll also add the number of turns divided by 100 (floored) since every full turn passes 0 once. Then we'll deal with the number of turns modulo 100. If the current value is already 0, then there won't be another pass. Else, if the turns change the value to/pass 0 or 100, we add 1 to the answer.

#### Time: O(1) for each string, O(n) for n as number of entries
#### Space: O(1)