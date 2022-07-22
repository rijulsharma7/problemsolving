#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum;
        cin>>sum;
        if(sum<n-1){
           
         for(int i=0; i<n/2; i++){
             if(i==sum){
                 cout<<i<<" "<<n-1<<endl;
             }
             else if(n-1-i==sum){
                 cout<<sum<<" "<<n-1<<endl;
             }
             else if(i==0){
                 cout<<0<<" "<<n-1-sum<<endl;
             }
             else{
                 cout<<i<<" "<<n-1-i<<endl;
             }
         }
        }
        else{
            if(n-1>3){
                cout<<n-1<<" "<<n-2<<endl;
                cout<<1<<" "<<3<<endl;
                cout<<0<<" "<<n-1-3<<endl;
 
            
            for(int i=2; i<n/2; i++){
                if(i==3){
                    continue;
                }
                else{
                    cout<<i<<" "<<n-1-i<<endl;
                }
            }
            }
            else{
                cout<<-1<<endl;
            }
 
        }
    }
}
