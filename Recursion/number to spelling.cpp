/* 
input : 2048
output : two zero four eight

in this problem we will first build build the function calls and then output the answer 
so we are gonna solve it in bottom up direction that means we are doing the work after the function call.

Thanks

*/


char words[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void printspellings(int n) {
	if (n == 0) {
		return;
	}
	printspellings(n / 10);
	int digit = n % 10;
	cout << words[digit] << " ";

}
