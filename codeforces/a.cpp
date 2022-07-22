#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vs = vector<string>;
using ml = map<ll, ll>;
using uml = unordered_map<ll, ll>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;
using vll = vector<pl>;
using vlll = vector<tl>;
using pq = priority_queue <ll, vl, greater<ll>>;
using gq = priority_queue <ll>;
#define mem(dp) memset(dp, -1, sizeof(dp))
#define aut(a, b) for (auto&(a) : (b))
#define out(v) for (auto&(x) : (v)) cout << x << " "; cout << '\n';
#define rep(i, n) for (ll (i) = 0; (i) < (n); ++(i) )
#define repp(i, n) for (ll (i) = 1; (i) <= (n); ++(i) )
#define rev(i, n) for (ll (i) = n-1; (i) >= 0; --(i) )
#define revv(i, n) for (ll (i) = n; (i) > 0; --(i) )
#define all(v) v.begin(), v.end()
#define fi get<0>
#define se get<1>
#define th get<2>
#define F first
#define S second
#define mp 
#define mt make_tuple
#define pb push_back
ll inf = 1e18; ll mod = 1e9 + 7;
bool compare(ll a, ll b) {return a > b;}
ll digit(ll n) {return floor(log10(n) + 1);}

ll n, m;
vl s(5000006), a(5000006);    
void calc()
{
    multiset<ll> ml;
    cin>>n>>m;
    rep(i, m) {cin>>s[i]; ml.insert(s[i]);}
    ll res = -m;
    ll ans = 0;
    bool f = true;
    rep(i, m) 
    {
        cin>>a[i];
        if(ml.count(a[i]) == 0) {ans++; f=false;}
        else ml.erase(ml.find(a[i]));
    }
    ml.clear();
    rep(i, m) ml.insert(a[i]);
    a.clear();
    // while(n && f)
    // {
    //     rep(i, m) 
    //     {
    //         cin>>a[i];
    //         if(ml.count(a[i]) == 0) {ans++; f=false;}
    //         else ml.erase(ml.find(a[i]));
    //     }
    //     ml.clear();
    //     rep(i, m) ml.insert(a[i]);
    //     n--;
    //     f = false;
    // }

    repp(i, n-1)
    {
        // out(ml);
        rep(i, m) 
        {
            cin>>a[i];
            if(ml.count(a[i]) == 0) res++;
            else
            {
                ml.erase(ml.find(a[i]));
            }
        }
        // out(a);
        ml.clear();
        rep(i, m) ml.insert(a[i]);
        a.clear();
        // cout << " "<<res<<" \n";
        // out(ml);
    }#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
   int key;
   Node *left;
   Node *right;

   Node(int key){
       this->key = key;
       left = right  = NULL;
   }
};


bool equal(Node * X, Node * Y){
    //Complete the Function
    if (X == Y) {
        return true;
    }
    return (X && Y) && (X->key == Y->key) &&
        ((equal(X->left, Y->left) && equal(X->right, Y->right)) ||
        (equal(X->right, Y->left) && equal(X->left, Y->right)));
    
}
    // cout << res << " "<< ans << '\n';
    s.clear(); ml.clear();
    if(res+ans > 0) cout << res+ans;
    else cout << ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("runway_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    repp(z, t)
    {
        cout << "Case #" << z << ": ";
        calc();
        cout << '\n';
    }

    return 0;
}
