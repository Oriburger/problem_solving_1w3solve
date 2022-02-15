#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

typedef pair<int, int> P;

struct DisjointSet
{
    vector<int> parent, rank;

    DisjointSet(int n) : parent(n), rank(n, 1)
    {
        for(int i=0; i<n; i++)
            parent[i]=i;
    }

    int Find(int u)
    {
        if(u == parent[u]) return u;
        return parent[u] = Find(u);
    }

    bool Merge(int u, int v)
    {
        u = Find(u); v = Find(v);
        if(u == v) return false;
        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        rank[v] += 
        return true;
    }
};

int n, m, ans;
vector<P> arr;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m;

    DisjointSet djs(n);
    
    for(int i=0; i<m; i++)
    {
        int u, v; cin>>u>>v;
        arr.push_back({u, v});
    }

    for(int i=0; i<m; i++)
        if(!djs.Merge(arr[i].first, arr[i].second))
        {
            ans = i+1; 
            break;
        }
    
    cout<<ans<<'\n';

    return 0;
}
