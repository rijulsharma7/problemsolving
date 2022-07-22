#include <iostream>
#include<climits>
using namespace std;
int main() {
 int n;
 cin>>n;
    for(int i=0;i<n;i++){
			for(int k=1;k<(n-i);k++){
                 cout<<" \t";
			}
            int v=i+1;
            for(int j=0;j<=i;j++){
                cout<<v<<"\t";
                v++;
            }
            v--;
            for(int j=1;j<=i;j++){
               cout<<v-1<<"\t";
               v--;
            }
            cout<<endl;
		}
}
