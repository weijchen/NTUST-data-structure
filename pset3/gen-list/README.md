### OS:

macOS Sierra (Version 10.12.6)

### IDE:

Sublime 3

### Compiler:

g++

### Process steps:

```
1. Compile with g++ (g++ *.cpp -o main.out).

2. Execute main.out (./main.out).

3. Enter polynomial terms (coff, x, y, z), enter Q/q to quit.

4. Choose function (retCoeff(), Mulf()).

Ex:
g++ *.cpp -o main.out
./main.out

Enter coefficient and exponents (coff x y z), Q to quit > 4 10 3 2
Enter coefficient and exponents (coff x y z), Q to quit > 2 8 3 2
Enter coefficient and exponents (coff x y z), Q to quit > 3 0 2 2
Enter coefficient and exponents (coff x y z), Q to quit > 1 4 4 1
Enter coefficient and exponents (coff x y z), Q to quit > q
===== Choose function =====
1. retCoeff(ex, ey, ez)
2. Mulf(ex, ey, ez)
0. Quit
> 1
Enter (ex ey ez) > 8 3 2
retCoeff(8, 3, 2) = 2

===== Choose function =====
1. retCoeff(ex, ey, ez)
2. Mulf(ex, ey, ez)
0. Quit
> 2
Enter (ex ey ez) > 0 1 2
Mulf(0, 1, 2)

===== Choose function =====
1. retCoeff(ex, ey, ez)
2. Mulf(ex, ey, ez)
0. Quit
> 1
Enter (ex ey ez) > 0 3 4
retCoeff(0, 3, 4) = 3
```