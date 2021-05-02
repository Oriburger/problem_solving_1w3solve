#include <string>
#include <vector>
using namespace std;

int cache[100][100];

int solution(int n, vector<vector<int>> results) 
{
    int answer = 0;
    
    for(int i=0; i<results.size(); i++)
    {
        int u = results[i][0]-1;
        int v = results[i][1]-1;
        cache[u][v]=1;
        cache[v][u]=-1;
    }
    
    for(int k=0; k<n; k++)
      for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(cache[i][k]==1 && cache[k][j]==1)
                cache[i][j]=1;
            if(cache[i][k]==-1 && cache[k][j]==-1)
                cache[i][j]=-1;
        }
    
    for(int i=0; i<n; i++)
    {
        int cnt = 0;
        for(int j=0; j<n; j++)
        {
            if(cache[i][j]==0)
                cnt += 1;
        }
        if(cnt == 1)
            answer += 1;
    }
    

    return answer;
}
