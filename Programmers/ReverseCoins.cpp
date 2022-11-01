#include <string>
#include <vector>
using namespace std;

int ylen, xlen;
const int INF = 100;
vector<vector<int> > st, fin;

void turnReverse(vector<vector<int> >& curr, int idx, bool bIsRow)
{
    for(int i=0; i<(bIsRow ? xlen : ylen); i++)
    {
        if(bIsRow) curr[idx][i] = 1 - curr[idx][i];
        else curr[i][idx] = 1 - curr[i][idx];
    }
}

bool isEqual(vector<vector<int> >& a, vector<vector<int> >& b)
{
    for(int i=0; i<ylen; i++)
    {
        for(int j=0; j<xlen; j++)
        {
            if(a[i][j] != b[i][j])
                return false;
        }
    }
    return true;
}

int getAnswer(vector<vector<int> > curr, int idx)
{
    int ret = INF;

    if(isEqual(curr, fin)) return 0;
    if(idx >= max(ylen, xlen)) return ret;
    
    ret = min(ret, getAnswer(curr, idx+1));
    
    if(ylen > idx)
    {
        turnReverse(curr, idx, 1);
        ret = min(ret, getAnswer(curr, idx+1)+1);
    }
    if(xlen > idx)
    {
        turnReverse(curr, idx, 0);
        ret = min(ret, getAnswer(curr, idx+1)+ (ylen>idx ? 2 : 1));
        
        if(ylen > idx)
        {
            turnReverse(curr, idx, 1);
            ret = min(ret, getAnswer(curr, idx+1)+1);
        }
    }
    return ret;
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) 
{
    ylen = beginning.size();
    xlen = beginning[0].size();
        
    st = beginning; fin = target;    
    
    int answer = getAnswer(beginning, 0);
    return answer >= INF ? -1 : answer;
}
