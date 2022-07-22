#include<iostream>
using namespace std;
int spower(int a, int b){
	if(b==0){
		return 1;
	}
	if(b==1){
		return a;
	}
	int ans = spower(a,b/2);
	ans*=ans;
	if(b&1){
		return ans*a;
	}else {return ans;
}}
int main() {
	int a,b;
	cin>>a>>b;
	cout<<spower(a,b);
	return 0;
}