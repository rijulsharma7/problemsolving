#include <bits/stdc++.h>
using namespace std;
using ll = long long;
signed main()
{

    //freopen("a.txt", "r", stdin);
    //freopen("ta.txt", "w", stdout);

    ll d , vertices , e , c , b;
    cin >> d >> vertices >> e >> c >> b;

    vector<vector<ll>> v( vertices , vector<ll> (vertices, -1));

    for (ll i = 0  ; i < vertices ; i++)
    {
        for (ll j =  0 ; j < vertices ; j++)
        {

            v[i][j] = -1;
        }
    }
    map<string, pair<ll, ll>> roads;
    map<string, bool> check;
    vector<vector<string>> path(c);
    vector<vector<string>> resPath(vertices);

    for (ll i = 0; i < e ; i++)
    {
        ll source , destination , l;
        string s;
        cin >> source >> destination ;
        cin >> s;
        cin >> l;
        roads[s] = make_pair(source, destination);
        check[s] = false;
        v[source][destination] = l;
    }


    for (ll  i = 0 ; i < c  ; i++)
    {
        ll travel ;
        cin >> travel;

        for (ll j = 0 ; j < travel ; j++)
        {
            string s;
            cin >> s;
            path[i].push_back(s);
        }
    }

    //for(auto x : roads) cout << x.second.second << " ";

    vector<ll> llersection(vertices , 0);

    for (ll i = 0 ; i < c ; i++)
    {
        for (ll j = 0; j < path[i].size() - 1; j++)
        {
            string x = path[i][j];
            if (check[x] == true) continue;
            map<string, pair<ll, ll>> :: iterator itr = roads.find(x);
            llersection[(*itr).second.second]++;
            resPath[(*itr).second.second].push_back(x);
            check[x] = true;
        }
    }

    //cout << "Check" << endl;
    ll cnt = 0;
    for (ll i = 0 ; i < vertices ; i++) if (llersection[i] != 0) cnt++;

    cout << cnt << '\n';
    for (ll i = 0; i < vertices; i++)
    {
        if (llersection[i] == 0) continue;
        cout << i << '\n';
        cout << resPath[i].size() << '\n';
        for (auto x : resPath[i]) cout << x << " 1\n";
    }

    //fclose(stdout);

    return 0;
}