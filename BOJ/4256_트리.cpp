#include <iostream>
#include <vector>
using namespace std;

int t, n;
vector<int> preorder, inorder;

void Answer(int root, int p, int q)
{
    for(int i=p; i<=q; i++)
        if(inorder[i] == preorder[root])
        {
            Answer(root+1, p, i-1);
            Answer(root+i-p+1, i+1, q);
            cout<<preorder[root]<<' ';
        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>t;

    while(t--)
    {
        int n; cin>>n;

        preorder = inorder = vector<int>(n, 0);

        for(int i=0; i<n; i++)
            cin>>preorder[i];
        for(int i=0; i<n; i++)
            cin>>inorder[i];

        Answer(0, 0, n-1);
        cout<<'\n';
    }

    return 0;
}
