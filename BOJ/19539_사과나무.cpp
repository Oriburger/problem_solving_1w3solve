#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, sum, sum2, tmp;
vector<int> arr;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;

    arr = vector<int>(n);
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        sum2 += arr[i]/2;
        sum += arr[i];
    }
    if(sum%3!=0)
        cout<<"NO\n";
    else
    {
        if(sum2 >= sum/3)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
