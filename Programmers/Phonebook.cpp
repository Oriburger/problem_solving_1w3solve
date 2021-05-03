#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<string> uset;

bool solution(vector<string> pnum) 
{
    bool answer = true;
    
    for(const auto& str : pnum)
        for(int i=0; i<str.size(); i++)
            uset.insert(str.substr(0, i));
    
    for(const auto& str : pnum)
        if(uset.count(str)>0)
        {
            answer = false;
            break;
        }
    
    return answer;
}
