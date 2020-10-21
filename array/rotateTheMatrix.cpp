
#include <iostream>
using namespace std;
void rotate(int a[1000][1000],int b[1000][1000],int n){
	for(int k=0, j=n-1;k<n,j>=0;j--,k++){
        for(int i=0;i<n;i++){
            b[k][i]=a[i][j];
        }
    }
}
int main() {
    int a[1000][1000],a1[1000][1000],a2[1000][1000],a3[1000][1000],b[1000][1000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
	rotate(a,a1,n);
	rotate(a1,a2,n);
	rotate(a2,a3,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==1 || a1[i][j]==1 || a2[i][j]==1 || a3[i][j]==1){
				b[i][j]=1;
			}
			else b[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<b[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}