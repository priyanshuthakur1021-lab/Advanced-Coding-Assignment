#include <bits/stdc++.h>
using namespace std;

int maximumCyclicSubstringSum(string s) {
    int n = s.size();

    string doubled = s + s;

    unordered_set<char> st;

    int left = 0;
    int currSum = 0;
    int maxSum = 0;

    for (int right = 0; right < doubled.size(); right++) {

        char ch = doubled[right];

        while (st.count(ch)) {
            char leftChar = doubled[left];

            currSum -= (leftChar - 'a' + 1);
            st.erase(leftChar);

            left++;
        }

        while (right - left + 1 > n) {
            char leftChar = doubled[left];

            currSum -= (leftChar - 'a' + 1);
            st.erase(leftChar);

            left++;
        }

        st.insert(ch);
        currSum += (ch - 'a' + 1);

        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int main() {

    string s;
    cin >> s;

    cout << maximumCyclicSubstringSum(s) << endl;

    return 0;
}