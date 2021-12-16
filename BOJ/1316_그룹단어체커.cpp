#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, ans;
string input;
vector<bool> check;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n; 
	
	while(n--)
	{
		check.resize(26, false);
		
		cin>>input;
		
		bool flag=false;
		for(int i=0; i<input.size(); i++)
		{
			int st, fin;
			
			st=input.find(input[i]);
			fin=input.rfind(input[i]);
			
			for(int j=st; j<=fin; j++)
				if(input[j] != input[i])
				{
					flag=true;
					break;
				}
			
			if(flag) break;
		}
		
		if(!flag) ans++;
		
		check.clear();
		input.clear();
	}
	
	cout<<ans<<'\n';
		
	return 0;
}
