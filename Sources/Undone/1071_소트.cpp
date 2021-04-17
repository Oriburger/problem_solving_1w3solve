#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr, ans;

void Answer()
{
	vector<int>::iterator iter;
	while(!arr.empty())
	{
		iter = arr.begin();
		for(; iter!=arr.end(); iter++)
		{
			if(ans.empty() || ans.back()+1 != *iter)
			{
				ans.push_back(*iter);
				arr.erase(iter);
				break;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	arr = vector<int>(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];

	sort(arr.begin(), arr.end());

	Answer();

	for(auto &p : ans)
		cout<<p<<' ';

	return 0;
}
