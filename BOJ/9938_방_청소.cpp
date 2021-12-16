#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct DisjointSet
{
	int n;

	vector<int> parent, size, rank, cnt;
	DisjointSet(int n) : n(n), parent(n), size(n, 1), rank(n, 1), cnt(n, 0)
	{
		for(int i=0; i<n; i++)
			parent[i]=i;
	}

	int find(int u)
	{
		if(u==parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	bool merge(int u, int v)
	{
		u = find(u); v = find(v);
		if(u==v) return false;

		if(rank[u] > rank[v]) swap(u, v);
		if(rank[u] == rank[v]) rank[v]+=1;

		parent[u] = v;
		size[v] += size[u];
		cnt[v] += cnt[u];
		return true;
	}

	int getSize(int u) //이 컴포넌트의 구성 노드(서랍) 개수를 반환
	{
		u = find(u);
		return size[u];
	}

	int getCnt(int u) //이 컴포넌트에 보관된 술병의 개수를 반환
	{
		u = find(u);
		return cnt[u];
	}
};

int n, l;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>l;

	DisjointSet djs(l);
	for(int i=0; i<n; i++)
	{
		int a, b;
		bool flag = true;
		cin>>a>>b;
		a -= 1; b -= 1;

		a = djs.find(a); 
		b = djs.find(b);

		//서랍 A가 비어있다면, 보관
		if(!djs.getCnt(a)) djs.cnt[a]+=1; 
		//서랍 B가 비어있다면, 보관
		else if(!djs.getCnt(b)) djs.cnt[b]+=1;
		//A가 속한 컴포넌트에 빈 자리가 존재한다면, 보관 
		else if(djs.getSize(a) > djs.getCnt(a)) djs.cnt[a]+=1;
		//B가 속한 컴포넌트에 빈 자리가 존재한다면, 보관
		else if(djs.getSize(b) > djs.getCnt(b)) djs.cnt[b]+=1;
		//보관이 불가능 하다면
		else flag = false;

		if(flag)
		{
 			djs.merge(a, b); //이동이 가능한 요소들을 merge 해준다.
			cout<<"LADICA\n";
		}
		else
			cout<<"SMECE\n";
	}

	return 0;
}
