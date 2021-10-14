#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

const int MAX = 10001;

bool flag = false;
vector<string> answer;
vector<vector<string>> tickets;
vector<bool> checked(MAX, false); //ticket[i]를 사용했는가?

void DFS(vector<string> picked, string curr)
{
    if(flag) return;
    
    if(picked.size() == tickets.size()+1)
    {
        flag = true;
        answer = picked; 
        return;
    }
    
    for(int i=0; i<tickets.size(); i++)
    {
        if(checked[i]) continue;
        if(tickets[i][0] != curr) continue;
        
        checked[i] = true;
        picked.push_back(tickets[i][1]);
        DFS(picked, tickets[i][1]);
        picked.pop_back(); //backtrack!
        checked[i] = false; //backtrack!
    }
    return;
}

vector<string> solution(vector<vector<string>> t)
{
    tickets = t;    
    sort(tickets.begin(), tickets.end());
    
    DFS({"ICN"}, "ICN");
    
    return answer;
}
