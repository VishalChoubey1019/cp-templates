const int mxN = 2e5+5;
ll segTree[4*mxN], lazy[4*mxN], arr[mxN];

void build(int node, int left, int right){
    if(left == right){
        segTree[node] = arr[left];
        return;
    }
    int mid = left+right >>1;
    build(2*node, left, mid);
    build(2*node+1, mid+1, right);
    segTree[node] = segTree[2*node] + segTree[2*node+1];
}

void update(int node, int left, int right, int l, int r, int val){
    if(left > r or right < l)return;
    if(left >= l and right <= r){
        segTree[node] += val;
        lazy[node] += val;
        return;
    }
    int mid = left+right >>1;
    update(2*node, left, mid, l, r, val);
    update(2*node+1, mid+1, right, l, r, val);
    segTree[node] = max(segTree[2*node], segTree[2*node+1]);
}
 
int query(int node, int left, int right, int l, int r){
    if(left > r or right < l)return -1e9;
    if(left >= l and right <= r)return segTree[node];
    segTree[2*node] += lazy[node];
    segTree[2*node+1] += lazy[node];
    lazy[2*node] += lazy[node];
    lazy[2*node+1] += lazy[node];
    lazy[node] = 0;
    int mid = left+right >>1;
    return max(query(2*node, left, mid, l, r), query(2*node+1, mid+1, right, l, r));
}