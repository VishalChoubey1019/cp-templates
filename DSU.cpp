#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class DSU
{
public:
    ll *rank, *parent, n;

    DSU(ll n)
    {
        rank = new ll[n];
        parent = new ll[n];
        this->n = n;
        makeSet();
    }

    void makeSet()
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    ll find(ll x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void Union(ll x, ll y)
    {
        ll xset = find(x);
        ll yset = find(y);

        if (xset == yset)
            return;

        if (rank[xset] < rank[yset])
        {
            parent[xset] = yset;
        }
        else if (rank[xset] > rank[yset])
        {
            parent[yset] = xset;
        }
        else
        {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};
