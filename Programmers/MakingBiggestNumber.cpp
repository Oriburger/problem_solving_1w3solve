#include <string>
#include <vector>

using namespace std;

string solution(string number, int k)
{
    string answer = "";
    vector<bool> check(number.size(), false);
    
    int lastPick = 0;
    int toPick = number.size()-k;
    while(toPick)
    {
        int maxVal = -1, maxIdx = -1;
        for(int j=lastPick; j<=number.size()-toPick; j++)
        {
            if(maxVal < number[j]-'0')
            {
                maxVal = number[j]-'0';
                maxIdx = j;
            }
        }
        answer.push_back(maxVal+'0');
        lastPick = maxIdx+1;
        toPick -= 1;
    }
    
    return answer;
}
