#include <iostream>
using namespace std;

int input, sum=0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int i=0; i<4; i++)
	{
		cin>>input;
		sum+=input;
	}
	
	cout<<sum/60<<'\n'<<sum%60<<'\n';
	
	return 0;
}
