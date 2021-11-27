#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> ans;

    for(const auto &k : arr)
       if(ans.size()==0 || ans.back()!=k)
           ans.push_back(k);

    return ans;
}
