#include <iostream>
using namespace std;

const int MAX = 1000000000;
double x, y;
int z, lo=1, hi=MAX, mid, val;

int GetIntValue(double k) { return k; }

int main()
{
	cin>>x>>y;

	z=GetIntValue(100*y/x);

	while(lo<=hi)
	{
		mid = (lo+hi)/2;
		
		val = GetIntValue(100*(y+mid)/(x+mid));

		if(val > z) hi = mid-1;
		else lo = mid+1;
	}

	if(hi == MAX) cout<<-1<<'\n';
	else if(val == z) cout<<mid+1<<'\n';
	else cout<<mid<<'\n';

	return 0;
}
