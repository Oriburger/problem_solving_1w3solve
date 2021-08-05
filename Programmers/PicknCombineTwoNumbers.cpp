#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> num)
{
    vector<int> ans;
    vector<bool> check(201, false);
    
    for(int i=0; i<num.size(); i++)
        for(int j=i+1; j<num.size(); j++)
        {
            if(i==j || check[num[i]+num[j]]) continue;
            check[num[i]+num[j]]=true;
            ans.push_back(num[i]+num[j]);
        }
    sort(ans.begin(), ans.end());
    
    return ans;
}
