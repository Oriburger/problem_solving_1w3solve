#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n; 
    cin>>n;
    
    n/=4;
    for(int i=0; i<n; i++)
        cout<<"long ";
    cout<<"int\n";
    
    return 0;
}
