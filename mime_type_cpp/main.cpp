#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

string str_to_lower(string s) {
    string lower_s {};
    for (const char c : s) {
        lower_s.push_back(tolower(c));
    }
    return lower_s;
}

vector<string> split(string s, string delimiter) {
    if (s.find(delimiter) == string::npos) {
        return vector<string> {s};
    }

    vector<string> s_parts {};
    size_t pos {0};
    string token {};
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        s_parts.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    s_parts.push_back(s.substr(0));

    return s_parts;
}

int main()
{
    int n; // Number of elements which make up the association table.
    cin >> n; cin.ignore();
    int q; // Number Q of file names to be analyzed.
    cin >> q; cin.ignore();

    map<string, string> mime_types;
    for (int i = 0; i < n; i++) {
        string ext; // file extension
        string mt; // MIME type.
        cin >> ext >> mt; cin.ignore();

        mime_types[str_to_lower(ext)] = mt;
    }
    for (int i = 0; i < q; i++) {
        string fname;
        getline(cin, fname); // One file name per line.

        vector<string> fparts {split(fname, ".")};

        if (fparts.size() == 1) {
            cout << "UNKNOWN" << endl;
            continue;
        }

        string ext {fparts[fparts.size()-1]};
        if (mime_types.find(str_to_lower(ext)) != mime_types.end()) {
            cout << mime_types[str_to_lower(ext)] << endl;
        } else {
            cout << "UNKNOWN" << endl;
        }
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


    // For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
    //cout << "UNKNOWN" << endl;
}
