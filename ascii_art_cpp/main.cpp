#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int l;
    cin >> l; cin.ignore();
    int h;
    cin >> h; cin.ignore();

    string t;
    getline(cin, t);
    transform(t.begin(), t.end(), t.begin(), ::toupper);

    vector<string> input_rows {};
    for (int i = 0; i < h; i++) {
        string row;
        getline(cin, row);

        input_rows.push_back(row);
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    vector<string> output_rows {};
    for (int i {}; i < h; i++) {
        output_rows.push_back("");
        for (auto c : t) {
            int c_idx {}; // {c-'A'}
            if (c >= 'A' && c <= 'Z') {
                c_idx = c - 'A';
            } else {
                c_idx = input_rows.at(0).length() / l - 1;
            }
            string c_ascii_part {input_rows.at(i).substr(c_idx*l, l)};
            output_rows.at(i) += c_ascii_part;
        }
        cout << output_rows.at(i) << endl;
    }
}
