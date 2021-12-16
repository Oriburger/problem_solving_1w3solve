#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<bool> chk;
vector<int> arr;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin>>n;

	chk.resize(2002, false);
	for(int i=0; i<n; i++)
	{
		int input=0;
		cin>>input;
		if(!chk[input+1000])
		{
			chk[input+1000]=true;
			arr.push_back(input);
		}
	}
	sort(arr.begin(), arr.end());

	for(auto &p : arr)
		cout<<p<<' ';

	return 0;
}
