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
             * @brief       Enum of the different pieces
             */
            enum piece {
                EMPTY,
                WHITE_KING,
                WHITE_QUEEN,
                WHITE_ROOK,
                WHITE_BISHOP,
                WHITE_KNIGHT,
                WHITE_PAWN,
                BLACK_KING,
                BLACK_QUEEN,
                BLACK_ROOK,
                BLACK_BISHOP,
                BLACK_KNIGHT,
                BLACK_PAWN
            };

            /**
             * @brief       Enum of the different types of actions that a piece can take
             */
            enum action {
                MOVE = 0,
                CAPTURE = 1,
                CASTLE = 2,
                PROMOTION = 3,
                CHECK = 4,
                CHECKMATE = 5
            };

            /**
             * @brief       Constructor for the Chessboard class
             */
            Chessboard();

            /**
             * @brief       Function for showing the pieces on the board
             */
            void printBoard();

            /**
             * @brief       Function for showing the pieces on the board
             */
            bool checkMove( piece the_piece, 
                            unsigned short file, 
                            unsigned short rank,  
                            unsigned short next_file, 
                            unsigned short next_rank,
                            action the_action, 
                            action options );

            // Member variables
            string hbar_line_;
            string vbar_line_;
            string top_left_corner_line_;
            string top_right_corner_line_;
            string bottom_left_corner_line_;
            string bottom_right_corner_line_;
            string line_with_middle_right_;
            string line_with_middle_left_;
            string bar_and_down_;
            string bar_and_up_;
            string cross_line_;

            string top_line_;
            string separation_line_;
            string bottom_line_;
            string label_;

            unordered_map<unsigned short, string> piece_map;
            unsigned short board [8][8];
    };
}