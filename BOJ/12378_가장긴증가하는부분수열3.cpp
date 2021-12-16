#include <iostream>
#include <vector>
#include <algorithm> //std::lower_bound
using namespace std;

const long long MIN_INF = -1000000001; 

int n, answer;
vector<long long> s;
vector<long long> arr;  

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	arr.push_back(MIN_INF);
	for(int i=0; i<n; i++)
	{
		int input; cin>>input;
		s.push_back(input);
	}
	
	for(int i=0; i<n; i++)
	{
		if(arr.back() < s[i])
			arr.push_back(s[i]);
		
		else
		{
			vector<long long>::iterator iterPos = lower_bound(arr.begin(), arr.end(), s[i]);
			*iterPos = s[i];
		}
	}
	
	cout<<arr.size()-1<<'\n';
	
	return 0;
}
