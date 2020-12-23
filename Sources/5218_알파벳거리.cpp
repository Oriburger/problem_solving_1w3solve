#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; 
	vector<int> ans;
	string str1, str2;

	cin>>n;

	while(n--)
	{
		cin>>str1>>str2;

		for(int i=0; i<str1.length(); i++)
		{
			if(str1[i] <= str2[i])
				ans.push_back((str2[i]-'a')-(str1[i]-'a'));
			else 
				ans.push_back((str2[i]-'a'+26)-(str1[i]-'a'));
		}

		cout<<"Distances: ";
		for(auto &p : ans)
			cout<<p<<' ';
		cout<<'\n';

		ans.clear();
	}
	
	return 0;
}
