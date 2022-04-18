/*
      https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875?leftPanelTab=0
*/

void insert(stack<int> &st, int temp) {
	if (st.size() == 0) {
		st.push(temp);
		return;
	}
	int val = st.top();
	st.pop();
	insert(st, temp);
	st.push(val);
	return;
}

void reverse(stack<int> &st) {
	if (st.size() == 0) {
		return;
	}
	int temp = st.top();
	st.pop();
	reverse(st);
	insert(st, temp);
}
void reverseStack(stack<int> &stack) {
    reverse(stack);
}
