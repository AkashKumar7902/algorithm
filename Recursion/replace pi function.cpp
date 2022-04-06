/* problem statement :
 Given a character array/ string ,
 we need to replace all occurences of
 "pi" with "3.14" without taking any extra
 array.
 
 Input : xpighpilmpibi
 output : x3.14gh3.14lm3.14lm3.143.14
 
 To do this we will shift the characters after pi in the
 original array by two positions because pi(len : 2) is going
 to be replaced by 3.14(len : 4), so (4 - 2) = 2.
 
 
 If pi is not found in the current index i , then call the recursive function
 for rest part of the character array i.e. character array starting from
 i + 1 and ending at null character.
 
 If pi is found in the current index , we will do the shifting, 
 followed by replacement, followed by recursive call on
 the array after being replaced i.e. if the i pointer
 was pointing to 'p' of "pi" then now its going to point
 to '3' of "3.14" so the next valid search for pi will
 begin from i + 4 . Hence we are going to call the recursion
 function on the character array starting at i + 4 and ending at the 
 null character.
  
    x   3  .  1   4   g   h  ....... 
        ^             ^
        |             |
        i             i + 4
        

*/


#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;

#define ll long long

#define MOD 1000000009

void replacepi(char a[], int i) {
	// base case
	if (a[i] == '\0' or a[i + 1] == '\0') {
		return;
	}
	// look for pi on current location
	if (a[i] == 'p' and a[i + 1] == 'i') {
		// shifting + replacement with 3.14
		int j = i + 2;

		// take j to the end of the array
		while (a[j] != '\0') {
			j++;
		}

		// shifting (right to left)
		while (j >= i + 2) {
			a[j + 2] = a[j];
			j--;
		}

		// replacement  + recursive call for remaining part
		a[i] = '3';
		a[i + 1] = '.';
		a[i + 2] = '1';
		a[i + 3] = '4';
		replacepi(a, i + 4);
	}
	else {
		replacepi(a, i + 1);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	char c[100000];
	cin >> c;
	replacepi(c, 0);
	cout << c << endl;
}
