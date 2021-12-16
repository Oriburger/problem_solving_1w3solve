#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int x, level=0, sum=0;

	cin>>x;

	while(sum < x) sum+=(++level);

	if(level%2==1)
	{
		int a = level - (x - (sum-level+1));
		cout<<a<<'/'<<level-a+1;
	}

	else
	{
		int a = level - (x - (sum-level+1));
		cout<<level-a+1<<'/'<<a;
	}

	return 0;
}
