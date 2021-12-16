#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

//typedef pair<int, int> P;

struct Node{ int dist; int cnt; int clip; };

const int MAX = 1001;
const int INF = 2147000000;

int s, ans, visited[MAX][MAX]; //display, clipboard
queue<Node> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>s;

	q.push({0, 1, 0});
	while(!q.empty())
	{
		Node curr = q.front();
		q.pop();

		//cout<<curr.cnt<<' '<<curr.clip<<'\n';
		if(curr.cnt == s)
		{
			ans = curr.dist;
			break; 
		}

		/*------push -------*/
		//새로 복사
		if(!visited[curr.cnt][curr.cnt])
		{
			q.push({curr.dist + 1, curr.cnt, curr.cnt});
			visited[curr.cnt][curr.cnt] = true;
		}
		//하나를 지움
		if(curr.cnt - 1 > 0
				 && !visited[curr.cnt - 1][curr.clip])
		{
			q.push({curr.dist + 1, curr.cnt - 1, curr.clip});
			visited[curr.cnt - 1][curr.clip] = true;
		}
		//그대로 붙여넣음
		if(curr.cnt + curr.clip <= s
				 && !visited[curr.cnt + curr.clip][curr.clip])
		{
			q.push({curr.dist + 1, curr.cnt + curr.clip, curr.clip});
			visited[curr.cnt + curr.clip][curr.clip] = true;
		}
	}

	cout<<ans<<'\n';

	return 0;
}

/* ---- Dynamic Programming 을 이용한 풀이 ---- 

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1001;
const int INF = 2147000000;

int s, cache[MAX][MAX]; //display, clipboard

int GetAnswer(int display, int clip)
{
	if(display < 0 || display >= MAX || clip >= MAX) return INF;
	if(display == s) return 0;

	int &ret = cache[display][clip];
	if(ret != -1) return ret;

	ret = INF;
	ret = min(ret, GetAnswer(display, display)+1);
	ret = min(ret, GetAnswer(display-1, clip)+1);
	ret = min(ret, GetAnswer(display+clip, clip)+1);

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>s;

	memset(cache, -1, sizeof(cache));
	cout<<GetAnswer(1, 0)<<'\n';

	return 0;
}

*/
