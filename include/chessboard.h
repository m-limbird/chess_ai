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
                CASTLE_KINGSIDE = 2,
                CASTLE_QUEENSIDE = 3,
                PROMOTION = 4,
                CHECK = 5,
                CHECKMATE = 6,
                NO_OPTION = 7,
            };

            /**
             * @brief       Enum of the different types of movement that a piece can take
             */
            enum movement {
                UP,
                DOWN,
                LEFT,
                RIGHT,
                DIAG_UP_RIGHT,
                DIAG_UP_LEFT,
                DIAG_DOWN_RIGHT,
                DIAG_DOWN_LEFT,
                NOT_VALID
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
             * @brief       Resets the board to the beginning configuration
             */
            void resetBoard();

            /**
             * @brief       Cleans the board off and no pieces on it
             */
            void clearBoard();

            /**
             * @brief       Function for checking whether it is legal to move to new space
             * 
             * @param[in]   begin_file     
             * @param[in]   begin_rank          
             * @param[in]   end_file           
             * @param[in]   end_rank       
             * @param[in]   is_white           
             * 
             * @return                      If the move is valid or not
             */
            bool checkLine( unsigned short begin_file,
                            unsigned short begin_rank,
                            unsigned short end_file,
                            unsigned short end_rank,
                            bool is_white );

            /**
             * @brief       Function for showing the pieces on the board
             * 
             * @param[in]   the_piece       Current piece to move
             * @param[in]   file            Current file of the piece
             * @param[in]   rank            Current rank of the piece
             * @param[in]   next_file       The file to move the piece to
             * @param[in]   next_rank       The rank to move the piece to
             * @param[in]   the_action      The action that the piece does
             * @param[in]   options         Additional actions that the piece does
             * 
             * @return                      If the move is valid or not
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

            unordered_map<unsigned short, string> piece_map_;
            unsigned short board_ [8][8];
    };
}