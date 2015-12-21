/* Mars Rover is at co-ordinates (x,y,cardinal_co-ordinate)
 * cardinal_co-ordinate = {N,S,E,W}.
 * The bottom left end of the planet is at (0,0) and top right
 * corner is at (x_max, y_max).
 * It receives an instruction string with moves and directions
 * {L,R,M} L - Left; R - Right; M - Move;
 * Display the new co-ordinate of the Mars rover
 */

#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

int new_x_rover(int, char );
int new_y_rover(int, char );
char getNewDirection(char , char );
bool checkBounds(int, int, int, int);

int main(int argc, char *argv[])
{
    string cmd;
    char curr_dir;
    int rover_x, rover_y;
    int win_max_x, win_max_y;

    cout <<"\nTop right corner co-ordinates : ";
    cin >> win_max_x >> win_max_y;
    cout << "Current position : ";
    cin >> rover_x >> rover_y;
    cout << "Current direction : ";
    cin >> curr_dir;
    cout << "Instructions : ";
    cin >> cmd;

    cout << endl;
    for (int i=0; i < cmd.length(); i++) {
        switch(cmd[i]) {
            case 'L' : {
                curr_dir = getNewDirection(curr_dir, cmd[i]);
                break;
            }
            case 'R' : {
                curr_dir = getNewDirection(curr_dir, cmd[i]);
                break;
            }
            case 'M' : {
                int temp_rover_x = new_x_rover(rover_x, curr_dir);
                int temp_rover_y = new_y_rover(rover_y, curr_dir);
                if (checkBounds(temp_rover_x, temp_rover_y, win_max_x, win_max_y)) {
                    rover_x = temp_rover_x;
                    rover_y = temp_rover_y;
                }
                break;
            }
            default : {
                cerr << "\nInvalid command string" << endl;
            }
        }
    }

    cout << "Rover is now at location : ";
    cout << "( "<< rover_x << ", " << rover_y << ", " << curr_dir << " ) " << endl;
    return 0;
}

int new_x_rover(int curr_x, char dir)
{
    if (! (dir == 'W' || dir == 'E') ) {
        return INT_MIN;
    } else   if (dir == 'W') return curr_x-1;
      else   if (dir == 'E') return curr_x+1;
}

int new_y_rover(int curr_y, char dir)
{
    if (! (dir == 'S' || dir == 'N') ) {
        return INT_MIN;
    } else if (dir == 'S')  return curr_y-1;
      else if (dir == 'N')  return curr_y+1;
}

char getNewDirection(char curr_dir, char cmd)
{
    switch (curr_dir) {
        case 'N' : {
            if (cmd == 'L')     return 'W';
            if (cmd == 'R')     return 'E';
            break;
        }
        case 'S' : {
            if (cmd == 'L')     return 'E';
            if (cmd == 'R')     return 'W';
            break;
        }
        case 'E' : {
            if (cmd == 'L')     return 'N';
            if (cmd == 'R')     return 'S';
            break;
        }
        case 'W' : {
            if (cmd == 'L')     return 'S';
            if (cmd == 'R')     return 'N';
        }
        default : {
            cerr << "\nInvalid direction" << endl;
        }
    }
}

bool checkBounds(int new_x, int new_y, int x_max, int y_max)
{
    if (
        ( (new_x <= x_max) && (new_x >= 0) ) &&
        ( (new_y <= y_max) && (new_y >= 0) )
    )
        return true;
    else {
        cerr << "Rover has moved out of bounds." << endl;
        return false;
    }
}
