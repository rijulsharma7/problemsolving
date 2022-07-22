#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++) {
        int n, m;
        cin >> n >> m;
        set<int> mp;
        vector<int> res;

        for (int i = 0; i < n; i++) {
            int s, e;
            cin >> s >> e;
            for (int j = s; j <= e; j++) {
                mp.insert(j);
            }
        }
        for (int i = 0; i < m; i++) {
            int s;
            cin >> s;

            int c = s;
            int diff = 0;

            while (!mp.empty()) {
                if (mp.find(c) != mp.end()) {
                    mp.erase(c);
                    res.push_back(c);
                    break;
                }
                else if (mp.find(c - diff) != mp.end()) {
                    mp.erase(c - diff);
                    res.push_back(c - diff);
                    break;
                }
                else if (mp.find(c + diff) != mp.end()) {
                    mp.erase(c + diff);
                    res.push_back(c + diff);
                    break;
                }
                else {
                    diff++;
                    continue;
                }
            }

        }
        cout << "Case #" << test << ": ";
        for (auto x : res) {
            cout << x << " ";
        }
        cout << endl;


    }
}