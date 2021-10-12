#include <iostream>
#include <string>
#include <vector>
using namespace std;

int board[100][100];

//board 배열을 초기화 --> 이렇게 구현안하고 인자로 계속 전달해도 될듯..
void reset(vector<vector<int>>& lock)
{
    for(int i=30; i<lock.size()+30; i++)
        for(int j=30; j<lock.size()+30; j++)
            board[i][j] = lock[i-30][j-30];
}
//인자로 전달된 key 배열을 회전
vector<vector<int>>& rotate(vector<vector<int>>& key)
{
    vector<vector<int>> temp = key;
    
    for(int i=0; i<key.size(); i++)
        for(int j=0; j<key.size(); j++)
            key[key.size()-j-1][i] = temp[i][j];
    
    return key;
}

//(y, x)에서 key로 lock을 풀 수 있는지 여부 반환
bool can_unlock(vector<vector<int>> &lock,
                vector<vector<int>>& key, const int y, const int x)
{
    //(y,x)에서 key와 lock를 대봄 (더함)
    for(int i=0; i<key.size(); i++)
        for(int j=0; j<key.size(); j++)
            board[i+y][j+x] += key[i][j];
    
    //겹치거나 빈 공간이 있다면, 열리지 않음
    for(int i=30; i<30+lock.size(); i++)
        for(int j=30; j<30+lock.size(); j++)
            if(board[i][j]!=1) return false;
    
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    for(int i=30; i<lock.size()+30; i++)
        for(int j=30; j<lock.size()+30; j++)
            board[i][j] = lock[i-30][j-30];
    
    //총 4번 회전
    for(int i=0; i<4; i++)
    {     
        const int border = 30 + lock.size();
        
        //모든 좌표에서 시도
        for(int y=30-key.size(); y<border; y++)
            for(int x=30-key.size(); x<border; x++)
		        {
		          	reset(lock); //자물쇠 배열을 초기화
		            if(can_unlock(lock, key, y, x))
                    return true;
		        }

        rotate(key);
    }
    return false; 
}
