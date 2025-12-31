// Solution1.cpp
// Problem: E2. Rudolf and Snowflakes (Hard Version)
//
// Short Problem Statement:
// Check if a number n can be represented as:
// 1 + k + k^2 + ... + k^m  (for some k > 1 and m >= 2)
//
// Approach:
// Try all possible values of m (height of the tree).
// For each m, binary search k such that the geometric sum equals n.
// Use __int128 to avoid overflow.
//
// Time Complexity: O(t * log(n) * log(n))
// Space Complexity: O(1)
//
// Submission Link:
// https://github.com/yogesh4216/CP-Chronicles/blob/day06-rudolf-snowflakes/Problems/Data-structures/Day-06/sol/yogesh/Solution1.cpp

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
#include <algorithm>

using namespace std;

bool check(long long k, int m, long long n) {
    __int128 sum = 1;
    __int128 cur = 1;

    for (int i = 1; i <= m; i++) {
        cur *= k;
        sum += cur;
        if (sum > n) return false;
    }
    return sum == n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        bool possible = false;

        for (int m = 2; m <= 60 && !possible; m++) {
            long long low = 2, high = 1e9;

            while (low <= high) {
                long long mid = (low + high) / 2;

                if (check(mid, m, n)) {
                    possible = true;
                    break;
                }

                __int128 sum = 1, cur = 1;
                for (int i = 1; i <= m; i++) {
                    cur *= mid;
                    sum += cur;
                    if (sum > n) break;
                }

                if (sum < n)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        cout << (possible ? "YES\n" : "NO\n");
    }

    return 0;
}
