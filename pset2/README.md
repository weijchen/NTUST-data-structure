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

3. Enter the number of client.

4. Enter Client's information (arrive time, serve time, allowable wating time).
PS:
* First client can't arrive at time 0
* Value of three time can't be negative

5. After entering clients, show serving results.

Ex:
g++ *.cpp -o main.out
./main.out

How many clients? > 6

Enter Client 1:
Arrive time: 3
Service time: 5
Allowable waiting time: 7
..
..
..
Enter Client 6:
Arrive time: 16
Service time: 6
Allowable waiting time: 3

Reach client number limited!
Begin program? (Y/N) > y

===== Final results =====
        Served or not?  Departure time
Client 1:       Yes          8
Client 2:       Yes          15
Client 3:       No
Client 4:       Yes          20
Client 5:       Yes          17
Client 6:       No
```