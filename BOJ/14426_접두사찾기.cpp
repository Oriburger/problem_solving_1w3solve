#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, ans=0;

struct TrieNode
{
	TrieNode * children[26];
	bool isTerminal; 
	
	TrieNode() : isTerminal(false)
	{
		memset(children, 0, sizeof(children));
	}
	~TrieNode()
	{
		for(int i=0; i<26; i++)
			delete children[i];
	}
	
	void insert(const char * key)
	{
		if(*key=='\0') isTerminal = true;
		else
		{
			int next = *key - 'a';
			if(children[next]==NULL)
				children[next] = new TrieNode;
			children[next]->insert(key+1);
		}
	}
	
	TrieNode* find(const char * key)
	{
		if(*key=='\0') return this;
		int next = *key - 'a';
		if(children[next]==NULL) return NULL;
		return children[next]->find(key+1);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>m;
	
	char tmp[501];
	TrieNode * root = new TrieNode;
	for(int i=0; i<n; i++)
	{
		cin>>tmp;
		root->insert(tmp);
	}
	
	for(int i=0; i<m; i++)
	{	
		cin>>tmp;
		ans += (root->find(tmp)!=NULL);
	}
	cout<<ans<<'\n';	
	
	return 0;
}
