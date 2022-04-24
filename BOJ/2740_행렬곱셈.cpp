#include <iostream>
using namespace std;

int a[100][100], b[100][100], ans[100][100];
int n, m, k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>a[i][j];
    
    cin>>m>>k;
    for(int i=0; i<m; i++)
        for(int j=0; j<k; j++)
            cin>>b[i][j];
            
    for(int h=0; h<m; h++)
        for(int i=0; i<n; i++)
            for(int j=0; j<k; j++)
                ans[i][j] += a[i][h] * b[h][j];
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<k; j++)
        {
            cout<<ans[i][j]<<' ';       
        }
        cout<<'\n';
    }
    
    return 0;
}
