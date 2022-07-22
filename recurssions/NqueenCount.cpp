#include<iostream>
using namespace std;
int cnt = 0;
bool check(int out[1000][1000], int x, int y, int size) {
	if (x >= size || y >= size || x < 0 || y < 0) {
		return false;
	}
	for (int i = 0; i < x; i++) {
		if (out[i][y] == 1) {
			return false;
		}
	}
	for (int i = 0; i < y; i++) {
		if (out[x][i] == 1) {
			return false;
		}
	}
	int m = x;
	int n = y;
	while (m >= 0 || n >= 0) {
		if (out[m][n] == 1) {
			return false;
		}
		m--;
		n--;
	}
	m = x;
	n = y;
	while (m >= 0 || n < size) {
		if (out[m][n] == 1) {
			return false;
		}
		m--;
		n++;
	}
	return true;
}
bool N_queen(int out[1000][1000], int n, int i) {
	if (i == n) {
		cnt++;
		return true;
	}
	for (int j = 0; j < n; j++) {
		if (check(out, i, j, n)) {
			out[i][j] = 1;
			N_queen(out, n, i + 1);

			out[i][j] = 0;
		}

	}
	return false;
}
int main() {
	int n;
	cin >> n;
	int out[1000][1000] = {0};
	N_queen(out, n, 0);
	cout << cnt << endl;
	return 0;
}
