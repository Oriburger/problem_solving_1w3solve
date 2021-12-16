#include <cstdio>
using namespace std;

int arr[5], answer=0;

int main()
{
	for(int i=0; i<5; i++)
	{
		scanf("%d", &arr[i]);
		
		answer+=arr[i]*arr[i];
	}
	
	answer=answer%10;
	
	printf("%d\n", answer);
	
	return 0;
}
