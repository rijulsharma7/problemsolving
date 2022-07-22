#include<iostream>
using namespace std;
	char table[][10] =
	 { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
void compute(char no[10],char str[10],int i,int j){
	if(no[i]=='\0'){
		str[j]='\0';
		cout<<str<<endl;
       return;
	}
	int digit= no[i]-'0';
	for(int k=0;table[digit][k]!='\0';k++){
		str[j]=table[digit][k];
	    compute(no,str,i+1,j+1);
	}
}
int main() {
	char no[10];
	cin>>no;
	char str[10];
	 compute(no,str,0,0);
	return 0;
}
