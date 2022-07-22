#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long int cnt = 0;
    // vector<long long int> big;
    priority_queue<int, vector<int>, greater<int> > big;
    for (int i = 0; i < n; i++) {
      int s;
      cin >> s;
      long long int arr[s];
      for (int i = 0; i < s; i++) {
        cin >> arr[i];
      }
      vector<long long int> num;
      int c = 1;
      for (int i = 1; i < s; i++) {
        if (arr[i] > arr[i - 1]) {
          c++;

        }
        else {
          //cout<<" "<<c<<" ";
          num.push_back(c);
          big.push(c);

          c = 1;

        }

      }
      // cout<<c<<endl;
      num.push_back(c);
      big.push(c);
      //cout<<"numofpart"<<num.size()<<endl;
      //cout<<endl;
      int start = 0;
      int end = num.size() - 1;
      //cout<<start<<" "<<end<<endl;
      while (start < end) {
        if (num[start] >= num[end]) {
          cnt += num[end];
          end--;
        }
        else {
          cnt += num[start];
          start++;
        }
      }


    }
    //int size=big.size();
    //priority_queue<int, vector<int>, greater<int> > gq;



    //sort(big.begin(),big.end(),greater<int>());
    int a = 1;
    // cout<<"cnt init"<<cnt<<endl;


    while (!big.empty()) {
      long long top = big.top();
      big.pop();
      if (big.empty()) {
        break;
      }
      top += big.top();
      big.pop();
      cnt += top;
      big.push(top);
    }


    //    for(int j=0; j<big.size(); j++){
    //        cnt+=big[j]*a;
    //        a++;
    //    }
    cout << cnt << endl;
  }
}
