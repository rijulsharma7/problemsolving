#include <bits/stdc++.h>
using namespace std;

char table[][10] = { " ", "ajs", "bkt", "clu", "dmv", "enw" , "fox", "gpy" , "hqz", "ir" };

void give(char out[10], string str)
{
    int e=0;
    for(int s=0; str[s]!='\0'; s++)
    {
        if(out[e] == '\0')
        {
            cout<<str<<endl;
            return;
        }
        if(e>0 && out[e]!=str[s]) e = 0;
        else if(out[e] == str[s]) e++;
    }
    if(out[e] == '\0') cout<<str<<endl;
}

void compute(char inp[10], char out[10], int i, int j, vector<string> v)
{
    if(inp[i] == '\0')
    {
        out[j] = '\0';
        //cout << out << " ";
        for(auto x : v) give(out, x);
        return;
    }
    int digit = inp[i] - '0';
    for(int k=0; table[digit][k]!='\0'; k++)
    {
        out[j] = table[digit][k];
        compute(inp, out, i+1, j+1, v);
    }
}

signed main() 
{
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i=0; i<n; i++)
    {
        string s; cin >> s;
        v[i] = s;
    }
    char inp[10];
    cin>>inp;
    char out[10];
    compute(inp, out, 0, 0, v);
}
