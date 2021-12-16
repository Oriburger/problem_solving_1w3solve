#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b, d, ans=0;
	
	cin>>a>>b>>d;
	
	vector<bool> pnum(b+1, false);
	
	pnum[0]=pnum[1]=true;
	for(int i=2; i<=b; i++)
	for(int j=2; i*j<=b; j++)
		pnum[i*j]=true;
	
	cin>>a>>b>>d;
	
	for(int curr=a; curr<=b; curr++)
	{
		if(pnum[curr]) continue;
		
		int temp=curr;
		bool flag=false;
		while(1)
		{
			if(temp<=0) break;
			if(temp%10==d)
			{
				flag=true;
				break;
			}
			temp/=10;
		}
		if(flag) ans++;
	}
	
	cout<<ans<<"\n";

	return 0;
}
