#include <iostream>
#include<string.h>
using namespace std;
int main() {
    char a[100],s[100];
    cin.get(a,100);
    //cout<<a<<endl;
    int n=strlen(a);s[100]=a[100];
    //cout<<n<<endl;
    for(int i=0;i<n;i++){
        int x=a[i];
        a[i]=a[n-1];
        a[n-1]=x;
        n--;
    }
	if(s[100]==a[100]){
		cout<<"true";
	}
}