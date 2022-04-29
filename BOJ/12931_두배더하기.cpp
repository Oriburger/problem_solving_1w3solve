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
    
    while(1)
    {
        bool flag = false;
        int sum = 0;
        
        for(int i=0; i<n; i++)
        {
            sum += arr[i];
            if(arr[i] && arr[i]%2==1)
            {
                flag = true;
                arr[i]--;
                break;
            }
        }
            
        for(int i=0; !flag && i<n; i++)
            if(arr[i]) arr[i]/=2;
        
        if(sum==0) break;
        ans++;            
    }
    
    cout<<ans<<'\n';
    
    return 0;
}
