#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <tuple>
#include <array>
#include <climits>
#include <sstream>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

map<int, char> cell_values = {
    {1, '.'}, {2, 'o'}, {3, '+'}, {4, '='}, {5, '*'}, {6, 'B'}, {7, 'O'},
    {8, 'X'}, {9, '@'}, {10, '%'}, {11, '&'}, {12, '#'}, {13, '/'}, {14, '^'}
};

string hex_pair_to_binary(string hex_pair) {
    stringstream ss;
    ss << hex << hex_pair;
    unsigned n;
    ss >> n;
    bitset<8> binary(n);
    return binary.to_string();
}

int main()
{
    string fingerprint;
    getline(cin, fingerprint);

    array<array<int, 17>, 9> board {};
    tuple<int, int> pos {make_tuple(8, 4)};

    string bytes {};
    while (fingerprint.length() > 0) {
        string hex_pair {fingerprint.substr(0, 2)};
        if (fingerprint.find(':') != string::npos) {
            fingerprint.erase(0, 3);
        } else {
            fingerprint.erase(0, 2);
        }

        string binary_str {hex_pair_to_binary(hex_pair)};
        //cerr << hex_pair << ": " << binary_str << endl;

        int idx {6};
        while (idx >= 0) {
            string next_move {binary_str.substr(idx, 2)};

            //cerr << next_move << endl;
            //cerr << "B: " << get<0>(pos) << " " << get<1>(pos) << endl;
            
            if (next_move == "00") {
                if (get<0>(pos) > 0 && get<1>(pos) > 0) {
                    get<0>(pos)--;
                    get<1>(pos)--;
                } else if (get<0>(pos) > 0 && get<1>(pos) == 0) {
                    get<0>(pos)--;
                } else if (get<0>(pos) == 0 && get<1>(pos) > 0) {
                    get<1>(pos)--;
                }
            } else if (next_move == "01") {
                if (get<0>(pos) < 16 && get<1>(pos) > 0) {
                    get<0>(pos)++;
                    get<1>(pos)--;
                } else if (get<0>(pos) < 16 && get<1>(pos) == 0) {
                    get<0>(pos)++;
                } else if (get<0>(pos) == 16 && get<1>(pos) > 0) {
                    get<1>(pos)--;
                }
            } else if (next_move == "10") {
                if (get<0>(pos) > 0 && get<1>(pos) < 8) {
                    get<0>(pos)--;
                    get<1>(pos)++;
                } else if (get<0>(pos) > 0 && get<1>(pos) == 8) {
                    get<0>(pos)--;
                } else if (get<0>(pos) == 0 && get<1>(pos) < 8) {
                    get<1>(pos)++;
                }
            } else if (next_move == "11") {
                if (get<0>(pos) < 16 && get<1>(pos) < 8) {
                    get<0>(pos)++;
                    get<1>(pos)++;
                } else if (get<0>(pos) < 16 && get<1>(pos) == 8) {
                    get<0>(pos)++;
                } else if (get<0>(pos) == 16 && get<1>(pos) < 8) {
                    get<1>(pos)++;
                }
            }

            //cerr << "A: " << get<0>(pos) << " " << get<1>(pos) << endl;

            board[get<1>(pos)][get<0>(pos)]++;
            if (board[get<1>(pos)][get<0>(pos)] == 15) {
                board[get<1>(pos)][get<0>(pos)] = 0;
            }
            idx -= 2;
        }
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "+---[CODINGAME]---+" << endl;
    for (int y {0}; y < 9; y++) {
        cout << "|";
        for (int x {0}; x < 17; x++) {
            if (x == 8 && y == 4) {
                cout << "S";
            } else if (x == get<0>(pos) && y == get<1>(pos)) {
                cout << "E";
            } else if (board[y][x] == 0) {
                cout << " ";
            } else {
                cout << cell_values[board[y][x]];
            }
        }
        cout << "|" << endl;
    }
    cout << "+-----------------+" << endl;
}
