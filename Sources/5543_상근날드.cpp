#include <iostream>
using namespace std;

int burger, beverage;
int input;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	burger = 9999;
	beverage = 9999;
	
	for(int i=0; i<3; i++)
	{
		cin>>input;
		burger = min(input, burger);
	}
		
	for(int i=0; i<2; i++)
	{
		cin>>input;
		beverage = min(input, beverage);
	}
		
	cout<<beverage + burger - 50<<'\n';
	
	return 0;
}
