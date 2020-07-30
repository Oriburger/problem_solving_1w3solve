#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef map<string, int> Map;

int t, n, ans=0;
string a, b;
Map m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>t;

	while(t--)
	{
		cin>>n;

		for(int i=0; i<n; i++)
		{
			cin>>a>>b;

			if(m.count(b)==0) m[b]=1;
			else m[b]=m[b]+1;
		}

		ans=1;
		for(Map::iterator i = m.begin(); i!=m.end(); i++)
			ans *= (i->second+1);

		cout<<ans-1<<'\n';
        
		m.clear();
		ans=0;
	}

	return 0;
}
