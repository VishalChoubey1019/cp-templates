
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
const ll mod = 1e9 + 7;
ll id;
const ll N = 1e5 + 10;
vll par(N);
vll Rank(N);
void make(ll node)
{
    par[node] = node;
    Rank[node]=0;
}

int Find(ll node)
{
    if (par[node] == node)
        return node;
    else
        return par[node] = Find(par[node]);
}
void Union(ll a, ll b)
{
    ll apar = Find(a);
    ll bpar = Find(b);
    if (apar != bpar)
    {
        if (Rank[apar] < Rank[bpar])
        {

            par[bpar] = apar;
        }
        else if (Rank[apar] > Rank[bpar])
        {
            par[apar] = bpar;
        }
        else
        {
            par[bpar] = apar;

            Rank[apar]++;
        }
    }
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++)make(i);
    vector<pair<ll,pair<ll,ll>>>v;
    for(int i=0;i<m;i++){
        ll x,y,wt;
        cin>>x>>y>>wt;
        v.pb({wt,{x,y}});

    }
    sort(v.begin(),v.end());
    for(auto &i:v){
        ll wt=i.first;
        ll x=i.second.first;
        ll y=i.second.second;
        if(Find(x)==Find(y))continue;
        Union(x,y);
        
    }
}
int main()
{
    FAST;
    ll n;
    cin >> n;
    while (n--)
        solve();
}
