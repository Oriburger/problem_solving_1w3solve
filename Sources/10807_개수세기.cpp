#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, v, ans=0;
vector<int> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		int input; cin>>input;
		arr.push_back(input);
	}
	sort(arr.begin(), arr.end());

	cin>>v;

	vector<int>::iterator a = lower_bound(arr.begin(), arr.end(), v);
	vector<int>::iterator b = upper_bound(arr.begin(), arr.end(), v);

	if(*a > v || a==arr.end()) cout<<0<<'\n';
	else cout<<b-a<<'\n';

	return 0;
}
