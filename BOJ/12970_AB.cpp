#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, k;
string ans = "-1";

string GetAnswer(int n, int k)
{
    string ret(n, 'B');
    
    if(k==0) 
    {
        ret[n-1] = 'A';
        return ret;
    }
    
    int cnt = 0, total = 0;
    for(int i=0; i<n; i++)
    {        
        int tmp = n-i-(cnt+1);
        if(tmp > 0 && total+tmp <= k)
        {
            ret[i] = 'A';
            total += tmp;
            cnt += 1;
        }
    }
    
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>k; 
    
    if((n/2)*(n/2+n%2) >= k)
        ans = GetAnswer(n, k);        
        
    cout<<ans<<'\n';

    return 0;
}
