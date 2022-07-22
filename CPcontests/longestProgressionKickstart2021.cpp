#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++) {
        int n;
        cin >> n;
        int l = INT_MIN;
        bool check = false;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int i = 0, j = 1;
        int prev_diff = arr[j] - arr[i];

        if (n == 2) {
            l = 2;
            cout << "Case #" << test << ": " << l << '\n';
            continue;
        }
        else {
            if (arr[2] - arr[1] == arr[1] - arr[0]) {
                prev_diff = arr[2] - arr[1];
                j = 2;
            }
            else {
                if (n == 3) {
                    l = 3;
                    cout << "Case #" << test << ": " << l << '\n';
                    continue;

                }
                else {
                    int x = arr[1] - arr[0];
                    int y = arr[2] - arr[1];
                    int z = arr[3] - arr[2];
                    if (y == z) {
                        i = 0;
                        check = true;
                        prev_diff = y;
                    }

                    else {
                        int key1 = arr[0] + z;
                        if (arr[2] - key1 == z) {
                            i = 0;
                            j = 3;
                            check = true;
                            prev_diff = z;
                        }
                        else {
                            key1 = arr[1] + x;
                            if (arr[3] - key1 == x) {
                                i = 0;
                                j = 3;
                                prev_diff = x;
                                check = true;
                            }
                            else {
                                if (n > 4) {
                                    key1 = y;
                                    if (arr[2] + y == arr[4] - y) {
                                        //cout<<"here"<<endl;
                                        prev_diff = y;
                                        //arr[3]=p
                                        check = true;
                                        i = 1;
                                        j = 4;
                                    }
                                }
                                i = 2;
                                j = 3;
                                prev_diff = arr[3] - arr[2];
                            }
                        }

                    }
                }

            }
        }

        j++;

        //cout<<"j is"<<j<<endl;



        while (j < n) {

            if (arr[j] - arr[j - 1] == prev_diff) {
                j++;
                continue;
            }
            else {
                if (!check) {

                    int key = arr[j - 1] + prev_diff;
                    if (j + 1 < n) {
                        if (arr[j + 1] - key == prev_diff) {
                            //cout<<"hi"<<endl;
                            arr[j] = key;
                            check = true;
                            j++;
                            continue;
                        }
                        else {

                            l = max(l, j - i + 1);
                            i = j - 1;

                            prev_diff = arr[j] - arr[i];
                            j++;

                        }
                    }
                    else {

                        l = max(l, j - i + 1);
                        i = j;
                        j++;

                        prev_diff = arr[j] - arr[i];

                    }
                }
                else {

                    l = max(l, j - i);
                    i = j;
                    j++;
                    check = false;

                }
            }

        }
        j--;
        if (!check) {

            if (i == 0) {
                l = max(l, j - i + 1);
            }
            else {
                l = max(l, j - i + 2);
            }
        }
        else {
            l = max(l, j - i + 1);
        }


        cout << "Case #" << test << ": " << l << '\n';


        //cout<<'\n';
    }
}
