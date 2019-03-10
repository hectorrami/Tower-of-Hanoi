# Towers of Hanoi 

## Problem
Solve the Towers of Hanoi game for the following graph G=(V,E) with V={Start, Aux1,Aux2, Aux3,Dest} 
and E ={(Start,Aux1), (Aux1,Aux2), (Aux2,Aux3), (Aux3,Aux1),(Aux3,Dest)}.

* Design an algorithm and determine the time and space complexities of moving n disks form Start to Dest.

* Implement this algorithm whereby your program prints out each of the moves of every disk. Show the output for n=1,2,3,4,5,6,7,8,9,10.

## Solution

#### Input
For input, this program takes an integer n, where n is the number of disks the user wants to solve for the Towers of Hanoi puzzle.

#### Assumptions
n is a number between 1 and 10, inclusive. Disks can only move to adjacent pegs. For example, the disk cannot travel from A1 directly to A3, the disk must travel from A1 to A2 and A2 to A3. Otherwise, the move is considered illegal. The Start peg cannot be moved onto again, and the Dest peg cannot be moved off once the disk has been moved onto it. The only disk that allows us to backtrack in this case is Aux3 from Aux3 to Aux1.
#### Time and Space Complexity
The time complexity would be derived from the number of recursive calls. For this algorithm there are 3 recursive calls so r =3 and d =1 because when n =1 disk 1 moves from the start to dest peg (base case).Using Master Theorem for time complexity:The time complexity for this F(n) = 3n/1 algorithm is O(3n).
The space complexity is O(n) because the recursive shifts are independent of each n (constant). The space complexity would then be linear.

#### Output

The output for n=10 (10 disks) consists of 24,979 moves to complete the puzzle
Here are the last ten (the complete list can be found on file output.txt)

Move 24970: Move disk 3 from Aux3 to Dest
Move 24971: Move disk 1 from Aux1 to Aux2
Move 24972: Move disk 1 from Aux2 to Aux3
Move 24973: Move disk 2 from Aux1 to Aux2
Move 24974: Move disk 1 from Aux3 to Aux1
Move 24975: Move disk 2 from Aux2 to Aux3
Move 24976: Move disk 2 from Aux3 to Dest
Move 24977: Move disk 1 from Aux1 to Aux2
Move 24978: Move disk 1 from Aux2 to Aux3
Move 24979: Move disk 1 from Aux3 to Dest



## Reference 
The concepts behind this implementation are best explained in this video:
https://www.youtube.com/watch?v=bFC9yB26Xrw
