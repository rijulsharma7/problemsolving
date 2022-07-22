#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
	queue<int> q; 
    int no;
    cin>>no;
	while(no!=-1){ 
		q.push(no);
        cin>>no; 
    }
    int n=q.size();
	queue<int> q1, q2; 
	for (int i=0;i<(n/2);i++) { 
		q1.push(q.front()); 
		q.pop(); 
	} 
	for (int i=0;i<(n/2);i++) { 
		q2.push(q.front()); 
		q.pop(); 
	} 

	for (int i=0;i<(n/2);i++) { 
		q.push(q1.front()); 
		q1.pop(); 
		q.push(q2.front()); 
		q2.pop(); 
	} 

	for (int i=0;i<n;i++) { 
		cout << q.front() << " "; 
		q.pop(); 
	} 
    return 0;
} 
