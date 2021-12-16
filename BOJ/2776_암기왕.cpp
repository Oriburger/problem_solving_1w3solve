#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<int> umap;
int t, n, m, temp;

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
			cin>>temp;
			umap.insert(temp);
		}

		cin>>m;
		for(int i=0; i<m; i++)
		{
			cin>>temp;
			if(umap.find(temp)==umap.end())
				cout<<0<<'\n';
			else
				cout<<1<<'\n';
		}
		umap.clear();
	}

	return 0;
}
