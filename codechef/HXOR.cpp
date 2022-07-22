#include <bits/stdc++.h>
#define foi ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
using ll = long long;
using namespace std;
ll powof2(ll n){
    if(n==1){
        return 0;
    }
    ll i=1;
    ll ans=0;
    while(i<n){
        i=i<<1;
        ans++;
        if(i==n){
          return i;
        }
    }
    return ans-1;
}
void solve(){
    ll n, x;
    cin >> n >> x;
    ll seq[n];
    bool check[31];
    for(ll i=0;i<=31;i++) {
        check[i] = true;
    }
    for(ll i=0; i<n; i++) {
        cin >> seq[i];
    } 
    ll p;
    if(n==2){
        p = powof2(seq[0]);
        for(ll k=p;k>=0;k--){
            if( ( (seq[0] ^ (1<<k) ) < seq[0]) && x!=0 ){
                x--;
                seq[0] = seq[0] ^ (1<<k);
                seq[1] = seq[1] ^ (1<<k);
            }
        }
        if(x%2!=0){
            seq[0] = seq[0] ^ (1<<0);
            seq[1] = seq[1] ^ (1<<0);
        }
        cout << seq[0] << " " << seq[1] <<endl;
        return;
    }
    for(ll i=0; i<n; i++)
    {
        if(i == (n-1)){
            for(ll k=0;k<=31;k++){
                if(!check[k]){
                    seq[i] = seq[i] ^ (1<<k);
                }
            }
            break;
        }
        if(x==0){
            for(ll l =i;l<(n-1);l++){
                p = powof2(seq[l]);
                for(ll k=p;k>= 0;k--){
                    if(!check[k]){
                        if( (seq[l] ^ (1<<k)) < seq[l] ){
                            check[k] = true;
                            seq[l] = seq[l] ^ (1<<k);
                        }
                    }
                }
            }
            for(ll k=0;k<=31;k++){
                if(!check[k]){
                    seq[n-1] = seq[n-1] ^ (1<<k);
                }
            }
            break;
        }
        p = powof2(seq[i]);
        for(ll k=p;k>= 0;k--){
            if(!check[k]){
                if( (seq[i] ^ (1<<k)) < seq[i] ){
                    check[k] = true;
                    seq[i] = seq[i] ^ (1<<k);
                }
            }
            else if( ((seq[i] ^ (1<<k)) < seq[i]) && x!=0 ){
                x--;
                check[k] = false;
                seq[i] = seq[i] ^ (1<<k);
            }
        } 
    }
    for(ll i=0; i<n; i++)  {
        cout << seq[i] << " ";
    }
    cout<<endl;
}
signed main() {
    foi
    ll test;
    cin >> test;
    while(test){
        solve();
        test-=1;
    }
    return 0;
}
