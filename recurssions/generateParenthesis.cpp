#include<iostream>
using namespace std;
void gen(char *out, int n, int id, int o, int c) {
	if (id == 2 * n) {
		out[id] = '\0';
		cout << out << endl;
		return;
	}
	if (c < o) {
		out[id] = ')';
		gen(out, n, id + 1, o, c + 1);
	}
	if (o < n) {
		out[id] = '(';
		gen(out, n, id + 1, o + 1, c);
	}
}
int main() {
	int n;
	cin >> n;
	char out[100000];
	gen(out, n, 0, 0, 0);
	return 0;
}