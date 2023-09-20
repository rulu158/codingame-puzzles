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
    int w; // number of columns.
    int h; // number of rows.
    cin >> w >> h; cin.ignore();

    vector<vector<int>> tiles {};
    for (int i {0}; i < h; i++) {
        tiles.push_back({});
        for (int j {0}; j < w; j++) {
            int tile_type;
            cin >> tile_type;
            tiles[i].push_back(tile_type);
        }
        //string line;
        //getline(cin, line); // represents a line in the grid and contains W integers. Each integer represents one room of a given type.

    }
    int ex; // the coordinate along the X axis of the exit (not useful for this first mission, but must be read).
    cin >> ex; cin.ignore();

    for (int i {0}; i < h; i++) {
        for (int j {0}; j < w; j++) {
            cerr << tiles[i][j] << " ";
        }
        cerr << endl;
    }

    // game loop
    while (1) {
        int xi;
        int yi;
        string pos;
        cin >> xi >> yi >> pos; cin.ignore();

        int next_xi {xi}, next_yi {yi};
        int current_tile {tiles[yi][xi]};
        cerr << xi << yi << tiles[yi][xi] << endl;
        switch (current_tile) {
            case 1:
            next_yi++;
            break;
            case 2:
            if (pos == "LEFT") {
                next_xi++;
            } else if (pos == "RIGHT") {
                next_xi--;
            }
            break;
            case 3:
            if (pos == "TOP") {
                next_yi++;
            }
            break;
            case 4:
            if (pos == "TOP") {
                next_xi--;
            } else if (pos == "RIGHT") {
                next_yi++;
            }
            break;
            case 5:
            if (pos == "TOP") {
                next_xi++;
            } else if (pos == "LEFT") {
                next_yi++;
            }
            break;
            case 6:
            if (pos == "LEFT") {
                next_xi++;
            } else if (pos == "RIGHT") {
                next_xi--;
            }
            break;
            case 7:
            case 8:
            case 9:
            next_yi++;
            break;
            case 10:
            next_xi--;
            break;
            case 11:
            next_xi++;
            break;
            case 12:
            case 13:
            next_yi++;
            break;
        }

        // One line containing the X Y coordinates of the room in which you believe Indy will be on the next turn.
        cout << next_xi << " " << next_yi << endl;
    }
}
