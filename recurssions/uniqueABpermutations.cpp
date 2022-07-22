#include<iostream>
using namespace std;
int cnt = 0;
int assign(int n, char out[26], int j) {
	if (j == n) {
		out[j] = '\0';
		//cout<<out<<" ";
		cnt++;
		return cnt;
	}
	out[j] = 'a';
	assign(n, out, j + 1);

	if (j == 0 || out[j - 1] != 'b') {
		out[j] = 'b';
		assign(n, out, j + 1);
	}
	return cnt;
}
int main() {
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		//int cnt=0;
		char out[26];
		cin >> n;
		int c = assign(n, out, 0);
		cout << "#" << i + 1 << " : " << c << endl;
		cnt = 0;
	}
	return 0;
}
