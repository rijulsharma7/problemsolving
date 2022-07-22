#include<iostream>
using namespace std;
int sum=0;
int cnt=0;
void subset(int n,int a[100000],int i){
	if(i==n){//cout<<sum<<endl;
        if(sum==0){
		cnt++;
		}
	return;}
    subset(n,a,i+1);
    sum+=a[i];
	subset(n,a,i+1);
    sum-=a[i];
	
}
int main() {
    int t;
    cin>>t;
    for(int j=0;j<t;j++){
		int n,a[100000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
    subset(n,a,0);
   // cout<<cnt<<endl;
    if (cnt>1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }sum=0;
    cnt=0;
    }
	return 0;
}