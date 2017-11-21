### OS:

macOS Sierra (Version 10.12.6)

### IDE:

Eclipse, Sublime 3

### Compiler:

g++

### Process steps:

```
1. Initial setting - Set maxRows and maxCols.

2. Compile with g++ (g++ pset1.cpp -o main.out).

3. Execute main.out (./main.out).

4. Enter matrix (row by row), matrix will prompt out.

5. Decide "reused" parameter (Y/N).

6. Enter pattern.

7. If pattern found, answer will be shown. Otherwise, show "no match".

8. Replay or not (will go to step (5) if choose yes, otherwise, close program).

Ex:
g++ *.cpp -o main.out
./main.out

Row: 1 > adbde
Row: 2 > dbcbe
Row: 3 > deadc
Row: 4 > bddbd
Row: 5 > cedcb

[Your matrix]
=============
a d b d e
d b c b e
d e a d c
b d d b d
c e d c b
=============
Do you want element to be reused? (Y/N)
> y
===== You can reuse element! =====
Enter check pattern
> acbea
(2,2) (1,2) (1,1) (2,1) (2,2)
Replay? (Y/N)
> y
=============
Do you want element to be reused? (Y/N)
> n
===== You can't reuse element! =====
Enter check pattern
> acbea
no match
Replay? (Y/N)
> n
=============
Shut down
```