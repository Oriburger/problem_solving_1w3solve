#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool flag = false; 
vector<bool> checked(10000, false);

void DFS(vector<string> &picked, string curr, const vector<vector<string>> &tickets)
{
    if(flag) return;
    if(picked.size() == tickets.size()+1)
    {
        flag = true;
        return;
    }
    
    for(int i=0; i<tickets.size(); i++)
    {
        if(curr != tickets[i][0] || checked[i]) continue;
        
        checked[i] = true;
        picked.push_back(tickets[i][1]);
        
        DFS(picked, tickets[i][1], tickets);
        if(flag) break;
        
        checked[i] = false;
        picked.pop_back();
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer = {"ICN"};
    sort(tickets.begin(), tickets.end());
    DFS(answer, "ICN", tickets);
    return answer;
}

/* 22/03/03 resolve

#include <queue>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string, int> city_idx;
vector<string> cities, answer = {"ICN"};
vector<vector<int> > adj, remain;
queue<int> q; bool flag = false;

void DFS(int curr, int ticket)
{
    if(flag) return;
    if(ticket==0)
    {
        flag = true;
        return;
    }
    
    for(auto &next : adj[curr])
    {
        if(!remain[curr][next]) continue;
        
        remain[curr][next]-=1;
        answer.push_back(cities[next]);
        
        DFS(next, ticket-1);
        if(flag) return;
        
        remain[curr][next]+=1; //backtrack
        answer.pop_back();
    }
}

vector<string> solution(vector<vector<string>> tickets) 
{    
    //사전순에 따른 해시화
    for(auto &t : tickets)
        for(int i=0; i<2; i++)
            cities.push_back(t[i]);
    
    sort(cities.begin(), cities.end());
    cities.erase(unique(cities.begin(), cities.end()), cities.end());
    for(int i=0; i<cities.size(); i++)
        city_idx.insert({cities[i], i});
    
    //그래프 구성
    adj.resize(cities.size());
    remain = vector<vector<int> >(cities.size(), vector<int>(cities.size(), 0));
    for(auto &t :tickets)
    {
        int u = city_idx[t[0]];
        int v = city_idx[t[1]];
        adj[u].push_back(v);
        remain[u][v]++;
    }
    for(int i=0; i<cities.size(); i++)
        sort(adj[i].begin(), adj[i].end());
    
    DFS(city_idx["ICN"], tickets.size());
    
    return answer;
}

*/
