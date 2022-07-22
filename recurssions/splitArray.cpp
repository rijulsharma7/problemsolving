#include <bits/stdc++.h>
using namespace std;
int sum1=0,sum2=0,cnt=0;
bool splitArray(int size,int *arr,int i,int *a,int *b,int m,int n){
    if(i==size){
        if(sum1==sum2){
            cnt++;
            for(int k=0;k<m;k++){
                cout<<" "<<a[k];
            }cout<<" and";
            for(int k=0;k<n;k++){
                cout<<" "<<b[k];
            }cout<<endl;
            return true;
        } else return false;
    }
    a[m]=arr[i];
    sum1+=a[m];
    splitArray(size,arr,i+1,a,b,m+1,n);
    sum1-=a[m];
    b[n]=arr[i];
    sum2+=b[n];
    splitArray(size,arr,i+1,a,b,m,n+1);
    sum2-=b[n];
    return false;
}
int main() {
    int n;
    cin>>n;
    int arr[n],a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    splitArray(n,arr,0,a,b,0,0);
    cout<<cnt;
    return 0;
}