#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct SegTree
{
    int n;
    vector<ll> tree, lazy;
    SegTree(int n) : n(n)
    {
        tree = lazy = vector<ll>(n*4, 0);
    }
    
    ll init(const vector<ll>& arr, int left, int right, int node)
    {
        if(left == right) return tree[node] = arr[left];
        
        int mid = (left + right) / 2;
        ll leftVal = init(arr, left, mid, node*2);
        ll rightVal = init(arr, mid+1, right, node*2+1);
        return tree[node] = leftVal + rightVal;
    }
    
    ll query(const int left, const int right, int node, int nodeLeft, int nodeRight)
    {
        propagate(node, nodeLeft, nodeRight);
        
        if(nodeLeft > right || left > nodeRight) return 0;
        if(left <= nodeLeft && nodeRight <= right) return tree[node];
        
        int mid = (nodeLeft + nodeRight) / 2;
        ll leftVal = query(left, right, node*2, nodeLeft, mid);
        ll rightVal = query(left, right, node*2+1, mid+1, nodeRight);
        return leftVal + rightVal;        
    }
    
    ll query(int left, int right)
    {
        return query(left, right, 1, 0, n-1);
    }
    
    ll update_range(const int left, const int right, ll newVal, int node, int nodeLeft, int nodeRight)
    {
        propagate(node, nodeLeft, nodeRight);
        
        if(nodeLeft > right || left > nodeRight) return tree[node];
        if(left <= nodeLeft && nodeRight <= right)
        {
            tree[node] += newVal * (nodeRight - nodeLeft + 1);
            if(nodeLeft != nodeRight)
            {
                lazy[node*2] += newVal;
                lazy[node*2+1] += newVal;
            }
            return tree[node];
        }
        int mid = (nodeLeft + nodeRight) / 2;
        
        return tree[node] = update_range(left, right, newVal, node*2, nodeLeft, mid)
                            + update_range(left, right, newVal, node*2+1, mid+1, nodeRight);
    }
    
    ll update_range(int left, int right, ll newVal)
    {
        return update_range(left, right, newVal, 1, 0, n-1);
    }
    
    void propagate(int node, int nodeLeft, int nodeRight)
    {
        if(lazy[node]==0) return;
        if(nodeLeft != nodeRight)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        tree[node] += (nodeRight - nodeLeft+1) * lazy[node];
        lazy[node] = 0;
    }
};

int n, m, tmp = -1;
vector<ll> arr;
vector<vector<int> > adj;
vector<int> in, out;

void DFS(int curr)
{
    in[curr] = ++tmp; 
    for(auto &next : adj[curr])
        if(in[next]==-1)
            DFS(next);
    out[curr] = tmp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>m;
    arr = vector<ll>(n);
    in = out = vector<int>(n, -1);
    adj.resize(n);
    for(int i=0; i<n; i++)
    {        
        cin>>arr[i];
        if(i!=0)
        {
            int j; cin>>j;
            adj[0].push_back(i);
            adj[j-1].push_back(i);
        }
    }   
    
    DFS(0);
    SegTree st(n);
    for(int i=0; i<n; i++)
        st.update_range(in[i], in[i], arr[i]);
        
    for(int i=0; i<m; i++)
    {
        char sel; 
        int a, x; 
        
        cin>>sel;
        if(sel == 'p')
        {
            cin>>a>>x;
            if(in[a-1] == out[a-1]) continue;
            st.update_range(in[a-1]+1, out[a-1], x);
        }
        else if(sel == 'u')
        {
            cin>>a;
            cout<<st.query(in[a-1], in[a-1])<<'\n';
        }
    }
    
    return 0;
}
