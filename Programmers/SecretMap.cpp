#include <string>
#include <vector>
using namespace std;

bool board[16][16];

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    vector<string> answer = vector<string>(n, string(n, ' '));

    for(int k=0; k<2; k++)
    {
        vector<int> arr;
        
        if(k==0) arr = arr1;
        else arr = arr2;
        
        for(int i=0; i<n; i++)
            for(int j=1; j<=n; j++)
            {
                if(answer[i][n-j]!='#')
                    answer[i][n-j] = arr[i]%2 ? '#' : ' ';
                arr[i]/=2;
            }
    }
    
    return answer;
}
