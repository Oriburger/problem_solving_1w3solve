#include <iostream>
using namespace std;

int val;
const int coin[6]={500, 100, 50, 10, 5, 1};

int GetAnswer(int cur, int cnt)
{
	if(cur==0)
		return cnt;

	for(int i=0; i<6; i++)
		if(cur-coin[i] >= 0)
			return GetAnswer(cur-coin[i], cnt+1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>val;
	
	cout<<GetAnswer(1000-val, 0)<<'\n';
	
	return 0;
}
