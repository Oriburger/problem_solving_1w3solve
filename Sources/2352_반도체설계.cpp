#include <iostream>
#include <vector>
#include <algorithm> //std::lower_bound
using namespace std;

const int MIN_INF = -210000000; 

int n, answer;
vector<int> s;
vector<int> arr;  

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
			vector<int>::iterator iterPos = lower_bound(arr.begin(), arr.end(), s[i]);
			*iterPos = s[i];
		}
	}
	
	cout<<arr.size()-1<<'\n';
	
	return 0;
}
