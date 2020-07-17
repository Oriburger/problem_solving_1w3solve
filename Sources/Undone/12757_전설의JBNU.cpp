#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

typedef vector<int>::iterator viter;

int n, m, k;
map<int, int> JBNU, nJBNU;

vector<int> FindKey(int key)
{
	map<int, int>::iterator iter = JBNU.lower_bound(key);
	map<int, int>::iterator niter = nJBNU.lower_bound(-key);

	//printf("-> %d %d\n", iter->first, niter->first);

	if(abs(key - iter->first) > k && abs(key + (niter->first)) > k) return { };

	else if(abs(key - iter->first) > k || abs(key + (niter->first)) > k  )
	{
		if(abs(key + (niter->first)) <= k)  
			return { -((niter->first)) };
		else if(abs(key + (iter->first)) <= k)  
			return { iter->first };
	}

	else if(abs(key - iter->first) <= k 
			&& abs(key + (niter->first)) <= k)
	{
		if(abs(key - iter->first) > abs(key + (niter->first))) 
			return { -((niter->first))};
		else if(abs(key - iter->first) < abs(key + (niter->first)))
			return { iter->first };
		else return { iter->first, -((niter->first)) };
	}

	return { };
}

void AddData(int key, int val)
{
	//중복 key 입력은 주어지지않음
	JBNU.insert({key, val});
	nJBNU.insert({-key, val});
}

void UpdateData(int key, int val)
{
	//조건을 만족하는 유일한 key가 있다면,
	if(JBNU.count(key)) JBNU[key]=val;
	
	//그렇지 않다면
	else
	{
		vector<int> keyArr = FindKey(key);

		if(keyArr.size() != 1) return;

		else JBNU[keyArr[0]]=val;
	}
}

void PrtData(int key)
{
	//유일한 키가 있다면,
	if(JBNU.count(key)==1)
		cout<<JBNU[key]<<'\n';

	else 
	{
		vector<int> keyArr = FindKey(key);

		if(keyArr.size()==0) cout<<-1<<'\n';
		else if(keyArr.size()==2) cout<<"?\n";
		else if(keyArr.size()==1) cout<<JBNU[keyArr[0]]<<'\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m>>k;
	
	//초기 데이터 입력
	for(int i=0; i<n; i++)
	{
		int key, value;
		cin>>key>>value;
		
		AddData(key, value);
	}
	
	//명령 횟수 입력
	while(m--)
	{
		int cmd, key, value;
		cin>>cmd>>key;
		
		if(cmd==1)
		{
			cin>>value;
			AddData(key, value);
		}
		else if(cmd==2)
		{
			cin>>value;		
			UpdateData(key, value);
		}
		else if(cmd==3)
			PrtData(key);
	}

	
	return 0;
}
