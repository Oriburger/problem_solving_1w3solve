#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int x, level=0, sum=0;

	cin>>x;

	while(sum <= x)
		sum+=(++level);
	
	cout<<sum<<' '<<level<<'\n';

	if(level%2==1)
	{
		int a = level - x - (sum-level+1);
		cout<<a<<'/'<<level-a;
	}

	return 0;
}
