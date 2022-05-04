#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans=0;
vector<int> arr;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;

    arr = vector<int>(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    sort(arr.begin(), arr.end());
    
    int lo=0, hi=n-1;
    while(lo <= hi)
    {
        if(lo==hi)
        {
            ans += arr[hi];
            break;
        }
        ans+=arr[hi]*2;
        lo++;
        hi--;
    }
    
    cout<<ans<<'\n';
    
    return 0;
}
