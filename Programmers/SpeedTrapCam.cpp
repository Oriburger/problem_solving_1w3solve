#include <bits/stdc++.h>
using namespace std;

bool comp(const vector<int>& a, const vector<int>& b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) 
{
    int ans = 0, cpos = -30001;
    sort(routes.begin(), routes.end(), comp);
    
    for(const auto &curr : routes)
        if(cpos < curr[0])
        {
            ans+=1;
            cpos = curr[1];
        }
    
    return ans;
}
