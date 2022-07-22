#include<bits/stdc++.h>
using namespace std;
int maximum=0;
bool check(int *arr,int k,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if((arr[i]+arr[j])%k==0){
				return false;
			}
		}
	}
	return true;
}
void cruelSubset(int n,int *a,int i,int *b,int j,int k){
	if(i==n){
		maximum=max(maximum,j);
		return;
	}
	if(check(b,k,j)){
		b[j]=a[i];
		cruelSubset(n,a,i+1,b,j+1,k);
	}
		cruelSubset(n,a,i+1,b,j,k);
	return;
}
int main() {
	int n,k;
	cin>>n>>k;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cruelSubset(n,a,0,b,0,k);
	cout<<maximum;
	return 0;
}