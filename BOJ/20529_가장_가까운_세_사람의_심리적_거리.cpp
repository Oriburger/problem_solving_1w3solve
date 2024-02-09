#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

int n, t, dist[16][16];
unordered_map<string, int> umap;
const string str[16] = {"ISTJ", "ISFJ", "INFJ", "INTJ", "ISTP", "ISFP", "INFP", "INTP"
						, "ESTP", "ESFP", "ENFP", "ENTP", "ESTJ", "ESFJ", "ENFJ", "ENTJ"};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>t;
	
	for(int i=0; i<16; i++)
		umap[str[i]] = i;
	
	for(int i=0; i<16; i++)
		for(int j=i+1; j<16; j++)
		{
			int cnt = 0;
			for(int k=0; k<4; k++)
				cnt += str[i][k] != str[j][k];
			dist[i][j] = dist[j][i] = cnt;
		}
	
	while(t--)
	{
		cin>>n;
		
		vector<int> cnt(16, 0);
		vector<string> arr;
		for(int i=0; i<n; i++)
		{
			string str; cin>>str;	
			cnt[umap[str]]++;
			if(cnt[umap[str]] < 4)
				arr.push_back(str);
		}
		
		int ans = 1e9;
		for(int i=0; i<arr.size(); i++)
		  for(int j=i+1; j<arr.size(); j++)
			for(int k=j+1; k<arr.size(); k++)
			{
				int a = umap[arr[i]], b = umap[arr[j]], c = umap[arr[k]];	
				ans = min(ans, dist[a][b] + dist[b][c] + dist[a][c]);
			}
			  			
		cout<<ans<<'\n';	
	}
	
	return 0;
}
