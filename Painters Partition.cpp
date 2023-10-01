#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(const vector<int>& boards, int painters, int time) {
    int paintersRequired = 1;
    int currentTime = 0;

    for (int i = 0; i < boards.size(); i++) {
        if (boards[i] > time) {
            return false;
        }

        if (currentTime + boards[i] <= time) {
            currentTime += boards[i];
        } else {
            paintersRequired++;
            currentTime = boards[i];
        }

        if (paintersRequired > painters) {
            return false;
        }
    }

    return true;
}

int minTimeToPaint(const vector<int>& boards, int painters) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (isPossible(boards, painters, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

int main() {
    int n, k;
    cin >> n;

    vector<int> boards(n);
    for (int i = 0; i < n; i++) {
        cin >> boards[i];
    }

    cin >> k;

    if (k >= n) {
        cout << *max_element(boards.begin(), boards.end()) << endl;
    } else {
        int minTime = minTimeToPaint(boards, k);
        cout << minTime << endl;
    }

    return 0;
}
