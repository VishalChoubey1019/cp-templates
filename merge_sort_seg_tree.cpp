const int mxN = 2e5+2;
vector<ll> segTree[mxN*4];

void Build(int left, int right, int node, pair<int,int> a[]){
    if(left == right){
        segTree[node].push_back(a[left].second);
        return;
    }
    int mid = left+right >>1;
    Build(left, mid, 2*node+1, a);
    Build(mid+1, right, 2*node+2, a);
    merge(
            segTree[2*node+1].begin(), segTree[2*node+1].end(),
            segTree[2*node+2].begin(), segTree[2*node+2].end(),
            back_inserter(segTree[node])
        );
}

int Query(int left, int right, int node, int l, int r, int k){ //find "idx" of k-th element in sorted range
    if(left == right)
        return segTree[node][0];

    int mid = left+right >>1;
    int idx = upper_bound(segTree[2*node+1].begin(), segTree[2*node+1].end(), r) -
              lower_bound(segTree[2*node+1].begin(), segTree[2*node+1].end(), l);
    if(idx >= k)
        return Query(left, mid, 2*node+1, l, r, k);
    
    return Query(mid+1, right, 2*node+2, l, r, k-idx);
}

void pre_compute(int n){

    int a[n];
    pair<int,int> b[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i], b[i] = {a[i],i};
    sort(b, b+n);
    Build(0, n-1, 0, b);
}
