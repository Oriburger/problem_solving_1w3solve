#include <cstdio>
#include <cmath>
using namespace std;

int a, b, c;
double t, ans1, ans2;

int main()
{
	scanf("%d %d %d", &a, &b, &c);

	t = sqrt(pow(b, 2) + pow(c, 2));
	ans1 = a*b/t;
	ans2 = a*c/t;

	printf("%d %d\n", (int) ans1, (int)ans2);

	return 0;
}
