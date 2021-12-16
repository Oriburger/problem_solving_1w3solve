#include <bits/stdc++.h>
using namespace std;

int t, n, ans;
vector<int> russia, korea;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>t;

	while(t--)
	{
		cin>>n;
		
		ans = 0;
		russia = korea = vector<int>(n);
		for(int i=0; i<n; i++)	
			cin>>russia[i];
		for(int i=0; i<n; i++)
			cin>>korea[i];
		
		multiset<int> ratings(korea.begin(), korea.end());
		for(int i=0; i<n; i++)
		{
			//레이팅이 가장 높은 한국 선수도 이기지 못하면
			if(*ratings.rbegin() < russia[i])
				ratings.erase(ratings.begin()); //가장 레이팅이 낮은 선수를 내보냄
			else //한 명이라도 이길 수 있는 사람이 존재하면
			{
				ans += 1; //정답 갱신
				ratings.erase(ratings.lower_bound(russia[i])); 
				//russia[i]를 이길수 있는 선수중 레이팅이 가장 낮은 선수를 출전
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}
