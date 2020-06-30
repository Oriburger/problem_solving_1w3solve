#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int answer=0;
bool flag = false;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while(1)
	{
		arr.clear();
		answer=0;
		
		while(1)
		{
			int n; cin>>n;
			
			if(n==0) break;
			else if(n==-1)
			{
				flag = true;
				break;
			}
			
			arr.push_back(n);			
		}
		
		if(flag) break;
		
		sort(arr.begin(), arr.end());
		

		for(int i=0; i<arr.size()-1; i++)
		{
			for(int j=i+1; j<arr.size(); j++)
			{
				if(arr[i]*2==arr[j]) answer++;
				else if(arr[i]*2<arr[i]) break;
			}
		}
		cout<<answer<<'\n';
		
	}
	
	return 0;
}
