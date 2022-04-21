#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, answer = 0;
vector<int> order = {1, 2, 3, 4, 5, 6, 7, 8};
int result[50][9];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<9; j++)
			cin>>result[i][j];
	
	do
	{
		int total_score = 0;
		int curr_idx = 0;
		for(int i=0; i<n; i++) //inning
		{
			int outCnt = 0, score = 0, baseCnt = 0;
			queue<int> baseQue;
			while(outCnt < 3)
			{
				int tmp = result[i][curr_idx < 3 ? order[curr_idx] : (curr_idx > 3 ? order[curr_idx-1] : 0)];
				curr_idx = (curr_idx + 1) % 9;
				
				if(tmp == 0)
				{
					outCnt += 1; 
					continue;
				}
				baseQue.push(1);
				for(int j=0; j<tmp-1; j++)
					baseQue.push(0);
				
				while(baseQue.size()>3)
				{
					score += baseQue.front();
					baseQue.pop();
				}
			}
			total_score += score; 
		}
		answer = max(answer, total_score);
	}while(next_permutation(order.begin(), order.end()));
	
	cout<<answer<<'\n';
	
	return 0;
}
