#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, ans=0;

    cin>>n;

    for(int i=0; i<=n; i++)
    {
        ans += i*(i+1)+((i*(i+1))/2);
    }

    cout<<ans<<'\n';
    
    return 0;
}
