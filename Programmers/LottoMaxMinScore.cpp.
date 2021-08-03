#include <string>
#include <vector>
using namespace std;

const int score[7] = {6,6,5,4,3,2,1};
bool win_check[46];

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    int correct = 0, blnk = 0;
    
    for(auto &n : win_nums)
        win_check[n] = true;
    
    for(int i=0; i<lottos.size(); i++)
    {
        correct += (win_check[lottos[i]]);
        blnk += (!lottos[i]);
    }
    
    return {score[correct+blnk], score[correct]};
}
