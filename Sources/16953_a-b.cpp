#include <iostream>
using namespace std;

int a, b;
bool flag = false;

int GetAnswer(int b)
{
	int cnt = 0;
	while(1)
	{
		if(b<a) return -1;
		if(b==a) break;

		if(b%2==0)
		{
			b/=2;
			cnt++;
		}
		else if(b%10==1)
		{
			b/=10;
			cnt++;
		}
		else
			return -1;
	}
	return cnt+1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>a>>b;

	cout<<GetAnswer(b)<<'\n';

	return 0;
}
