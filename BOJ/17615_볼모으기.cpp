#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, ans = 1e9;
	string str;
	
	cin>>n>>str; 
	
	for(int i=0; i<2; i++)
	{
		const char target = (i == 0 ? 'R' : 'B');
		
		bool flag[2] = {0};
		int count[2] = {0};
		for(int j=0; j<str.size(); j++)
		{
			if(str[j] != target)
				flag[0] = true;
			else if(flag[0])
				count[0] += 1;
				
			if(str[str.size()-j-1] != target)
				flag[1] = true;
			else if(flag[1])
				count[1] += 1;
		}
		ans = min(ans, min(count[0], count[1]));
	}
	cout<<ans<<'\n';
	
	return 0;
}
