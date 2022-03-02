#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

unordered_set<string> uset;

bool solution(vector<string> phone_book)
{
    sort(phone_book.begin(), phone_book.end());
    
    for(const auto& s : phone_book)
    {
        for(int i=1; i<s.size(); i++)
            if(uset.find(s.substr(0, i)) != uset.end())
                return false;
        uset.insert(s);
    }
    return true;
}
