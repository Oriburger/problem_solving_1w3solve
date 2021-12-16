#include <iostream>
using namespace std;

int e, f, c, answer=0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>e>>f>>c;

	while(1)
	{
		if((e+f) < c) break;

		answer = answer + ((e+f)/c);
		e= (e+f) % c + (e+f) / c;
		f=0;
	}

	cout<<answer<<'\n';

	return 0;
}
