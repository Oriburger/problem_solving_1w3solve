#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

struct Town
{
	int from;
	int to;
	int cnt;
};

bool comp(const Town& t1, const Town& t2)  //도착 지점을 기준으로 오름차순 정렬
{
	if(t1.to == t2.to) //도착 지점이 같다면? 시작 지점을 기준으로 오름차순 정렬
    return t1.from < t2.from;
	return t1.to < t2.to;
}

int n, c, m, ans = 0;
int capacity[2001];
vector<Town> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>c>>m;
	
	for(int i=0; i<m; i++)
	{
		int f, t, c;
		cin>>f>>t>>c;
		arr.push_back({f, t, c});	
	}
	sort(arr.begin(), arr.end(), comp); //comp 함수 기반으로 정렬

	for(const auto &curr : arr)
	{
		int max_box = 0; // [curr.from, curr.to]에 가장 많이 적재된 박스 수
		for(int i = curr.from; i < curr.to; i++) 
			max_box = max(max_box, capacity[i]);
		
		int extra = min(curr.cnt, c - max_box); //추가로 적재할 수 있는 박스 수
		for(int i = curr.from; i < curr.to; i++)
			capacity[i] += extra; //[curr.from, curr.to] 구간에 추가 적재 박스 수를 더함

		ans += extra; //정답 갱신
	}

	cout<<ans<<'\n';

	return 0;
}
