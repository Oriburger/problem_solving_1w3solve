#include <bits/stdc++.h>
using namespace std;

struct Road{ int cost; int u; int v; };
bool Comp(const Road& r1, const Road& r2){ return r1.cost > r2.cost; }
const int INF = 1000000000;

int n, ans, dist[20][20], adj[20][20]; //dist : 입력, adj : 빈 그래프
vector<Road> order;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			cin>>dist[i][j];
			if(i < j) order.push_back({dist[i][j], i, j}); //양방향 간선이니 절반의 정보만 필요
		}

	sort(order.begin(), order.end(), Comp); //내림차순 정렬 (pop.back)
	fill(&adj[0][0], &adj[19][19], INF); //빈 그래프를 INF로 채움

	while(!order.empty()) //간선 목록이 빌 때 까지 반복
	{
		Road curr = order.back(); //가장 작은 간선을 뺀다
		order.pop_back();

        //이미 최단거리라면? continue;
		if(adj[curr.u][curr.v] == dist[curr.u][curr.v]) continue;
        
        //반드시 필요한 간선이므로 정답에 더하고, 빈 그래프에 추가 
		ans += curr.cost;
		adj[curr.u][curr.v] = adj[curr.v][curr.u] = curr.cost;
        
        //플로이드-워셜
		for(int k=0; k<n; k++)
			for(int u=0; u<n; u++)
				for(int v=0; v<n; v++)
					if(u!=v && adj[u][v] > adj[u][k] + adj[k][v])
						adj[u][v] = adj[u][k] + adj[k][v];

		bool flag = false;
		for(int u=0; u<n; u++) //원래의 그래프와 비교
			for(int v=0; v<n; v++)
			{
				if(u==v || adj[u][v]==0) continue;
				if(adj[u][v] < dist[u][v]) //불가능한 경우라면? 
					flag = true;
			}
		if(flag){ ans = -1; break; } //정답은 -1
	}

	cout<<ans<<'\n';
	
	return 0;
}


/* 더 빠른 방법 O(n^3)
#include <bits/stdc++.h>
using namespace std;

int n, dist[20][20];
bool check[20][20];

int GetAnswer()
{
	int ret = 0;
	for(int k=0; k<n; k++)
		for(int u=0; u<n; u++)
			for(int v=0; v<n; v++)
			{
				if(u==v || k==u || k==v) continue; 
                //불가능한 상황 -1 반환 
				else if(dist[u][v] > dist[u][k] + dist[k][v]) return ret = -1; 
                //반드시 필요하지 않은 간선 체크 해제
				else if(dist[u][v] == dist[u][k] + dist[k][v]) check[u][v] = check[v][u] = false; 
			}
	
	for(int u=0; u<n; u++) //간선들을 순회하며
		for(int v=u+1; v<n; v++) 
			if(check[u][v]) ret += dist[u][v]; //반드시 필요한 간선들의 cost를 더함

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>dist[i][j];

	memset(check, true, sizeof(check)); //처음은 모두 필요한것으로 체크
	
	cout<<GetAnswer()<<'\n';
	
	return 0;
}



*/
