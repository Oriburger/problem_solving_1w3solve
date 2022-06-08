#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
vector<vector<int> > adj;
vector<int> indegree;
vector<P> order;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;
    while(t--)
    {
        int k, m, p;
        cin>>k>>m>>p;

        adj.resize(m+1, vector<int>());
        indegree.resize(m+1, 0);
        order.resize(m+1, {0, 0});
        for(int i=0; i<p; i++)
        {
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i=1; i<=m; i++)
            if(indegree[i]==0)
            {
                q.push(i);
                order[i] = {1, 1}; //현재 order 값, 가장 큰 order값
            }

        int last = -1;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            last = curr;
            for(auto &next : adj[curr])
            {
                int maxOrder = max(order[next].first, order[curr].first);
                if(order[next].first == 0)
                    order[next] = {maxOrder, maxOrder};
                else
                {
                    if(order[next].first == order[curr].first
                        && order[next].second == maxOrder)
                        order[next] = {maxOrder+1, maxOrder};
                    else
                        order[next] = {maxOrder, maxOrder};
                }

                if(--indegree[next] == 0)
                    q.push(next);
            }
        }
        cout<<k<<' '<<order[last].first<<'\n';

        order.clear();
        adj.clear();
        indegree.clear();
    }

    return 0;
}
