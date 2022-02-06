# WHAT IS BRAINFUCK?

Brainfuck is an esoteric language that is turing-complete and works with cells. 
Even though it isn't very useful, it's an interesting experience every passionate programmer should 
experience.

# HOW DO I BRAINFUCK?

This version of brainfuck has only 8 instructions, and those are:

```
 +  --> Adds 1 to the cell it's in.

 -  --> Removes 1 to the cell it's in.

 >  --> Changes the cell it's in by 1.

 <  --> Changes the cell it's in by -1.

 ,  --> Allows for ascii input.

 .  --> Echoes the ascii value of the cell.

 [  --> Starts a loop.

 ]  --> Goes to the last open bracket if it doesn't end on 0 / null.
```

Every character other than those is (hopefully) ignored.

# WHY?

Why i did it? Because I was bored. Why does this language exists in the first place? I guess someone felt the same way ~15 years before me.

# ERRORS
If it doesn't work, depending on the exit it can be the following:

0  -  No problems on the code, have you checked that it's well written?

1  -  There is an unfinished loop.

2  -  You are trying to access a negative cell position.

3  -  1 & 2.

4  -  Not enough input or not input at all.

5  -  1 & 4

6  -  2 & 4

7  -  1 & 2 & 4

# TODO
[x] Make it to interpret brainfuck(only in the python version atm).

[ ] Make it to COMPILE brainfuck.

[ ] Add more stuff to the TODO.

# AUTHOR NOTE

Hope you enjoy playing with this, it's possible to do some impressive stuff.
