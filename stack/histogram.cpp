#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ll n;
    cin >> n;
    ll h[n];
    for (ll i = 0; i < n; i++) {
        cin >> h[i];
    }
    ll i, sum = 0, ma = 0;
    stack <ll> s;
    s.push(0);
    for ( i = 1; i < n; i++) {
        if (h[i] >= h[s.top()]) {
            s.push(i);
        }
        else {
            while (!s.empty() && h[i] < h[s.top()]) {
                ll a = h[s.top()];
                s.pop();
                if (!s.empty()) {
                    sum = a * (i - s.top() - 1);
                    ma = max(ma, sum);
                } else {
                    sum = a * (i);
                    ma = max(ma, sum);
                }
            }
            s.push(i);
        }

    }
    while (!s.empty()) {
        ll a = h[s.top()];
        s.pop();
        if (!s.empty()) {
            sum = a * (i - s.top() - 1);
            ma = max(ma, sum);
        } else {
            sum = a * (i);
            ma = max(ma, sum);
        }
    }
    cout << ma;
    return 0;
}
