#include<iostream>
using namespace std;
long long int knapsack(long long int s,int a[1000000],int b[1000000],int n){
	if(n==0 || s==0){
		return 0;
	}
	if(a[n-1]>s){
		return knapsack(s,a,b,n-1);
	}else return max(b[n-1]+knapsack(s-a[n-1],a,b,n-1),knapsack(s,a,b,n-1));
}
int main() {
	int n,a[1000000],b[1000000];
	long long int s;
	cin>>n>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	cout<<knapsack(s,a,b,n);
	return 0;
}