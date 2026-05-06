#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    int n = S.size();
    string T = S + S;

    vector<int> freq(26, 0);
    int left = 0;
    long long currSum = 0, maxSum = 0;

    for (int right = 0; right < 2 * n; right++) {
        int r = T[right] - 'a';

        while (freq[r] > 0) {
            int l = T[left] - 'a';
            freq[l]--;
            currSum -= (l + 1);
            left++;
        }

        freq[r]++;
        currSum += (r + 1);

        while (right - left + 1 > n) {
            int l = T[left] - 'a';
            freq[l]--;
            currSum -= (l + 1);
            left++;
        }

        maxSum = max(maxSum, currSum);
    }

    cout << maxSum << endl;
    return 0;
}