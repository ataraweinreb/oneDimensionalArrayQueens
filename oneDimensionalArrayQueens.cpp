

#include <iostream>
#include<cstdlib>
#include <cmath>
using namespace std;

	bool ok(int q[], int col){ //Returns true if the queen in column c is ok
		for(int i=0;i<col;i++){ //for each i from 0 to c-1
			if((q[i] == q[col]) || (abs(q[col] - q[i]) == (col - i))) { //and if theres a conflict you should return FALSE!
				return false;
			 }
		 }
			return true;
	} //boolean function ends here

	void backtrack(int &col){ //function to backtrack and find more answers!
		col--;
		if(col==-1) exit(1);
	} //backtrack function ends here

	void print(int q[]){ //use this function to print out the board!
		static int count =0;
		count++;
		int i,j,board[8][8]={0};
		cout<<"Solution #"<<count<<endl;
		for( i=0;i<8;i++){
			board[q[i]][i]=1;           
		}
		for(i=0;i<8;i++){ //final print board
			for(j=0;j<8;j++)
				cout<<board[i][j]<<" ";
				cout<<endl;
		 }
	 } // Print function ends here

	int main(){
	int q[8]; q[0]=0;
	int c=1; // keeps track if need to reset row
	bool from_backtrack=false; /*The outer loop keep looking for solutions and the program terminates from function backtrack when we are forced to backtack into column -1 */
	while(1){
		while(c<8){ //this loop goes across columns. If we just backtracked then you should use the val. of the rows
			if(!from_backtrack) // we did not just return from backtrack
				q[c]=-1;   //check here
				from_backtrack=false;
	while(q[c]<8){ // put the queen in this column
		q[c]++;
		// if row=8, there are no places left to put a queen! you finished the board!
		// so now we backtrack!
		while(q[c]==8){
			backtrack(c);
			q[c]++;
		}

                //if this position is ok, place the queen, otherwise we need to backtrack!
		if(ok(q, c))
			break;
	}// while q[c]<8
		c++; // if you placed the queen, you can go to the next col
	}//while(c<8)
	// solution found, print it.
	print(q); // board completed, print it out
	backtrack(c);
	from_backtrack=true;
}//while(1)
return 0;
}//main method
