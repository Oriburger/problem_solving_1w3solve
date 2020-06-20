#include <iostream>
#include <cstring>
using namespace std;

int n, answer, box[1001], cache[1001]; 

int lis(int start) //start를 기점으로한 lis의 길이 
{	
	int& ret = cache[start];
	
	if(ret!=-1) return ret;
	
	ret = 1;
	
	for(int next=start+1; next<=n; next++)
	{
		if(box[start]<box[next])
			ret = max(ret, lis(next)+1);
	}
	
	return ret;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	memset(cache, -1, sizeof(cache));
	
	for(int i=1; i<=n; i++)
		cin>>box[i];
	
	for(int i=1; i<=n; i++)
		answer = max(answer, lis(i));
	
	cout<<answer<<'\n';
	
	return 0;
}
