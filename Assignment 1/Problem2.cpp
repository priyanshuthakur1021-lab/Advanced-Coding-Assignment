#include <bits/stdc++.h>
using namespace std;

long long minimumOperations(vector<int>& arr, int k) {

    int n = arr.size();

    // Check if transformation is possible
    int rem = arr[0] % k;

    for (int num : arr) {
        if (num % k != rem) {
            return -1;
        }
    }

    // Median gives minimum operations
    sort(arr.begin(), arr.end());

    int target = arr[n / 2];

    long long operations = 0;

    for (int num : arr) {
        operations += abs(num - target) / k;
    }

    return operations;
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << minimumOperations(arr, k) << endl;

    return 0;
}