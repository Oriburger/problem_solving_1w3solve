#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int a=0, b[3], answer=0;
			
	scanf("%d", &a);
	scanf("%1d%1d%1d", &b[0], &b[1], &b[2]);
	
	for(int i=2; i>=0; i--)	
	{
		printf("%d\n", a*b[i]);
		answer = answer + (a*b[i]) * pow(10, 2-i);
	}
	
	printf("%d\n", answer);
	
	return 0;
} 
