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
        order.resize(m+1, {0, 0}); //초기 order은 모두 0
        for(int i=0; i<p; i++)
        {
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            indegree[v]++; //진입차수 ++
        }

        queue<int> q;
        for(int i=1; i<=m; i++)
            if(indegree[i]==0) //진입차수가 0인 정점들을 모두 큐에 넣음
            {
                q.push(i);
                order[i] = {1, 1}; //현재 order 값, 가장 큰 order값
            }

        while(!q.empty())
        {
            int curr = q.front(); //진입차수 0인 정점을 큐에서 
            q.pop();              //꺼낸다 (나가는 간선을 모두 끊는다)

            for(auto &next : adj[curr]) //해당 정점과 연결된 정점들을 돌며 order 업데이
            {
                //두 정점 중 최대 order인 maxOrder을 구함
                int maxOrder = max(order[next].first, order[curr].first);

                //만약 들어오는 정점의 order과 현재 정점의 order이 같고,
                //현재 정점에 들어온 최대 order값도 같다면?
                if(order[next].first == order[curr].first 
                   && order[next].second == maxOrder)
                    order[next] = {maxOrder+1, maxOrder}; //maxOrder+1이 이 정점의 order값이 됨
                else //그렇지 않다면
                    order[next] = {maxOrder, maxOrder}; //maxOorder

                if(--indegree[next] == 0) //진입차수가 0이 되었다면
                    q.push(next); //큐에 넣음
            }
        }
        cout<<k<<' '<<order[m].first<<'\n'; //마지막 정점의 order 출력,, 

        order.clear();
        adj.clear();
        indegree.clear();
    }

    return 0;
}
