OS: macOS Sierra (Version 10.12.6)
IDE: Sublime 3
Compiler: g++

Process steps:

1. Compile with g++ (g++ *.cpp -o main.out).

2. Execute main.out (./main.out).

3. Enter sequence of node, type 'Q' or 'q' to quit.

4. Choose function.
4-1. Insert
4-2. Delete
4-3. Show
4-4. Avg (returns the average of the elements that are ranked lth to uth)
4-5. Root val (print root value)
4-6. Quit

Ex:
g++ *.cpp -o main.out
./main.out

BST created!
Enter node, Q to quit > 20
Enter node, Q to quit > 17
Enter node, Q to quit > 14
Enter node, Q to quit > 36
Enter node, Q to quit > 22
Enter node, Q to quit > 28
Enter node, Q to quit > 48
Enter node, Q to quit > q
********************
1. Insert
2. Delete
3. Show
4. Avg
5. Root val
6. Quit
********************
Enter your choice: 3

===== Show Data =====
Value: 14; Leftsize: 1; Rank: 1
Value: 17; Leftsize: 2; Rank: 2
Value: 20; Leftsize: 3; Rank: 3
Value: 22; Leftsize: 1; Rank: 4
Value: 28; Leftsize: 1; Rank: 5
Value: 36; Leftsize: 3; Rank: 6
Value: 48; Leftsize: 1; Rank: 7

********************
1. Insert
2. Delete
3. Show
4. Avg
5. Root val
6. Quit
********************
Enter your choice: 4

Enter lower bound: 2
Enter upper bound: 4
19