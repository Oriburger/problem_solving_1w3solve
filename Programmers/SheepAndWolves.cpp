#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> adj;
bool visited[20][20][20];
bool isEmpty[20];

void getAnswer(int curr, int scnt, int wcnt, const vector<int> &info, int& answer)
{
    if(scnt <= wcnt) return;
    answer = max(answer, scnt);
    
    for(auto& next : adj[curr])
    {
        if(!isEmpty[next] && !visited[next][scnt + (1-info[next])][wcnt + info[next]])
        {
            isEmpty[next] = true;
            visited[next][scnt + (1-info[next])][wcnt + info[next]] = true;
            getAnswer(next, scnt + (1-info[next]), wcnt + info[next], info, answer);
            visited[next][scnt + (1-info[next])][wcnt + info[next]] = false;
            isEmpty[next] = false;
        }
        else if(isEmpty[next] && !visited[next][scnt][wcnt])
        {
            visited[next][scnt][wcnt] = true;
            getAnswer(next, scnt, wcnt, info, answer);
            visited[next][scnt][wcnt] = false;
        }
    }
}


int solution(vector<int> info, vector<vector<int>> edges) 
{
    int answer = 0;
    
    adj.resize(info.size());
    for(auto &e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    
    isEmpty[0] = true;
    visited[0][1][0] = true;
    getAnswer(0, 1, 0, info, answer);
    return answer;
}
