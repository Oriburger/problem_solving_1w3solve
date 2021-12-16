#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin>>t;
    vector<int> arr(10, 0);

    while(t--)
    {
        for(int i=0; i<10; i++)
            cin>>arr[i];
        sort(arr.begin(), arr.end(), greater<int>());
        
        cout<<arr[2]<<"\n";
    }
    
    return 0;
}
