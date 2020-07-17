#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int i, n, k;

    cin>>n>>k;

    for(i=1; i<=n; i++)
    {
        if(n%i==0)
        {
            k--;
            if(k==0) break;
        }
    }

    if(k==0)    
        cout<<i<<'\n';
    else
        cout<<0<<'\n';

    
    return 0;
}
