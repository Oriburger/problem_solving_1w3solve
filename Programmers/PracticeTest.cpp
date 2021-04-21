#include <string>
#include <vector>

using namespace std;

const int A[5] = {1, 2, 3, 4, 5};
const int B[8] = {2, 1, 2, 3, 2, 4, 2, 5};
const int C[10] = {3, 3, 1, 1, 2, 2 , 4, 4, 5, 5};

vector<int> solution(vector<int> answers) 
{
    vector<int> ret;
    
    int score[3]={0,0,0};
    for(int i=0; i<answers.size(); i++)
    {
        if(A[i%5]==answers[i])
            score[0]+=1;
        if(B[i%8]==answers[i])
            score[1]+=1;
        if(C[i%10]==answers[i])
            score[2]+=1;
    }
    
    int maxScore=-1;
    for(int i=0; i<3; i++)
    {
        if(maxScore < score[i])
        {
            maxScore = score[i];
            ret.clear();
            ret.push_back(i+1);
        }
        else if(maxScore == score[i])
            ret.push_back(i+1);
    }
    
    return ret;
}
