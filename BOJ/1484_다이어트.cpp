#include <iostream>
using namespace std;

typedef unsigned long long ull;

const ull MAX_G=1000000;
ull g, val=0, st=1, fin=1;
bool flag = false;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>g;

	while(1)
	{
		val = fin*fin-st*st;
		if(val > g && fin-st==1) break;
		else if(val==g)
		{
			cout<<fin<<'\n';
			flag = true;
		}

		if(val > g) st++;
		else fin++;
	}

	if(!flag) cout<<-1<<'\n';

	return 0;
}
