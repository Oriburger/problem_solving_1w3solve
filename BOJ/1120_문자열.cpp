#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string a, b;
	int answer=2147000000;

	cin>>a>>b;

	for(int i=0; i<=b.size()-a.size(); i++)
	{
		int cnt=0;
		for(int j=0; j<a.size(); j++)
		{
			if(b[j+i] != a[j]) cnt++;
		}
		answer = min(cnt, answer);
	}

	cout<<answer<<'\n';

	return 0;
}
