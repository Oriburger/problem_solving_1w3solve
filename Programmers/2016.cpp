#include <string>
#include <vector>
using namespace std;

const int month[13] = {0, 31, 29, 31, 30, 31, 30
                        , 31, 31, 30, 31, 30, 31};
const string day[7] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};

string solution(int a, int b)
{
    int temp = 0;
    for(int i=1; i<a; i++)
        temp += month[i];
    
    temp += b;
        
    return day[temp%7];
}
