#include <iostream>
using namespace std;
template <typename T>
class Queue{
    T* arr;
    int cs,ms,f,r;
    public:
    Queue(int d=5){
        arr= new T[d];
        cs=0;
        ms=d;
        f=0;
        r=ms-1;
    }
    bool isEmpty(){
        return cs==0;
    }
    bool isFull(){
        return cs==ms;
    }
    void push(int data){
        if(!isFull()){
            cs++;
            r=(r+1)%ms;
            arr[r]=data;
        }
    }
    void pop(){
        if(!isEmpty()){
            cs--;
            f=(f+1)%ms;
            }
    }
    T front(){
        return arr[f];
    }
    ~Queue(){
        if(arr!=NULL){
            delete [] arr;
            arr=NULL;
        }
    }
};
int main() {
	Queue <int> q;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		q.push(i);
	}
	while(!q.isEmpty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	return 0;
}
