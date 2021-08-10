//https://programmers.co.kr/learn/courses/30/lessons/83201

#include <string>
#include <vector>
using namespace std;

char GetGrade(double score)
{
    if(score >= 90) return 'A';
    else if(score >= 80 && score < 90) return 'B';
    else if(score >= 70 && score < 80) return 'C';
    else if(score >= 50 && score < 70) return 'D';
    return 'F';
}

string solution(vector<vector<int>> scores)
{
    string answer = "";
    
    for(int i=0; i<scores.size(); i++)
    {
        double sum = 0;
        for(int j=0; j<scores.size(); j++)
        {
            if(i==j) continue;
            sum += scores[j][i];
        }
        answer.push_back(GetGrade(sum/(double)(scores.size()-1)));
    }
    
    return answer;
}
