#include <cstdio>

int main()
{
	short a, b;
	
	while(1)
	{
		scanf("%hd %hd", &a, &b);

		if(a==0 && b==0) break;

		printf("%d\n", a+b);
	}

	return 0;
}
