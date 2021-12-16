#include <iostream>
#include <string>
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n;

	while(n--)
	{
		int p, cost=0;
		string str;
		
		cin>>p;

		while(p--)
		{
			int c;
			string input;

			cin>>c>>input;

			if(c>cost)
			{
				cost = c;
				str = input;
			}
		}

		cout<<str<<'\n';
	}

	return 0;
}
