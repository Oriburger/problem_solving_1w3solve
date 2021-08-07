#include <string>
#include <vector>

using namespace std;

string solution(string pnum)
{
    for(int i=0; i<pnum.size()-4; i++)
        pnum[i] = '*';
    return pnum;
}
