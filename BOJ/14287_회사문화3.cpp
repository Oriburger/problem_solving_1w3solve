#include <bits/stdc++.h>
using namespace std;

int n, m, tmp=-1;
vector<int> tree, lazy, st, fin;
vector<vector<int>> adj;

void propagate(int node, int nl, int nr)
{
    if(lazy[node]==0) return;
    if(nl != nr)
    {
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }
    tree[node] += (nr-nl+1)*lazy[node];
    lazy[node] = 0;
}

int update(const int l, const int r, const int newVal, int node, int nl, int nr)
{
    propagate(node, nl, nr);
    if(nl > r || l > nr) return tree[node];
    if(l <= nl && nr <= r)
    {
        tree[node] += (nr - nl + 1) * newVal;
        if(nl != nr)
        {
            lazy[node*2] += newVal;
            lazy[node*2+1] += newVal;
        }
        return tree[node];
    }
    int mid = (nl + nr) / 2;
    return tree[node] = update(l, r, newVal, node*2, nl, mid) + update(l, r, newVal, node*2+1, mid+1, nr);
}

int query(const int l, const int r, int node, int nl, int nr)
{
    propagate(node, nl, nr);
    
    if(nl > r || l > nr) return 0;
    if(l <= nl && nr <= r) return tree[node];
    int mid = (nl+nr)/2;
    return query(l, r, node*2, nl, mid) + query(l, r, node*2+1, mid+1, nr);
}

int update(int l, int r, int newVal) { return update(l, r, newVal, 1, 0, n-1); }
int query(int l, int r) { return query(l, r, 1, 0, n-1); }

void DFS(int curr)
{
    st[curr] = ++tmp; 
    for(auto &next : adj[curr])
        if(st[next]==-1) DFS(next);
    fin[curr] = tmp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>m;
    tree = lazy = vector<int>(n*4, 0);
    st = fin = vector<int>(n, -1);
    adj = vector<vector<int> >(n);
    
    for(int i=0; i<n; i++)
    {
        int j; cin>>j;
        if(i>0)
        {
            adj[j-1].push_back(i);  
            adj[0].push_back(i);
        }
    }
    
    DFS(0);
    while(m--)
    {
        int sel, idx, w;
        cin>>sel>>idx;
        if(sel==1)
        {
            cin>>w;
            if(st[idx-1]!=fin[idx-1]) update(st[idx-1], st[idx-1], w);
        }
        else if(sel==2)
            cout<<query(st[idx-1], fin[idx-1])<<'\n';
    }
    
    return 0;
}
