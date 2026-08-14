/* You are given a string moves containing direction commands ('^', 'v', '<', '>') that direct a robot moving on a 2D grid
from an initial starting point $(0,0)$.The problem asks: Does the robot form a completely closed, simple cycle/loop?
*/


#include <string>

bool solution(const std::string &moves) {
    int up = 0, down = 0, left = 0, right = 0;

    for (char c : moves) {
        if (c == '^') up++;
        else if (c == 'v') down++;
        else if (c == '<') left++;
        else if (c == '>') right++;
    }

    // Both axes must balance out AND have at least 1 unit of length/width
    return (up == down) && (up > 0) && (left == right) && (left > 0);
}