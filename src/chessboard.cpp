#include "../include/chessboard.h"
#include <iostream>
#include <unordered_map>

namespace chess {
    using namespace std;

    Chessboard::Chessboard() {
        // lines
        hbar_line_ = "\u2500";
        vbar_line_ = "\u2502";
        top_left_corner_line_ = "\u250C";
        top_right_corner_line_ = "\u2510";
        bottom_left_corner_line_ = "\u2514";
        bottom_right_corner_line_ = "\u2518";
        line_with_middle_right_ = "\u251C";
        line_with_middle_left_ = "\u2524";
        bar_and_down_ = "\u252C";
        bar_and_up_ = "\u2534";
        cross_line_ = "\u253C";

        // piece map
        piece_map_[EMPTY] = "    ";
        piece_map_[WHITE_KING] = " \u265A  ";
        piece_map_[WHITE_QUEEN] = " \u265B  ";
        piece_map_[WHITE_ROOK] = " \u265C  ";
        piece_map_[WHITE_BISHOP] = " \u265D  ";
        piece_map_[WHITE_KNIGHT] = " \u265E  ";
        piece_map_[WHITE_PAWN] = " \u265F  ";
        piece_map_[BLACK_KING] = " \u2654  ";
        piece_map_[BLACK_QUEEN] = " \u2655  ";
        piece_map_[BLACK_ROOK] = " \u2656  ";
        piece_map_[BLACK_BISHOP] = " \u2657  ";
        piece_map_[BLACK_KNIGHT] = " \u2658  ";
        piece_map_[BLACK_PAWN] = " \u2659  ";

        // board initialization
        resetBoard();

        string start_box = top_left_corner_line_ + hbar_line_ + hbar_line_ + hbar_line_ + hbar_line_ + bar_and_down_;
        string middle_line = hbar_line_ + hbar_line_ + hbar_line_ + hbar_line_ + cross_line_;
        string middle_end = hbar_line_ + hbar_line_ + hbar_line_ + hbar_line_ + line_with_middle_left_;
        string box = hbar_line_ + hbar_line_ + hbar_line_ + hbar_line_ + bar_and_down_;
        string end_box = hbar_line_ + hbar_line_ + hbar_line_ + hbar_line_ + top_right_corner_line_;
        string start_bot_box = bottom_left_corner_line_ + hbar_line_ + hbar_line_ + hbar_line_ + hbar_line_ + bar_and_up_;
        string end_bot_box = hbar_line_ + hbar_line_ + hbar_line_ + hbar_line_ + bottom_right_corner_line_;
        string middle_bot_line = hbar_line_ + hbar_line_ + hbar_line_ + hbar_line_ + bar_and_up_;
        string box_bot = hbar_line_ + hbar_line_ + hbar_line_ + hbar_line_ + bar_and_up_;

        top_line_ = "  " + start_box + box + box + box + box + box + box + end_box;
        separation_line_ = "  " + line_with_middle_right_ + middle_line + middle_line + middle_line + middle_line + middle_line + middle_line + middle_line + middle_end;
        bottom_line_ = "  " + start_bot_box + box_bot + box_bot + box_bot + box_bot + box_bot + box_bot + end_bot_box;
        label_ = "     a    b    c    d    e    f    g    h ";
    }

    void Chessboard::printBoard() {
        cout << label_ << endl << top_line_ << endl;

        for(int i = 0; i < 8; i++){
            cout << 8-i << " " << vbar_line_;
            for(int j = 0; j < 8; j++){
                cout << piece_map_[board_[i][j]] << vbar_line_;
            }
            cout << " " << 8-i;
            if(i < 7){
                cout << endl << separation_line_ << endl;
            }
        }

        cout << endl << bottom_line_ << endl << label_ << endl;
    }

