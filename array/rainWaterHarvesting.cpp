#include<iostream>
using namespace std;
int main() {
	int a[10000],n,l[10000],r[10000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int c,d;
	l[0]=a[0];
	c=l[0];
	for(int i=1;i<n;i++){
		if(a[i]>c){
			c=a[i];
		}
		l[i]=c;
	}r[n-1]=a[n-1];
	d=r[n-1];
	for(int i=n-2;i>=0;i--){
		if(a[i]>d){
			d=a[i];
		}
		r[i]=d;
	}
		int s=0;
	for(int i=0;i<n;i++){
		int e=min(l[i],r[i])-a[i];
		s+=e;
	}
cout<<s;
	return 0;
}