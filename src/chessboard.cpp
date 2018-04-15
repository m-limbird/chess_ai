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
        piece_map[EMPTY] = "    ";
        piece_map[WHITE_KING] = " \u265A  ";
        piece_map[WHITE_QUEEN] = " \u265B  ";
        piece_map[WHITE_ROOK] = " \u265C  ";
        piece_map[WHITE_BISHOP] = " \u265D  ";
        piece_map[WHITE_KNIGHT] = " \u265E  ";
        piece_map[WHITE_PAWN] = " \u265F  ";
        piece_map[BLACK_KING] = " \u2654  ";
        piece_map[BLACK_QUEEN] = " \u2655  ";
        piece_map[BLACK_ROOK] = " \u2656  ";
        piece_map[BLACK_BISHOP] = " \u2657  ";
        piece_map[BLACK_KNIGHT] = " \u2658  ";
        piece_map[BLACK_PAWN] = " \u2659  ";

        // board initialization
        board[0][0] = BLACK_ROOK; board[0][1] = BLACK_KNIGHT; board[0][2] = BLACK_BISHOP; board[0][3] = BLACK_QUEEN; board[0][4] = BLACK_KING; board[0][5] = BLACK_BISHOP; board[0][6] = BLACK_KNIGHT; board[0][7] = BLACK_ROOK;
        board[1][0] = BLACK_PAWN; board[1][1] = BLACK_PAWN;   board[1][2] = BLACK_PAWN;   board[1][3] = BLACK_PAWN;  board[1][4] = BLACK_PAWN; board[1][5] = BLACK_PAWN;   board[1][6] = BLACK_PAWN;   board[1][7] = BLACK_PAWN;
        board[2][0] = EMPTY;      board[2][1] = EMPTY;        board[2][2] = EMPTY;        board[2][3] = EMPTY;       board[2][4] = EMPTY;      board[2][5] = EMPTY;        board[2][6] = EMPTY;        board[2][7] = EMPTY;
        board[3][0] = EMPTY;      board[3][1] = EMPTY;        board[3][2] = EMPTY;        board[3][3] = EMPTY;       board[3][4] = EMPTY;      board[3][5] = EMPTY;        board[3][6] = EMPTY;        board[3][7] = EMPTY;
        board[4][0] = EMPTY;      board[4][1] = EMPTY;        board[4][2] = EMPTY;        board[4][3] = EMPTY;       board[4][4] = EMPTY;      board[4][5] = EMPTY;        board[4][6] = EMPTY;        board[4][7] = EMPTY;
        board[5][0] = EMPTY;      board[5][1] = EMPTY;        board[5][2] = EMPTY;        board[5][3] = EMPTY;       board[5][4] = EMPTY;      board[5][5] = EMPTY;        board[5][6] = EMPTY;        board[5][7] = EMPTY;
        board[6][0] = WHITE_PAWN; board[6][1] = WHITE_PAWN;   board[6][2] = WHITE_PAWN;   board[6][3] = WHITE_PAWN;  board[6][4] = WHITE_PAWN; board[6][5] = WHITE_PAWN;   board[6][6] = WHITE_PAWN;   board[6][7] = WHITE_PAWN;
        board[7][0] = WHITE_ROOK; board[7][1] = WHITE_KNIGHT; board[7][2] = WHITE_BISHOP; board[7][3] = WHITE_QUEEN; board[7][4] = WHITE_KING; board[7][5] = WHITE_BISHOP; board[7][6] = WHITE_KNIGHT; board[7][7] = WHITE_ROOK;
        
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
                cout << piece_map[board[i][j]] << vbar_line_;
            }
            cout << " " << 8-i;
            if(i < 7){
                cout << endl << separation_line_ << endl;
            }
        }

        cout << endl << bottom_line_ << endl << label_ << endl;
    }

    bool Chessboard::checkMove( piece the_piece, 
                                unsigned short file, 
                                unsigned short rank,  
                                unsigned short next_file, 
                                unsigned short next_rank,
                                action the_action,
                                action options ) {
        bool is_correct = true;

        if (board[rank][file] != the_piece)
            is_correct = false;
        
        // check piece can move to the next position
        int diff_file = abs(next_file - file);
        int diff_rank = abs(next_rank - rank);
        // need to check when the next position is itself? no piece should go to the same pos it already is in
        switch(the_piece){
            case 1:     //white king
                if(diff_file > 1 || diff_rank > 1)
                    is_correct = false;
                break;
            case 2:     //white queen
                // save the direction the queen is going to check along that line for obstacles
                // absolute vals of the diffs should be equal unless one of the diffs is zero
                // essentially the logic of the bishop and the rook together.
                if(diff_file != 0 && diff_rank != 0){
                    if(diff_file != diff_rank){
                        is_correct = false;
                    }
                }
                break;
            case 3:     //white rook
                // save the direction the rook is going to check along that line for obstacles
                // only one diff should have a non-zero value
                if(diff_file != 0 && diff_rank != 0)
                    is_correct = false;
                break;
            case 4:     //white bishop
                if(diff_file != diff_rank)
                    is_correct = false;
                break;
            case 5:     //white knight
                if((diff_file == 2 && diff_rank != 1) || (diff_file == 1 && diff_rank != 2) || (diff_file != 2 && diff_file != 1)){
                    is_correct = false;
                }
                break;
            case 6:     //white pawn
                if(rank == 6){ // At the beginning

                }
                //need a way to promote pawns
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
        }
        // check that the action is appropriate
        // check the options


        if(is_correct){
            board[rank][file] = EMPTY;
            board[next_rank][next_file] = the_piece;
        }

        return is_correct;
    }
}