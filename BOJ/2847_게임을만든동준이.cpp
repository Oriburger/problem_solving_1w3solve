#include <iostream>
using namespace std;

int n, arr[101], ans=0;

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int tmp = arr[n-1]-1;
    for(int i=n-2; i>=0; i--)
     {
        if(arr[i] > tmp)
		{
		    ans += (arr[i]-tmp);
			tmp--;
		}
		else
			tmp = arr[i]-1;
    }
    cout<<ans<<'\n';
    return 0;
}
