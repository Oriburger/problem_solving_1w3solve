#include <string>
#include <vector>

using namespace std;

vector<int> cnt; 

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    int answer = 0;
    cnt.resize(n, 1);
    
    for(auto &p : lost) cnt[p-1]--;
    for(auto &p : reserve) cnt[p-1]++;
    
    for(int i=1; i<n; i++)
    {
        if(cnt[i-1]==0 && cnt[i]==2)
            cnt[i-1]=cnt[i]=1;
        else if(cnt[i]==0 && cnt[i-1]==2)
            cnt[i-1]=cnt[i]=1;
    }
    
    for(int i=0; i<n; i++)
        answer += ((bool)cnt[i]);
    
    return answer;
}
