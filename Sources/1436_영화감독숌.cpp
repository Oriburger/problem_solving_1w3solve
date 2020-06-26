#include <iostream>
#include <vector>
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n;
	
	for(int i=666; i<=4000000; i++)
	{
		int cur=i, cnt=0;
		
		while(cur!=0) 
		{
			if(cur%10==6) cnt++; //6의 개수 cnt
			else
            {
				if(cnt<3) cnt=0; //6이 3개 미만으로 연속될 경우,
            }
			cur/=10;
		}
		if(cnt>=3)	n--; //6이 3개 이상으로 연속될때, n=n-1
		
		if(n==0) //n이 0이 되는게 n번째 수
		{
			cout<<i<<'\n';
			break;
		}
	}
	
	return 0;
} 
