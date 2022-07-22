#include<iostream>
#include<cstring>
using namespace std;
 void rec_func(string str , int i ){
	 if(str[i+1]== NULL){
		 cout<<str[i];
		 return;
	 }
	 if(str[i]==str[i+1] ){
           cout<<str[i];
		   cout<<"*";
		   i++;
	 rec_func(str,i);
	 }
	 else {cout<<str[i];
	 i++;
	 rec_func(str,i);}
 }
int main() {
	string strg;
	cin>>strg;
	int i=0;
	rec_func(strg,i);
	return 0;
}
