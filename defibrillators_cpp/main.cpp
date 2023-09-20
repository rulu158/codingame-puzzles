#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <cmath>

using namespace std;

constexpr double pi = 3.14159265358979323846;

vector<string> split(string s, string delimiter) {
    if (s.find(delimiter) == std::string::npos) {
        return vector<string> {s};
    }

    vector<string> s_parts {};
    size_t pos {0};
    string token {};
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        s_parts.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    s_parts.push_back(s.substr(0));

    return s_parts;
}

double sanitize_number(string european_number) {
    int pos {};
    if ((pos = european_number.find(",")) != string::npos) {
        european_number[pos] = '.';
    }

    double number {stod(european_number)};
    return number;
}

struct User {
    double longitude;
    double latitude;
};

struct Defibrillator {
    int id;
    string name;
    string address;
    string phone_number;
    double longitude;
    double latitude;
};

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    User u {};

    string lon;
    cin >> lon; cin.ignore();

    u.longitude = sanitize_number(lon) * pi / 180;

    string lat;
    cin >> lat; cin.ignore();

    u.latitude = sanitize_number(lat) * pi / 180;

    vector<shared_ptr<Defibrillator>> defibs {};

    shared_ptr<Defibrillator> nearest_defib = make_shared<Defibrillator>();
    double min_distance {};

    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string defib_str;
        getline(cin, defib_str);

        vector<string> defib_parts {split(defib_str, ";")};
        shared_ptr<Defibrillator> defib = make_shared<Defibrillator>();
        defib->id = stoi(defib_parts[0]);
        defib->name = defib_parts[1];
        defib->address = defib_parts[2];
        defib->phone_number = defib_parts[3];
        defib->longitude = sanitize_number(defib_parts[4]) * pi / 180;
        defib->latitude = sanitize_number(defib_parts[5]) * pi / 180;

        double x {(defib->longitude - u.longitude) * cos((u.latitude + defib->latitude) / 2)};
        double y {(defib->latitude - u.latitude)};

        double distance {sqrt(x*x + y*y) * 6371};
        if (i == 0 || distance < min_distance) {
            nearest_defib = defib;
            min_distance = distance;
        }
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << nearest_defib->name << endl;
}
