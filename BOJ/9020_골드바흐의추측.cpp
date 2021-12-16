#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool arr[10000];
vector<int> pnum;

bool IsPrime(int n)
{
	vector<int>::iterator iterPos = lower_bound(pnum.begin(), pnum.end(), n);

	if(*iterPos == n) return true;
	else return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin>>t;

	arr[1]=true;
	for(int i=2; i<10000; i++)
		for(int j=2; j*i<10000; j++)
			arr[i*j]=true;
	
	for(int i=2; i<10000; i++)
		if(!arr[i]) pnum.push_back(i);

	while(t--)
	{
		int n, a, b;
		
		cin>>n;

		vector<int>::iterator iterPos = lower_bound(pnum.begin(), pnum.end(), n/2);

		while(1)
		{
			a = *iterPos;
			b = n - a;

			if(IsPrime(b)) break;
			else iterPos--;

			//if(iterPos == pnum.begin()) return 0;
		}

		if(a>b) swap(a, b);

		cout<<a<<' '<<b<<'\n';
	}

	return 0;
}
