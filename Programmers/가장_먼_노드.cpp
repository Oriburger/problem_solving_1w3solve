//https://school.programmers.co.kr/learn/courses/30/lessons/49189

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

typedef pair<int, int> P;

priority_queue<P, vector<P>, greater<P> > pq;
vector<P> adj[20001];
vector<int> dist(20001, 1e9);

int solution(int n, vector<vector<int>> edge) 
{
    for(auto &e : edge)
    {
        adj[e[0]].push_back({1, e[1]});
        adj[e[1]].push_back({1, e[0]});
    }
    
    int curr = 1;
    dist[1] = 0;
    pq.push({dist[1], 1});
    
    while(!pq.empty())
    {
        P top = pq.top(); 
        const int curr = top.second; 
        const int curDist = top.first;
        pq.pop(); 
        
        for(auto &next : adj[curr])
        {            
            if(dist[next.second] > dist[curr] + next.first)
            {
                dist[next.second] = dist[curr] + next.first;
                pq.push({dist[next.second], next.second});
            }
        }
    }
    
    int maxDist = 0, maxCnt = 0;
    for(int i=2; i<=n; i++)
    {
        cout<<dist[i]<<", ";
        if(maxDist < dist[i]) 
        {
            maxCnt = 1; 
            maxDist = dist[i];
        }
        else if(maxDist == dist[i]) 
            maxCnt += 1;
    }
        
    return maxCnt;
}
