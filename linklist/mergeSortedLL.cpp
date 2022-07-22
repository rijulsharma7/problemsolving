#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node* next;
	node(int d){
		data=d;
		next=NULL;
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
    temp->next=NULL;
    
    return;
}
node* merge(node*a,node*b){
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return a;
	}
    node*c;
    if(a->data>b->data){
        c=b;
        c->next=merge(a,b->next);
    } else {
        c=a;
        c->next=merge(a->next,b);
    }
    return c;
}
void print(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }cout<<endl;
}
int main() {
	int t;
	cin>>t;
	for(int k=0;k<t;k++){
		int n1,n2;
		cin>>n1;
		node*head1=NULL;
		takeinput(head1,n1);
		cin>>n2;
		node*head2=NULL;
		takeinput(head2,n2);
		node*head=merge(head1,head2);
		print(head);
	}
	return 0;
}