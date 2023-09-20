#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int n;
    cin >> n; cin.ignore();

    vector<int> horses_power {};

    for (int i = 0; i < n; i++) {
        int pi;
        cin >> pi; cin.ignore();

        horses_power.push_back(pi);
    }

    sort(horses_power.begin(), horses_power.end());

    int diff {};
    for (int i {1}; i < n; i++) {
        if (i == 1 || horses_power[i] - horses_power[i - 1] < diff) {
            diff = horses_power[i] - horses_power[i - 1];
        }
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << diff << endl;
}
