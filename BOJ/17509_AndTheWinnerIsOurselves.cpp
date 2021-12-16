#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

vector<P> arr;

int GetAnswer(int curr, int ret, int t)
{
	if(curr>arr.size()) return ret;
	
	ret += t + 20*arr[curr].second;
	t += arr[curr].first;
	
	return GetAnswer(curr+1, ret, t);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int i=0; i<11; i++)
	{
		int di, vi; //di is the amount of minutes required to solve the i-th problem.
				      	//vi is the number of incorrect verdicts on the i-th problem.
		cin>>di>>vi;
		
		arr.push_back({di, vi}); 
	}
	sort(arr.begin(), arr.end());
	
	cout<<GetAnswer(0, 0, 0);
	
	return 0;
}
