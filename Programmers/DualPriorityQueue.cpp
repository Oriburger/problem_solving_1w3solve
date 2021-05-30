#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

typedef deque<int>::iterator dIter;

vector<int> solution(vector<string> operations)
{
    deque<int> answer;
    
    for(const string &p : operations) 
    {
        dIter iter;
        if(p[0]=='I')
        {
            int num = stoi(p.substr(2));
            iter = lower_bound(answer.begin(), answer.end(), num);
            answer.insert(iter, num);
        }
        else if(p[0]=='D')
        {
            if(!answer.size()) continue;
            
            if(p[2]=='-') answer.pop_front();
            else answer.pop_back();
        }
    }
    
    if(!answer.size()) return {0, 0};
    
    return {answer.back(), answer.front()};
}
