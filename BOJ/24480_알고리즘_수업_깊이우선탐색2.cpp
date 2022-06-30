#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, r, cnt=1;
vector<vector<int> > adj;
vector<int> visited;

void DFS(int curr)
{
    visited[curr]=cnt++;
    for(auto &next : adj[curr])
        if(!visited[next])
            DFS(next);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m>>r;

    adj = vector<vector<int> >(n+1);
    visited = vector<int>(n+1, 0);
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++)
        sort(adj[i].begin(), adj[i].end(), greater<int>());

    DFS(r);
    for(int i=1; i<=n; i++)
        cout<<visited[i]<<'\n';

    return 0;
}
