#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    string answer = "";
    unordered_map<string, int> umap;
    
    for(int i=0; i<completion.size(); i++)
    {
        if(!umap.count(completion[i])) umap[completion[i]]=1;
        else umap[completion[i]]+=1;
    }
    
    for(int i=0; i<participant.size(); i++)
    {
        if(!umap.count(participant[i]) || !umap[participant[i]]) answer = participant[i];
        else umap[participant[i]]-=1;
    }
    
    return answer;
}
