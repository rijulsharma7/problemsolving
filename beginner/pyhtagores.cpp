#include<iostream>
using namespace std;
int main() {
	int n,a,x,y;
	cin>>n;
	while(n>0){
		cin>>a;
		for(x=0;x<=a;x++){
		for(y=x;y<=a;y++){
			if((a)==(y*y) + (x*x)){
				cout<<"("<<x<<","<<y<<") ";
			}
		}
		}cout<<endl;
		n--;
	}
	return 0;