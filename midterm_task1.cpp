#include <bits/stdc++.h>
using namespace std;

// constant for the maximum length of X
const int N = 1000010;

// X and S
string X;
bool S[10];

// n is the length of X, m is the number of digits in S
int n, m, ans;

// occ[i] is the number of occurrences of i in the current substring
int occ[N];

// check if all the elements in S are in the current substring
bool check() {
    for (int i = 0; i < 10; i++) {
        if (S[i] && !occ[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    // prompt the user to enter X
    cout << "Enter the string X: ";
    cin >> X;
    n = X.length();

    // prompt the user to enter the number of elements in S
    cout << "Enter the number of elements in the set S: ";
    cin >> m;

    // prompt the user to enter the elements of S
    cout << "Enter the elements of the set S: ";
    while (m--) {
        int x;
        cin >> x;
        S[x] = true;
    }

    // use two pointers, l and r, to define the current substring
    int l = 0, r = 0;

    // while r is within the bounds of X
    while (r < n) {
        // increment the count of X[r] in the current substring
        occ[X[r] - '0']++;

        // if the count of X[r] in the current substring is greater than 1
        while (occ[X[r] - '0'] > 1) {
            // decrement the count of X[l] in the current substring
            occ[X[l] - '0']--;
            // move l to the right
            l++;
        }

        // check if all the elements in S are in the current substring
        if (check()) {
            // if so, increment the answer
            ans++;
        }
        // move r to the right
        r++;
    }

    // output the answer
    cout << "The number of substrings of X that contain all the elements of S is: " << ans << endl;
    return 0;
}