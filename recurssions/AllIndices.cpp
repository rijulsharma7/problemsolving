#include<iostream>
using namespace std;
void search_indices(int n,int *arr, int key, int i ){
    if(i==n){
        return;
    }
    if(arr[i]==key){
        cout<<i<<" ";
    }
    search_indices(n,arr,key,i+1);

}
int main(){
    int n;
    cin>>n; 
    int arr[100000000];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    search_indices(n,arr,key,0);
}