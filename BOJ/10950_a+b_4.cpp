#include <cstdio>
using namespace std;

int main()
{
	int t, a, b;
	
	while(1)
	{
		t = scanf("%d %d", &a, &b);
		
		if(t == EOF) break;
		
		printf("%d\n", a+b);
	}
	
	return 0;
}
