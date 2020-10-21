#include <iostream>
#include<climits>
using namespace std;
int main() {
    int n,a[100000000],no;
	cin>>no;
	for(int j=0;j<no;j++){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
	int s=0,ans=INT_MIN;
    for(int i=0;i<n;i++){
        s+=a[i];
     if(ans<s)
	 ans=s;
        if(s<0)
		s=0;
    }cout<<ans<<endl;}
	return 0;

}