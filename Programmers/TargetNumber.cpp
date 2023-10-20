#include <string>
#include <vector>
using namespace std;

void dfs(int curr, int total, const vector<int>& nums, const int& target, int& ans)
{
    if(curr == nums.size())
    {
        ans += (total == target);
        return;
    }
    dfs(curr+1, total + nums[curr], nums, target, ans);
    dfs(curr+1, total - nums[curr], nums, target, ans);
}

int solution(vector<int> numbers, int target) 
{
    int answer = 0;
    dfs(0, 0, numbers, target, answer);
    return answer;
}
