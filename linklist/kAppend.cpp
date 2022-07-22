#include <iostream>
using namespace std;

class node{
    public:
	int data;
	node*next;
	node(int d){
      data = d;
      next = NULL;
	}
};

void takeinput(node*&head,int n){
    int d;
    cin>>d;
    if(head==NULL){
        head=new node(d);
    }
    node*temp=head;
    int t=1;
    int e;
    while(t<n){
    cin>>e;
    temp->next= new node(e);
    temp=temp->next;
    t++;
    }
    temp->next=head;
    
    return;
}
void printll(node*&head){
	if(head==NULL){
		return;
	}
	node*temp= head;
	while(temp->next!=NULL){
		cout<<temp->data<<" ";
        temp=temp->next;
	}
    cout<<temp->data<<endl;
    return;
}


void kAppend(node*&head,int n,int k){
	if(head==NULL){
		return;
	}
	int p=n-k;
	node*temp=head;
	while(p>1){
		temp=temp->next;
		p--;
	}
	head=temp->next;
	temp->next=NULL;
	return;
}


int main() {
    int n;
    cin>>n;
    node*head= NULL;
    takeinput(head,n);
    int k;
    cin>>k;

    if(k>=n){
        k=k%n;
    }
    kAppend(head,n,k);

    printll(head);
    
    
}
