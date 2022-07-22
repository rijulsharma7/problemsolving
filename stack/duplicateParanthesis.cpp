#include <bits/stdc++.h>
using namespace std;

bool isValid(char *s1) {
	stack <char> s;
	for (int i = 0; s1[i] != '\0'; i++) {
		char ch = s1[i];
		s.push(ch);
		if (ch == ')') {
			s.pop();
			if (s.top() == '(') {
				return false;
			}
			while (s.top() != '(') {
				s.pop();
			}
			s.pop();
		}
	}
	return s.empty();
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		char s1[100];
		cin >> s1;
		if (isValid(s1)) {
			cout << "No Duplicates Found" << endl;
		}
		else {
			cout << "Duplicate Found" << endl;
		}
	}
	return 0;
}