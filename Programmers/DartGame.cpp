#include <string>
#include <cmath>
using namespace std;

int score[3];

int solution(string result) 
{
    int idx = 0;
    
    string temp;
    for(int i=0; i<result.size(); i++)
    {
        if(result[i]>='0' && result[i]<='9')
        {
            if(result[i+1]=='0')
            {
                score[idx++] = 10;
                i++; continue;
            }
            else score[idx++] = result[i]-'0';
        }
        else if(result[i]=='D') score[idx-1] = pow(score[idx-1], 2);
        else if(result[i]=='T') score[idx-1] = pow(score[idx-1], 3);
        else if(result[i]=='*')
        {
            for(int j=idx-2; j<idx; j++)
                if(j>=0) score[j]*=2;
        }
        else if(result[i]=='#') score[idx-1] *= -1;
    }
    
    return score[0]+score[1]+score[2];
}
