#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int>::iterator viter;

int n, m;
vector<int> cards;
vector<int> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;

	for(int i=0; i<n; i++)
	{
		int input;
		cin>>input;
		cards.push_back(input);
	}
	sort(cards.begin(), cards.end());

	cin>>m;
	for(int i=0; i<m; i++)
	{
		int input;
		cin>>input;
		arr.push_back(input);
	}

	for(int i=0; i<m; i++)
	{
		viter stIter = lower_bound(cards.begin(), cards.end(), arr[i]);
		viter endIter = upper_bound(cards.begin(), cards.end(), arr[i]);

		if(*stIter != arr[i])
		{
			cout<<0<<' ';
			continue;
		}

		cout<<endIter-stIter<<' ';
	}

	return 0;
}
