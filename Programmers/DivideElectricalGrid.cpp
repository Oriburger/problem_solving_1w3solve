#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool adj[201][201]; //그래프는 인접 행렬 형식
vector<bool> visited; 

int DFS(int curr, const int n)
{
    if(visited[curr]) return 0;
    visited[curr] = true;
    
    int ret = 1;
    for(int next=1; next<=n; next++)
    {
        if(!adj[curr][next]) continue;
        
        ret += DFS(next, n);
    }
    return ret;
}

int solution(int n, vector<vector<int>> wires) 
{
    int answer = 201;
    
    for(int i=0; i<wires.size(); i++) //그래프 초기화
    {
        int u = wires[i][0];
        int v = wires[i][1];
        adj[u][v] = adj[v][u] = true;
    }
    
    for(int i=0; i<wires.size(); i++) //모든 선을 하나씩 끊어보며 정답을 탐색
    {
        int u = wires[i][0];
        int v = wires[i][1];
        adj[u][v] = adj[v][u] = false; //i번째 선을 끊음
        
        vector<int> count;
        visited = vector<bool>(n+1, false);
        for(int j=1; j<=n; j++) //모든 정점에 대해 DFS를 진행하여 2개로 나뉜 구간의 크기를 구한다.
        {
            int temp = DFS(j, n);
            if(!temp) continue; 
            count.push_back(temp);
        }
        answer = min(answer, abs(count[0]-count[1])); //정답 갱신
        adj[u][v] = adj[v][u] = true; //다시 재연결
    }
    
    return answer;
}