    void Chessboard::resetBoard() {
        board_[0][0] = BLACK_ROOK; board_[0][1] = BLACK_KNIGHT; board_[0][2] = BLACK_BISHOP; board_[0][3] = BLACK_QUEEN; board_[0][4] = BLACK_KING; board_[0][5] = BLACK_BISHOP; board_[0][6] = BLACK_KNIGHT; board_[0][7] = BLACK_ROOK;
        board_[1][0] = BLACK_PAWN; board_[1][1] = BLACK_PAWN;   board_[1][2] = BLACK_PAWN;   board_[1][3] = BLACK_PAWN;  board_[1][4] = BLACK_PAWN; board_[1][5] = BLACK_PAWN;   board_[1][6] = BLACK_PAWN;   board_[1][7] = BLACK_PAWN;
        board_[2][0] = EMPTY;      board_[2][1] = EMPTY;        board_[2][2] = EMPTY;        board_[2][3] = EMPTY;       board_[2][4] = EMPTY;      board_[2][5] = EMPTY;        board_[2][6] = EMPTY;        board_[2][7] = EMPTY;
        board_[3][0] = EMPTY;      board_[3][1] = EMPTY;        board_[3][2] = EMPTY;        board_[3][3] = EMPTY;       board_[3][4] = EMPTY;      board_[3][5] = EMPTY;        board_[3][6] = EMPTY;        board_[3][7] = EMPTY;
        board_[4][0] = EMPTY;      board_[4][1] = EMPTY;        board_[4][2] = EMPTY;        board_[4][3] = EMPTY;       board_[4][4] = EMPTY;      board_[4][5] = EMPTY;        board_[4][6] = EMPTY;        board_[4][7] = EMPTY;
        board_[5][0] = EMPTY;      board_[5][1] = EMPTY;        board_[5][2] = EMPTY;        board_[5][3] = EMPTY;       board_[5][4] = EMPTY;      board_[5][5] = EMPTY;        board_[5][6] = EMPTY;        board_[5][7] = EMPTY;
        board_[6][0] = WHITE_PAWN; board_[6][1] = WHITE_PAWN;   board_[6][2] = WHITE_PAWN;   board_[6][3] = WHITE_PAWN;  board_[6][4] = WHITE_PAWN; board_[6][5] = WHITE_PAWN;   board_[6][6] = WHITE_PAWN;   board_[6][7] = WHITE_PAWN;
        board_[7][0] = WHITE_ROOK; board_[7][1] = WHITE_KNIGHT; board_[7][2] = WHITE_BISHOP; board_[7][3] = WHITE_QUEEN; board_[7][4] = WHITE_KING; board_[7][5] = WHITE_BISHOP; board_[7][6] = WHITE_KNIGHT; board_[7][7] = WHITE_ROOK;
    }

