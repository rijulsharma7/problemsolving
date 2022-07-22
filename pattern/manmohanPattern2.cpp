#include <iostream>
using namespace std;
int main() {
   int n;
   cin>>n;
   int row=1;
   while(row<=n){
       if(row==1){
           cout<<1;
           cout<<endl;
       }
       else {
       cout<<row-1;
       int col=1;
       while(col<=row-2){
           cout<<0;
           col=col+1;
       }
       cout<<row-1;
       cout<<endl;}
       row=row+1;
   }
   return 0;
}
