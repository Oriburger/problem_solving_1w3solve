#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
vector<string> ans;

int gcd(int a, int b) {
  int tmp, n;
  if (a < b)
    swap(a, b);

  while (b != 0) {
    n = a % b;
    a = b;
    b = n;
  }
  return a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  arr = vector<int>(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];

    if (i > 0) {
      int tmp = gcd(arr[0], arr[i]);
      ans.push_back(to_string(arr[0] / tmp) + "/" + to_string(arr[i] / tmp));
    }
  }

  for (auto &p : ans)
    cout << p << '\n';

  return 0;
}
