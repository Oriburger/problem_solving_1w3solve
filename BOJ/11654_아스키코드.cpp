#include <cstdio>
using namespace std;

int main()
{
	int c;
	
	scanf("%d", &c);
	
	while(c--)
	{
		double score[1000], cnt=0;
		double n, sum=0, input;
		
		scanf("%d", &n);
		
		for(int i=0; i<n; i++)
		{
			scanf("%lf", &score[i]);
			sum+=score[i];
		}
		sum=sum/n;
		
		for(int i=0; i<n; i++)
		{
			if(score[i] > sum)
				cnt++;
		}
		
		printf("	%.3lf%\n", cnt/n);
	} 
}
