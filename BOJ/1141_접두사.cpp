#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_set>
using namespace std;

struct TrieNode
{
	TrieNode * children[26];
	bool isTerminal;
	
	TrieNode()
	{
		memset(children, 0, sizeof(children));
	}
	~TrieNode()
	{
		for(int i=0; i<26; i++)
			if(children[i])
				delete children[i];
	}
	
	void insert(const char* key)
	{
		if(*key == '\0') isTerminal = true;
		else
		{
			int next = *key - 'a';
			if(children[next]==NULL)
				children[next] = new TrieNode();
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

bool comp(string &s1, string &s2) { return s1.size() > s2.size(); }

int n, ans;
vector<string> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n;
	
	TrieNode * root = new TrieNode;
	arr = vector<string>(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	sort(arr.begin(), arr.end(), comp);
	
	for(auto &s : arr)
	{
		if(!root->find(s.c_str()))
			ans += 1;
		root->insert(s.c_str());
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
