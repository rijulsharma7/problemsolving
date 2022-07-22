#include <iostream>
#include<climits>
using namespace std;
int main() {
    int n;
    cin>>n;
	for(int i=0;i<(2*n-1);i++){
        cout<<"*";
    }
	cout<<endl;
    for(int i=1;i<=n;i++){
        for(int space=1;space<=n-i;space++){
            cout<<"*";
        }
        for(int j=1;j<=i;j++){
            cout<<" ";
        }
        for(int k=1;k<i;k++){
            cout<<" ";
        }
        for(int space=1;space<=n-i;space++){
            cout<<"*";
        }
        cout<<endl;
    }
	for(int i=2;i<n;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        for(int space=0;space<n-i;space++){
            cout<<" ";
        }
        for(int space=1;space<n-i;space++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=0;i<(2*n-1);i++){
        cout<<"*";
    }
    return 0;
}
