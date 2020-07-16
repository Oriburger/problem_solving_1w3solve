#include <iostream>
using namespace std;

int main()
{
	int n, answer=0;

	cin>>n;

	int bonus=0;
	for(int i=0; i<n; i++)
	{
		int input;

		cin>>input;

		if(input==0) bonus=0;

		else
			answer+=input+(bonus++);
	}
	cout<<answer<<'\n';

	return 0;
}
