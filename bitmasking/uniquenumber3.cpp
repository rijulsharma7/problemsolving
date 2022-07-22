#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int a[100000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int arr[64]={0},j;
	for(int i=0;i<n;i++){
		j=0;
		while(a[i]!=0){
			arr[j]+=(a[i]&1);
			a[i]=a[i]>>1;
			j++;
		}
	}
	int sum=0;
	for(int i=0;i<64;i++){
		arr[i]%=3;
		arr[i]*=pow(2,i);
		sum+=arr[i];
	}
	cout<<sum;
	return 0;
}