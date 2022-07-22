#include <iostream>
using namespace std;
using ll = long long int;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=1; i<=n; i++){
            cin>>arr[i];
        }
        int cnt=0;
        arr[0]=0;
        for(int i=1; i<=n; i++){
            for(int j=i; j<=n; j++){
                bool check=true;
                int prev=i-1;
                for(int k=i; k<=j; k++){
                   if(arr[k]>=i && arr[k]<=j ){
                       if(arr[k]<prev){
                            check=false;
                            break;
                       }
                       else{
                           prev=arr[k];
                       }
                      
                   }
                }
                if(check){
                    cnt++;
                }
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}