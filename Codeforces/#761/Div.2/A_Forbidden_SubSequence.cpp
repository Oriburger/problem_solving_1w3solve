//https://codeforces.com/contest/1617/problem/A

#include <bits/stdc++.h>
using namespace std;

string s, t, ans, tmp;
int total = 0;
vector<int> cnt;
const vector<int> seq = {0, 2, 1};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int k; cin>>k;

	while(k--)
	{
		cin>>s>>t;

		sort(s.begin(), s.end());
		cnt = vector<int>(3, 0);
		
		if(s.size()<3) ans = s;
		else
		{
			for(const auto &c : s)
			{
				if(c > 'c')
				{
					tmp += c;
					continue;
				}
				cnt[c-'a']++;
				total++;
			}

			if(total == 0 || t!="abc" || cnt[0]==0) ans = s;
			else
			{
				for(auto &i : seq)
					for(int j=0; j<cnt[i]; j++)
						ans += (i+'a');
				
				ans += tmp;
			}
		}

		cout<<ans<<'\n';

		ans = tmp = "";
	}

	return 0;
}
