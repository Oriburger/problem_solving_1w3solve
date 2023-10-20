#include <string>
#include <cstring>
#include <vector>
using namespace std;

int cache[500][500];

int solution(vector<vector<int>> triangle) 
{
    int answer = 0;
    memset(cache, 0, sizeof(cache));
    
    cache[0][0] = triangle[0][0];
    for(int i=1; i<triangle.size(); i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j==0) cache[i][j] = cache[i-1][j] + triangle[i][j];
            else if(j==i) cache[i][j] = cache[i-1][j-1] + triangle[i][j];
            else cache[i][j] = max(cache[i][j], max(cache[i-1][j], cache[i-1][j-1]) + triangle[i][j]);
            answer = max(answer, cache[i][j]);
        }
    }
    return answer;
}
