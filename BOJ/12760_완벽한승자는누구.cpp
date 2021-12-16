#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int score[101];
vector<int> winner;
vector<vector<int> > card;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	card.resize(n);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			int k; cin>>k;
			card[i].push_back(k);
		}

	for(int i=0; i<n; i++)
		sort(card[i].begin(), card[i].end(), greater<int>());

	for(int r=0; r<m; r++)
	{
		int maxVal = 0;
		winner.clear();

		for(int i=0; i<n; i++)
		{
			if(maxVal < card[i][r])
			{
				maxVal = card[i][r];
				winner.clear();
				winner.push_back(i);
			}
			else if(maxVal == card[i][r])
				winner.push_back(i);
		}

		for(int &p : winner)
			score[p]++;
	}
	winner.clear();

	int maxVal = 0;
	for(int i=0; i<n; i++)
	{		
		if(maxVal < score[i])
		{
			maxVal = score[i];
			winner.clear();
			winner.push_back(i);
		}
		else if(maxVal == score[i])
			winner.push_back(i);
	}
	
	for(int &p : winner)
		cout<<p+1<<' ';

	return 0;
}
