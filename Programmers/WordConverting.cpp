#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#define INF 2147000000
using namespace std;

queue<int> q; 
vector<vector<int> > adj; 
unordered_map<string, int> umap; //key : string,  value : int 
vector<int> dist; //시작점으로부터 거리를 저장

int get_diff(const string &st1, const string &st2) //st1와 st2가 얼마나 차이나는지 반환
{
    int ret = 0;
    for(int i=0; i<st1.size(); i++)
        ret += (st1[i]!=st2[i]);
    return ret;
}

int solution(string begin, string target, vector<string> words)
{       
    words.push_back(begin); //시작점을 words에 push 
    for(int i=0; i<words.size(); i++) //문자열을 정수에 1:1 매칭 시켜준다.
        umap[words[i]] = i;
    
    if(!umap.count(target)) return 0; //target이 words에 없다면 0 반환
    
    adj.resize(words.size()); //adj와 dist 크기 초기화
    dist = vector<int>(words.size(), INF);
    
    for(int i=0; i<words.size()-1; i++) //모든 문자열 쌍을 탐색하며 차이가 1인 문자열들을 간선으로 이어준다.
        for(int j=i+1; j<words.size(); j++)
            if(get_diff(words[i], words[j])==1) //만약 두 문자열이 1글자만 차이가 난다면?
            {
                int u = umap[words[i]]; //두 문자열을 간선으로 이어준다
                int v = umap[words[j]]; 
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
    
    //BFS를 이용한 최단거리 도출
    q.push(umap[begin]);
    dist[umap[begin]]=0;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        
        for(const int& next : adj[curr])
        {
            if(dist[next] != INF) continue;
            if(dist[next] < dist[curr] + 1) continue;
            
            dist[next] = dist[curr] + 1;
            q.push(next);
        }
    }
    if(dist[umap[target]]==INF) return 0; //만약 도달할 수 없는 문자열이라면?
    
    return dist[umap[target]];
}
