#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct SegTree
{
    int n;
    vector<ll> tree;
    SegTree(const vector<ll>& arr)
    {
        n = arr.size();
        tree = vector<ll>(n*4, 0);
        init(arr, 0 , n-1, 1);
    }

    //node 노드가 arr[left, right] 배열을 표현할 때,
    //node를 루트로 하는 서브트리를 초기화하고, 이 구간의 합을 반환
    ll init(const vector<ll>& arr, int left, int right, int node)
    {
        if(left == right) return tree[node] = arr[left];
        int mid = (left + right)/2;
        ll leftSum = init(arr, left, mid, node*2);
        ll rightSum = init(arr, mid+1, right, node*2+1);
        return tree[node] = leftSum + rightSum;
    }

    //node가 표현한느 범위 arr[nodeLeft .. nodeRight]가 주어질 때,
    //이 범위와 arr[left, right]의 교집합의 합을 구함
    ll query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        //두 구간이 겹치지 않으면, 전혀 의미 없는 값을 반환
        if(nodeLeft > right || left > nodeRight) return 0;
        //node가 표현하는 범위가 arr[left, right]에 완전히 포함되는 경우
        if(left <= nodeLeft && nodeRight <= right) return tree[node];

        //양 쪽 구간을 나눠서 푼 뒤, 결과를 반환 
        int mid = (nodeLeft + nodeRight) / 2;
        return query(left, right, node*2, nodeLeft, mid)   
                + query(left, right, node*2+1, mid+1, nodeRight);
    }

    ll query(int left, int right){ return query(left, right, 1, 0, n-1); }

    //arr[idx] = newVal로 바뀌었을 때, node를 루트로 하는
    //구간 트리를 갱신하고 노드가 표현하는 구간의 합을 반환
    ll update(int idx, ll newVal, int node, int nodeLeft, int nodeRight)
    {
        //idx가 노드가 표현하는 구간과 상관없는 경우에는 무시
        if(idx < nodeLeft || idx > nodeRight) return tree[node];
        //트리의 리프까지 내려온 경우
        if(nodeLeft == nodeRight) return tree[node] = newVal;
        
        int mid = (nodeLeft + nodeRight) / 2;
        return tree[node] = update(idx, newVal, node*2, nodeLeft, mid)
                            + update(idx, newVal, node*2+1, mid+1, nodeRight);
    }

    ll update(int idx, ll newVal){ return update(idx, newVal, 1, 0, n-1); }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, m, k;
    vector<ll> arr;

    cin>>n>>m>>k;

    arr = vector<ll>(n+1);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    SegTree st(arr);
    ll a, b, c;    
    for(ll q=0; q<m+k; q++)
    {
        cin>>a>>b>>c; 
        if(a==1) st.update(b-1, c); 
        else if(a==2) cout<<st.query(b-1, c-1)<<'\n';
    }

    return 0;
}
