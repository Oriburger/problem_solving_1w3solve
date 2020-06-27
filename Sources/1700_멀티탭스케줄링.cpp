#include <iostream>
#include <vector>
using namespace std;

int n, k, remaining, ans=0; //n, k, 멀티탭 남은 칸 수, 정답
vector<int> schedule; //장치 사용 순서
vector<bool> check; //현재 멀티탭에 꼽혀 있는지? 
vector<int> cnt; //장치별 스케쥴링 될 총 횟수

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>k;
	
	remaining=n;
	check.resize(k+1);
	cnt.resize(k+1);
	for(int i=0; i<k; i++)
	{
		int input;
		cin>>input;
		schedule.push_back(input);
		cnt[input]++;
	}
	
	for(int i=0; i<k; i++)
	{
		//이미 사용중인게 아니고, 공간이 남지 않았을 경우
		if(!check[schedule[i]] && remaining==0)
		{
			bool flag = false;
			int lastIdx = 0;
			
			//현재 꽂혀 있고, 추후 사용하지 않을 장치인 경우
			for(int j=1; j<=k; j++) 
			{
				if(check[j] && cnt[j]==0)
				{
					check[j]=false; //해당 장치를 뽑는다.
					flag = true; ans++;
					break;
				}
			}

			if(!flag) //현재 꽂혀있는 장치들이 모두 사용될 예정인 경우
			{
				int z=0;
				bool visited[100]={false}; //중복 체크
				for(int j=i+1; j<k; j++)
				{
					if(check[schedule[j]] && !visited[schedule[j]])
					{
						lastIdx = schedule[j];
						visited[schedule[j]]=true;
						z++;
					}
					if(z==n) break;
				}
				ans++;
				
				check[lastIdx]=false;
			}
		}
		if(!check[schedule[i]] && remaining>0 ) remaining--;

		check[schedule[i]]=true; 
		cnt[schedule[i]]--;
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
