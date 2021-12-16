#include <iostream>
using namespace std;

const int MAX_N = 1000000000;
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;

	if(n==1)
	{
		cout<<1<<'\n';
		return 0;
	}

	int sum=1;
	for(int i=1; i<=MAX_N/6; i++)
	{
		sum = sum + 6*i;
		if(sum >= n)
		{
			cout<<i+1<<'\n';
			break;
		}
	}

	return 0;
}
