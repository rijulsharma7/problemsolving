#include<iostream>
using namespace std;
int main() {
	int n,k;
	cin>>n>>k;
	int arr[1000000];
	for(int k=0;k<n;k++){
		cin>>arr[k];
	}
	int i=0,j=0;
	int sum=0;
	int max=0;
	while(j<n){
	   sum += arr[j];
	   if(sum<=k){
		   if(j-i+1>max){
			   max=j-i+1;
		   }
		   j++;
		   continue;
	   }
	   else if(sum>k){
		   
		   sum -= arr[i];
		   i++;
		  
		   
		   sum -= arr[j];
		   continue;
	   }  
	
}
cout<<max;
return 0;
}