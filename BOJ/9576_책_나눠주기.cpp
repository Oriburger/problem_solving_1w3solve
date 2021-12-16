#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int t, n, m;
vector<P> arr; 
vector<bool> check;

bool comp(P& p, P& q) //비교함수
{
	return p.second != q.second ? p.second < q.second 
                                : p.first < q.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>t;

	while(t--)
	{
		cin>>n>>m;

		check = vector<bool>(1001, false);

		for(int i=0; i<m; i++)
		{
			int a, b;
			cin>>a>>b;
			arr.push_back({a, b});
		}
		sort(arr.begin(), arr.end(), comp); //끝 번호를 기준으로 오름차순 정렬 

		int ans = 0;
		for(int i=0; i<m; i++) //정렬된 신청서를 순회 
		{
            //시작번호 ~ 끝번호에서 아직 남아있는 책을 준다.
			for(int j=arr[i].first; j<=arr[i].second; j++) 
			{
				if(!check[j])
				{
					check[j]=true;
					ans++;
					break;
				}
			}
		}
		cout<<ans<<'\n';
		
		arr.clear();
	}

	return 0;
}
