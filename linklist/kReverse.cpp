#include<iostream>
using namespace std;


class node{
    public:
	int data;
	node*next;
	node*prev;
	node(int d){
      data = d;
      next = NULL;
      prev = NULL;
	}
};

void print(node*&head){
	if(head==NULL){
		return;
	}
	node*temp= head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
        temp=temp->next;
	}cout<<endl;
    return;
}
void create(int n, node*&head){
	if(head==NULL){
		int d;
		cin>>d;
		head=new node(d);
	}
	node* temp=head;
	int t=1,e;
	while(t<n){
		cin>>e;
		temp->next=new node(e);
        temp->next->prev=temp;
		temp=temp->next;
        t++;
			}
}
void push(node*& head, node* temp) 
{  
    temp->prev = NULL; 
    temp->next = head;
    if (head!= NULL) {
        head->prev = temp; 
    }
    head= temp; 
    return;
}
node*reverseK(node*head,int k){
    node*current=head;
    node*nxt=NULL;
    node* newhead=NULL;
    int cnt=k;
    while(current!=NULL && cnt>0){
        nxt=current->next;
        push(newhead,current);
        current=nxt;
        cnt--;
    }
    if (nxt != NULL) 
    { 
        head->next = reverseK(nxt, k); 
        head->next->prev = head; 
    } 
    return newhead;
}


int main(){
node* head = NULL;
node*rev=NULL;
int n,k;
cin>>n>>k;
create(n,head);
rev=reverseK(head,k);
print(rev);
//print(head);
return 0;
}