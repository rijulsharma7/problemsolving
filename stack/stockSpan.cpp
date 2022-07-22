#include<bits/stdc++.h>
using namespace std;
void stockSpan(int n, int a[1000000]) {
	stack <int> s;
	int arr[100000];
	arr[0] = 1;
	s.push(0);
	for (int i = 1; i < n; i++) {
		while (!s.empty() and a[s.top()] <= a[i]) {
			s.pop();
		}
		if (!s.empty()) {
			arr[i] = i - s.top();
		} else arr[i] = i + 1;
		s.push(i);
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	} cout << endl;
}
int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		int n;
		cin >> n;

		int a[100000];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		stockSpan(n, a);
	}
	return 0;
}
