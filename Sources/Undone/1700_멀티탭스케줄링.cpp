#include <iostream>
#include <vector>
using namespace std;

int n, k, mtap, ans=0; //n, k, 멀티탭 남은 칸 수, 정답
vector<int> schedule; //장치 사용 순서
vector<bool> check; //현재 멀티탭에 꼽혀 있는지? 
vector<int> cnt;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>k;
	
	mtap=n;
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
		if(check[schedule[i]]) //schedule[i]가 이미 꽂혀 있는 경우 
		{
			cnt[schedule[i]]--;
			continue;
		}
		
		else if(mtap>0)  //구멍이 남아있는 경우 
		{
			check[schedule[i]]=true;
			mtap--;
			cnt[schedule[i]]--;
		}
		else //구멍이 남아있지 않은 경우 
		{	
			int minUse = 999; 
			int minUseIdx = 0;
			
			for(int j=1; j<=k; j++) 
			{
				if(check[j] && cnt[j]<minUse)
				{
					minUseIdx = j;
					minUse = cnt[j];
				}
			}
			
			if(minUse==0) //앞으로 사용하지 않을 장치라면, 
			{
				ans++;
				check[minUseIdx] = false;
				check[schedule[i]] = true;	
				cnt[schedule[i]]--;
				
				//cout<<minUseIdx<<" pop!\n";
			}
			
			//꼽혀있는 장치들 중에, 그런 장치가 없다면
			//가장 마지막에 쓸 장치를 뽑는다. 
			else  
			{
				for(int j=k-1; j>i; j--)
				{
					if(check[schedule[j]])
					{
						ans++;
						check[schedule[j]] = false;
						check[schedule[i]] = true;	
						cnt[schedule[i]]--;
						
						//cout<<schedule[j]<<" pop!\n";
						
						break;
					}
				}
			}
		}
		//cout<<schedule[i]<<" push!\n";
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
