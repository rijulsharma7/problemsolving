#include<iostream>
using namespace std;
int main() {
	int n,is=0,ds=0,k=0;
	long long int a[1000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]; 
		}
		for(int i=0;i<n;i++){
			if(a[i]<a[i+1]){
                if(i==0){
					ds++;
                    k=i+2;
                    break;
                }
                k++;
				break;
			}
            ds++;
            k++;}


			for(int i=k;i<n;i++){
			 if(a[i]>a[i+1]){
                 if(i==n-1){
					 is++;
                     break;
                 }
				 break;
			}is++;
			}


			if((is!=0 && ds!=0)){
				cout<<"true";
			}
			else cout<<"false";
	return 0;
}
