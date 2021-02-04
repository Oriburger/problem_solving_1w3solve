#include <iostream>
#include <cmath>
using namespace std;

int GetAnswer(int n, int r, int c)
{
	if(n==0) return 0;

	if(pow(2, n-1) <= r)
	{
		if(pow(2, n-1) <= c) //4
			return GetAnswer(n-1, r-pow(2, n-1), c-pow(2, n-1)) + pow(pow(2, n-1), 2)*3;
		else //3
			return GetAnswer(n-1, r-pow(2, n-1), c) + pow(pow(2, n-1), 2)*2;
	}
	else
	{
		if(pow(2, n-1) <= c) //2
			return GetAnswer(n-1, r, c-pow(2, n-1)) + pow(pow(2, n-1), 2);
		else //1
			return GetAnswer(n-1, r, c);
	}

	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, r, c;
	cin>>n>>r>>c;

	cout<<GetAnswer(n, r, c);

	return 0;
}
