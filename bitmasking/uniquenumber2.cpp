#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int a[100000],x=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		x^=a[i];
	}
	int first[n],second[n];
	int f=0,s=0,x1=0,x2=0;
	for(int i=0;i<n;i++){
		if((a[i]&x)==0){
			first[f]=a[i];
			x1^=first[f];
			f++;
		} else {
			second[s]=a[i];
			x2^=second[s];
			s++;
		}
	}
	cout<<min(x1,x2)<<" "<<max(x1,x2);
	return 0;
}