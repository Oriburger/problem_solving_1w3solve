#include <string>
#include <vector>

using namespace std;

string solution(string number, int k)
{
    string answer = "";
    vector<bool> check(number.size(), false);
    
    int lastPick = 0;
    int toPick = number.size()-k;
    while(toPick) //toPick번 반복
    {
        int maxVal = -1, maxIdx = -1;
        for(int j=lastPick; j<=number.size()-toPick; j++) //주어진 범위 내에서 가장 큰 수를 구한다.
        {
            if(maxVal < number[j]-'0') 
            {
                maxVal = number[j]-'0';
                maxIdx = j;
            }
        }
        answer.push_back(maxVal+'0'); 
        lastPick = maxIdx+1; //다음 범위의 시작은 마지막으로 뽑은 수 idx + 1
        toPick -= 1;
    }
    
    return answer;
}
