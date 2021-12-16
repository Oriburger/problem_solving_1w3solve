#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, cnt=0, answer=0;
	//bool -flag = false;
	string s;

	cin>>n>>m>>s;

	for(int i=1; i<m-1; i++)
	{	
		if(s[i-1]=='I' && s[i+1]=='I' && s[i]=='O')
		{
			cnt++;
			if(cnt==n)
			{
				answer++;
				cnt-=1;
			}
			i+=1;
			continue;
		}
		
		else
			cnt=0;
	}
	cout<<answer<<'\n';
	
	return 0;
}
