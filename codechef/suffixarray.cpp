#include <bits/stdc++.h>
using namespace std;

#define MAX 100000
int cum[MAX];

struct suffix
{
    int index; 
    int rank[2]; 
};

bool compare(string &s1,string &s2) 
{ 
    return s1.length() < s2.length(); 
}

int cmp(struct suffix a, struct suffix b)
{
    return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ?1: 0) : (a.rank[0] < b.rank[0] ? 1 : 0);
}

vector<int> buildSuffixArray(string txt, int n)
{
    struct suffix suffixes[n];
    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].rank[0] = txt[i] - 'a';
        suffixes[i].rank[1] = ((i+1) < n) ? (txt[i + 1] - 'a') : -1;
    }
    sort(suffixes, suffixes+n, cmp);
    int ind[n]; 
    for (int k = 4; k < 2*n; k = k*2)
    {
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;

        for (int i = 1; i < n; i++)
        {
            if (suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i-1].rank[1])
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            }
            else 
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }

        for (int i = 0; i < n; i++)
        {
            int nextindex = suffixes[i].index + k/2;
            suffixes[i].rank[1] = (nextindex < n) ? suffixes[ind[nextindex]].rank[0] : -1;
        }

        sort(suffixes, suffixes+n, cmp);
    }

    vector<int>suffixArr;
    for (int i = 0; i < n; i++) suffixArr.push_back(suffixes[i].index);

    return suffixArr;
}

vector<int> buildLCP(string txt, vector<int> suffixArr)
{
    int n = suffixArr.size();

    vector<int> lcp(n, 0);
    vector<int> invSuff(n, 0);

    for (int i=0; i < n; i++) invSuff[suffixArr[i]] = i;

    int k = 0;
    for (int i=0; i<n; i++)
    {
        if (invSuff[i] == n-1)
        {
            k = 0;
            continue;
        }

        int j = suffixArr[invSuff[i]+1];

        while (i+k<n && j+k<n && txt[i+k]==txt[j+k]) k++;

        lcp[invSuff[i]] = k; 

        if (k>0) k--;
    }

    return lcp;
}
bool check (string a, string b)
{
    int az = 0, bz = 0;
    for(int i=0; i<a.length(); i++)
    {
        if(a[i] == '0') az++;
        if(b[i] == '0') bz++;
    }
    if(az != bz) return false;
    if(az==0 || az==a.length()) return true;
    int i = 0, j = 0;
    bool stop = false;
    while(1)
    {
        if(a[i]=='0'){
            j = i+1;
            int ones = 0;
            while(ones != 2)
            {
                if(j==a.length())
                {
                    stop=true;
                    break;
                }
                if(a[j]=='1') ones++;
                j++;
            }
            j--;
            if(stop) break;
            reverse(a.begin()+i,a.begin()+j+1);
            i++;
            continue;
        }
        i++;
    }
    i = 0,
    j = 0;
    stop = false;
    while(1)
    {
        if(b[i]=='0')
        {
            j = i+1;
            int ones = 0;
            while(ones != 2)
            {
                if(j==b.length())
                {
                    stop=true;
                    break;
                }
                if(b[j]=='1') ones++;
                j++;
            }
            j--;
            if(stop) break;
            reverse(b.begin()+i,b.begin()+j+1);
            i++;
            continue;
        }
        i++;
    }
   if(a==b) return true;
   return false;         
}
int main()
{
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;

    while (t--)  
    {
        string str;
        cin >> str;

        vector <string> v;

        vector<int>suffixArr = buildSuffixArray(str, str.length());
        int n = suffixArr.size();

        //cout << "Suffix Array : \n";
        //printArr(suffixArr, n);

        vector<int>lcp = buildLCP(str, suffixArr);

        //cout << "\nLCP Array : \n";
        //printArr(lcp, n);

        cum[0] = n - suffixArr[0];

        //int count = 1;


        for (int i = 1; i <= n-suffixArr[0]; i++)
        {
            string sub_str = str.substr(suffixArr[0],i);
            v.push_back(sub_str);
            //cout << count << "  ";
            //cout <<  sub_str << endl;
            //count++;
        }

        for(int i = 1;i < n;i++)  
        {
            cum[i] = cum[i-1] + (n - suffixArr[i] - lcp[i - 1]);

            int end = n - suffixArr[i];
            int begin = lcp[i-1] + 1;
            int begin_suffix = suffixArr[i];

            for (int j = begin, k = 1; j <= end; j++, k++)  
            {
                string sub_str = str.substr(begin_suffix, lcp[i-1] +k);
                v.push_back(sub_str);
                //cout << count << "  ";
                //cout <<  sub_str << endl;
                //count++;
            }

        }
        int result = v.size();
        sort(v.begin(),v.end(),compare);
        //for (auto x : v) cout << x <<" ";
        //cout<<"\n"<<v.size()<<"\n";
        bool visited[v.size()];
        for(int i = 0; i < v.size(); i++) visited[i] = true;

        for (int i=0; i<(v.size()-1); i++)
        {
            for (int j=i+1; j<v.size(); j++)
            {
                string a = v[i];
                string b = v[j];
                if(!visited[j] || !visited[i]) continue;
                if(a.length() == b.length())
                {
                    if( check(a,b) ) 
                    {
                        visited[j] = false;
                        result--;
                    }
                }
                else break;
            }
        }
        cout << result << '\n';
    }

    return 0;
}