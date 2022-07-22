#include <iostream>
using namespace std;
int cnt=0;

void mazepath(int m, int n, char *mat, int i, int j, int k){
	if(i==m-1 && j==n-1){
		mat[k]='\0';
		cout<<mat<<" ";
		cnt++;
	return;
	}


if(i<m){
    mat[k]='V';
    mazepath(n,m,mat,i+1,j,k+1);
}
if(j<n){
    mat[k]='H';
    mazepath(n,m,mat,i,j+1,k+1);
}
if(i<m && j<n){
    mat[k]='D';
    mazepath(n,m,mat,i+1,j+1,k+1);  
}
return;

}

int main() {
    int m,n;
    cin>>m>>n;
    char mat[100000];
    mazepath(m,n,mat,0,0,0);
    cout<<endl<<cnt;
	return 0;
}