#include<iostream>
using namespace std;
void replaceAllPie(char str[3000],int n,int i){
	if(i==n){
		return;
	}
	if(str[i]=='p' && str[i+1]=='i'){
		for(int k=n-1;k>=i+2;k--){
			str[k+2]=str[k];
		}
		str[i]='3';str[i+1]='.';str[i+2]='1';str[i+3]='4';
		replaceAllPie(str,n+2,i+4);
	}
	replaceAllPie(str,n,i+1);
	return;
}
int main() {
	int t;cin>>t;
	char str[3000];

	for(int i=0;i<t;i++){
		cin>>str;
		int n=sizeof(str)/sizeof(str[0]);
		replaceAllPie(str,n,0);
		cout<<str<<endl;
	}
	return 0;
}
