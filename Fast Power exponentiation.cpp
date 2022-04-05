
//inefficient space : O(N);
int power(int a, int n) {
	if (n == 0) {
		return 1;
	}
	return a * power(a, n - 1);
}

//efficient space: O(log2 N)
int fast_power(int a, int n) {
	if (n == 0) {
		return 1;
	}
	int smaller_ans = fast_power(a, n / 2);
	smaller_ans *= smaller_ans;
	if (n & 1) {
		return smaller_ans * a;
	}
	return smaller_ans;
}

//inefficient recursive call 
// will compute same thing twice while traversing in the 
// recursive tree.
int ineff_fast_power(int a, int n) {
	if (n == 0) {
		return 1;
	}
	int smaller_ans = ineff_fast_power(a, n / 2) * ineff_fast_power(a, n / 2);
	if (n & 1) {
		return smaller_ans * a;
	}
	return smaller_ans;
}
