#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int n;
vector<int> arr, ans;
vector<P> tmp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n;
	
	ans = arr = vector<int>(n, -1); //-1로 초기화
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
		
		while(!tmp.empty()) //스택에 넣기전에 검사 : arr[i]이 오큰수가 될 수 있는지 판별
		{
			if(tmp.back().second >= arr[i]) break;  //만약 스택의 top보다 이 수가 작다면 break

			ans[tmp.back().first] = arr[i]; //정답을 갱신! 스택의 top보다 크므로 arr[i]는 오큰수
			tmp.pop_back(); 스택 pop
		}
		tmp.push_back({i, arr[i]});	스택에 넣음	
	}
		
	for(auto &p : ans) //정답 출력
		cout<<p<<' ';
	cout<<'\n';
	
	return 0;
}
