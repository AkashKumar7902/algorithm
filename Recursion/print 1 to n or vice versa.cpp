/*
  Parts of recursion algorithm 
  1) Base case
  2) Recursive call (to work towards Base case) 
  
  while solving recursion question 
  if there is a case of choices, then make recursive tree.
  If u make the recursive tree then writing code will be a cakewalk.
  
  If its not the case of choices,
  do the following (Principle of Mathematical Induction) (PMI) :
  1) Figure out the Base Case
  2) Assume sub Problems can be solved by recursion (automatically)
  3) using the Sub- Problems write the answer for the current problem.
  Lets call this Method IBH (Induction- Base case - Hypothesis).
*/


 // Problem statement : print numbers from 1 to n using recursion.
// since its not the case of choices we will use IBH.

void solve(int n) {
	//base case
	if (n == 0) {       // step 1
		return;
	}
	solve(n - 1);      // step 2
  cout << n << endl; // step 3
}


// problem statement : print numbers from n to 1 using recursion
// since its not the case of choices we will use IBH.

void solve(int n) {
	//base case
	if (n == 0) {       // step 1
		return;
	}
  cout << n << endl; // step 3
	solve(n - 1);      // step 2
}


// Thanks 
