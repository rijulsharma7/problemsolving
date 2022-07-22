#include<iostream>
using namespace std;
#include<math.h>
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int a,b,c;
	float delta,r1,r2;
	cin>>a>>b>>c;
	delta=sqrt(pow(b,2)-4*a*c);
    if(delta==0){
		r1=r2=-b/(2*a);
		cout<<"Real and Equal"<<endl;
		cout<<r1<<" "<<r2;
	}
	else if(delta>0){
		r1=(-b+delta)/(2*a);
		r2=(-b-delta)/(2*a);
		cout<<"Real and Distinct"<<endl;;
		cout<<r2<<" "<<r1;
	}
	else
	cout<<"Imaginary";
	return 0;
}