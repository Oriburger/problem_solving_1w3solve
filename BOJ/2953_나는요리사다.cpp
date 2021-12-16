#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int ans=0, ansIdx=0;

	for(int i=0; i<5; i++)
	{
		int sum=0;
		for(int j=0; j<4; j++)
		{
			int input;
			cin>>input;
			sum+=input;
		}
		
		if(ans<sum)
		{
			ans = sum;
			ansIdx = i+1;
		}
	}

	cout<<ansIdx<<' '<<ans<<'\n';

	return 0;
}
