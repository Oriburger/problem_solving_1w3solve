#include <bits/stdc++.h>
using namespace std;

typedef unordered_map<string, int> umap;

string ans="Okay";
int a, b, c, n;
umap normal, special, forfree;
vector<string> order;

void Input(int k, umap &tmp, bool is_free)
{
	for(int i=0; i<k; i++)
	{
		string name; int price = 0;
		if(is_free) cin>>name;
		else cin>>name>>price;
		tmp[name] = price;
	}
}

char GetMenuType(string str)
{
	if(normal.count(str)) return 'A';
	else if(special.count(str)) return 'B';
	return 'C';
}

int GetMenuPrice(string str)
{
	if(normal.count(str)) return normal[str];
	else if(special.count(str)) return special[str];
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>a>>b>>c;

	Input(a, normal, false);
	Input(b, special, false);
	Input(c, forfree, true);	

	cin>>n;

	order = vector<string>(n);
	for(int i=0; i<n; i++)
		cin>>order[i];
	
	long sum[2];
	int free_cnt = 0;

	for(int i=0; i<n; i++)
	{
		char type = GetMenuType(order[i]);
		int price = GetMenuPrice(order[i]);

		if(type=='A') sum[0] += (long)price;
		else if(type=='B') sum[1] += (long)price;
		free_cnt+=(type == 'C');
	}

	if(sum[0] < 20000 && sum[1] > 0) cout<<"No\n";
	else if(sum[0]+sum[1] < 50000 && free_cnt > 0) cout<<"No\n";
	else if(free_cnt >= 2) cout<<"No\n";
	else cout<<"Okay\n";

	return 0;	
}
