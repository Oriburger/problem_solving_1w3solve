#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int t, n, answer; 
vector<pair<int, int> > score;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>t;
	
	while(t--)
	{
		cin>>n;

		int pos=-1;

		for(int i=0; i<n; i++)
		{
			int a, b; 
			cin>>a>>b;

			if(b==1) pos = a;

			score.push_back({a, b});
		}
		sort(score.begin(), score.end());

		int minVal=score[0].second;
		answer++;
		for(int i=1; i<pos; i++)
		{
			if(minVal > score[i].second)
			{
				answer++;
				minVal = score[i].second;
			}
		}

		cout<<answer<<'\n';

		score.clear();
		answer=0;
	}

	return 0;
}
