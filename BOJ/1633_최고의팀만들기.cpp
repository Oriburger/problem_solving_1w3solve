#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
vector<P> arr;
int cache[1001][16][16];
int a, b, ans;

int GetAnswer(int idx, int w, int b)
{
    if(idx == arr.size() || (!w && !b)) return 0;
    int &ret = cache[idx][w][b];
    if(ret != -1) return ret;
    
    ret = 0;
    if(w>0) ret = GetAnswer(idx+1, w-1, b) + arr[idx].first;
    if(b>0) ret = max(ret, GetAnswer(idx+1, w, b-1) + arr[idx].second);
    if(w+b <= arr.size()-idx-1) ret = max(ret, GetAnswer(idx+1, w, b));
    
    return ret;
}

int main()
{
    while(scanf("%d %d", &a, &b) == 2)
        arr.push_back({a, b});
    memset(cache, -1, sizeof(cache));
    ans = GetAnswer(0, 15, 15);
    printf("%d\n", ans);
    
    return 0;
}
