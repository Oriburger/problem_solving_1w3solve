#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int n;
vector<int> arr, ans;

//정렬된 arr을 기반으로 정답 ret를 반환
vector<int> Answer()
{
	vector<int> ret; 

	vector<bool> check(n, false); //ret에 들어갔는지?
	ret.push_back(arr[0]); //가장 작은 수 push
	check[0]=true; //넣었으니 check
	for(int i=0; i<n; i++) 
	{
		if(check[i]) continue;
		
		if(ret.back()+1 != arr[i]) //ret에 들어갈 수 있다면?
		{
			ret.push_back(arr[i]); //ret에 push 
			check[i]=true; //push 한거 체크
			i=0; //처음부터 순회
		}
	}

	if(ret.size()!=n) //아직 push되지 않고 남은게 있다면..?
	{
		vector<int> temp; //temp로 집합
		for(int i=0; i<n; i++) 
			if(!check[i]) temp.push_back(arr[i]);
		
		vector<int>::iterator iter;
		iter = lower_bound(ret.begin(), ret.end(), temp[0]); 
		if(*iter == temp[0]) //남은 수가 이미 ret에 있다면 
			ret.insert(iter, temp.size(), temp[0]); //거기에 insert
		else //없다면? 
		{
			iter = lower_bound(ret.begin(), ret.end(), ret.back()); //들어갈 자리를 찾는다
			ret.insert(iter, temp.size(), temp[0]); //그리고 insert 
		}
	}
	return ret; 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	arr = vector<int>(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];

	sort(arr.begin(), arr.end());
	ans = Answer();

	for(auto &p : ans)
		cout<<p<<' ';

	return 0;
}
