#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, minGap;
vector<int> button;
vector<bool> combi;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;

	for(int i=0; i<m; i++)
	{
		int input; cin>>input;
		button.push_back(input);
	}

	do
	{
		int total=0;
		for(int i=0; i<button.size(); i++)
			total += button[i]*pow(10,button.size()-i-1);

		minGap = min(minGap, abs(n-total));
		
	}while(next_permutation(button.begin(), button.end()));

	cout<<minGap<<'\n';

	return 0;
}
