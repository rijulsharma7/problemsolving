#include<bits/stdc++.h>
using namespace std;
bool check=false;
void ratchase(char a[100][100],int b[100][100],int i,int j,int n,int m){
	if(i==n && j==m){
		for(int k=0;k<=n;k++){
			for(int l=0;l<=m;l++){
				cout<<b[k][l]<<" ";
			}cout<<endl;
		}
		check=true;
		return;
	}
	if(i!=n && a[i+1][j]!='X' && b[i+1][j]!=1){
		b[i+1][j]=1;
		ratchase(a,b,i+1,j,n,m);
		b[i+1][j]=0;
	}
	if(i>0 && a[i-1][j]!='X' && b[i-1][j]!=1){
		b[i-1][j]=1;
		ratchase(a,b,i-1,j,n,m);
		b[i-1][j]=0;
	}
	if(j!=m && a[i][j+1]!='X' && b[i][j+1]!=1){
		b[i][j+1]=1;
		ratchase(a,b,i,j+1,n,m);
		b[i][j+1]=0;
	}
	if(j>0 && a[i][j-1]!='X' && b[i][j-1]!=1){
		b[i][j-1]=1;
		ratchase(a,b,i,j-1,n,m);
		b[i][j-1]=0;
	}
	return;
}
int main() {
	int n,m;
	cin>>n>>m;
	char a[100][100];
	int b[100][100]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	b[0][0]=1;
	ratchase(a,b,0,0,n-1,m-1);
	if(check==false){
		cout<<"NO PATH FOUND";
	};
	return 0;
}
