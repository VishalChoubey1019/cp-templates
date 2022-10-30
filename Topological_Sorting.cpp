#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll n, m;
ll vis[100000] = {0};

vector<ll> ans;
vector<ll> adj[100000];

bool f = 0;

void dfs(ll i)
{
    vis[i] = 1;

    sort(adj[i].begin(), adj[i].end());

    for (ll j = 0; j < adj[i].size(); j++)
    {
        if (vis[adj[i][j]] == 0)
        {
            dfs(adj[i][j]);
            /* code */
        }
        else if (vis[adj[i][j]] == 1)
        {
            f = 1;
        }
    }
    vis[i] = 2;
    ans.push_back(i);
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        // -------   check for n==1   -------------

        cin >> n >> m;
        // cout<<n<<m;

        for (ll i = 0; i < m; i++)
        {
            ll x, y;
            cin >> x >> y;

            adj[x].push_back(y);
            /* code */
        }

        for (ll i = n; i >= 1; i--)
        {
            if (vis[i] == 0)
            {
                dfs(i);
                /* code */
            }
        }
        // cout<<"wtf";

        reverse(ans.begin(), ans.end());

        if (f == 1)
        {
            cout << "Sandro fails.";
            continue;
            /* code */
        }

        for (ll i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
            /* code */
        }

        cout << endl;
    }
    return 0;
}