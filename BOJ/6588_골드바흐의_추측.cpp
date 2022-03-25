#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000000;

int n, ans;
vector<int> arr;
vector<bool> check(MAX+1, false);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for(int i=2; i<=MAX; i++)
		for(int j=2; i*j<=MAX; j++)
			check[i*j] = true;
			
	for(int i=3; i<=MAX; i++)
		if(!check[i])
			arr.push_back(i);
	
	while(1)
	{
		ans = -1;
		cin>>n;
		if(n==0) break;
		
		for(auto &k : arr)
		{
			if(n < k) break; 
			if(!check[n-k])
			{
				ans = k;
				break;
			}
		}
		
		if(ans==-1) cout<<"Goldbach\'s conjecture is wrong.\n";
		else cout<<n<<" = "<<ans<<" + "<<n-ans<<'\n';
	}
	
	return 0;
}
