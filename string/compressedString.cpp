#include <iostream>
using namespace std;
int cnt;
void compressedString(char str[1000],char out[1000],int i,int j){
    if(str[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    out[j]=str[i];
    cnt=1;
    int k=i;
    while(str[k]==str[k+1]){
        cnt++;
        k++;
    }if(cnt<10){
    out[j+1]=cnt+'0';
    compressedString(str,out,i+cnt,j+2);
	}
	else if(cnt<100 && cnt>9){
		int f=cnt;
		out[j+2]=f%10+'0';
		f=f/10;
		out[j+1]=f%10+'0';
    compressedString(str,out,i+cnt,j+3);
	}else if(cnt<1000){
		int g=cnt;
		out[j+3]=g%10+'0';
		g=g/10;
		out[j+2]=g%10+'0';
		g=g/10;
		out[j+1]=g%10+'0';
    compressedString(str,out,i+cnt,j+4);		
	}
}
int main() {
	char str[1000],out[1000];
	cin>>str;
	compressedString(str,out,0,0);
	return 0;
}