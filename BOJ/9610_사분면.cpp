#include <iostream>
#include <cmath>
using namespace std;

int n, ans[5];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	while(n--)
	{
		int x, y;
		cin>>x>>y;

		if(x==0 || y==0) ans[4]++;
		else if(x>0 && y>0) ans[0]++;
		else if(x<0 && y>0) ans[1]++;
		else if(x<0 && y<0) ans[2]++;
		else if(x>0 && y<0) ans[3]++;
	}

	for(int i=0; i<4; i++)
		cout<<'Q'<<i+1<<": "<<ans[i]<<'\n';
	cout<<"AXIS: "<<ans[4]<<'\n';

	return 0;
}
