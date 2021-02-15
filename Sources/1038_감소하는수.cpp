#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

vector<ll> arr;

void GetAnswer(ll num)
{
	arr.push_back(num);

	for(int i=0; i<(num==0 ? 10 : num%10); i++)
	{
		if(num==0 && i==0) continue;
		GetAnswer(num*10+i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;

	if(n>=1023) cout<<-1<<'\n';
	else
	{
		GetAnswer(0);
		sort(arr.begin(), arr.end());
		cout<<arr[n]<<'\n';
	}

	return 0;
}
