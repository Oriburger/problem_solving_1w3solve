#include <bits/stdc++.h>
using namespace std;

int n, m, tmp = -1;
vector<int> tree, lazy, st, fin; 
vector<vector<int> > adj;

void propagate(int node, int nl, int nr)
{
    if(!lazy[node]) return;
    if(nl != nr)
    {
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }
    tree[node] += lazy[node] * (nr - nl + 1);
    lazy[node] = 0;
}

int update(int l, int r, int newVal, int node, int nl, int nr)
{
    propagate(node, nl, nr);
    
    if(nl > r || l > nr) return tree[node];
    else if(l <= nl && nr <= r)
    {
        tree[node] += newVal * (nr - nl + 1);
        if(nl != nr)
        {
            lazy[node*2] += newVal; 
            lazy[node*2+1] += newVal;   
        }
        return tree[node];
    }
    int mid = (nl + nr) / 2;
    return tree[node] = update(l, r, newVal, node*2, nl, mid)
                     + update(l, r, newVal, node*2+1, mid+1, nr);
}

int query(int l, int r, int node, int nl, int nr)
{
    propagate(node, nl, nr);
    
    if(nl > r || l > nr) return 0;
    if(l <= nl && nr <= r) return tree[node];
    int mid = (nl + nr) / 2;
    return query(l, r, node*2, nl, mid) + query(l, r, node*2+1, mid+1, nr);
}

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
    
    tree = lazy = vector<int>(n*4);
    st = fin = vector<int>(n, -1);
    adj = vector<vector<int> >(n);
    
    for(int i=0; i<n; i++)
    {
        int j; cin>>j;
        if(i>0) adj[j-1].push_back(i);    
    }

    DFS(0);
    while(m--)
    {
        int sel, i, w;
        cin>>sel>>i;
        if(sel==1)
        {
            cin>>w;
            update(st[i-1], fin[i-1], w, 1, 0, n-1);
        }
        else if(sel==2)
            cout<<query(st[i-1], st[i-1], 1, 0, n-1)<<'\n';
    }
    
    return 0;
}
