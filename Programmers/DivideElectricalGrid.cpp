#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> P;
vector<int> adj[101];
vector<bool> visited(101, false);

void DFS(int curr, const P ignoreEdge, int &count)
{
    visited[curr] = true;
    count += 1;
    
    for(int &next : adj[curr])
    {
        if(P(curr, next) == ignoreEdge
            || P(next, curr) == ignoreEdge) continue; 
        if(visited[next]) continue;    
        
        DFS(next, ignoreEdge, count);
    }
}

int solution(int n, vector<vector<int>> wires) 
{
    int answer = 1e9;
    
    for(auto &w : wires)
    {
        adj[w[0]].push_back(w[1]);
        adj[w[1]].push_back(w[0]);
    }
    
    for(int i=0; i<wires.size(); i++)
    {
        int areaCnt = 0;
        DFS(1, {wires[i][0], wires[i][1]}, areaCnt);
        answer = min(answer, abs((n-areaCnt) - areaCnt));
        visited = vector<bool>(101, false);
    }
    return answer;
}
