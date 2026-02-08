#include <bits/stdc++.h>
using namespace std;

/*
Qiyin masala 1:
Massivni K ta bo‘lakka bo‘lib, maksimal bo‘lak yig‘indisini minimal qil
(Binary Search + Greedy)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long left = *max_element(a.begin(), a.end());
    long long right = accumulate(a.begin(), a.end(), 0LL);
    long long ans = right;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long sum = 0;
        int parts = 1;

        for (int i = 0; i < n; i++) {
            if (sum + a[i] <= mid) {
                sum += a[i];
            } else {
                parts++;
                sum = a[i];
            }
        }

        if (parts <= k) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
