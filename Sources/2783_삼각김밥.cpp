#include <cstdio>
#include <algorithm>
using namespace std;

int n;
double x, y, minCost=99999;

int main()
{
	scanf("%lf %lf", &x, &y); //y그램당 x원  
	
	scanf("%d", &n);
	
	minCost = min(minCost, x/y);
	
	for(int i=0; i<n; i++)
	{
		double a, b;
		scanf("%lf %lf", &a, &b);
		
		minCost = min(minCost, a/b);
	}
	
	printf("%.2lf", minCost*1000);
	
	return 0;
}
