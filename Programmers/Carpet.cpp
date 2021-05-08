#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) 
{
    vector<int> answer;
    
    bool flag = false;
    for(int i=3; i<=brown; i++)
    {
        for(int j=3; j<=i; j++)
        {
            if(i*j - yellow == brown
              && (i-2)*(j-2) == yellow)
            {
                answer.push_back(i);
                answer.push_back(j);
                flag = true;
                break;
            }
            else if(i*j - yellow > brown)
                break;
        }
        if(flag) break;
    }
    
    return answer;
}
