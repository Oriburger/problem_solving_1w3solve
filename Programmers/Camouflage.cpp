#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> umap;
vector<string> clothes_list;

int solution(vector<vector<string>> clothes) 
{
    int answer = 0;
    
    for(auto &c : clothes)
    {
        if(umap.count(c[1])==0)
        {
            umap[c[1]]=0;
            clothes_list.push_back(c[1]);
        }
        umap[c[1]] += 1;
    }
    
    if(!umap.empty()) answer = 1;
    
    for(auto &p : clothes_list)
        answer *= (umap[p]+1);
    
    return answer-1;
}
