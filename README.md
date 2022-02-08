# WHAT IS BRAINFUCK?

Brainfuck is a turing-complete, esoteric language that uses only 8 commands.

# HOW DO I BRAINFUCK?

> mempo = memory pointer

The instructions for writting in brainfuck are the following:

```
+ --> Adds 1 to the value on the mempo is in.

- --> Removes 1 to the value on the mempo is in.

> --> Changes the mempo by 1.

< --> Changes the mempo by -1.

. --> Outputs ASCII(char) value.

, --> Inputs ASCII(char) value.

[ --> Starts a loop.

] --> Ends a loop if the value of the mempo it's in equals to 0, otherwise it restarts.
```

Every character other than those is (hopefully) ignored.

# ERRORS
If it doesn't work, depending on the return it can be the following:

```
0   - No problems on the code, check it's well written.

1   - There is an unfinished loop, somewhere.

2   - You are trying to access a negative mempo.

3   - 1 & 2

4   - Not enough input.

5   - 1 & 4

6   - 2 & 4

7   - 1 & 2 & 4
```
