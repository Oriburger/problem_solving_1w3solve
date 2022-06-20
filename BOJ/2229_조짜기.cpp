#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> score, cache(1001, -1);

int Answer(int idx)
{
    if(idx<0) return 0;
    int &ret = cache[idx];
    if(ret != -1) return ret;

    int max_val = score[idx], min_val = score[idx];
    for(int j = idx; j>=0; j--)
    {
        max_val = max(max_val, score[j]);
        min_val = min(min_val, score[j]);
        ret = max(ret, max_val - min_val + Answer(j-1));
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    score = vector<int>(n);
    for(int i=0; i<n; i++)
        cin>>score[i];

    cout<<Answer(n-1)<<'\n';

    return 0;
}
