vector<pair<ll,ll>> adj[mxN];
vector<ll> d(mxN, ll(1e18)), par(mxN, -1);

vector<int> restore_path(int s, int t) //s = start t = terminating
{
    vector<int> path;

    for (int v = t; v != s; v = par[v])
        path.push_back(v);

    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}
 
void dijkstra()
{
    d[1] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,1});
 
    while(!pq.empty())
    {
        ll dis = pq.top().first;
        ll v = pq.top().second;
        pq.pop();
        
        if(dis != d[v])continue;

        for(auto x:adj[v])
        {
            if(dis + x.second < d[x.first])
            {
                d[x.first] = dis + x.second;
                par[x.first] = v;
                pq.push({d[x.first],x.first});
            }
        }
    }
}
