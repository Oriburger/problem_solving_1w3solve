#include <iostream>
#include <vector>
using namespace  std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, answer=1, cnt=1;
	cin>>n;
	vector<int> s(n);

	for(int i=0; i<n; i++) cin>>s[i];

	for(int i=1; i<n; i++)
	{
		if(s[i-1]<=s[i]) cnt++;
		else cnt=1;
		answer = max(answer, cnt);
	}

	cnt=1;
	for(int i=1; i<n; i++)
	{
		if(s[i-1]>=s[i]) cnt++;
		else cnt=1;
		answer = max(answer, cnt);
	}

	cout<<answer<<'\n';
	return 0;
}
