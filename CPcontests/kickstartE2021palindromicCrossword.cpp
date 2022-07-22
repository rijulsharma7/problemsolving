#include <iostream>
using namespace std;
using ll = long long int;



void dfs(char arr[][1005], int sr[][1005], int er[][1005], int sc[][1005], int ec[][1005], bool visited[][1005], int i, int j, int &cnt) {
    if (!visited[i][j]) {
        if (arr[i][j] != '.' || arr[i][j] != '#') {

            if (er[i][j] - sr[i][j] > 2) {

                int l = er[i][j] - sr[i][j] - 1;
                int idx = j - sr[i][j];

                if (arr[i][j - idx] == '.') {
                    arr[i][j - idx] = arr[i][j];
                    cnt++;
                    dfs(arr, sr, er, sc, ec, visited, i, j - idx, cnt);
                }
            }

            if (ec[i][j] - sc[i][j] > 2) {

                int l = er[i][j] - sr[i][j] - 1;
                int idx = i - sc[i][j];

                if (arr[i - idx][j] == '.') {
                    arr[i - idx][j] = arr[i][j];
                    cnt++;
                    dfs(arr, sr, er, sc, ec, visited, i - idx, j, cnt);
                }
            }

        }
    }
    visited[i][j] = true;
    return;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << "Case #" << z << ": ";

        int m, n;
        cin >> m >> n;
        char arr[m][1005];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        int sr[m][1005], er[m][1005], sc[m][1005], ec[m][1005];
        for (int i = 0; i < m; i++) {
            int last = n;
            for (int j = n - 1; j >= 0; j--) {
                if (arr[i][j] == '#') {
                    er[i][j] = j;
                    last = j;
                }
                else {
                    er[i][j] = last;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            int first = -1;
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == '#') {
                    er[i][j] = j;
                    first = j;
                }
                else {
                    er[i][j] = first;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            int first = -1;
            for (int i = 0; i < m; i++) {
                if (arr[i][j] == '#') {
                    er[i][j] = i;
                    first = i;
                }
                else {
                    er[i][j] = first;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            int last = m;
            for (int i = m - 1; i >= 0; i--) {
                if (arr[i][j] == '#') {
                    er[i][j] = i;
                    last = i;
                }
                else {
                    er[i][j] = last;
                }
            }
        }
        bool visited[m][1005];
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(arr, sr, er, sc, ec, visited, i, j, cnt);
            }
        }
        cout << cnt << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j];
            }
            cout << endl;
        }

    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    repp(z, t)
    {
        //cout << "Case #" << z << ": ";
        calc();
        cout << '\n';
    }

    return 0;
}
