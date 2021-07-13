#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

const int INF = 2147000000;
typedef pair<int, int> P;

int solution(int N, vector<vector<int> > road, int K)
{
    int answer = 0;
    vector<int> dist(N+1, INF);
    vector<vector<P> > adj;
    priority_queue<P, vector<P>, greater<P> > pq;
    
    adj.resize(N+1);
    for(auto &p : road)
    {
        adj[p[0]].push_back({p[1], p[2]});
        adj[p[1]].push_back({p[0], p[2]});
    }
    
    dist[1]=0;
    pq.push({dist[1], 1});
    
    while(!pq.empty())
    {
        int curr = pq.top().second;
        int cur_dist = pq.top().first;
        pq.pop();
        
        if(cur_dist > dist[curr]) continue;
        
        for(auto &p : adj[curr])
        {
            int next = p.first;
            int next_dist = dist[curr] + p.second;
            
            if(next_dist < dist[next])
            {
                dist[next] = next_dist;
                pq.push({dist[next], next});
            }
        }
    }
    
    for(int i=1; i<=N; i++)
        if(dist[i]<=K)
            answer++;

    return answer;
}
