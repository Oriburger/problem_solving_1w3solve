#include <string>
#include <vector>
#include <stack>
using namespace std;

//board의 k번 행에서 인형을 뽑는다.
int Pick(vector<vector<int>>& board, const int k)
{
    int ret = 0;
    for(int i=0; i<board.size(); i++)
        if(board[i][k])
        {
            ret = board[i][k];
            board[i][k]=0; //뽑으면 빈자리가 돰
            break;
        }
    return ret; //뽑은 인형 번호 반환
}

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    stack<int> stk;
    
    for(auto &k : moves) //한턴씩 진행
    {
        int id = Pick(board, k-1);
        
        if(!id) continue;
        else if(!stk.empty() && stk.top() == id)
        {
            stk.pop();
            answer += 2;
        }
        else
            stk.push(id);
    }
    
    return answer;
}
