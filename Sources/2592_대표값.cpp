#include <iostream>
using namespace std;

int check[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int mean=0, mode=0, modeVal=-999;

	for(int i=0; i<10; i++)
	{
		int input;
		cin>>input;
		
		mean+=input;
		check[input/10]++;
	}

	cout<<mean/10<<'\n';

	for(int i=1; i<=100; i++)
	{
		if(check[i] > modeVal)
		{
			modeVal = check[i];
			mode = i*10;
		}
	}
	cout<<mode<<'\n';
	
	return 0;
}
