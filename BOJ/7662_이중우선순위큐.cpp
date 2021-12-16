#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin>>t;

	while(t--)
	{
		int k; cin>>k;
		multiset<int> arr;

		for(int i=0; i<k; i++)
		{
			char c; int n;
			cin>>c>>n;
			
			if(c=='I')
			{
				arr.insert(n);
			}

			else if(c=='D')
			{
				if(arr.empty())	continue;

				if(n==-1)
					arr.erase(arr.begin());
				else if(n==1)
					arr.erase(std::prev(arr.end()));
			}
		}
		
		if(arr.empty()) cout<<"EMPTY\n";
		else cout<<*(arr.rbegin())<<" "<<*(arr.begin())<<'\n';
	}

	return 0;
}
