#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {

#ifndef ONLINE_JUDGE
    freopen("runway_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    for(int test=1; test<=t; test++){
        int n,m;
        cin>>n>>m;
        int s[m];
        int idx[m];
        for(int i=0; i<m; i++){
            idx[i]=1;
        }
        unordered_map<int,vector<int>> mp;
        for(int i=0; i<m; i++){
            cin>>s[i];
            mp[s[i]].push_back(i);
        }
        int d=m;
        int cnt=0;
        int mat[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>mat[i][j];
            }
        }
        for(int i=0; i<n; i++){
            unordered_map<int,vector<int>> curr;
            stack<int> q;
            for(int j=0; j<m; j++){
                if(mp[mat[i][j]].size()>0){
                    int x=mat[i][j];
                    int ind=mp[x][mp[x].size()-1];
                    mp[x].pop_back();
                    curr[mat[i][j]].push_back(ind);
                }
                else{
                    q.push(mat[i][j]);



                }
            }
            //cout<<"n is "<<i<<" d is "<<d<<endl;
            for(auto p:mp){
                if(p.second.size()>0){
                    for(auto y:p.second){
                        if(idx[y]<=0){
                            cnt++;
                        }
                        else{
                            idx[y]--;
                        }

                        curr[q.top()].push_back(y);
                        q.pop();
                    }
                }
            }
            mp.clear();
            swap(mp,curr);
            curr.clear();
        }
        cout<<"Case #"<<test<<": "<<cnt<<endl;

    }
}