# WHAT IS BRAINFUCK?

Brainfuck is an esoteric language, or joke language, that is turing-complete and it works with cells. Even though it isn't very useful, it's an interesting experience every passionate programmer should experience. The name comes because coding on it does feel you that.

# HOW DO I BRAINFUCK?

Even though brainfuck is somewhat hard, it has only 7 instructions, and those are:

```
 +  --> Adds 1 to the cell it's in.

 -  --> Removes 1 to the cell it's in.

 >  --> Changes the cell position by 1.

 <  --> Changes the cell position by -1.

 ,  --> Allows for input.

 .  --> Echoes the value of the cell.

 [] --> Loops the instructions inside them as long as in the cell it ends on isn't 0.
```

Every character other than those is ignored.

# HOW DOES THIS INTERPRETER WORK?

That's something easy to answer since I was the one to write it's source code.
You should enter a file as an argument, and it should end in .b / .bf (mainly for organisation), and the file structure should be as follows:

```
1   CELLS:[number of cells(defaults to 10)]/ASCII:[y/n(defaults to n)]
2   // Brainfuck code
```

Easy, right? As a side note, you should keep this structure as similar as possible. You could not add the CELLS and ASCII specificators, but if you do, you must keep it as shown before.

# WHY?

Why i did it? Because I was bored. Why does this language exists in the first place? I guess someone felt the same way ~15 years before me.

# AUTHOR NOTE

Hope you enjoy playing with this, it's possible to do some impressive stuff. Remember that is under the GPLv3, that means that if you improve my shitty design, remember to push the changes to the repo.
