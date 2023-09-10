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
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();

    vector<int> temps {};
    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();

        temps.push_back(t);
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    if (temps.size() == 0) {
        cout << "0" << endl;
    }

    int min_t {temps.at(0)};
    for (int i = 0; i < temps.size(); i++) {
        if (abs(min_t) == abs(temps.at(i)) && min_t != temps.at(i)) {
            min_t = abs(min_t);
        } else if (abs(temps.at(i)) < abs(min_t)) {
            min_t = temps.at(i);
        }
    }

    cout << min_t << endl;
}
