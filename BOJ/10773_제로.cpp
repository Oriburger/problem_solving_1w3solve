#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, input;
	long long answer=0;
	vector<int> arr;

	cin>>n;

	for(int i=0; i<n; i++)
	{
		cin>>input;
		
		if(input==0)
		{
			if(!arr.empty()) 
				arr.pop_back();
		}

		else arr.push_back(input);
	}

	for(int i=0; i<arr.size(); i++)
		answer += arr[i];
	
	cout<<answer<<'\n';

	return 0;
}
