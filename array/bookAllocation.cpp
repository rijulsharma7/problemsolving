#include<iostream>
using namespace std;
bool check(int a[100],int mid,int n,int m){
	int s=1,p=0;
	for(int i=0;i<n;i++){
		if((p+a[i])>mid){
			s++;
			if(s>m){
				return false;
			}
			p=0;
		}
		p+=a[i];
	}
    return true;
}
int bookAlloc(int n,int m,int a[100]){
	int s=a[n-1],e=0;
	for(int i=0;i<n;i++){
		e+=a[i];
	}
	while(s<=e){
		int mid=(s+e)/2;
		if(check(a,mid,n,m)){
			e=mid-1;
		} else {
			s=mid+1;
			}
	}
	return s;
}
int main() {
	int t;
	cin>>t;
	for(int k=0;k<t;k++){
		int n,m;
		cin>>n>>m;
		int a[100];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<bookAlloc(n,m,a)<<endl;
	}
	return 0;
}
