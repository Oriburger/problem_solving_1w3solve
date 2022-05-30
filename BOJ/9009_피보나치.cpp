#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr(50), ans;
const int MAX = 1e9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin>>t;
    
    arr[0] = arr[1] = 1;
    for(int i=2; ; i++)
    {
        if(arr[i-1]+arr[i-2] > MAX) break;
        arr[i] = arr[i-1] + arr[i-2];
    }
    
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=43; i>=0; i--)
        {
            if(arr[i] > n) continue; 
            if(n==0) break;
            
            n -= arr[i];
            ans.push_back(arr[i]);
        }
        
        for(int i=ans.size()-1; i>=0; i--)
            cout<<ans[i]<<' ';
        cout<<'\n';
        ans.clear();
    }
    
    return 0;
}
