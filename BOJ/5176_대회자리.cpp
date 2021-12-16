#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin>>t;
    
    while(t--)
    {
        int p, m, ans=0;
        vector<bool> arr;
        cin>>p>>m;
        
        arr.resize(m, false);
        
        int input;
        for(int i=0; i<p; i++)
        {
            cin>>input;
            if(arr[input-1]) ans++;
            else arr[input-1]=true;
        }
        
        cout<<ans<<"\n";
        
        arr.clear();
    }
    
    return 0;
}
