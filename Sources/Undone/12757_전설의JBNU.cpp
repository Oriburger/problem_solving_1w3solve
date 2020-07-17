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
	map<int, int>::iterator iter = JBNU.lower_bound(key); //key값 이상의 근접키
	map<int, int>::iterator niter = nJBNU.lower_bound(-key); //key값 이하의 근접키

	int diff = abs(key - (iter->first)); //key값과의 차이
	int ndiff = abs(key + (niter->first)); 

	//diff와 ndiff의 차이가 모두 k보다 크다면,
	if(diff > k && ndiff > k) return { };
	
	//둘 중 하나만 k보다 크다면
	else if(diff > k || ndiff > k)
	{
		//key값 이하의 근접키는 k 이하라면,
		if(ndiff <= k)  
			return { -(niter->first) };
		//key값 이상의 근접키는 k 이하라면,
		else if(diff <= k)  
			return { iter->first };
	}
	
	//둘 다 k 이하라면,
	else if(diff <= k && ndiff <= k)
	{
		//key값 이하의 근접키가 더 차이가 적다면,
		if(diff > ndiff) 
			return { -((niter->first))};
		//key값 이상의 근접키가 더 차이가 적다면,
		else if(diff < ndiff)
			return { iter->first };
		//두 근접키의 차이는 같지만, 실제 값은 다르다면,
		else if( iter->first != -(niter->first) )
			return { iter->first, -(niter->first) };
		//두 근접키의 차이도 같고, 실제 키 값도 같다면,
		else return { iter->first };
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
