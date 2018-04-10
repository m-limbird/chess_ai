#include <string>
#include <unordered_map>

using namespace std;

namespace chess{

    /**
     * @brief       Class for holding the pieces and visualizing a board for chess
     */
    class Chessboard {

        public:

            /**
             * @brief       Constructor for the Chessboard class
             */
            Chessboard();

            /**
             * @brief       Function for showing the pieces on the board
             */
            void printBoard();

            // Member variables
            string empty_;
            
            string white_king_;
            string white_queen_;
            string white_rook_;
            string white_bishop_;
            string white_knight_;
            string white_pawn_;
            
            string black_king_;
            string black_queen_;
            string black_rook_;
            string black_bishop_;
            string black_knight_;
            string black_pawn_;

            string left_line_;
            string hbar_line_;
            string top_left_corner_line_;
            string top_right_corner_line_;
            string bottom_left_corner_line_;
            string bottom_right_corner_line_;
            string vbar_line_;
            string line_with_middle_right_;
            string line_with_middle_left_;
            string bar_and_down_;
            string bar_and_up_;
            string cross_line_;

            unordered_map<int, string> piece_map;
            int board [8][8];
    };
}