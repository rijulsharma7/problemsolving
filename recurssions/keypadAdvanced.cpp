#include <iostream>
#include<cstring>
using namespace std;
char searchIn[][10]= { "prateek", "sneha", "deepak", "arnav", "shikha", "palak", "utkarsh", "divyam", "vidhi", "sparsh", "akku" };
char table[][10] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
void give(char out[10], char *str){
    int e=0;
    for(int s=0;str[s]!='\0';s++){
        if(out[e]=='\0'){
            cout<<str<<endl;
        }
        if(e>0 && out[e]!=str[s]){
            e=0;
        }else if(out[e]==str[s]){
          e++;
        }
    }
}
void compute(char n[10],char out[10],int i,int j){
    if(n[i]=='\0'){
        out[j]='\0';
        for(int f=0;searchIn[f][0]!='\0';f++){
            give(out,searchIn[f]);
        }
        return;
    }
    int digit=n[i]-'0';
    for(int k=0;table[digit][k]!='\0';k++){
        out[j]=table[digit][k];
        compute(n,out,i+1,j+1);
    }
}
int main() {
    char n[10];
    cin>>n;
    char out[10];
    compute(n,out,0,0);
    return 0;
}