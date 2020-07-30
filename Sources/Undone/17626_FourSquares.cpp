#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans=0;
vector<int> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	for(int i=1; i<=n; i++)
	{
		if(i*i > n) break;
		arr.push_back(i*i*(-1));
	}
	sort(arr.begin(), arr.end());

	for(auto p : arr)
		cout<<p<<' ';
	cout<<'\n';

	vector<int>::iterator pos;
	while(n!=0)
	{
		pos = lower_bound(arr.begin(), arr.end(), n*(-1));
		int curr = (*pos)*-1;

		cout<<curr<<','<<n<<'\n';

		if(curr == 1)
		{
			ans+=n;
			break;
		}

		else if(*pos == n)
		{	
			ans++;
			break;
		}
		else
		{
			n-=curr;
			ans++;
		}
	}
	cout<<ans<<'\n';

	return 0;
}
