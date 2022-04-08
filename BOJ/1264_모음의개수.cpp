#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int n;
vector<char> arr = {'a', 'e', 'i', 'o', 'u'};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(1)
	{
		string tmp;
		int ans = 0;
		getline(cin, tmp);
		
		if(tmp == "#") break;
		
		for(auto &p : tmp)
			for(auto &c : arr)
				if(tolower(p)==c) ans += 1;
		
		cout<<ans<<'\n';
	}
	
	return 0;
}
