#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int w[31], ball[8];
bool cache[31][15001];
vector<char> ans;

void GetAnswer(int idx, int curr)
{
	if(idx > n) return; //더 이상 추가할 추가 없다면

	bool &ret = cache[idx][curr];
	if(ret) return; //이미 찾은 무게라면?
 
	ret = true;

	GetAnswer(idx+1, curr); //이 추는 담지 않을래
	GetAnswer(idx+1, curr+w[idx]); //아냐, 담자 
	GetAnswer(idx+1, abs(curr-w[idx])); //음,, 구슬쪽에 담아야겠어. 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	for(int i=0; i<n; i++) 
		cin>>w[i];
	
	cin>>m;
	for(int i=0; i<m; i++)
		cin>>ball[i];
	
	GetAnswer(0, 0); //만들 수 있는 무게를 전부 찾기 
	for(int i=0; i<m; i++)
	{
		//만약 추로 만들 수 있는 무게를 초과한다면? 'N'
		//추의 최대 무게 * 추의 최대 개수 = 500 * 30 = 15000
		if(ball[i] > 15000) 
		{
			ans.push_back('N'); 
			continue;
		}

		if(cache[n][ball[i]]==1) //추의 무게를 찾을 수 있다면 'Y'
			ans.push_back('Y');
		else 					 //찾을수가 없다.. 'N'
			ans.push_back('N');
	}

	for(auto &p : ans) //정답 출력
		cout<<p<<' ';

	return 0;
}
