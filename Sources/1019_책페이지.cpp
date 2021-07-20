#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

typedef vector<int>::iterator ITER;

int n, head = 1, tail, squ = 1;
vector<int> ans(10, 0);

void subCalc(int num, int squ_tmp)
{
	while(num)
	{
		ans[num%10] += squ_tmp;
		num/=10;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	tail = n;
	while(head <= tail)
	{
		while(head%10 != 0 && head<=tail)
			subCalc(head++, squ);
		
		if(tail < head) break;

		while(tail%10 != 9 && head<=tail)
			subCalc(tail--, squ);

		head /= 10;
		tail /= 10;

		for(int i=0; i<10; i++)
			ans[i] += (tail-head+1) * squ;
		squ *= 10;
	}

	for(int i=0; i<10; i++)
		cout<<ans[i]<<' ';

	return 0;
}
