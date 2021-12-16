#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;

    cin>>t;

    while(t--)
    {
        int n, a, sum=0;

        cin>>n;

        for(int i=0; i<n; i++)
        {
            cin>>a;
            sum+=a;
        }

        cout<<sum<<'\n';
    }

    return 0;
}