    void Chessboard::clearBoard() {
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                board_[i][j] = EMPTY;
            }
        }
    }

    bool Chessboard::checkLine( unsigned short begin_file,
                                unsigned short begin_rank,
                                unsigned short end_file,
                                unsigned short end_rank,
                                bool is_white ) {
        bool is_clear = true;

        short check_file = begin_file;
        short check_rank = begin_rank;
        movement direction = NOT_VALID;

        // Change direction based on input
        int diff_file = begin_file - end_file;
        int diff_rank = begin_rank - end_rank;

        if (diff_rank > 0 && diff_file == 0) {
            direction = UP;
        } else if (diff_rank < 0 && diff_file == 0) {
            direction = DOWN;
        } else if (diff_file > 0 && diff_rank == 0) {
            direction = LEFT;
        } else if (diff_file < 0 && diff_rank == 0) {
            direction = RIGHT;
        } else if (diff_rank > 0 && diff_file < 0 && abs(diff_rank) == abs(diff_file)) {
            direction = DIAG_UP_RIGHT;
        } else if (diff_rank > 0 && diff_file > 0 && abs(diff_rank) == abs(diff_file)) {
            direction = DIAG_UP_LEFT;
        } else if (diff_rank < 0 && diff_file < 0 && abs(diff_rank) == abs(diff_file)) {
            direction = DIAG_DOWN_RIGHT;
        } else if (diff_rank < 0 && diff_file > 0 && abs(diff_rank) == abs(diff_file)) {
            direction = DIAG_DOWN_LEFT;
        }

        switch (direction) {
            case UP:
                while (check_rank > end_rank){
                    check_rank--;
                    unsigned short check_piece = board_[check_rank][check_file];
                    if (check_piece != EMPTY) {
                        if (check_rank != end_rank) {
                            is_clear = false;
                        } else {
                            if (is_white && check_piece <= 6){
                                is_clear = false;
                            } else if (!is_white && check_piece > 6){
                                is_clear = false;
                            }
                        }
                    }
                }
                break;
            case DOWN:
                while(check_rank < end_rank){
                    check_rank++;
                    unsigned short check_piece = board_[check_rank][check_file];
                    if(check_piece != EMPTY){
                        if(check_rank != end_rank){
                            is_clear = false;
                        } else {
                            if(is_white && check_piece <= 6){
                                is_clear = false;
                            } else if(!is_white && check_piece > 6){
                                is_clear = false;
                            }
                        }
                    }
                }
                break;
            case LEFT:
                while(check_file > end_file){
                    check_file--;
                    unsigned short check_piece = board_[check_rank][check_file];
                    if(check_piece != EMPTY){
                        if(check_file != end_file){
                            is_clear = false;
                        } else {
                            if(is_white && check_piece <= 6){
                                is_clear = false;
                            } else if(!is_white && check_piece > 6){
                                is_clear = false;
                            }
                        }
                    }
                }
                break;
            case RIGHT:
                while(check_file < end_file){
                    check_file++;
                    unsigned short check_piece = board_[check_rank][check_file];
                    if(check_piece != EMPTY){
                        if(check_file != end_file){
                            is_clear = false;
                        } else {
                            if(is_white && check_piece <= 6){
                                is_clear = false;
                            } else if(!is_white && check_piece > 6){
                                is_clear = false;
                            }
                        }
                    }
                }
                break;
            case DIAG_UP_RIGHT:
                while (check_rank > end_rank && check_file < end_file){
                    check_rank--;
                    check_file++;
                    unsigned short check_piece = board_[check_rank][check_file];
                    if (check_piece != EMPTY) {
                        if (check_rank != end_rank && check_file != end_file) {
                            is_clear = false;
                        } else {
                            if (is_white && check_piece <= 6){
                                is_clear = false;
                            } else if (!is_white && check_piece > 6){
                                is_clear = false;
                            }
                        }
                    }
                }
                break;
            case DIAG_UP_LEFT:
                while (check_rank > end_rank && check_file > end_file){
                    check_rank--;
                    check_file--;
                    unsigned short check_piece = board_[check_rank][check_file];
                    if (check_piece != EMPTY) {
                        if (check_rank != end_rank && check_file != end_file) {
                            is_clear = false;
                        } else {
                            if (is_white && check_piece <= 6){
                                is_clear = false;
                            } else if (!is_white && check_piece > 6){
                                is_clear = false;
                            }
                        }
                    }
                }
                break;
            case DIAG_DOWN_RIGHT:
                while (check_rank < end_rank && check_file < end_file){
                    check_rank++;
                    check_file++;
                    unsigned short check_piece = board_[check_rank][check_file];
                    if (check_piece != EMPTY) {
                        if (check_rank != end_rank && check_file != end_file) {
                            is_clear = false;
                        } else {
                            if (is_white && check_piece <= 6){
                                is_clear = false;
                            } else if (!is_white && check_piece > 6){
                                is_clear = false;
                            }
                        }
                    }
                }
                break;
            case DIAG_DOWN_LEFT:
                while (check_rank < end_rank && check_file > end_file){
                    check_rank++;
                    check_file--;
                    unsigned short check_piece = board_[check_rank][check_file];
                    if (check_piece != EMPTY) {
                        if (check_rank != end_rank && check_file != end_file) {
                            is_clear = false;
                        } else {
                            if (is_white && check_piece <= 6){
                                is_clear = false;
                            } else if (!is_white && check_piece > 6){
                                is_clear = false;
                            }
                        }
                    }
                }
                break;
            case NOT_VALID:
                is_clear = false;
                break;
        }

        return is_clear;
    }

    bool Chessboard::checkMove( piece the_piece, 
                                unsigned short file, 
                                unsigned short rank,  
                                unsigned short next_file, 
                                unsigned short next_rank,
                                action the_action,
                                action options ) {
        bool is_correct = true;

        // This space does not contain that piece
        if (board_[rank][file] != the_piece)
            is_correct = false;
        
        int diff_file = next_file - file;
        int diff_rank = next_rank - rank;
        int diff_file_abs = abs(next_file - file);
        int diff_rank_abs = abs(next_rank - rank);

        // make sure piece doesn't try to go to the same place
        if (diff_file_abs == 0 && diff_rank_abs == 0)
            is_correct = false;

        bool is_white = false;
        if (the_piece < BLACK_KING)
            is_white = true;

        if (!checkLine(file, rank, next_file, next_rank, is_white) && the_piece != WHITE_KNIGHT && the_piece != BLACK_KNIGHT)
            is_correct = false;

        switch(the_piece){
            case WHITE_KING:
                if(diff_file_abs > 1 || diff_rank_abs > 1)
                    is_correct = false;
                break;
            case WHITE_QUEEN:
                if(diff_file_abs != 0 && diff_rank_abs != 0){
                    if(diff_file_abs != diff_rank_abs){
                        is_correct = false;
                    }
                }
                break;
            case WHITE_ROOK:
                if(diff_file_abs != 0 && diff_rank_abs != 0)
                    is_correct = false;
                break;
            case WHITE_BISHOP:
                if(diff_file_abs != diff_rank_abs)
                    is_correct = false;
                break;
            case WHITE_KNIGHT:
                if( (diff_file_abs == 2 && diff_rank_abs != 1) || 
                    (diff_file_abs == 1 && diff_rank_abs != 2) || 
                    (diff_file_abs != 2 && diff_file_abs != 1) ){
                    is_correct = false;
                }
                break;
            case WHITE_PAWN: 
                // TODO: need a way to promote pawns
                if(rank == 6){ // At the beginning
                    if(diff_rank < -2 || diff_rank > -1 || diff_file_abs != 0){
                        is_correct = false;
                    }
                } else {
                    if(diff_rank != -1 || diff_file_abs != 0){
                        is_correct = false;
                    }
                }
                break;
            case BLACK_KING:
                if(diff_file_abs > 1 || diff_rank_abs > 1)
                    is_correct = false;
                break;
            case BLACK_QUEEN:
                if(diff_file_abs != 0 && diff_rank_abs != 0){
                    if(diff_file_abs != diff_rank_abs){
                        is_correct = false;
                    }
                }
                break;
            case BLACK_ROOK:
                if(diff_file_abs != 0 && diff_rank_abs != 0)
                    is_correct = false;
                break;
            case BLACK_BISHOP:
                if(diff_file_abs != diff_rank_abs)
                    is_correct = false;
                break;
            case BLACK_KNIGHT:
                if( (diff_file_abs == 2 && diff_rank_abs != 1) || 
                    (diff_file_abs == 1 && diff_rank_abs != 2) || 
                    (diff_file_abs != 2 && diff_file_abs != 1) ){
                    is_correct = false;
                }
                break;
            case BLACK_PAWN:
                // TODO: need a way to promote pawns
                if(rank == 1){ // At the beginning
                    if(diff_rank > 2 || diff_rank < 1 || diff_file_abs != 0){
                        is_correct = false;
                    }
                } else {
                    if(diff_rank != 1 || diff_file_abs != 0){
                        is_correct = false;
                    }
                }
                break;
        }
        
        // check that the action is appropriate
        // check the options


        if(is_correct){
            board_[rank][file] = EMPTY;
            board_[next_rank][next_file] = the_piece;
        }

        return is_correct;
    }
}