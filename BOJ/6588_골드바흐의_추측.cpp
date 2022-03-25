#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000000;

int n, p, q;
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
		bool flag = false; 
		
		cin>>n;
		if(n==0) break;
		
		for(auto &k : arr)
		{
			p = k;
			q = *lower_bound(arr.begin(), arr.end(), n-k);
			
			if(p+q==n)
			{
				flag = true;
				break; 
			}
		}
		
		if(!flag) cout<<"Goldbach\'s conjecture is wrong.\n";
		else cout<<n<<" = "<<p<<" + "<<q<<'\n';
	}
	
	return 0;
}
