#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) 
{
    vector<int> answer;
    
    for(const auto &k : arr)
        if(k >= divisor && k%divisor==0)
            answer.push_back(k);
    
    if(answer.size()) sort(answer.begin(), answer.end());
    else answer.push_back(-1);
    
    return answer;
}
