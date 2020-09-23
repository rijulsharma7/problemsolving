#include<iostream>
using namespace std;
bool check = false;
void ratInMaze(int i,int j,int n ,int m, char arr[1000][1000], int out[1000][1000]){
	if(i==n && j==m){
	    check =true;
		return;
	}

	if(arr[i][j+1]!='X' && j!=m){
		ratInMaze(i,j+1,n,m,arr,out);
		if(check==true){
			out[i][j+1]=1;
		}
	} 
	if(check==false)
	{if(arr[i+1][j]!='X' && i!=n){
		ratInMaze(i+1,j,n,m,arr,out);
		if(check==true){
			out[i+1][j]=1;
		}
	}
	}
	if(arr[i][j+1]=='X' && arr[i+1][j]=='X'){
		check=false;
	}
	return;
}
int main() {
	int n,m;
	cin>>n>>m;
	char arr[1000][1000];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	int out[1000][1000]={0};
	out[0][0]=1;
	 ratInMaze(0,0,n-1,m-1,arr,out);
	 if(check==false){
		 cout<<"-1";
	 } else{
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<out[i][j]<<" ";
		}cout<<endl;
	}}
	return 0;
}