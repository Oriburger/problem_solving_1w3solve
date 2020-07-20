#include <cstdio>
using namespace std;

int main()
{
	int t, h, w, n;

	scanf("%d", &t);

	while(t--)
	{
		scanf("%d %d %d", &h, &w, &n);
		
		if(n%h>=10)
			printf("%02d%02d\n", n%h ? n%h : h , n/h + (n%h>0));
		else 
			printf("%d%02d\n", n%h ? n%h : h, n/h + (n%h>0));
	}

	return 0;
}
