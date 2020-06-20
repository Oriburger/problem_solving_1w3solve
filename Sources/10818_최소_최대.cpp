#include <iostream>
using namespace std;

int main()
{
	int n, maxVal=-987654321, minVal=987654321;
	cin>>n;
	
	while(n--)
	{
		int input;
		cin>>input;
		maxVal = max(maxVal, input);
		minVal = min(minVal, input);
	}
	
	cout<<minVal<<" "<<maxVal<<'\n';
	
	return 0;
}
