#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

struct T {
    int val;
    int idx;
};

bool order_by_value_asc(const T * t1, const T * t2) {
    return t1->val > t2->val;
}

bool order_by_value_des(const T * t1, const T * t2) {
    return t1->val < t2->val;
}

int main()
{
    int n;
    cin >> n; cin.ignore();

    if (n == 0) {
        cout << "0" << endl;
    }

    T ts[n];
    vector<const T *> max_points;
    vector<const T *> min_points;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v; cin.ignore();

        ts[i] = T{v, i};
        
        if (i == 0 || i < n - 1 && v > ts[i - 1].val && ts[i].val > ts[i + 1].val) {
            max_points.push_back(&ts[i]);
        } else {
            min_points.push_back(&ts[i]);
        }
    }

    sort(max_points.begin(), max_points.end(), order_by_value_asc);
    sort(min_points.begin(), min_points.end(), order_by_value_des);

    vector<int> diffs;
    int counter {0};
    for (auto t0 : max_points) {
        if (counter == 50) {
            break;
        }
        for (auto t1 : min_points) {
            if (t0->idx < t1->idx) {
                diffs.push_back(t0->val - t1->val);
                continue;
            }
        }
        counter++;
    }
    int max_diff {0};
    for (auto diff : diffs) {
        if (diff > max_diff) {
            max_diff = diff;
        }
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << -max_diff << endl;

    return 0;
}
