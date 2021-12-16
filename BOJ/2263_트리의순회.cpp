#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100001;

int n, inorder[MAXN], postorder[MAXN], idx[MAXN];

void Answer(int ia, int ib, int pa, int pb)
{
	if(ia > ib || pa > pb) return;

	int root = postorder[pb];
	cout<<root<<' ';

	Answer(ia, idx[root]-1, pa, pa + idx[root]-1-ia);
	Answer(idx[root]+1, ib, pa + idx[root]-ia, pb-1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	for(int i=0; i<n; i++)
		cin>>inorder[i];
	for(int i=0; i<n; i++)
		cin>>postorder[i];
	for(int i=0; i<n; i++)
		idx[inorder[i]]=i;

	Answer(0, n-1, 0, n-1);

	return 0;
}
