#include<iostream>
using namespace std;
void toh(int n,char src,char helper,char dest){
	if(n==0){
		return;
	}
	toh(n-1,src,dest,helper);
	cout<<"Moving ring "<<n<<" from "<<src<<" to "<<dest<<endl;
	toh(n-1,helper,src,dest);
}
int main() {
	int n;
	cin>>n;
	char A,B,C;
	toh(n,'A','C','B');
	return 0;
}
