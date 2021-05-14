#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <unordered_map>
#define INF 2147000000
using namespace std;

typedef pair<int, int> P;

priority_queue<P, vector<P>, greater<P> > pq;
vector<vector<int> > adj;
unordered_map<string, int> umap;
vector<int> dist;

int get_diff(const string &st1, const string &st2)
{
    int ret = 0;
    for(int i=0; i<st1.size(); i++)
        ret += (st1[i]!=st2[i]);
    return ret;
}

int solution(string begin, string target, vector<string> words)
{       
    words.push_back(begin);
    for(int i=0; i<words.size(); i++)
        umap[words[i]] = i;
    
    if(!umap.count(target)) return 0;
    
    adj.resize(words.size());
    dist = vector<int>(words.size(), INF);
    
    for(int i=0; i<words.size()-1; i++)
        for(int j=i+1; j<words.size(); j++)
            if(get_diff(words[i], words[j])==1)
            {
                int u = umap[words[i]];
                int v = umap[words[j]];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
    
    pq.push({0, umap[begin]});
    dist[umap[begin]]=0;
    while(!pq.empty())
    {
        int curr = pq.top().second;
        pq.pop();
        
        for(const int& next : adj[curr])
        {
            if(dist[next] < dist[curr] + 1) continue;
            
            dist[next] = dist[curr] + 1;
            pq.push({dist[next], next});
        }
    }
    if(dist[umap[target]]==INF) return 0;
    
    return dist[umap[target]];
}
