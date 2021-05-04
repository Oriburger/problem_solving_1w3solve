#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> umap;
vector<string> arr;

int solution(vector<vector<string>> clothes) 
{
    int answer = 1;
    
    for(int i=0; i<clothes.size(); i++)
    {
        string b;
        b = clothes[i][1];
        
        if(umap.count(b)==0)
        {
            arr.push_back(b);
            umap[b]=2;
        }
        else
            umap[b]++;
    }
    
    for(int i=0; i<arr.size(); i++)        
        answer *= umap[arr[i]];
    
    return answer-1;
}
