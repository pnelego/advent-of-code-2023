# advent-of-code-2023
This year, doing c++, folders will contain source code for each challenge as well as my challenge file.

### Goal and project structure
My goal for this advent of code isn't to be the first to do a challenge.
Instead im trying to make my code as fast as I can possibly get it in microseconds.

In order to do this, I've opted to remove as much OS overhead as I could from the 
actual execution of the part.

In general the steps look like this:
1. Read File
2. Start Timer
3. Execute and collect input
4. Stop Timer
5. Display Time to Execute and result.

It will do this for both parts idependently, besides part two's file aquisision, where instead of re-reading, 
it will copy the buffer before part1 is executed. In addition, while it's not something I would ever do normally,
I'm considering the input file arrays mutable, this will allow us to get a more accurate time, as we won't be
wasting any time copying it after the time has started. 

In addition, the actual functions are highly devoid of console outputs in their final form, due to the overhead
of stdout.
