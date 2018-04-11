#include "../include/chessboard.h"
#include <iostream>
#include <unordered_map>

namespace chess {
    using namespace std;

    Chessboard::Chessboard() {
        empty_ = "    ";

        // white pieces
        white_king_ = " \u265A  ";
        white_queen_ = " \u265B  ";
        white_rook_ = " \u265C  ";
        white_bishop_ = " \u265D  ";
        white_knight_ = " \u265E  ";
        white_pawn_ = " \u265F  ";
        
        // black pieces
        black_king_ = " \u2654  ";
        black_queen_ = " \u2655  ";
        black_rook_ = " \u2656  ";
        black_bishop_ = " \u2657  ";
        black_knight_ = " \u2658  ";
        black_pawn_ = " \u2659  ";

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
        piece_map[0] = empty_;
        piece_map[1] = white_king_;
        piece_map[2] = white_queen_;
        piece_map[3] = white_rook_;
        piece_map[4] = white_bishop_;
        piece_map[5] = white_knight_;
        piece_map[6] = white_pawn_;
        piece_map[7] = black_king_;
        piece_map[8] = black_queen_;
        piece_map[9] = black_rook_;
        piece_map[10] = black_bishop_;
        piece_map[11] = black_knight_;
        piece_map[12] = black_pawn_;

        // board initialization
        board[0][0] = 9;  board[0][1] = 11; board[0][2] = 10; board[0][3] = 8;  board[0][4] = 7;  board[0][5] = 10; board[0][6] = 11; board[0][7] = 9;
        board[1][0] = 12; board[1][1] = 12; board[1][2] = 12; board[1][3] = 12; board[1][4] = 12; board[1][5] = 12; board[1][6] = 12; board[1][7] = 12;
        board[2][0] = 0;  board[2][1] = 0;  board[2][2] = 0;  board[2][3] = 0;  board[2][4] = 0;  board[2][5] = 0;  board[2][6] = 0;  board[2][7] = 0;
        board[3][0] = 0;  board[3][1] = 0;  board[3][2] = 0;  board[3][3] = 0;  board[3][4] = 0;  board[3][5] = 0;  board[3][6] = 0;  board[3][7] = 0;
        board[4][0] = 0;  board[4][1] = 0;  board[4][2] = 0;  board[4][3] = 0;  board[4][4] = 0;  board[4][5] = 0;  board[4][6] = 0;  board[4][7] = 0;
        board[5][0] = 0;  board[5][1] = 0;  board[5][2] = 0;  board[5][3] = 0;  board[5][4] = 0;  board[5][5] = 0;  board[5][6] = 0;  board[5][7] = 0;
        board[6][0] = 6;  board[6][1] = 6;  board[6][2] = 6;  board[6][3] = 6;  board[6][4] = 6;  board[6][5] = 6;  board[6][6] = 6;  board[6][7] = 6;
        board[7][0] = 3;  board[7][1] = 5;  board[7][2] = 4;  board[7][3] = 2;  board[7][4] = 1;  board[7][5] = 4;  board[7][6] = 5;  board[7][7] = 3;
        

        string start_box = top_left_corner_line_ + hbar_line_ + hbar_line_ + hbar_line_ + hbar_line_ + bar_and_down_;
        string middle_line = hbar_line_ + hbar_line_ + hbar_line_ + hbar_line_ + cross_line_;
        string middle_end = hbar_line_ + hbar_line_ + hbar_line_ + hbar_line_ + line_with_middle_left_;
        string box = hbar_line_ + hbar_line_ + hbar_line_ + hbar_line_ + bar_and_down_;
        string end_box = hbar_line_ + hbar_line_ + hbar_line_ + hbar_line_ + top_right_corner_line_;

        string start_bot_box = bottom_left_corner_line_ + hbar_line_ + hbar_line_ + hbar_line_ + hbar_line_ + bar_and_up_;
        string end_bot_box = hbar_line_ + hbar_line_ + hbar_line_ + hbar_line_ + bottom_right_corner_line_;
        string middle_bot_line = hbar_line_ + hbar_line_ + hbar_line_ + hbar_line_ + bar_and_up_;

        string top_line = start_box + box + box + box + box + box + box + end_box;
        string separation_line = line_with_middle_right_ + middle_line + middle_line + middle_line + middle_line + middle_line + middle_line + middle_line + middle_end;
        string box_bot = hbar_line_ + hbar_line_ + hbar_line_ + hbar_line_ + bar_and_up_;
        string bottom_line = start_bot_box + box_bot + box_bot + box_bot + box_bot + box_bot + box_bot + end_bot_box;
        

        cout << top_line << endl;

        for(int i = 0; i < 8; i++){
            cout << vbar_line_;
            for(int j = 0; j < 8; j++){
                cout << piece_map[board[i][j]] + vbar_line_;
            }
            if(i < 7){
                cout << endl << separation_line << endl;
            }
        }

        cout << endl << bottom_line << endl;
    }
}