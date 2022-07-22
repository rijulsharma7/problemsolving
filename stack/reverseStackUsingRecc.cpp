#include <bits/stdc++.h>
using namespace std;
class Stack {
    vector <int> v;
    public:
    void push( const int d){
        v.push_back(d);
    }
    bool isEmpty(){
        return v.size()==0;
    }
    int size(){
        return v.size();
    }
    void pop(){
        if(!isEmpty()){
             v.pop_back();
        }
    }
     int top(){
         return v[v.size()-1];
    }
};
void transfer(Stack &s1, Stack &s2 ,int n){
    for(int i=0;i<n;i++){
        s2.push(s1.top());
        s1.pop();
    }
    return;
}
void reverseStack(Stack &s){
    Stack s1;
    int n=s.size();
    for(int i=0;i<n;i++){
        int x=s.top();
        s.pop();
        transfer(s,s1,n-1-i);
        s.push(x);
        transfer(s1,s,n-1-i);
    }
    return;
}
void insertAtBottom(Stack &s,int x){
    if(s.isEmpty()){
        s.push(x);
        return;
    }
    int data=s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(data);
    return;
}
void recursiveReverse(Stack &s){
    if(s.isEmpty()){
        return;
    }
    int x=s.top();
    s.pop();
    recursiveReverse(s);
    insertAtBottom(s,x);
    return;
}
int main() {
    Stack s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int no;
        cin>>no;
        s.push(no);
    }
    //reverseStack(s);
    recursiveReverse(s);
    while(!s.isEmpty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}