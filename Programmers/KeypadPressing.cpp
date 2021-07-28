#include <string>
#include <queue>
#include <vector>
using namespace std;

struct Pos{ int y; int x; };
Pos left={3,0}, right={3,2};

int GetDist(Pos A, Pos B)
{
    return abs(A.y-B.y) + abs(A.x-B.x);
}

char GetNextHand(int k, string hand)
{
    if(k==1 || k==4 || k==7)
    {
        if(k==1) left = {0, 0};
        else if(k==4) left = {1, 0};
        else left = {2, 0};
        return 'L';
    }
    
    else if(k==3 || k==6 || k==9)
    {
        if(k==3) right = {0, 2};
        else if(k==6) right = {1, 2};
        else right = {2, 2};
        return 'R';
    }
    
    int dist_l=0, dist_r=0;
    Pos k_pos={0, 0};
    
    if(k==2) k_pos = {0, 1};
    else if(k==5) k_pos = {1, 1};
    else if(k==8) k_pos = {2, 1};
    else if(k==0) k_pos = {3, 1};
    
    dist_l = GetDist(left, k_pos);
    dist_r = GetDist(right, k_pos);
    
    if(dist_l < dist_r)
    {
        left = k_pos;
        return 'L';
    }
    else if(dist_l > dist_r)
    {
        right = k_pos;
        return 'R';
    }
    
    left = (hand=="left" ? k_pos : left);
    right = (hand=="left" ? right : k_pos);
    return (hand=="left" ? 'L' : 'R');
}

string solution(vector<int> numbers, string hand)
{
    string ans = "";
    
    for(auto &n : numbers)
        ans.push_back(GetNextHand(n, hand));
    
    return ans;
}
