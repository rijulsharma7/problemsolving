#include<iostream>
#include<cstring>
using namespace std;
int cnt=0;
void compute_seq(char str[10000],char otr[10000], int i,int j){
	if(str[i]=='\0'){
		otr[j]= '\0' ;
		cout<<otr<<" ";
		cnt++;
		return; 
	}
	 compute_seq(str,otr,i+1,j);
	otr[j]=str[i];
	 compute_seq(str,otr,i+1,j+1);
	 
}
int main() {
	char str[10000],otr[10000];
	cin>>str;
	compute_seq(str,otr,0,0);
	cout<<endl<<cnt;
	return 0;
}