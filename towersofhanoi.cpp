	
	
	#include <iostream>
	#include <stack>
	#include <fstream>
	using namespace std;
	/*
	 newDisk function gets a disk from the start peg and places it on peg 1
	 updates values of current, start, and moves
	 n: disk that is being moved
	 current: current number of disks on the auxillary pegs
	 start: current number of disks on the start peg
	 movesFile: output file stream
	 */
	void H(int n, char aux1, char aux2, char aux3, int& current, int& start, int&moves, ofstream & movesFile);
	
	void newDisk(int n, int& current, int& start, int& moves, ofstream & movesFile)
	{
	    if(start>0 && n>current){
	        movesFile<< "Disk "<< n<<" moves from start to aux1"<<endl;
	        current++;
	        start--;
	        moves++;
	    }
	}
	/*
	 outDisk function places a disk on the dest peg from peg 3
	 updates values of current and moves
	 */
	void outDisk(int n, int& current, int start, int& moves, ofstream & movesFile){
	    if(start==0 && n==current){
	        movesFile<< "Disk " << n <<" moves from aux3 to dest"<<endl;
	        current--;
	        moves++;
	    }
	}
	
	/*
	 H is a recursive function that also calls inDisk, and outDisk to insert and
	 remove disks to and from the auxillary pegs.
	 */
	
	void H(int n, char aux1, char aux2, char aux3, int& current, int& start, int&moves, ofstream &movesFile) {
	    if (n == 1) {
	        newDisk(n, current, start, moves, movesFile);
	        movesFile<< "Disk " << n << " moves from aux" << aux1 << " to aux" << aux2 << endl;
	        movesFile<< "Disk " << n << " moves from aux" << aux2 << " to aux" << aux3 << endl;
	        moves = moves + 2;
	        if (start == 0 && current == 1){
	            movesFile<< "Disk " << n << " moves from aux" << aux3 << " to dest" << endl;
	            moves++; }
	    }
	    if(n >=2) {
	        H(n-1,aux1,aux2,aux3,current, start,moves,movesFile);
	        newDisk(n, current, start, moves, movesFile);
	        movesFile<< "Disk " << n << " moves from aux" << aux1 << " to aux" << aux2 << endl;
	        moves++;
	        H(n-1,aux3,aux1,aux2,current,start,moves,movesFile);
	        movesFile<< "Disk "<< n << " moves from aux" << aux2 << " to aux" << aux3 << endl;
	        moves++;
	        outDisk(n, current,start,moves,movesFile);
	        H(n-1,aux1,aux2,aux3,current, start,moves,movesFile);
	    }
	}
	
	/*
	 main function calls H for n=1,2,3,4,5,6,7,8,9,10
	 */
	int main(int argc, const char * argv[]) {
	    
	    int n;
	    int startCount;
	    int currentCount=0;
	    int moves=0;
	    //char variables to represent pegs
	    char aux1='1';
	    char aux2='2';
	    char aux3='3';
	    ofstream movesFile;
	    movesFile.open("moves.txt");
	    //loop n from 1 to 10 as number of disks
	    for(n =1; n < 4; n++){
	        startCount=n;
	        H(n, aux1, aux2, aux3, currentCount, startCount, moves, movesFile);
	        movesFile<<"Number of total moves: " << moves<<endl;
	        moves=0;
	        startCount=0;
	        currentCount=0;
	        movesFile<<endl;
	    }
	    return 0;
}
