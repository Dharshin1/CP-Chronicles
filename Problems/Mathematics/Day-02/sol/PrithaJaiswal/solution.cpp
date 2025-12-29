#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        vector<long long int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        int min_val = arr[0];
        int max_val = arr[n - 1];

        long long int count_min = 0, count_max = 0;
        for (long long int i = 0; i < n; i++)
        {
            if (arr[i] == min_val)
            {
                count_min++;
            }
            else if (arr[i] == max_val)
            {
                count_max++;
            }
        }

        if (min_val == max_val)
        {
            cout << n * (n - 1) << endl;
            continue;
        }

        cout << 2LL * count_min * count_max << endl;
    }

    return 0;
}