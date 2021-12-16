#include <iostream>
using namespace std;

int a, b, x, y;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>a>>b;
    
    if((a+b)%2!=0 || (a-b)%2!=0)
    {
        cout<<-1<<endl;
        return 0;
    }
    
    x=(a+b)/2;
    y=(a-b)/2;
    
    if(x<y) swap(x,y);
    
    if(x<0 || y<0)
        cout<<-1<<endl;
    else
        cout<<x<<' '<<y<<endl;
    
    return 0;
}
