// Main function for running a chess game with the robotic arm

#include <iostream>
#include "../include/chessboard.h"

using namespace std;

enum state {
    WHITE_TURN,
    BLACK_TURN,
    GAME_OVER
};

void update_state(state& cur_state) {
    if (cur_state != GAME_OVER){
        if (cur_state == WHITE_TURN)
            cur_state = BLACK_TURN;
        else
            cur_state = WHITE_TURN;
    }
}

int main() {

    chess::Chessboard board;
    state game_state = WHITE_TURN;
    string input;

    while(game_state != GAME_OVER) {

        board.printBoard();

        cin >> input;

        // switch the turn
        update_state(game_state);
    }

    
    return 0;
}
