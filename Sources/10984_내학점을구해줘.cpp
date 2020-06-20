#include <cstdio>

int t, n, c, sum=0;
double g, gpa=0;

int main()
{
	scanf("%d", &t);
	
	for(int i=0; i<t; i++)
	{
		scanf("%d", &n);
		for(int j=0; j<n; j++)
		{
			scanf("%d %lf", &c, &g);
			gpa+=(double)c*g;
			sum+=c;
		}
		gpa/=sum;
		printf("%d %.1lf\n", sum, gpa);
		
		sum=0;
		gpa=0;
	}
	
	return 0;
}
