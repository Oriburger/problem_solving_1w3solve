#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Boxer
{
    int id;
    int weights;
    double win_rate;
    int heavier;
};

bool comp(const Boxer& b1, const Boxer& b2)
{
    if(b1.win_rate > b2.win_rate) return true;
    else if(b1.win_rate < b2.win_rate) return false;
    else if(b1.heavier > b2.heavier) return true;
    else if(b1.heavier < b2.heavier) return false;
    else if(b1.weights > b2.weights) return true;
    else if(b1.weights < b2.weights) return false;
    return b1.id < b2.id;
}

vector<int> solution(vector<int> weights, vector<string> head2head)
{
    vector<Boxer> boxers(weights.size());
    vector<int> answer;
    
    for(int i=0; i<weights.size(); i++)
    {
        boxers[i].id = i+1;
        boxers[i].weights = weights[i];
        
        int heavier = 0;
        int win_count = 0, total_count = 0;
        for(int j=0; j<weights.size(); j++)
        {
            if(i==j) continue;
            if(head2head[i][j]=='W')
            {
                win_count++;
                total_count++;
                if(weights[i] < weights[j])
                    heavier++;
            }
            else if(head2head[i][j]=='L')
                total_count++;
        }
        if(!total_count) boxers[i].win_rate = 0;
        else boxers[i].win_rate = (double)win_count / (double)total_count;
        boxers[i].heavier = heavier;
    }
    sort(boxers.begin(), boxers.end(), comp);
    
    for(int i=0; i<boxers.size(); i++)
        answer.push_back(boxers[i].id);
    
    return answer;
}
