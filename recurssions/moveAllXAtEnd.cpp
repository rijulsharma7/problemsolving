#include<bits/stdc++.h>
using namespace std;
void moveAllX(char str[1000],int n,int i){
	if(i==n){
		return;
	}
	if(i<n && str[i]=='x'){
		for(int k=i;k<n-1;k++){
			swap(str[k],str[k+1]);
		}//cout<<str;
		moveAllX(str,n,i+1);
	}
		moveAllX(str,n,i+1);
		return;
}
int main() {
	char str[1000];
	cin>>str;
	int n=0;
	for(int j=0; str[j] != 0;j++){
	    n++;
	}
	moveAllX(str,n,0);
	cout<<str;
	return 0;
}