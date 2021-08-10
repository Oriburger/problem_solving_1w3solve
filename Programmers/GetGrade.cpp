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
    string answer;
    
    for(int i=0; i<scores.size(); i++)
    {
        double sum = 0;
        int max_score = -1, min_score = 999, self_score;
        int max_cnt = 0, min_cnt = 0;
        for(int j=0; j<scores.size(); j++)
        {
            int &curr = scores[j][i];
            if(i==j) self_score = curr;
            sum += curr;
            
            if(max_score < curr)
            {
                max_cnt = 1;
                max_score = curr;
            }
            else if(max_score == curr)
                max_cnt++;
            
            if(min_score > curr)
            {
                min_cnt = 1;
                min_score = curr;
            }
            else if(min_score == curr)
                min_cnt++;
        }          
        
        if((max_score == self_score && max_cnt == 1) ||
            (min_score == self_score && min_cnt == 1))
            sum = (sum-self_score) / (double)(scores.size()-1);
        
        else
            sum = sum / (double)(scores.size());
                   
        answer.push_back(GetGrade(sum));
    }
    
    return answer;
}
