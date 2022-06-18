#include <cstdio>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

double a, b, ans;
double cache[19][19][19];
unordered_set<int> uset = {2, 3, 5, 7, 11, 13, 17};

double Answer(int idx, int p, int q) //idx번째 기회이고, a팀의 점수가 p일때, 두 팀 모두 소수가 아닐 확률
{
    if(idx == 18) return (uset.count(p)==0 && uset.count(q)==0) ? 1.0 : 0.0;
    double& ret = cache[idx][p][q];
    if(ret != -1) return ret;

    ret = 0;
    ret += Answer(idx + 1, p + 1, q) * a * (1-b);
    ret += Answer(idx+1, p+1, q+1) * a * b;
    ret += Answer(idx+1, p, q+1) * b * (1-a);
    ret += Answer(idx+1, p, q) * (1-a) * (1-b);

    return ret;
}

int main()
{
    scanf("%lf %lf", &a, &b);

    a/=100, b/=100;

    fill(&cache[0][0][0], &cache[18][18][19], -1.0);
    ans = 1.0 - Answer(0, 0, 0);
    printf("%.7lf\n", ans);
    
    return 0;
}
