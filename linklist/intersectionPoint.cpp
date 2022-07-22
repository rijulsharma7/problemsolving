#include<iostream>
using namespace std;
bool check = false;
class node{
	public:
	int data;
	node*next;
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
		temp->next=new node(e);
		temp=temp->next;
		t++;
	}
	temp->next=NULL;
	return;
}
void intersectionPoint(node*a,node*b){
	if(a->data==b->data){
		cout<<a->data;
		check=true;
		return;
	}
	if(a->next==NULL && b->next==NULL){
		return;
	}
	if(b->next!=NULL){
	intersectionPoint(a,b->next);
	}
	if(a->next!=NULL && b->next==NULL){
		intersectionPoint(a->next,b);
	}
	return;
}
int main() {
	int n1;
	cin>>n1;
	node*head1=NULL;
	takeinput(head1,n1);
	int n2;
	cin>>n2;
	node*head2=NULL;
	takeinput(head2,n2);
	if(n1>=n2){
	while(n2>1){
		head1=head1->next;
		n2--;
	}
	intersectionPoint(head1,head2);
	}
	if(check==false){
		cout<<"-1";
	}
	return 0;
}
