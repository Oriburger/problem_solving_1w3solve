#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<bool> checked;

int BFS(vector<int>& degree, vector<vector<int>>& adj)
{
    int ret = 0;
    int n = degree.size();
    vector<bool> visited(n, false);
    
    for(int k=0; k<n; k++)
    {
        bool flag = false;
        int curr = -1;
        
        for(int i=0; i<n; i++)
        {
            if(visited[i]) continue;
            if(degree[i]==0)
            {
                if(curr != -1) return ret;
                curr = i;
            }
            flag = true;
        }
        if(!flag) break;
        
        if(!checked[curr]) ret += 1;
        visited[curr] = checked[curr] = true;
        
        for(auto &next : adj[curr])
            degree[next]--;
    }
    
    return ret;
}

int solution(int n, vector<vector<int>> results) 
{
    int answer = 0;
    vector<int> indegree, outdegree;
    vector<vector<int>> adj, radj;
    
    adj.resize(n); 
    radj.resize(n);
    indegree = outdegree = vector<int>(n, 0);
    checked = vector<bool>(n, false);
    
    for(int i=0; i<results.size(); i++)
    {
        int u = results[i][0]-1;
        int v = results[i][1]-1;
        
        indegree[v]++;
        outdegree[u]++;
        
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    
    answer += BFS(outdegree, radj);
    answer += BFS(indegree, adj);
    
    return answer;
}
