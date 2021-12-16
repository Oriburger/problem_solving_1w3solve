#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef vector<int>::iterator ITERPOS;
typedef pair<int, int> P;

int n;
vector<P> arr;
vector<int> temp;

bool comp(const P& p, const P& q) 
{
	if(p.first == q.first) //LIS에 유리하도록 배치
        return p.second > q.second;
	return p.first < q.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	for(int i=0; i<n; i++)
	{
		int idx, l, r;
		cin>>idx>>l>>r;
		arr.push_back({l, r});
	}
	sort(arr.begin(), arr.end(), comp); //L값에 따라 오름차순 정렬 
	arr.erase(unique(arr.begin(), arr.end()), arr.end()); //중복 제거!!!

	temp.push_back(-1); //이분탐색을 이용한 LIS 길이 찾기 
	for(int i=n-1; i>=0; i--)
	{
		if(temp.back() <= arr[i].second) //크거나 같다면? temp에 push
			temp.push_back(arr[i].second);
		else //작다면? upper_bound 위치를 찾아서 교체
		{ 
			ITERPOS iter = upper_bound(temp.begin(), temp.end(), arr[i].second);
			*iter = arr[i].second;
		}
	}	

	cout<<temp.size()-1<<'\n'; //LIS길이 출력

	return 0;
}
