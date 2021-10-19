#include <string>
#include <vector>
#include <utility>
using namespace std;

struct POS{ int y; int x; }; 

bool check[11][11][11][11];
POS curr = {5, 5};

int solution(string dirs)
{
    int answer = 0;
    
    for(const char &c : dirs)
    {   
        POS next;
        switch(c)
        {
        case 'U':
            next = {curr.y+1, curr.x};
            break;
        case 'D':
            next = {curr.y-1, curr.x};
            break;
        case 'R':
            next = {curr.y, curr.x+1};  
            break;
        case 'L':
            next = {curr.y, curr.x-1};
            break;
        }
        if(next.y < 0 || next.x < 0
           || next.y > 10 || next.x > 10) continue;
        
        answer += !check[curr.y][curr.x][next.y][next.x];
        check[curr.y][curr.x][next.y][next.x]
            = check[next.y][next.x][curr.y][curr.x] = true;
        curr = next;
    }
    
    return answer;
}
