#include <iostream>
#include <vector>
using namespace std;

int n; bool flag;
vector<int> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(1)
	{
		cin>>n;
		
		if(n==0) break;
		
		while(n!=0)
		{
			arr.push_back(n%10);
			n/=10;
		}
		
		for(int i=0; i<arr.size()/2; i++)
		{
			if(arr[i]!=arr[arr.size()-i-1])
			{
				flag=true;
				break;
			}
		}
		
		if(flag)
			cout<<"no\n";
		else
			cout<<"yes\n";
			
		arr.clear();
		flag=false;
	}
	
	return 0;
} 
