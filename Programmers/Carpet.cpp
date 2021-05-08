#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) 
{
    vector<int> answer;
    
    bool flag = false;
    for(int i=3; i<=brown; i++) //적당히 가로 범위 잡아주고
    {
        for(int j=3; j<=i; j++) //세로는 가로보다 짧게
        {
            if(i*j - yellow == brown //카펫 모양이 만들어진다면?
              && (i-2)*(j-2) == yellow)
            {
                answer.push_back(i); //가로, 세로 순서대로 push
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
