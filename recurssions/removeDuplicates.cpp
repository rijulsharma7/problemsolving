#include<iostream>
#include<cstring>
using namespace std;
void remove_duplicates(string str,int i){
	if(i==0){
		cout<<str[i];
		return;
	}
	remove_duplicates(str,i-1);
	if(str[i]!=str[i-1]){
		cout<<str[i];
	}
}
int main() {
	string str;
	cin>>str;
	int i=str.length()-1;
	remove_duplicates(str,i);
	return 0;
}