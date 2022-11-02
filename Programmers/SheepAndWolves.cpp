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
    answer = max(answer, scnt); //정답 갱신
    
    for(auto& next : adj[curr])
    {
        if(!isEmpty[next] && !visited[next][scnt + (1-info[next])][wcnt + info[next]]) //비어있지 않다면?
        {
            isEmpty[next] = true;
            visited[next][scnt + (1-info[next])][wcnt + info[next]] = true;
            getAnswer(next, scnt + (1-info[next]), wcnt + info[next], info, answer); 
            visited[next][scnt + (1-info[next])][wcnt + info[next]] = false; //backtrack
            isEmpty[next] = false;
        }
        else if(isEmpty[next] && !visited[next][scnt][wcnt]) //비어있다면?
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

/* ------- 비트필드 DP 활용 ------------

#include <cstring>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> adj;
int cache[17][1<<17];


int getAnswer(int curr, int state, const vector<int> &info)  //현재까지 방문한 노드들의 상태가 state이고, 현재 노드는 curr일때의 최대 sheep 수 
{ 
    int &ret = cache[curr][state];
    if(ret != -1) return ret;
    
    int wcnt = 0, scnt = 0;
    for(int i=0; i<info.size(); i++) //현재 state에 대해 wcnt와 scnt를 세어줌
    {
        if(state & (1<<i))
        {
            wcnt += info[i];
            scnt += (1-info[i]);
        }
    }
    if(wcnt == scnt) return ret = 0; //같다면 0 반환
    
    ret = scnt; //초기 ret
    for(auto& next : adj[curr]) //인접한 정점 탐색
    {
        ret = max(ret, getAnswer(next, state | (1<<next), info)); //ret 갱신
    }
    return ret; 
}


int solution(vector<int> info, vector<vector<int>> edges) 
{
    memset(cache, -1, sizeof(cache));
    
    adj.resize(info.size());
    for(auto &e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    
    return getAnswer(0, 1, info);
}


*/
