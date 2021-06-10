#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const string tri_nums = "412";

string solution(int n)
{
    string answer = "";
    bool flag = false;
    
    while(1)
    {
        if(!n) break;
        answer.push_back(tri_nums[n%3]);
        n = n%3==0 ? n/3-1 : n/3;
    }
    reverse(answer.begin(), answer.end());
    
    return answer;
}
