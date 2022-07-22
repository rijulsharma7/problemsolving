#include<iostream>
using namespace std;
int momimom(int a[30], int i, int n) {
	if (i + 1 == n) {
		return max(a[i], a[n]);
	}
	return max(a[i] + min(momimom(a, i + 1, n - 1), momimom(a, i + 2, n)),
	           a[n] + min(momimom(a, i, n - 2), momimom(a, i + 1, n - 1)));
}
int main() {
	int n, a[30], s1 = 0, s2 = 0;
	cin >> n;
	int i = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << momimom(a, i, n - 1);
	return 0;
}