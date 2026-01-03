//#Submission Link: https://codeforces.com/contest/1538/submission/356245022

/*
I used upper_bound and lower_bound function(in-built) which operate on the sorted array to efficiently determine the count of valid index pairs (i, j); for every 
element a[i] using binary search, lower_bound locates the start of the range where a[j] >= l - a[i] and upper_bound locates the end where a[j] > r - a[i], 
the difference between these iterators provide the number of elements a[j] that satisfy the condition l <= a[i] + a[j] <= r.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        long long n, l, r;
        cin>>n>>l>>r;
        int a[n];
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }
        sort(a, a+n);
        long long ans=0;
        for(int i=0; i<n; i++) ans+= upper_bound(a+i+1, a+n, r-a[i])-lower_bound(a+i+1, a+n, l-a[i]);
        cout<<ans<<endl;
    }
}
