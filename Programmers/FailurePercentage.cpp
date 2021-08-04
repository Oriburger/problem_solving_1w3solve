#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<double, int> P;

bool Comp(P &a, P &b)
{
	if(a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages)
{
    vector<int> ans;
    vector<double> success(N+2, 0), current(N+2, 0);
    vector<P > fail(N);
    
    for(int i=0; i<stages.size(); i++)
    {
        for(int j=1; j<stages[i]; j++)
            success[j]++;
        current[stages[i]]++;
    }
    
    for(int i=0; i<N; i++)
    {
        fail[i].second = i+1;
        if(!success[i+1] && !current[i+1])
            fail[i].first = 0;
        else
            fail[i].first = current[i+1] / (current[i+1]+success[i+1]);
    }
    sort(fail.begin(), fail.end(), Comp);
    
    for(auto &p : fail)
        ans.push_back(p.second);
    
    return ans;
}
