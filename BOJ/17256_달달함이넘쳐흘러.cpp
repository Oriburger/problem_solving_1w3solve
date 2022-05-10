#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int k[2][3], ans=0;
    for(int i=0; i<2; i++)
        for(int j=0; j<3; j++) 
            cin>>k[i][j];
    
    cout<<k[1][0]-k[0][2]<<' '<<k[1][1]/k[0][1]<<' '<<k[1][2]-k[0][0]<<'\n';
    
    return 0;
}
