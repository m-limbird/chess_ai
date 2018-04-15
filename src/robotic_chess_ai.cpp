// Main function for running a chess game with the robotic arm

#include <iostream>
#include <unordered_map>
#include "../include/chessboard.h"

using namespace std;

enum state {
    WHITE_TURN,
    BLACK_TURN,
    GAME_OVER
};

enum input_state {
    PIECE,
    CURRENT_FILE,
    CURRENT_RANK,
    ACTION,
    NEXT_FILE,
    NEXT_RANK,
    OPTIONAL
};

unordered_map<string, unsigned short> piece_number;

void update_state(state& cur_state) {
    if (cur_state != GAME_OVER){
        if (cur_state == WHITE_TURN)
            cur_state = BLACK_TURN;
        else
            cur_state = WHITE_TURN;
    }
}

bool check_input(string& in, chess::Chessboard& board, state& game_state){
    input_state in_state = PIECE;

    // check to see if input is correctly put in
    unsigned short black_add = 0;
    if(game_state == BLACK_TURN)
        black_add = 6;

    string::iterator it;
    string cur_char;
    chess::Chessboard::piece the_piece;
    unsigned short file_num, rank_num, next_file_num, next_rank_num;
    chess::Chessboard::action the_action, optional;

    for(it = in.begin(); it < in.end(); it++) {
        // TODO: Need error checking for inputs that don't make sense

        if(in_state == PIECE){
            cur_char = *it;
            the_piece = static_cast<chess::Chessboard::piece>(piece_number[cur_char] + black_add);
            in_state = CURRENT_FILE;
        } else if (in_state == CURRENT_FILE){
            if (the_piece == chess::Chessboard::piece::WHITE_PAWN || the_piece == chess::Chessboard::piece::BLACK_PAWN)
                it--;
            file_num = *it - 'a';
            in_state = CURRENT_RANK;
        } else if (in_state == CURRENT_RANK) {
            rank_num = 8 - (*it - '0');
            in_state = ACTION;
        } else if (in_state == ACTION) {
            cur_char = *it;
            if(cur_char.compare("x") == 0){
                the_action = chess::Chessboard::action::CAPTURE;
            } else if (cur_char.compare(" ") == 0){
                the_action = chess::Chessboard::action::MOVE;
            } else {
                cout << "Invalid input!" << endl;
                return false;
            }
            in_state = NEXT_FILE;
        } else if (in_state == NEXT_FILE) {
            next_file_num = *it - 'a';
            in_state = NEXT_RANK;
        } else if (in_state == NEXT_RANK) {
            next_rank_num = 8 - (*it - '0');
            in_state = OPTIONAL;
        } else if (in_state == OPTIONAL) {
            cur_char = *it;
            if(cur_char.compare("+") == 0){
                optional = chess::Chessboard::action::CHECK;
            } else if (cur_char.compare("#") == 0){
                optional = chess::Chessboard::action::CHECKMATE;
            } else {
                cout << "Invalid input!" << endl;
                return false;
            }
        }
    }

    bool move_correct = board.checkMove( the_piece, 
                                         file_num, 
                                         rank_num, 
                                         next_file_num, 
                                         next_rank_num,
                                         the_action, 
                                         optional );

    if(!move_correct){
        cout << "Invalid input!" << endl;
    }

    return move_correct;
}

int main() {
    piece_number["K"] = 1;
    piece_number["Q"] = 2;
    piece_number["R"] = 3;
    piece_number["B"] = 4;
    piece_number["N"] = 5;
    piece_number["a"] = 6;
    piece_number["b"] = 6;
    piece_number["c"] = 6;
    piece_number["d"] = 6;
    piece_number["e"] = 6;
    piece_number["f"] = 6;
    piece_number["g"] = 6;
    piece_number["h"] = 6;

    chess::Chessboard board;
    state game_state = WHITE_TURN;
    string input;

    while(game_state != GAME_OVER) {

        board.printBoard();

        bool valid_input = false;
        while(!valid_input){
            cin >> input;
            valid_input |= check_input(input, board, game_state);
        }
        
        // switch the turn
        //update_state(game_state);
    }

    return 0;
}
