#include <iostream>
#include <vector>
using namespace std;

int n, ans;
vector<int> arr;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;

    arr = vector<int>(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int max_val = -1;
    for(int i=arr.size()-1; i>=0; i--)
    {
        if(max_val <= arr[i]) max_val = arr[i];
        else ans += max_val - arr[i];
    }
    cout<<ans<<'\n';

    return 0;
}
