#include<iostream>
using namespace std;
void maps(char str[1000000],char out[1000000],int i,int j){
	if(str[i]=='\0'){
		out[j]='\0';
		cout<<out<<endl;
		return;
	}
	int d=str[i]-'0';
	char c=d+'A'-1;
	out[j]=c;
	maps(str,out,i+1,j+1);
	if(str[i+1]!='\0'){
	int d2=str[i+1]-'0';
	int no=d*10+d2;
	if(no<=26){
		char c1=no+'A'-1;
		out[j]=c1;
		maps(str,out,i+2,j+1);
	}
	}return;

}
int main() {
	char str[1000000],out[1000000];
	cin>>str;
	maps(str,out,0,0);
	return 0;
}
