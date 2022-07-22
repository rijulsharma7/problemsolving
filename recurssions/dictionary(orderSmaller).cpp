#include<bits/stdc++.h>
using namespace std;
string name[1000000];
int l=0;
void permutation(string str,int i){
    if(str[i]=='\0'){
        name[l]=str;
        l++;
    }
    for(int j=i;str[j]!='\0';j++){
        swap(str[i],str[j]);
        permutation(str,i+1);
        swap(str[i],str[j]);
    }
}
int main() {
    string str;
    cin>>str;
    int index;
    permutation(str,0);
    sort(name,name+l);
    for(int j=0;j<l;j++){
        if(name[j]==str){
            index=j;
        }
    }
    for(int j=0;j<index;j++){
        cout<<name[j]<<endl;
    }
}