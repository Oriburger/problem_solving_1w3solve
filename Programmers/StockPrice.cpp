#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;
    
    for(int i=0; i<prices.size(); i++) //하나씩 기준잡는다.
    {
        int cnt = 0; //몇초부터 떨어졌는지를 나타내는 값
        for(int j=i+1; j<prices.size(); j++) //떨어지는 순간을 찾으면 break; 
        {
            cnt++;
            if(prices[i] > prices[j]) break;
        }
        answer.push_back(cnt); //cnt를 push
    }
    
    return answer;
}
