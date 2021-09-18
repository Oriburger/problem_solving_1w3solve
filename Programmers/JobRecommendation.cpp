#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string, int> umap;
vector<string> jobs;

int GetScore(string tableStr, const vector<string> languages, const vector<int> preference)
{
    int ret = 0;
    
    string temp = "";
    int scoreCnt = 6;
    for(int i=0; i<tableStr.size(); i++)
    {
        temp.push_back(tableStr[i]);
        
        if(tableStr[i] == ' ' || i==tableStr.size()-1)
        {
            if(tableStr[i] == ' ') temp.pop_back();
            
            if(scoreCnt == 6) jobs.push_back(temp);
            else umap[temp] = scoreCnt;
            
            scoreCnt -= 1;
            temp = "";
            continue;
        }
    }
    
    for(int i=0; i<languages.size(); i++)
        ret += (preference[i] * umap[languages[i]]);
    
    umap.clear();
    return ret;
}
    
string solution(vector<string> table, vector<string> languages, vector<int> preference)
{
    string answer = "";
    int maxScore = -1;
    
    sort(table.begin(), table.end());
    
    for(int i=0; i<table.size(); i++)
    {
        int currScore = GetScore(table[i], languages, preference);
        if(maxScore < currScore)
        {
            maxScore = currScore;
            answer = jobs[i];
        }
    }
    
    return answer;
}
