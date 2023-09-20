#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    string message;
    getline(cin, message);

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    if (message.length() == 0) {
        cout << "" << endl;
    }

    string binary_message {};
    for (const char character : message) {
        string binary_character = bitset<7>(character).to_string();
        binary_message += binary_character;
    }

    cerr << binary_message << endl;

    string unary_message {};
    for (int i {0}; i < binary_message.length();) {
        char binary_character {binary_message[i]};
        if (binary_character == '1') {
            unary_message += " 0 ";
        } else {
            unary_message += " 00 ";
        }
        while (binary_message[i] == binary_character) {
            unary_message += "0";
            i++;
        }
    }

    if (unary_message[0] == ' ') {
        unary_message.erase(0, 1);
    }
    if (unary_message[unary_message.length() - 1] == ' ') {
        unary_message.pop_back();
    }

    cout << unary_message << endl;
}
