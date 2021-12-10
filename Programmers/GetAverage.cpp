#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr)
{
    double ret = 0;
    for(const auto &k : arr)
        ret += k;
    return ret/arr.size();
}
