#include <bits/stdc++.h>
#define nl "\n"
#define vll vector<ll>
#define ll long long
#define all(v) v.begin(),v.end()

using namespace std;

void solve() {
  int n, ct = 0;
    cin >> n;
    vll a;
   for(int i=0;i<n;i++)
{
    int b;
  cin>>b;
  a.push_back(b);
}
    string s;
    cin >> s;
    if(is_sorted(all(a))){
      cout << 0 << endl;
      return;
    }
    for(auto x: s) if(x == 'N') ct++;
    if(ct == n or ct == 0){
      cout << -1 << endl;
      return;
    }
    vll b = a;
    sort(all(a));
    int start = INT_MAX, last = INT_MIN;
    for(int i = 0; i < n; i++){
      if(a[i] != b[i]){
        start = min(i, start);
        last = max(last, i);
      }
    }
    bool f1 = false, f2 = false;
    for(int i = 0; i < start; i++) if(s[i] != s[last]) f1 = true;
    for(int i = last; i < n; i++) if(s[i] != s[start]) f2 = true;
    if(s[start] != s[last] or f1 || f2) cout << 1;
    else cout << 2;
    cout << endl;
}

int main() {
  // your code goes here
  long long ht;
  cin>>ht;
  
  for(long long i=0;i<ht;i++)
{
solve();
} 
  return 0;
}
