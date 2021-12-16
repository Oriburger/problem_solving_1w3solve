#include <cstdio>

int t;
double n;

int main()
{
    scanf("%d", &t);
    
    while(t--)
    {
        scanf("%lf", &n);
    
        printf("$%.2lf\n", n*0.8);
    }

	return 0;
}
