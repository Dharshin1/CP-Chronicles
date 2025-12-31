// Solution1.cpp
// Problem: Even Positions (Codeforces)
//
// Approach:
// - Traverse string left to right
// - Use stack for '(' positions
// - Use stack for '_' positions
// - When encountering ')':
//      - If '(' exists → match it
//      - Else use nearest '_' as '('
// - Add distance to cost
//
// Time Complexity: O(n)
// Space Complexity: O(n)
//
// Submission Link:
// https://github.com/yogesh4216/CP-Chronicles/blob/day04-solution/Problems/Data-structures/Day-04/sol/yogesh/Solution1.cpp

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        stack<int> open;       
        stack<int> underscore; 
        long long cost = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open.push(i);
            } 
            else if (s[i] == '_') {
                underscore.push(i);
            } 
            else { // ')'
                if (!open.empty()) {
                    int j = open.top();
                    open.pop();
                    cost += (i - j);
                } else {
                    int j = underscore.top();
                    underscore.pop();
                    cost += (i - j);
                }
            }
        }

        cout << cost << "\n";
    }

    return 0;
}