#include<iostream>
using namespace std;
int main() {
	int n,k,f=0,s=1,u;
	cin>>n;
	k=(n*(n+1))/2;
	{
		for(int i=0;i<n;i++){
			for(int j=0;j<=i;j++){
                 cout<<f<<" ";
		u=f+s;
		f=s;
		s=u;
			}
			cout<<endl;
		}
		
	}
	return 0;
}
