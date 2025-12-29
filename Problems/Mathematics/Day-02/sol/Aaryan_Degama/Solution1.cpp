// link : https://codeforces.com/problemset/submission/1771/355643992

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;

void solve() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll i = 1;
    while (i < n && a[i] == a[i - 1]) i++;

    if (i == n) {
        cout << n * (n - 1) << "\n";
        return;
    }

    ll j = 1;
    while (j < n && a[n - j] == a[n - j - 1]) j++;

    cout << 2LL * i * j << "\n";
}

int main() {
    fastio
    int t;
    cin >> t;
    while (t--) solve();
}


/*
The maximum possible absolute difference in an array is obtained only by
choosing the minimum and the maximum elements.

So, all valid pairs must consist of:
one minimum element
one maximum element

Approach:

1. Sort the array.
   Minimum elements appear at the beginning.
   Maximum elements appear at the end.

2. Count how many times the minimum element appears.
   Let this count be 'i'.

3. Count how many times the maximum element appears.
   Let this count be 'j'.



Time Complexity: O(n log n)
Space Complexity: O(n)

*/