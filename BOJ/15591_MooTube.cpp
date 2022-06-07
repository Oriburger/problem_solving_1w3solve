#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, ll> P;

int n, q;
const int INF = 2147000000;
vector<vector<P> > adj;
int BFS(int start, int k)
{
    int ret = 0;
    queue<P> q;
    vector<bool> visited(n+1, false);

    q.push({start, INF});
    visited[start] = true;

    while(!q.empty())
    {
        P curr = q.front();
        q.pop();

        for(P next : adj[curr.first])
        {
            if(visited[next.first]) continue;
            visited[next.first] = true;
            next.second = min(next.second, curr.second);
            q.push(next);
            if(next.second >= k) ret += 1;
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>q;

    adj.resize(n+1);
    for(int i=0; i<n-1; i++)
    {
        int p, q, r;
        cin>>p>>q>>r;
        adj[p].push_back({q, r});
        adj[q].push_back({p, r});
    }
    for(int i=1; i<=n; i++)
        sort(adj[i].begin(), adj[i].end());

    while(q--)
    {
        int k, v; cin>>k>>v;
        cout<<BFS(v, k)<<'\n';
    }

    return 0;
}
