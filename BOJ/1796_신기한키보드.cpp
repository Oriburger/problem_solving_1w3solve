#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int ans = 1e9; 
vector<int> lo, hi;

int search(int idx, int curr)
{
    if(idx == 26) return 0; 

    if(lo[idx] != -1)
    {
        const int dist = hi[idx] - lo[idx];
        if(curr < lo[idx]) 
            return search(idx + 1, hi[idx]) + lo[idx] - curr + dist;
        else if(hi[idx] < curr) 
            return search(idx + 1, lo[idx]) + curr - hi[idx] + dist;
        return min( search(idx + 1, lo[idx]) + abs(curr - hi[idx]) + dist
                    , search(idx + 1, hi[idx]) + abs(curr - lo[idx]) + dist);
    }
    return search(idx+1, curr);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
     
    string s;
    cin>>s; 

    lo = hi = vector<int>(26, -1);
    
    for(int i=0; i<s.size(); i++)
    {
        if(lo[s[i]-'a'] == -1) lo[s[i]-'a'] = i;
        hi[s[i]-'a'] = i;
    }
    cout<<search(0, 0) + s.size()<<'\n';

    return 0;
}
