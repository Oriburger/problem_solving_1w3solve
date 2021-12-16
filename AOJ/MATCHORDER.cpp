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
		
		//한국 선수들을 이진트리 기반 컨테이너 multiset에 넣음
		multiset<int> kor_rating(korea.begin(), korea.end());
		for(const auto& r : russia) //러시아 선수들을 차례로 순회하며:
		{
			if(r > *kor_rating.rbegin()) //해당 러시아 선수가 한국의 모든 선수보다 레이팅이 높다면?
				kor_rating.erase(kor_rating.begin()); //가장 낮은 레이팅의 한국 선수와 매칭
			else //최소 한명이라도 이길 한국 선수가 존재한다면?
			{
				ans = ans + 1; //정답 갱신
				kor_rating.erase(kor_rating.lower_bound(r));
				//r을 이길 수 있는 선수들 중 가장 레이팅이 작은 선수를 고름
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}
