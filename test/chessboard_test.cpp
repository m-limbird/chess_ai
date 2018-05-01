// Test file for the chessboard

#include "../include/chessboard.h"
#include <gtest/gtest.h>

/**
 * @brief       Test fixture for the Chessboard tests to reduce repeating test setup
 */
class ChessboardTest : public ::testing::Test {

    public:

        /**
         * @brief       Test fixture setup
         */
        virtual void SetUp() {}

        // Member variables
        chess::Chessboard board_;
};

/*****************************************************************
*
* TEST FUNCTION: printBoard
*
* note: Unit tests for the printBoard of the Chessboard class
*
*****************************************************************/

TEST_F(ChessboardTest, printBoard){
    ASSERT_TRUE(true);
}

/*****************************************************************
*
* TEST FUNCTION: checkLine
*
* note: Unit tests for the checkLine of the Chessboard class
*       Assumes that all inputs have been sanitized to get rid
*       of bad inputs (like off of the board, not a piece, etc.)
*
*****************************************************************/

//UP

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 1-7, and file 0-7.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ x  │ x  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ ^  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │    │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │    │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♟ --------------------------------->  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveUp_whiteToEmpty_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank = 0;
    bool is_white = true;

    for (unsigned short begin_file = 0; begin_file < 8; begin_file++) {
        end_file = begin_file;
        for (unsigned short begin_rank = 7; begin_rank > 0; begin_rank--) {
            board_.clearBoard();

            bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
            ASSERT_TRUE(actual_check);
        }
    }
}

/**         
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. This time there
 *          is always a piece inbetween the movement. Starting rank
 *          ranges from 1-7, and file 0-7. 
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ x  │ x  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ ♙  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ ^  │    │    │    │    │    │    │    │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │    │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♟ --------------------------------->  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveUp_whiteToEmpty_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank = 0;
    bool is_white = true;

    for (unsigned short begin_file = 0; begin_file < 8; begin_file++) {
        end_file = begin_file;
        for (unsigned short begin_rank = 7; begin_rank > 1; begin_rank--) {
            for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                for (unsigned short rank = 1; rank < begin_rank; rank++){
                    board_.clearBoard();

                    board_.board_[rank][begin_file] = piece;
                    bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                    ASSERT_FALSE(actual_check);
                }
            }
        }
    }
}

/**         
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. This time there
 *          is always a piece inbetween the movement. Starting rank
 *          ranges from 1-7, and file 0-7. 
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ ^  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │    │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │    │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♟ --------------------------------->  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveUp_whiteToBlackPiece_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank = 0;
    bool is_white = true;

    for (unsigned short begin_file = 0; begin_file < 8; begin_file++) {
        end_file = begin_file;
        for (unsigned short begin_rank = 7; begin_rank >= 1; begin_rank--) {

            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++ ){
                board_.clearBoard();

                board_.board_[end_rank][begin_file] = black_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_TRUE(actual_check);
            }
        }
    }
}

/**         
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. This time there
 *          is always a piece inbetween the movement. Starting rank
 *          ranges from 1-7, and file 0-7. 
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ ♟  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ ^  │    │    │    │    │    │    │    │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │    │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♟ --------------------------------->  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveUp_whiteToBlackPiece_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank = 0;
    bool is_white = true;

    board_.clearBoard();

    for (unsigned short begin_file = 0; begin_file < 8; begin_file++) {
        end_file = begin_file;
        for (unsigned short begin_rank = 7; begin_rank > 1; begin_rank--) {
            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.board_[end_rank][begin_file] = black_piece;

                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (unsigned short rank = 1; rank < begin_rank; rank++){
                        board_.board_[rank][begin_file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/**         
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. This time there
 *          is always a piece inbetween the movement. Starting rank
 *          ranges from 1-7, and file 0-7. 
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ ^  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │    │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │    │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♟ --------------------------------->  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveUp_whiteToWhitePiece_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank = 0;
    bool is_white = true;

    for (unsigned short begin_file = 0; begin_file < 8; begin_file++) {
        end_file = begin_file;
        for (unsigned short begin_rank = 7; begin_rank >= 1; begin_rank--) {
            board_.clearBoard();

            for ( unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::BLACK_KING; white_piece++ ){
                board_.board_[end_rank][begin_file] = white_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_FALSE(actual_check);

                board_.clearBoard();
            }
        }
    }
}

/**         
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. This time there
 *          is always a piece inbetween the movement. Starting rank
 *          ranges from 1-7, and file 0-7. 
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ ♟  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ ^  │    │    │    │    │    │    │    │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │    │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♟ --------------------------------->  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveUp_whiteToWhitePiece_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank = 0;
    bool is_white = true;

    board_.clearBoard();

    for (unsigned short begin_file = 0; begin_file < 8; begin_file++) {
        end_file = begin_file;
        for (unsigned short begin_rank = 7; begin_rank > 1; begin_rank--) {
            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::WHITE_PAWN + 1; white_piece++) {
                board_.board_[end_rank][begin_file] = white_piece;

                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (unsigned short rank = 1; rank < begin_rank; rank++){
                        board_.board_[rank][begin_file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/**
 * @brief   This test will use a black piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 1-7, and file 0-7.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ x  │ x  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ ^  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │    │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │    │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♙ --------------------------------->  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveUp_blackToEmpty_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank = 0;
    bool is_white = false;

    for (unsigned short begin_file = 0; begin_file < 8; begin_file++) {
        end_file = begin_file;
        for (unsigned short begin_rank = 7; begin_rank > 0; begin_rank--) {
            board_.clearBoard();

            bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
            ASSERT_TRUE(actual_check);
        }
    }
}

/**         
 * @brief   This test will use a black piece and try to go to the
 *          end of the board for a full movement. This time there
 *          is always a piece inbetween the movement. Starting rank
 *          ranges from 1-7, and file 0-7. 
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ x  │ x  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ ♙  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ ^  │    │    │    │    │    │    │    │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │    │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♙ --------------------------------->  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveUp_blackToEmpty_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank = 0;
    bool is_white = false;

    for (unsigned short begin_file = 0; begin_file < 8; begin_file++) {
        end_file = begin_file;
        for (unsigned short begin_rank = 7; begin_rank > 1; begin_rank--) {
            for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                for (unsigned short rank = 1; rank < begin_rank; rank++){
                    board_.clearBoard();

                    board_.board_[rank][begin_file] = piece;
                    bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                    ASSERT_FALSE(actual_check);
                }
            }
        }
    }
}

/**         
 * @brief   This test will use a black piece and try to go to the
 *          end of the board for a full movement. This time there
 *          is always a piece inbetween the movement. Starting rank
 *          ranges from 1-7, and file 0-7. 
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ ^  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │    │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │    │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♙ --------------------------------->  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveUp_blackToBlackPiece_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank = 0;
    bool is_white = false;

    for (unsigned short begin_file = 0; begin_file < 8; begin_file++) {
        end_file = begin_file;
        for (unsigned short begin_rank = 7; begin_rank >= 1; begin_rank--) {

            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++ ){
                board_.clearBoard();

                board_.board_[end_rank][begin_file] = black_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_FALSE(actual_check);
            }
        }
    }
}

/**         
 * @brief   This test will use a black piece and try to go to the
 *          end of the board for a full movement. This time there
 *          is always a piece inbetween the movement. Starting rank
 *          ranges from 1-7, and file 0-7. 
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ ♟  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ ^  │    │    │    │    │    │    │    │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │    │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♙ --------------------------------->  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveUp_blackToBlackPiece_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank = 0;
    bool is_white = false;

    board_.clearBoard();

    for (unsigned short begin_file = 0; begin_file < 8; begin_file++) {
        end_file = begin_file;
        for (unsigned short begin_rank = 7; begin_rank > 1; begin_rank--) {
            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.board_[end_rank][begin_file] = black_piece;

                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (unsigned short rank = 1; rank < begin_rank; rank++){
                        board_.board_[rank][begin_file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/**         
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. This time there
 *          is always a piece inbetween the movement. Starting rank
 *          ranges from 1-7, and file 0-7. 
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ ^  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │    │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │    │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♙ --------------------------------->  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveUp_blackToWhitePiece_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank = 0;
    bool is_white = false;

    for (unsigned short begin_file = 0; begin_file < 8; begin_file++) {
        end_file = begin_file;
        for (unsigned short begin_rank = 7; begin_rank >= 1; begin_rank--) {
            board_.clearBoard();

            for ( unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::BLACK_KING; white_piece++ ){
                board_.board_[end_rank][begin_file] = white_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_TRUE(actual_check);

                board_.clearBoard();
            }
        }
    }
}

/**         
 * @brief   This test will use a black piece and try to go to the
 *          end of the board for a full movement. This time there
 *          is always a piece inbetween the movement. Starting rank
 *          ranges from 1-7, and file 0-7. 
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ ♟  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ ^  │    │    │    │    │    │    │    │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │    │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♙ --------------------------------->  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveUp_blackToWhitePiece_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank = 0;
    bool is_white = false;

    board_.clearBoard();

    for (unsigned short begin_file = 0; begin_file < 8; begin_file++) {
        end_file = begin_file;
        for (unsigned short begin_rank = 7; begin_rank > 1; begin_rank--) {
            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::WHITE_PAWN + 1; white_piece++) {
                board_.board_[end_rank][begin_file] = white_piece;

                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (unsigned short rank = 1; rank < begin_rank; rank++){
                        board_.board_[rank][begin_file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}


//DOWN

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-6, and file 0-7.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟ --------------------------------->  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │    │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │    │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ v  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ x  │ x  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDown_whiteToEmpty_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank = 7;
    bool is_white = true;

    for (unsigned short begin_file = 0; begin_file < 8; begin_file++) {
        end_file = begin_file;
        for (unsigned short begin_rank = 0; begin_rank < 7; begin_rank++) {
            board_.clearBoard();

            bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
            ASSERT_TRUE(actual_check);
        }
    }
}

/**         
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. This time there
 *          is always a piece inbetween the movement. Starting rank
 *          ranges from 0-5, and file 0-7. 
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟ --------------------------------->  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │    │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │    │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ v  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ ♙  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ x  │ x  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDown_whiteToEmpty_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank = 7;
    bool is_white = true;

    for (unsigned short begin_file = 0; begin_file < 8; begin_file++) {
        end_file = begin_file;
        for (unsigned short begin_rank = 0; begin_rank < 6; begin_rank++) {
            for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                for (unsigned short rank = 6; rank > begin_rank; rank--){
                    board_.clearBoard();

                    board_.board_[rank][begin_file] = piece;
                    bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                    ASSERT_FALSE(actual_check);
                }
            }
        }
    }
}

/**         
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. This time there
 *          is always a piece inbetween the movement. Starting rank
 *          ranges from 0-5, and file 0-7. 
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟ --------------------------------->  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │    │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │    │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ v  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♙  │ x  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDown_whiteToBlackPiece_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank = 7;
    bool is_white = true;

    for (unsigned short begin_file = 0; begin_file < 8; begin_file++) {
        end_file = begin_file;
        for (unsigned short begin_rank = 0; begin_rank < 7; begin_rank++) {

            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++ ){
                board_.clearBoard();

                board_.board_[end_rank][begin_file] = black_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_TRUE(actual_check);
            }
        }
    }
}

/**         
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. This time there
 *          is always a piece inbetween the movement. Starting rank
 *          ranges from 0-5, and file 0-7. 
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟ --------------------------------->  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │    │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │    │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ v  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ ♟  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♙  │ x  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDown_whiteToBlackPiece_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank = 7;
    bool is_white = true;

    board_.clearBoard();

    for (unsigned short begin_file = 0; begin_file < 8; begin_file++) {
        end_file = begin_file;
        for (unsigned short begin_rank = 0; begin_rank < 6; begin_rank++) {
            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.board_[end_rank][begin_file] = black_piece;

                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (unsigned short rank = 6; rank > begin_rank; rank--){
                        board_.board_[rank][begin_file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/**         
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. This time there
 *          is always a piece inbetween the movement. Starting rank
 *          ranges from 0-5, and file 0-7. 
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟ --------------------------------->  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │    │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │    │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ v  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♟  │ x  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDown_whiteToWhitePiece_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank = 7;
    bool is_white = true;

    for (unsigned short begin_file = 0; begin_file < 8; begin_file++) {
        end_file = begin_file;
        for (unsigned short begin_rank = 0; begin_rank < 7; begin_rank++) {
            board_.clearBoard();

            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::BLACK_KING; white_piece++){
                board_.board_[end_rank][begin_file] = white_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_FALSE(actual_check);

                board_.clearBoard();
            }
        }
    }
}

/**         
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. This time there
 *          is always a piece inbetween the movement. Starting rank
 *          ranges from 0-5, and file 0-7. 
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟ --------------------------------->  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │    │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │    │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ v  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ ♟  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♟  │ x  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDown_whiteToWhitePiece_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank = 7;
    bool is_white = true;

    board_.clearBoard();

    for (unsigned short begin_file = 0; begin_file < 8; begin_file++) {
        end_file = begin_file;
        for (unsigned short begin_rank = 0; begin_rank < 6; begin_rank++) {
            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::WHITE_PAWN + 1; white_piece++) {
                board_.board_[end_rank][begin_file] = white_piece;

                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (unsigned short rank = 6; rank > begin_rank; rank--){
                        board_.board_[rank][begin_file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/**         
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. This time there
 *          is always a piece inbetween the movement. Starting rank
 *          ranges from 0-5, and file 0-7. 
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙ --------------------------------->  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │    │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │    │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ v  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ x  │ x  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDown_blackToEmpty_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank = 7;
    bool is_white = false;

    for (unsigned short begin_file = 0; begin_file < 8; begin_file++) {
        end_file = begin_file;
        for (unsigned short begin_rank = 0; begin_rank < 7; begin_rank++) {
            board_.clearBoard();

            bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
            ASSERT_TRUE(actual_check);
        }
    }
}

/**         
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. This time there
 *          is always a piece inbetween the movement. Starting rank
 *          ranges from 0-5, and file 0-7. 
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙ --------------------------------->  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │    │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │    │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ v  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ ♙  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ x  │ x  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDown_blackToEmpty_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank = 7;
    bool is_white = false;

    for (unsigned short begin_file = 0; begin_file < 8; begin_file++) {
        end_file = begin_file;
        for (unsigned short begin_rank = 0; begin_rank < 6; begin_rank++) {
            for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                for (unsigned short rank = 6; rank > begin_rank; rank--){
                    board_.clearBoard();

                    board_.board_[rank][begin_file] = piece;
                    bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                    ASSERT_FALSE(actual_check);
                }
            }
        }
    }
}

/**         
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. This time there
 *          is always a piece inbetween the movement. Starting rank
 *          ranges from 0-5, and file 0-7. 
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙ --------------------------------->  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │    │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │    │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ v  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♙  │ x  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDown_blackToBlackPiece_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank = 7;
    bool is_white = false;

    for (unsigned short begin_file = 0; begin_file < 8; begin_file++) {
        end_file = begin_file;
        for (unsigned short begin_rank = 0; begin_rank < 7; begin_rank++) {

            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++ ){
                board_.clearBoard();

                board_.board_[end_rank][begin_file] = black_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_FALSE(actual_check);
            }
        }
    }
}

/**         
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. This time there
 *          is always a piece inbetween the movement. Starting rank
 *          ranges from 0-5, and file 0-7. 
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙ --------------------------------->  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │    │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │    │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ v  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ ♙  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♙  │ x  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDown_blackToBlackPiece_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank = 7;
    bool is_white = false;

    board_.clearBoard();

    for (unsigned short begin_file = 0; begin_file < 8; begin_file++) {
        end_file = begin_file;
        for (unsigned short begin_rank = 0; begin_rank < 6; begin_rank++) {
            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.board_[end_rank][begin_file] = black_piece;

                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (unsigned short rank = 6; rank > begin_rank; rank--){
                        board_.board_[rank][begin_file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/**         
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. This time there
 *          is always a piece inbetween the movement. Starting rank
 *          ranges from 0-5, and file 0-7. 
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙ --------------------------------->  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │    │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │    │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ v  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♟  │ x  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDown_blackToWhitePiece_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank = 7;
    bool is_white = false;

    for (unsigned short begin_file = 0; begin_file < 8; begin_file++) {
        end_file = begin_file;
        for (unsigned short begin_rank = 0; begin_rank < 7; begin_rank++) {
            board_.clearBoard();

            for ( unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::BLACK_KING; white_piece++ ){
                board_.board_[end_rank][begin_file] = white_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_TRUE(actual_check);

                board_.clearBoard();
            }
        }
    }
}

/**         
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. This time there
 *          is always a piece inbetween the movement. Starting rank
 *          ranges from 0-5, and file 0-7. 
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙ --------------------------------->  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │    │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │    │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ v  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ ♙  │    │    │    │    │    │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♟  │ x  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDown_blackToWhitePiece_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank = 7;
    bool is_white = false;

    board_.clearBoard();

    for (unsigned short begin_file = 0; begin_file < 8; begin_file++) {
        end_file = begin_file;
        for (unsigned short begin_rank = 0; begin_rank < 6; begin_rank++) {
            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::WHITE_PAWN + 1; white_piece++) {
                board_.board_[end_rank][begin_file] = white_piece;

                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (unsigned short rank = 6; rank > begin_rank; rank--){
                        board_.board_[rank][begin_file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

// LEFT

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ x  │  <--------------------------- ♟  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       1 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       7 │ x  │    │    │    │    │    │    │ v  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveLeft_whiteToEmpty_nothingInbetween){
    unsigned short end_file = 0;
    unsigned short end_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 0; begin_rank < 8; begin_rank++) {
        end_rank = begin_rank;
        for (unsigned short begin_file = 7; begin_file > 0; begin_file--) {
            board_.clearBoard();

            bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
            ASSERT_TRUE(actual_check);
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-2.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ x  │ ♟  │  <---------------------- ♟  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       1 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       7 │ x  │    │    │    │    │    │    │ v  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveLeft_whiteToEmpty_piecesInbetween){
    unsigned short end_file = 0;
    unsigned short end_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 0; begin_rank < 8; begin_rank++) {
        end_rank = begin_rank;
        for (unsigned short begin_file = 7; begin_file > 1; begin_file--) {
            for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                for (unsigned short file = 1; file < begin_file; file++){
                    board_.clearBoard();

                    board_.board_[begin_rank][file] = piece;
                    bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                    ASSERT_FALSE(actual_check);
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-2.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙  │  <--------------------------- ♟  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       1 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       7 │ x  │    │    │    │    │    │    │ v  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveLeft_whiteToBlackPiece_nothingInbetween){
    unsigned short end_file = 0;
    unsigned short end_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 0; begin_rank < 8; begin_rank++) {
        end_rank = begin_rank;
        for (unsigned short begin_file = 7; begin_file > 0; begin_file--) {

            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.clearBoard();

                board_.board_[begin_rank][end_file] = black_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_TRUE(actual_check);
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-2.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙  │ ♙  │  <---------------------- ♟  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       1 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       7 │ x  │    │    │    │    │    │    │ v  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveLeft_whiteToBlackPiece_piecesInbetween){
    unsigned short end_file = 0;
    unsigned short end_rank;
    bool is_white = true;

    board_.clearBoard();

    for (unsigned short begin_rank = 0; begin_rank < 8; begin_rank++) {
        end_rank = begin_rank;
        for (unsigned short begin_file = 7; begin_file > 1; begin_file--) {
            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.board_[end_rank][end_file] = black_piece;

                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (unsigned short file = 1; file < begin_file; file++){
                        board_.board_[begin_rank][file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-2.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟  │  <--------------------------- ♟  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       1 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       7 │ x  │    │    │    │    │    │    │ v  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveLeft_whiteToWhitePiece_nothingInbetween){
    unsigned short end_file = 0;
    unsigned short end_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 0; begin_rank < 8; begin_rank++) {
        end_rank = begin_rank;
        for (unsigned short begin_file = 7; begin_file > 0; begin_file--) {
            board_.clearBoard();

            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::BLACK_KING; white_piece++){
                board_.board_[end_rank][end_file] = white_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_FALSE(actual_check);

                board_.clearBoard();
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-2.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟  │ ♟  │  <---------------------- ♟  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       1 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       7 │ x  │    │    │    │    │    │    │ v  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveLeft_whiteToWhitePiece_piecesInbetween){
    unsigned short end_file = 0;
    unsigned short end_rank;
    bool is_white = true;

    board_.clearBoard();

    for (unsigned short begin_rank = 0; begin_rank < 8; begin_rank++) {
        end_rank = begin_rank;
        for (unsigned short begin_file = 7; begin_file > 1; begin_file--) {
            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::WHITE_PAWN + 1; white_piece++) {
                board_.board_[end_rank][end_file] = white_piece;

                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (unsigned short file = 1; file < begin_file; file++){
                        board_.board_[begin_rank][file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-2.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ x  │  <--------------------------- ♙  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       1 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       7 │ x  │    │    │    │    │    │    │ v  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveLeft_blackToEmpty_nothingInbetween){
    unsigned short end_file = 0;
    unsigned short end_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 0; begin_rank < 8; begin_rank++) {
        end_rank = begin_rank;
        for (unsigned short begin_file = 7; begin_file > 0; begin_file--) {
            board_.clearBoard();

            bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
            ASSERT_TRUE(actual_check);
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-2.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ x  │ ♙  │  <---------------------- ♙  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       1 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       7 │ x  │    │    │    │    │    │    │ v  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveLeft_blackToEmpty_piecesInbetween){
    unsigned short end_file = 0;
    unsigned short end_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 0; begin_rank < 8; begin_rank++) {
        end_rank = begin_rank;
        for (unsigned short begin_file = 7; begin_file > 1; begin_file--) {
            for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                for (unsigned short file = 1; file < begin_file; file++){
                    board_.clearBoard();

                    board_.board_[begin_rank][file] = piece;
                    bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                    ASSERT_FALSE(actual_check);
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-2.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙  │  <--------------------------- ♙  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       1 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       7 │ x  │    │    │    │    │    │    │ v  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveLeft_blackToBlackPiece_nothingInbetween){
    unsigned short end_file = 0;
    unsigned short end_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 0; begin_rank < 8; begin_rank++) {
        end_rank = begin_rank;
        for (unsigned short begin_file = 7; begin_file > 0; begin_file--) {

            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++ ){
                board_.clearBoard();

                board_.board_[end_rank][end_file] = black_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_FALSE(actual_check);
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-2.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙  │ ♙  │  <---------------------- ♙  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       1 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       7 │ x  │    │    │    │    │    │    │ v  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveLeft_blackToBlackPiece_piecesInbetween){
    unsigned short end_file = 0;
    unsigned short end_rank;
    bool is_white = false;

    board_.clearBoard();

    for (unsigned short begin_rank = 0; begin_rank < 8; begin_rank++) {
        end_rank = begin_rank;
        for (unsigned short begin_file = 7; begin_file > 1; begin_file--) {
            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.board_[end_rank][end_file] = black_piece;

                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (unsigned short file = 1; file < begin_file; file++){
                        board_.board_[begin_rank][file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-2.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟  │  <--------------------------- ♙  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       1 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       7 │ x  │    │    │    │    │    │    │ v  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveLeft_blackToWhitePiece_nothingInbetween){
    unsigned short end_file = 0;
    unsigned short end_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 0; begin_rank < 8; begin_rank++) {
        end_rank = begin_rank;
        for (unsigned short begin_file = 7; begin_file > 0; begin_file--) {
            board_.clearBoard();

            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::BLACK_KING; white_piece++ ){
                board_.board_[end_rank][end_file] = white_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_TRUE(actual_check);

                board_.clearBoard();
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-2.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟  │ ♙  │  <---------------------- ♙  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       1 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       7 │ x  │    │    │    │    │    │    │ v  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveLeft_blackToWhitePiece_piecesInbetween){
    unsigned short end_file = 0;
    unsigned short end_rank;
    bool is_white = false;

    board_.clearBoard();

    for (unsigned short begin_rank = 0; begin_rank < 8; begin_rank++) {
        end_rank = begin_rank;
        for (unsigned short begin_file = 7; begin_file > 1; begin_file--) {
            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::WHITE_PAWN + 1; white_piece++) {
                board_.board_[end_rank][end_file] = white_piece;

                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (unsigned short file = 1; file < begin_file; file++){
                        board_.board_[begin_rank][file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

//RIGHT

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟----------------------------->  │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ v  │    │    │    │    │    │    │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveRight_whiteToEmpty_nothingInbetween){
    unsigned short end_file = 7;
    unsigned short end_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 0; begin_rank < 8; begin_rank++) {
        end_rank = begin_rank;
        for (unsigned short begin_file = 0; begin_file < 7; begin_file++) {
            board_.clearBoard();

            bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
            ASSERT_TRUE(actual_check);
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟------------------------>  │ ♟  │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ v  │    │    │    │    │    │    │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveRight_whiteToEmpty_piecesInbetween){
    unsigned short end_file = 7;
    unsigned short end_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 0; begin_rank < 8; begin_rank++) {
        end_rank = begin_rank;
        for (unsigned short begin_file = 0; begin_file < 6; begin_file++) {
            for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                for (unsigned short file = 6; file > begin_file; file--){
                    board_.clearBoard();

                    board_.board_[begin_rank][file] = piece;
                    bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                    ASSERT_FALSE(actual_check);
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟----------------------------->  │ ♙  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ v  │    │    │    │    │    │    │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveRight_whiteToBlackPiece_nothingInbetween){
    unsigned short end_file = 7;
    unsigned short end_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 0; begin_rank < 8; begin_rank++) {
        end_rank = begin_rank;
        for (unsigned short begin_file = 0; begin_file < 7; begin_file++) {

            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.clearBoard();

                board_.board_[begin_rank][end_file] = black_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_TRUE(actual_check);
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟------------------------>  │ ♙  │ ♙  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ v  │    │    │    │    │    │    │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveRight_whiteToBlackPiece_piecesInbetween){
    unsigned short end_file = 7;
    unsigned short end_rank;
    bool is_white = true;

    board_.clearBoard();

    for (unsigned short begin_rank = 0; begin_rank < 8; begin_rank++) {
        end_rank = begin_rank;
        for (unsigned short begin_file = 0; begin_file < 6; begin_file++) {
            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.board_[end_rank][end_file] = black_piece;

                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (unsigned short file = 6; file > begin_file; file--){
                        board_.board_[begin_rank][file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟----------------------------->  │ ♟  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ v  │    │    │    │    │    │    │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveRight_whiteToWhitePiece_nothingInbetween){
    unsigned short end_file = 7;
    unsigned short end_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 0; begin_rank < 8; begin_rank++) {
        end_rank = begin_rank;
        for (unsigned short begin_file = 0; begin_file < 7; begin_file++) {
            board_.clearBoard();

            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::BLACK_KING; white_piece++){
                board_.board_[end_rank][end_file] = white_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_FALSE(actual_check);

                board_.clearBoard();
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟------------------------>  │ ♟  │ ♟  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ v  │    │    │    │    │    │    │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveRight_whiteToWhitePiece_piecesInbetween){
    unsigned short end_file = 7;
    unsigned short end_rank;
    bool is_white = true;

    board_.clearBoard();

    for (unsigned short begin_rank = 0; begin_rank < 8; begin_rank++) {
        end_rank = begin_rank;
        for (unsigned short begin_file = 0; begin_file < 6; begin_file++) {
            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::WHITE_PAWN + 1; white_piece++) {
                board_.board_[end_rank][end_file] = white_piece;

                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (unsigned short file = 6; file > begin_file; file--){
                        board_.board_[begin_rank][file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙----------------------------->  │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ v  │    │    │    │    │    │    │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveRight_blackToEmpty_nothingInbetween){
    unsigned short end_file = 7;
    unsigned short end_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 0; begin_rank < 8; begin_rank++) {
        end_rank = begin_rank;
        for (unsigned short begin_file = 0; begin_file < 7; begin_file++) {
            board_.clearBoard();

            bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
            ASSERT_TRUE(actual_check);
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙------------------------>  │ ♙  │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ v  │    │    │    │    │    │    │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveRight_blackToEmpty_piecesInbetween){
    unsigned short end_file = 7;
    unsigned short end_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 0; begin_rank < 8; begin_rank++) {
        end_rank = begin_rank;
        for (unsigned short begin_file = 0; begin_file < 6; begin_file++) {
            for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                for (unsigned short file = 6; file > begin_file; file--){
                    board_.clearBoard();

                    board_.board_[begin_rank][file] = piece;
                    bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                    ASSERT_FALSE(actual_check);
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙----------------------------->  │ ♙  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ v  │    │    │    │    │    │    │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveRight_blackToBlackPiece_nothingInbetween){
    unsigned short end_file = 7;
    unsigned short end_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 0; begin_rank < 8; begin_rank++) {
        end_rank = begin_rank;
        for (unsigned short begin_file = 0; begin_file < 7; begin_file++) {

            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++ ){
                board_.clearBoard();

                board_.board_[end_rank][end_file] = black_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_FALSE(actual_check);
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙------------------------>  │ ♙  │ ♙  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ v  │    │    │    │    │    │    │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveRight_blackToBlackPiece_piecesInbetween){
    unsigned short end_file = 7;
    unsigned short end_rank;
    bool is_white = false;

    board_.clearBoard();

    for (unsigned short begin_rank = 0; begin_rank < 8; begin_rank++) {
        end_rank = begin_rank;
        for (unsigned short begin_file = 0; begin_file < 6; begin_file++) {
            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.board_[end_rank][end_file] = black_piece;

                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (unsigned short file = 6; file > begin_file; file--){
                        board_.board_[begin_rank][file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙----------------------------->  │ ♟  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ v  │    │    │    │    │    │    │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveRight_blackToWhitePiece_nothingInbetween){
    unsigned short end_file = 7;
    unsigned short end_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 0; begin_rank < 8; begin_rank++) {
        end_rank = begin_rank;
        for (unsigned short begin_file = 0; begin_file < 7; begin_file++) {
            board_.clearBoard();

            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::BLACK_KING; white_piece++ ){
                board_.board_[end_rank][end_file] = white_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_TRUE(actual_check);

                board_.clearBoard();
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙------------------------>  │ ♙  │ ♟  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ v  │    │    │    │    │    │    │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveRight_blackToWhitePiece_piecesInbetween){
    unsigned short end_file = 7;
    unsigned short end_rank;
    bool is_white = false;

    board_.clearBoard();

    for (unsigned short begin_rank = 0; begin_rank < 8; begin_rank++) {
        end_rank = begin_rank;
        for (unsigned short begin_file = 0; begin_file < 6; begin_file++) {
            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::WHITE_PAWN + 1; white_piece++) {
                board_.board_[end_rank][end_file] = white_piece;

                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (unsigned short file = 6; file > begin_file; file--){
                        board_.board_[begin_rank][file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}


// DIAG_UP_RIGHT

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │    │ x  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ ^  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♟ --------------------------->   │    │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagUpRight_whiteToEmpty_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 1; begin_rank < 8; begin_rank++) {
        for (unsigned short begin_file = 0; begin_file < 7; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 7 && check_rank != 0) {
                check_file++;
                check_rank--;
            }
            end_file = check_file;
            end_rank = check_rank;

            board_.clearBoard();

            bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
            ASSERT_TRUE(actual_check);
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │    │    │ x  │ x  │ x  │ x  │ x  │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │    │ ♟  │    │    │    │    │    │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ ^  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♟ ----------------------->  │    │    │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagUpRight_whiteToEmpty_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 2; begin_rank < 8; begin_rank++) {
        for (unsigned short begin_file = 0; begin_file < 6; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 7 && check_rank != 0) {
                check_file++;
                check_rank--;
            }
            end_file = check_file;
            end_rank = check_rank;

            for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                for (check_file = end_file - 1, check_rank = end_rank + 1; check_file != begin_file || check_rank != begin_rank; check_file--, check_rank++){
                    board_.clearBoard();

                    board_.board_[check_rank][check_file] = piece;
                    bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                    ASSERT_FALSE(actual_check);
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │    │ ♙  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ ^  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♟ ---------------------------->  │    │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagUpRight_whiteToBlackPiece_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 1; begin_rank < 8; begin_rank++) {
        for (unsigned short begin_file = 0; begin_file < 7; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 7 && check_rank != 0) {
                check_file++;
                check_rank--;
            }
            end_file = check_file;
            end_rank = check_rank;

            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.clearBoard();

                board_.board_[end_rank][end_file] = black_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_TRUE(actual_check);
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │    │    │ ♙  │ x  │ x  │ x  │ x  │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │    │ ♟  │    │    │    │    │    │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ ^  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♟ ----------------------->  │    │    │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagUpRight_whiteToBlackPiece_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 2; begin_rank < 8; begin_rank++) {
        for (unsigned short begin_file = 0; begin_file < 6; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 7 && check_rank != 0) {
                check_file++;
                check_rank--;
            }
            end_file = check_file;
            end_rank = check_rank;

            board_.clearBoard();

            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.board_[end_rank][end_file] = black_piece;
                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (check_file = end_file - 1, check_rank = end_rank + 1; check_file != begin_file || check_rank != begin_rank; check_file--, check_rank++){
                        board_.board_[check_rank][check_file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │    │ ♟  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ ^  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♟ ---------------------------->  │    │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagUpRight_whiteToWhitePiece_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 1; begin_rank < 8; begin_rank++) {
        for (unsigned short begin_file = 0; begin_file < 7; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 7 && check_rank != 0) {
                check_file++;
                check_rank--;
            }
            end_file = check_file;
            end_rank = check_rank;

            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::BLACK_KING; white_piece++ ){
                board_.clearBoard();

                board_.board_[end_rank][end_file] = white_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_FALSE(actual_check);
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │    │    │ ♟  │ x  │ x  │ x  │ x  │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │    │ ♟  │    │    │    │    │    │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ ^  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♟ ----------------------->  │    │    │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagUpRight_whiteToWhitePiece_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 2; begin_rank < 8; begin_rank++) {
        for (unsigned short begin_file = 0; begin_file < 6; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 7 && check_rank != 0) {
                check_file++;
                check_rank--;
            }
            end_file = check_file;
            end_rank = check_rank;

            board_.clearBoard();

            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::BLACK_KING; white_piece++ ){
                board_.board_[end_rank][end_file] = white_piece;
                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (check_file = end_file - 1, check_rank = end_rank + 1; check_file != begin_file || check_rank != begin_rank; check_file--, check_rank++){
                        board_.board_[check_rank][check_file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │    │ x  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ ^  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♙ --------------------------->   │    │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagUpRight_blackToEmpty_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 1; begin_rank < 8; begin_rank++) {
        for (unsigned short begin_file = 0; begin_file < 7; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 7 && check_rank != 0) {
                check_file++;
                check_rank--;
            }
            end_file = check_file;
            end_rank = check_rank;

            board_.clearBoard();

            bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
            ASSERT_TRUE(actual_check);
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │    │    │ x  │ x  │ x  │ x  │ x  │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │    │ ♟  │    │    │    │    │    │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ ^  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♙ ----------------------->  │    │    │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagUpRight_blackToEmpty_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 2; begin_rank < 8; begin_rank++) {
        for (unsigned short begin_file = 0; begin_file < 6; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 7 && check_rank != 0) {
                check_file++;
                check_rank--;
            }
            end_file = check_file;
            end_rank = check_rank;

            for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                for (check_file = end_file - 1, check_rank = end_rank + 1; check_file != begin_file || check_rank != begin_rank; check_file--, check_rank++){
                    board_.clearBoard();

                    board_.board_[check_rank][check_file] = piece;
                    bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                    ASSERT_FALSE(actual_check);
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │    │ ♙  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ ^  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♙ ---------------------------->  │    │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagUpRight_blackToBlackPiece_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 1; begin_rank < 8; begin_rank++) {
        for (unsigned short begin_file = 0; begin_file < 7; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 7 && check_rank != 0) {
                check_file++;
                check_rank--;
            }
            end_file = check_file;
            end_rank = check_rank;

            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.clearBoard();

                board_.board_[end_rank][end_file] = black_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_FALSE(actual_check);
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │    │    │ ♙  │ x  │ x  │ x  │ x  │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │    │ ♟  │    │    │    │    │    │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ ^  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♙ ----------------------->  │    │    │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagUpRight_blackToBlackPiece_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 2; begin_rank < 8; begin_rank++) {
        for (unsigned short begin_file = 0; begin_file < 6; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 7 && check_rank != 0) {
                check_file++;
                check_rank--;
            }
            end_file = check_file;
            end_rank = check_rank;

            board_.clearBoard();

            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.board_[end_rank][end_file] = black_piece;
                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (check_file = end_file - 1, check_rank = end_rank + 1; check_file != begin_file || check_rank != begin_rank; check_file--, check_rank++){
                        board_.board_[check_rank][check_file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │    │ ♟  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ ^  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♙ ---------------------------->  │    │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagUpRight_blackToWhitePiece_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 1; begin_rank < 8; begin_rank++) {
        for (unsigned short begin_file = 0; begin_file < 7; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 7 && check_rank != 0) {
                check_file++;
                check_rank--;
            }
            end_file = check_file;
            end_rank = check_rank;

            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::BLACK_KING; white_piece++ ){
                board_.clearBoard();

                board_.board_[end_rank][end_file] = white_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_TRUE(actual_check);
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │    │    │ ♟  │ x  │ x  │ x  │ x  │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │    │ ♟  │    │    │    │    │    │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ ^  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ |  │    │    │    │    │    │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ ♟ ----------------------->  │    │    │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagUpRight_blackToWhitePiece_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 2; begin_rank < 8; begin_rank++) {
        for (unsigned short begin_file = 0; begin_file < 6; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 7 && check_rank != 0) {
                check_file++;
                check_rank--;
            }
            end_file = check_file;
            end_rank = check_rank;

            board_.clearBoard();

            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::BLACK_KING; white_piece++ ){
                board_.board_[end_rank][end_file] = white_piece;
                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (check_file = end_file - 1, check_rank = end_rank + 1; check_file != begin_file || check_rank != begin_rank; check_file--, check_rank++){
                        board_.board_[check_rank][check_file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

//DIAG_UP_LEFT

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ x  │ x  │ x  │ x  │ x  │ x  │ x  │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ x  │    │    │    │    │    │    │ ^  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       7 │    │  <--------------------------- ♟  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagUpLeft_whiteToEmpty_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 1; begin_rank < 8; begin_rank++) {
        for (unsigned short begin_file = 1; begin_file < 8; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 0 && check_rank != 0) {
                check_file--;
                check_rank--;
            }
            end_file = check_file;
            end_rank = check_rank;

            board_.clearBoard();

            bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
            ASSERT_TRUE(actual_check);
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ x  │ x  │ x  │ x  │ x  │ x  │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ x  │    │    │    │    │    │ ♟  │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ x  │    │    │    │    │    │    │ ^  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │    │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       7 │    │    │  <---------------------- ♟  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagUpLeft_whiteToEmpty_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 2; begin_rank < 8; begin_rank++) {
        for (unsigned short begin_file = 2; begin_file < 8; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 0 && check_rank != 0) {
                check_file--;
                check_rank--;
            }
            end_file = check_file;
            end_rank = check_rank;

            for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                for (check_file = end_file + 1, check_rank = end_rank + 1; check_file != begin_file || check_rank != begin_rank; check_file++, check_rank++){
                    board_.clearBoard();

                    board_.board_[check_rank][check_file] = piece;
                    bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                    ASSERT_FALSE(actual_check);
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ x  │ x  │ x  │ x  │ x  │ x  │ ♙  │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ x  │    │    │    │    │    │    │ ^  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       7 │    │  <--------------------------- ♟  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagUpLeft_whiteToBlackPiece_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 1; begin_rank < 8; begin_rank++) {
        for (unsigned short begin_file = 1; begin_file < 8; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 0 && check_rank != 0) {
                check_file--;
                check_rank--;
            }
            end_file = check_file;
            end_rank = check_rank;

            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.clearBoard();

                board_.board_[end_rank][end_file] = black_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_TRUE(actual_check);
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ x  │ x  │ x  │ x  │ x  │ ♙  │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ x  │    │    │    │    │    │ ♟  │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ x  │    │    │    │    │    │    │ ^  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │    │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       7 │    │    │  <---------------------- ♟  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagUpLeft_whiteToBlackPiece_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 2; begin_rank < 8; begin_rank++) {
        for (unsigned short begin_file = 2; begin_file < 8; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 0 && check_rank != 0) {
                check_file--;
                check_rank--;
            }
            end_file = check_file;
            end_rank = check_rank;

            board_.clearBoard();

            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.board_[end_rank][end_file] = black_piece;
                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (check_file = end_file + 1, check_rank = end_rank + 1; check_file != begin_file || check_rank != begin_rank; check_file++, check_rank++){
                        board_.board_[check_rank][check_file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ x  │ x  │ x  │ x  │ x  │ x  │ ♟  │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ x  │    │    │    │    │    │    │ ^  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       7 │    │  <--------------------------- ♟  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagUpLeft_whiteToWhitePiece_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 1; begin_rank < 8; begin_rank++) {
        for (unsigned short begin_file = 1; begin_file < 8; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 0 && check_rank != 0) {
                check_file--;
                check_rank--;
            }
            end_file = check_file;
            end_rank = check_rank;

            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::BLACK_KING; white_piece++ ){
                board_.clearBoard();

                board_.board_[end_rank][end_file] = white_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_FALSE(actual_check);
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ x  │ x  │ x  │ x  │ x  │ ♟  │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ x  │    │    │    │    │    │ ♙  │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ x  │    │    │    │    │    │    │ ^  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │    │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       7 │    │    │  <---------------------- ♟  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagUpLeft_whiteToWhitePiece_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 2; begin_rank < 8; begin_rank++) {
        for (unsigned short begin_file = 2; begin_file < 8; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 0 && check_rank != 0) {
                check_file--;
                check_rank--;
            }
            end_file = check_file;
            end_rank = check_rank;

            board_.clearBoard();

            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::BLACK_KING; white_piece++ ){
                board_.board_[end_rank][end_file] = white_piece;
                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (check_file = end_file + 1, check_rank = end_rank + 1; check_file != begin_file || check_rank != begin_rank; check_file++, check_rank++){
                        board_.board_[check_rank][check_file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ x  │ x  │ x  │ x  │ x  │ x  │ x  │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ x  │    │    │    │    │    │    │ ^  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       7 │    │  <--------------------------- ♙  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagUpLeft_blackToEmpty_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 1; begin_rank < 8; begin_rank++) {
        for (unsigned short begin_file = 1; begin_file < 8; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 0 && check_rank != 0) {
                check_file--;
                check_rank--;
            }
            end_file = check_file;
            end_rank = check_rank;

            board_.clearBoard();

            bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
            ASSERT_TRUE(actual_check);
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ x  │ x  │ x  │ x  │ x  │ x  │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ x  │    │    │    │    │    │ ♙  │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ x  │    │    │    │    │    │    │ ^  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │    │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       7 │    │    │  <---------------------- ♙  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagUpLeft_blackToEmpty_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 2; begin_rank < 8; begin_rank++) {
        for (unsigned short begin_file = 2; begin_file < 8; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 0 && check_rank != 0) {
                check_file--;
                check_rank--;
            }
            end_file = check_file;
            end_rank = check_rank;

            for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                for (check_file = end_file + 1, check_rank = end_rank + 1; check_file != begin_file || check_rank != begin_rank; check_file++, check_rank++){
                    board_.clearBoard();

                    board_.board_[check_rank][check_file] = piece;
                    bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                    ASSERT_FALSE(actual_check);
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ x  │ x  │ x  │ x  │ x  │ x  │ ♙  │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ x  │    │    │    │    │    │    │ ^  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       7 │    │  <--------------------------- ♙  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagUpLeft_blackToBlackPiece_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 1; begin_rank < 8; begin_rank++) {
        for (unsigned short begin_file = 1; begin_file < 8; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 0 && check_rank != 0) {
                check_file--;
                check_rank--;
            }
            end_file = check_file;
            end_rank = check_rank;

            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.clearBoard();

                board_.board_[end_rank][end_file] = black_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_FALSE(actual_check);
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ x  │ x  │ x  │ x  │ x  │ ♙  │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ x  │    │    │    │    │    │ ♙  │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ x  │    │    │    │    │    │    │ ^  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │    │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       7 │    │    │  <---------------------- ♙  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagUpLeft_blackToBlackPiece_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 2; begin_rank < 8; begin_rank++) {
        for (unsigned short begin_file = 2; begin_file < 8; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 0 && check_rank != 0) {
                check_file--;
                check_rank--;
            }
            end_file = check_file;
            end_rank = check_rank;

            board_.clearBoard();

            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.board_[end_rank][end_file] = black_piece;
                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (check_file = end_file + 1, check_rank = end_rank + 1; check_file != begin_file || check_rank != begin_rank; check_file++, check_rank++){
                        board_.board_[check_rank][check_file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ x  │ x  │ x  │ x  │ x  │ x  │ ♟  │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ x  │    │    │    │    │    │    │ ^  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       7 │    │  <--------------------------- ♙  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagUpLeft_blackToWhitePiece_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 1; begin_rank < 8; begin_rank++) {
        for (unsigned short begin_file = 1; begin_file < 8; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 0 && check_rank != 0) {
                check_file--;
                check_rank--;
            }
            end_file = check_file;
            end_rank = check_rank;

            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::BLACK_KING; white_piece++ ){
                board_.clearBoard();

                board_.board_[end_rank][end_file] = white_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_TRUE(actual_check);
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ x  │ x  │ x  │ x  │ x  │ ♟  │    │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ x  │    │    │    │    │    │ ♙  │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ x  │    │    │    │    │    │    │ ^  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │    │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       7 │    │    │  <---------------------- ♙  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagUpLeft_blackToWhitePiece_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 2; begin_rank < 8; begin_rank++) {
        for (unsigned short begin_file = 2; begin_file < 8; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 0 && check_rank != 0) {
                check_file--;
                check_rank--;
            }
            end_file = check_file;
            end_rank = check_rank;

            board_.clearBoard();

            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::BLACK_KING; white_piece++ ){
                board_.board_[end_rank][end_file] = white_piece;
                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (check_file = end_file + 1, check_rank = end_rank + 1; check_file != begin_file || check_rank != begin_rank; check_file++, check_rank++){
                        board_.board_[check_rank][check_file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

// DIAG_DOWN_RIGHT

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟ ---------------------------->  │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ v  │    │    │    │    │    │    │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │    │ x  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagDownRight_whiteToEmpty_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 0; begin_rank < 7; begin_rank++) {
        for (unsigned short begin_file = 0; begin_file < 7; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 7 && check_rank != 7) {
                check_file++;
                check_rank++;
            }
            end_file = check_file;
            end_rank = check_rank;

            board_.clearBoard();

            bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
            ASSERT_TRUE(actual_check);
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟ ----------------------->  │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │ ♟  │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ v  │    │    │    │    │    │    │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │    │    │    │    │    │    │    │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │    │    │ x  │ x  │ x  │ x  │ x  │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagDownRight_whiteToEmpty_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 0; begin_rank < 6; begin_rank++) {
        for (unsigned short begin_file = 0; begin_file < 6; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 7 && check_rank != 7) {
                check_file++;
                check_rank++;
            }
            end_file = check_file;
            end_rank = check_rank;

            for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                for (check_file = end_file - 1, check_rank = end_rank - 1; check_file != begin_file || check_rank != begin_rank; check_file--, check_rank--){
                    board_.clearBoard();

                    board_.board_[check_rank][check_file] = piece;
                    bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                    ASSERT_FALSE(actual_check);
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟ ---------------------------->  │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │ ♙  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ v  │    │    │    │    │    │    │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │    │ x  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagDownRight_whiteToBlackPiece_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 0; begin_rank < 7; begin_rank++) {
        for (unsigned short begin_file = 0; begin_file < 7; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 7 && check_rank != 7) {
                check_file++;
                check_rank++;
            }
            end_file = check_file;
            end_rank = check_rank;

            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.clearBoard();

                board_.board_[end_rank][end_file] = black_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_TRUE(actual_check);
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟ ----------------------->  │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │ ♟  │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ ♙  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ v  │    │    │    │    │    │    │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │    │    │    │    │    │    │    │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │    │    │ x  │ x  │ x  │ x  │ x  │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagDownRight_whiteToBlackPiece_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 0; begin_rank < 7; begin_rank++) {
        for (unsigned short begin_file = 0; begin_file < 7; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 7 && check_rank != 7) {
                check_file++;
                check_rank++;
            }
            end_file = check_file;
            end_rank = check_rank;

            board_.clearBoard();

            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.board_[end_rank][end_file] = black_piece;
                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (check_file = end_file - 1, check_rank = end_rank - 1; check_file != begin_file || check_rank != begin_rank; check_file--, check_rank--){
                        board_.board_[check_rank][check_file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟ ---------------------------->  │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │ ♟  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ v  │    │    │    │    │    │    │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │    │ x  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagDownRight_whiteToWhitePiece_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 0; begin_rank < 7; begin_rank++) {
        for (unsigned short begin_file = 0; begin_file < 7; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 7 && check_rank != 7) {
                check_file++;
                check_rank++;
            }
            end_file = check_file;
            end_rank = check_rank;

            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::BLACK_KING; white_piece++ ){
                board_.clearBoard();

                board_.board_[end_rank][end_file] = white_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_FALSE(actual_check);
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♟ ----------------------->  │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │ ♟  │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ ♟  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ v  │    │    │    │    │    │    │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │    │    │    │    │    │    │    │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │    │    │ x  │ x  │ x  │ x  │ x  │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagDownRight_whiteToWhitePiece_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 0; begin_rank < 6; begin_rank++) {
        for (unsigned short begin_file = 0; begin_file < 6; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 7 && check_rank != 7) {
                check_file++;
                check_rank++;
            }
            end_file = check_file;
            end_rank = check_rank;

            board_.clearBoard();

            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::BLACK_KING; white_piece++ ){
                board_.board_[end_rank][end_file] = white_piece;
                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (check_file = end_file - 1, check_rank = end_rank - 1; check_file != begin_file || check_rank != begin_rank; check_file--, check_rank--){
                        board_.board_[check_rank][check_file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙ ---------------------------->  │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ v  │    │    │    │    │    │    │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │    │ x  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagDownRight_blackToEmpty_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 0; begin_rank < 7; begin_rank++) {
        for (unsigned short begin_file = 0; begin_file < 7; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 7 && check_rank != 7) {
                check_file++;
                check_rank++;
            }
            end_file = check_file;
            end_rank = check_rank;

            board_.clearBoard();

            bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
            ASSERT_TRUE(actual_check);
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙ ----------------------->  │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │ ♟  │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ v  │    │    │    │    │    │    │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │    │    │    │    │    │    │    │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │    │    │ x  │ x  │ x  │ x  │ x  │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagDownRight_blackToEmpty_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 0; begin_rank < 6; begin_rank++) {
        for (unsigned short begin_file = 0; begin_file < 6; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 7 && check_rank != 7) {
                check_file++;
                check_rank++;
            }
            end_file = check_file;
            end_rank = check_rank;

            for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                for (check_file = end_file - 1, check_rank = end_rank - 1; check_file != begin_file || check_rank != begin_rank; check_file--, check_rank--){
                    board_.clearBoard();

                    board_.board_[check_rank][check_file] = piece;
                    bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                    ASSERT_FALSE(actual_check);
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙ ---------------------------->  │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │ ♙  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ v  │    │    │    │    │    │    │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │    │ x  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagDownRight_blackToBlackPiece_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 0; begin_rank < 7; begin_rank++) {
        for (unsigned short begin_file = 0; begin_file < 7; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 7 && check_rank != 7) {
                check_file++;
                check_rank++;
            }
            end_file = check_file;
            end_rank = check_rank;

            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.clearBoard();

                board_.board_[end_rank][end_file] = black_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_FALSE(actual_check);
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙ ----------------------->  │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │ ♟  │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ ♙  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ v  │    │    │    │    │    │    │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │    │    │    │    │    │    │    │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │    │    │ x  │ x  │ x  │ x  │ x  │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagDownRight_blackToBlackPiece_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 0; begin_rank < 6; begin_rank++) {
        for (unsigned short begin_file = 0; begin_file < 6; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 7 && check_rank != 7) {
                check_file++;
                check_rank++;
            }
            end_file = check_file;
            end_rank = check_rank;

            board_.clearBoard();

            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.board_[end_rank][end_file] = black_piece;
                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (check_file = end_file - 1, check_rank = end_rank - 1; check_file != begin_file || check_rank != begin_rank; check_file--, check_rank--){
                        board_.board_[check_rank][check_file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙ ---------------------------->  │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │    │ ♟  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ x  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ v  │    │    │    │    │    │    │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │    │ x  │ x  │ x  │ x  │ x  │ x  │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagDownRight_blackToWhitePiece_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 0; begin_rank < 7; begin_rank++) {
        for (unsigned short begin_file = 0; begin_file < 7; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 7 && check_rank != 7) {
                check_file++;
                check_rank++;
            }
            end_file = check_file;
            end_rank = check_rank;

            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::BLACK_KING; white_piece++ ){
                board_.clearBoard();

                board_.board_[end_rank][end_file] = white_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_TRUE(actual_check);
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │ ♙ ----------------------->  │    │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       1 │ |  │    │    │    │    │    │ ♟  │    │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       2 │ |  │    │    │    │    │    │    │ ♟  │
 *   r     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   a   3 │ |  │    │    │    │    │    │    │ x  │
 *   n     ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *   k   4 │ |  │    │    │    │    │    │    │ x  │
 *         ├─|──┼────┼────┼────┼────┼────┼────┼────┤
 *       5 │ v  │    │    │    │    │    │    │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │    │    │    │    │    │    │    │ x  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │    │    │ x  │ x  │ x  │ x  │ x  │ x  │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagDownRight_blackToWhitePiece_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 0; begin_rank < 6; begin_rank++) {
        for (unsigned short begin_file = 0; begin_file < 6; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 7 && check_rank != 7) {
                check_file++;
                check_rank++;
            }
            end_file = check_file;
            end_rank = check_rank;

            board_.clearBoard();

            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::BLACK_KING; white_piece++ ){
                board_.board_[end_rank][end_file] = white_piece;
                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (check_file = end_file - 1, check_rank = end_rank - 1; check_file != begin_file || check_rank != begin_rank; check_file--, check_rank--){
                        board_.board_[check_rank][check_file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}


// DIAG_DOWN_LEFT


/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │    │  <--------------------------- ♟  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       1 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │ x  │    │    │    │    │    │    │ v  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ x  │ x  │ x  │ x  │ x  │ x  │ x  │    │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagDownLeft_whiteToEmpty_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 0; begin_rank < 7; begin_rank++) {
        for (unsigned short begin_file = 1; begin_file < 8; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 0 && check_rank != 7) {
                check_file--;
                check_rank++;
            }
            end_file = check_file;
            end_rank = check_rank;

            board_.clearBoard();

            bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
            ASSERT_TRUE(actual_check);
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │    │    │  <---------------------- ♟  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       1 │    │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ v  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ x  │    │    │    │    │    │ ♟  │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ x  │ x  │ x  │ x  │ x  │ x  │    │    │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagDownLeft_whiteToEmpty_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 0; begin_rank < 6; begin_rank++) {
        for (unsigned short begin_file = 2; begin_file < 8; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 0 && check_rank != 7) {
                check_file--;
                check_rank++;
            }
            end_file = check_file;
            end_rank = check_rank;

            for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                for (check_file = end_file + 1, check_rank = end_rank - 1; check_file != begin_file || check_rank != begin_rank; check_file++, check_rank--){
                    board_.clearBoard();

                    board_.board_[check_rank][check_file] = piece;
                    bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                    ASSERT_FALSE(actual_check);
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │    │  <--------------------------- ♟  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       1 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │ x  │    │    │    │    │    │    │ v  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ x  │ x  │ x  │ x  │ x  │ x  │ ♙  │    │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagDownLeft_whiteToBlackPiece_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 0; begin_rank < 7; begin_rank++) {
        for (unsigned short begin_file = 1; begin_file < 8; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 0 && check_rank != 7) {
                check_file--;
                check_rank++;
            }
            end_file = check_file;
            end_rank = check_rank;

            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.clearBoard();

                board_.board_[end_rank][end_file] = black_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_TRUE(actual_check);
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │    │    │  <---------------------- ♟  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       1 │    │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ v  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ x  │    │    │    │    │    │ ♟  │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ x  │ x  │ x  │ x  │ x  │ ♙  │    │    │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagDownLeft_whiteToBlackPiece_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 1; begin_rank < 7; begin_rank++) {
        for (unsigned short begin_file = 2; begin_file < 8; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 0 && check_rank != 7) {
                check_file--;
                check_rank++;
            }
            end_file = check_file;
            end_rank = check_rank;

            board_.clearBoard();

            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.board_[end_rank][end_file] = black_piece;
                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (check_file = end_file + 1, check_rank = end_rank - 1; check_file != begin_file || check_rank != begin_rank; check_file++, check_rank--){
                        board_.board_[check_rank][check_file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │    │  <--------------------------- ♟  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       1 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │ x  │    │    │    │    │    │    │ v  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ x  │ x  │ x  │ x  │ x  │ x  │ ♟  │    │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagDownLeft_whiteToWhitePiece_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 0; begin_rank < 7; begin_rank++) {
        for (unsigned short begin_file = 1; begin_file < 8; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 0 && check_rank != 7) {
                check_file--;
                check_rank++;
            }
            end_file = check_file;
            end_rank = check_rank;

            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::BLACK_KING; white_piece++ ){
                board_.clearBoard();

                board_.board_[end_rank][end_file] = white_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_FALSE(actual_check);
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │    │    │  <---------------------- ♟  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       1 │    │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ v  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ x  │    │    │    │    │    │ ♟  │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ x  │ x  │ x  │ x  │ x  │ ♟  │    │    │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagDownLeft_whiteToWhitePiece_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = true;

    for (unsigned short begin_rank = 0; begin_rank < 6; begin_rank++) {
        for (unsigned short begin_file = 2; begin_file < 8; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 0 && check_rank != 7) {
                check_file--;
                check_rank++;
            }
            end_file = check_file;
            end_rank = check_rank;

            board_.clearBoard();

            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::BLACK_KING; white_piece++ ){
                board_.board_[end_rank][end_file] = white_piece;
                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (check_file = end_file + 1, check_rank = end_rank - 1; check_file != begin_file || check_rank != begin_rank; check_file++, check_rank--){
                        board_.board_[check_rank][check_file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │    │  <--------------------------- ♙  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       1 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │ x  │    │    │    │    │    │    │ v  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ x  │ x  │ x  │ x  │ x  │ x  │ x  │    │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagDownLeft_blackToEmpty_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 0; begin_rank < 7; begin_rank++) {
        for (unsigned short begin_file = 1; begin_file < 8; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 0 && check_rank != 7) {
                check_file--;
                check_rank++;
            }
            end_file = check_file;
            end_rank = check_rank;

            board_.clearBoard();

            bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
            ASSERT_TRUE(actual_check);
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │    │    │  <---------------------- ♙  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       1 │    │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ v  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ x  │    │    │    │    │    │ ♟  │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ x  │ x  │ x  │ x  │ x  │ x  │    │    │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagDownLeft_blackToEmpty_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 0; begin_rank < 6; begin_rank++) {
        for (unsigned short begin_file = 2; begin_file < 8; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 0 && check_rank != 7) {
                check_file--;
                check_rank++;
            }
            end_file = check_file;
            end_rank = check_rank;

            for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                for (check_file = end_file + 1, check_rank = end_rank - 1; check_file != begin_file || check_rank != begin_rank; check_file++, check_rank--){
                    board_.clearBoard();

                    board_.board_[check_rank][check_file] = piece;
                    bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                    ASSERT_FALSE(actual_check);
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │    │  <--------------------------- ♙  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       1 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │ x  │    │    │    │    │    │    │ v  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ x  │ x  │ x  │ x  │ x  │ x  │ ♙  │    │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagDownLeft_blackToBlackPiece_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 0; begin_rank < 7; begin_rank++) {
        for (unsigned short begin_file = 1; begin_file < 8; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 0 && check_rank != 7) {
                check_file--;
                check_rank++;
            }
            end_file = check_file;
            end_rank = check_rank;

            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.clearBoard();

                board_.board_[end_rank][end_file] = black_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_FALSE(actual_check);
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │    │    │  <---------------------- ♙  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       1 │    │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ v  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ x  │    │    │    │    │    │ ♟  │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ x  │ x  │ x  │ x  │ x  │ ♙  │    │    │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagDownLeft_blackToBlackPiece_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 0; begin_rank < 6; begin_rank++) {
        for (unsigned short begin_file = 2; begin_file < 8; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 0 && check_rank != 7) {
                check_file--;
                check_rank++;
            }
            end_file = check_file;
            end_rank = check_rank;

            board_.clearBoard();

            for (unsigned short black_piece = chess::Chessboard::piece::BLACK_KING; black_piece != chess::Chessboard::piece::BLACK_PAWN + 1; black_piece++) {
                board_.board_[end_rank][end_file] = black_piece;
                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (check_file = end_file + 1, check_rank = end_rank - 1; check_file != begin_file || check_rank != begin_rank; check_file++, check_rank--){
                        board_.board_[check_rank][check_file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │    │  <--------------------------- ♙  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       1 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       6 │ x  │    │    │    │    │    │    │ v  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ x  │ x  │ x  │ x  │ x  │ x  │ ♟  │    │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagDownLeft_blackToWhitePiece_nothingInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 0; begin_rank < 7; begin_rank++) {
        for (unsigned short begin_file = 1; begin_file < 8; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 0 && check_rank != 7) {
                check_file--;
                check_rank++;
            }
            end_file = check_file;
            end_rank = check_rank;

            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::BLACK_KING; white_piece++ ){
                board_.clearBoard();

                board_.board_[end_rank][end_file] = white_piece;
                bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                ASSERT_TRUE(actual_check);
            }
        }
    }
}

/**
 * @brief   This test will use a white piece and try to go to the
 *          end of the board for a full movement. There is nothing
 *          in the way of the piece this time. Starting rank ranges
 *          from 0-7, and file 7-1.         
 *         ┌────┬────┬────┬────┬────┬────┬────┬────┐
 *       0 │    │    │  <---------------------- ♙  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       1 │    │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       2 │ x  │    │    │    │    │    │    │ |  │
 *   r     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   a   3 │ x  │    │    │    │    │    │    │ |  │
 *   n     ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *   k   4 │ x  │    │    │    │    │    │    │ |  │
 *         ├────┼────┼────┼────┼────┼────┼────┼─|──┤
 *       5 │ x  │    │    │    │    │    │    │ v  │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       6 │ x  │    │    │    │    │    │ ♟  │    │
 *         ├────┼────┼────┼────┼────┼────┼────┼────┤
 *       7 │ x  │ x  │ x  │ x  │ x  │ ♟  │    │    │
 *         └────┴────┴────┴────┴────┴────┴────┴────┘
 *            0    1    2    3    4    5    6    7 
 *                          file
 */
TEST_F(ChessboardTest, checkLine_moveDiagDownLeft_blackToWhitePiece_piecesInbetween){
    unsigned short end_file;
    unsigned short end_rank;
    unsigned short check_file;
    unsigned short check_rank;
    bool is_white = false;

    for (unsigned short begin_rank = 0; begin_rank < 6; begin_rank++) {
        for (unsigned short begin_file = 2; begin_file < 8; begin_file++) {
            check_file = begin_file;
            check_rank = begin_rank;
            while(check_file != 0 && check_rank != 7) {
                check_file--;
                check_rank++;
            }
            end_file = check_file;
            end_rank = check_rank;

            board_.clearBoard();

            for (unsigned short white_piece = chess::Chessboard::piece::WHITE_KING; white_piece != chess::Chessboard::piece::BLACK_KING; white_piece++ ){
                board_.board_[end_rank][end_file] = white_piece;
                for (unsigned short piece = chess::Chessboard::piece::WHITE_KING; piece != chess::Chessboard::piece::BLACK_PAWN + 1; piece++){
                    for (check_file = end_file + 1, check_rank = end_rank - 1; check_file != begin_file || check_rank != begin_rank; check_file++, check_rank--){
                        board_.board_[check_rank][check_file] = piece;
                        bool actual_check = board_.checkLine(begin_file, begin_rank, end_file, end_rank, is_white);
                        ASSERT_FALSE(actual_check);

                        board_.clearBoard();
                    }
                }
            }
        }
    }
}

/*****************************************************************
*
* TEST FUNCTION: checkMove
*
* note: Unit tests for the checkMove of the Chessboard class
*       Assumes that all inputs have been sanitized to get rid
*       of bad inputs (like off of the board, not a piece, etc.)
*
*****************************************************************/

// White King
TEST_F(ChessboardTest, checkMove_whiteKing_moveEmptySpace){
    unsigned short file = 4;
    unsigned short rank = 4;
    chess::Chessboard::piece test_piece = chess::Chessboard::piece::WHITE_KING;
    chess::Chessboard::action move = chess::Chessboard::action::MOVE;
    chess::Chessboard::action no_option = chess::Chessboard::action::NO_OPTION;

    bool can_move [8][8];
    can_move[0][0] = false; can_move[0][1] = false; can_move[0][2] = false; can_move[0][3] = false; can_move[0][4] = false; can_move[0][5] = false; can_move[0][6] = false; can_move[0][7] = false;
    can_move[1][0] = false; can_move[1][1] = false; can_move[1][2] = false; can_move[1][3] = false; can_move[1][4] = false; can_move[1][5] = false; can_move[1][6] = false; can_move[1][7] = false;
    can_move[2][0] = false; can_move[2][1] = false; can_move[2][2] = false; can_move[2][3] = false; can_move[2][4] = false; can_move[2][5] = false; can_move[2][6] = false; can_move[2][7] = false;
    can_move[3][0] = false; can_move[3][1] = false; can_move[3][2] = false; can_move[3][3] = true;  can_move[3][4] = true;  can_move[3][5] = true;  can_move[3][6] = false; can_move[3][7] = false;
    can_move[4][0] = false; can_move[4][1] = false; can_move[4][2] = false; can_move[4][3] = true;  can_move[4][4] = false; can_move[4][5] = true;  can_move[4][6] = false; can_move[4][7] = false;
    can_move[5][0] = false; can_move[5][1] = false; can_move[5][2] = false; can_move[5][3] = true;  can_move[5][4] = true;  can_move[5][5] = true;  can_move[5][6] = false; can_move[5][7] = false;
    can_move[6][0] = false; can_move[6][1] = false; can_move[6][2] = false; can_move[6][3] = false; can_move[6][4] = false; can_move[6][5] = false; can_move[6][6] = false; can_move[6][7] = false;
    can_move[7][0] = false; can_move[7][1] = false; can_move[7][2] = false; can_move[7][3] = false; can_move[7][4] = false; can_move[7][5] = false; can_move[7][6] = false; can_move[7][7] = false;
        
    board_.clearBoard();

    for(unsigned short tFile = 0; tFile < 8; tFile++){
        for(unsigned short tRank = 0; tRank < 8; tRank++){
            board_.board_[rank][file] = test_piece;

            bool expected_check = can_move[tRank][tFile];
            bool actual_check = board_.checkMove(test_piece, file, rank, tFile, tRank, move, no_option);
            ASSERT_EQ(expected_check, actual_check);

            board_.clearBoard();
        }
    }
}

//White Queen
TEST_F(ChessboardTest, checkMove_whiteQueen_moveEmptySpace){
    unsigned short file = 4;
    unsigned short rank = 4;
    chess::Chessboard::piece test_piece = chess::Chessboard::piece::WHITE_QUEEN;
    chess::Chessboard::action move = chess::Chessboard::action::MOVE;
    chess::Chessboard::action no_option = chess::Chessboard::action::NO_OPTION;

    bool can_move [8][8];
    can_move[0][0] = true;  can_move[0][1] = false; can_move[0][2] = false; can_move[0][3] = false; can_move[0][4] = true;  can_move[0][5] = false; can_move[0][6] = false; can_move[0][7] = false;
    can_move[1][0] = false; can_move[1][1] = true;  can_move[1][2] = false; can_move[1][3] = false; can_move[1][4] = true;  can_move[1][5] = false; can_move[1][6] = false; can_move[1][7] = true;
    can_move[2][0] = false; can_move[2][1] = false; can_move[2][2] = true;  can_move[2][3] = false; can_move[2][4] = true;  can_move[2][5] = false; can_move[2][6] = true;  can_move[2][7] = false;
    can_move[3][0] = false; can_move[3][1] = false; can_move[3][2] = false; can_move[3][3] = true;  can_move[3][4] = true;  can_move[3][5] = true;  can_move[3][6] = false; can_move[3][7] = false;
    can_move[4][0] = true;  can_move[4][1] = true;  can_move[4][2] = true;  can_move[4][3] = true;  can_move[4][4] = false; can_move[4][5] = true;  can_move[4][6] = true;  can_move[4][7] = true;
    can_move[5][0] = false; can_move[5][1] = false; can_move[5][2] = false; can_move[5][3] = true;  can_move[5][4] = true;  can_move[5][5] = true;  can_move[5][6] = false; can_move[5][7] = false;
    can_move[6][0] = false; can_move[6][1] = false; can_move[6][2] = true;  can_move[6][3] = false; can_move[6][4] = true;  can_move[6][5] = false; can_move[6][6] = true;  can_move[6][7] = false;
    can_move[7][0] = false; can_move[7][1] = true;  can_move[7][2] = false; can_move[7][3] = false; can_move[7][4] = true;  can_move[7][5] = false; can_move[7][6] = false; can_move[7][7] = true;
        
    board_.clearBoard();

    for(unsigned short tFile = 0; tFile < 8; tFile++){
        for(unsigned short tRank = 0; tRank < 8; tRank++){
            board_.board_[rank][file] = test_piece;

            bool expected_check = can_move[tRank][tFile];
            bool actual_check = board_.checkMove(test_piece, file, rank, tFile, tRank, move, no_option);
            ASSERT_EQ(expected_check, actual_check);

            board_.clearBoard();
        }
    }
}

//White Rook
TEST_F(ChessboardTest, checkMove_whiteRook_moveEmptySpace){
    unsigned short file = 4;
    unsigned short rank = 4;
    chess::Chessboard::piece test_piece = chess::Chessboard::piece::WHITE_ROOK;
    chess::Chessboard::action move = chess::Chessboard::action::MOVE;
    chess::Chessboard::action no_option = chess::Chessboard::action::NO_OPTION;

    bool can_move [8][8];
    can_move[0][0] = false; can_move[0][1] = false; can_move[0][2] = false; can_move[0][3] = false; can_move[0][4] = true;  can_move[0][5] = false; can_move[0][6] = false; can_move[0][7] = false;
    can_move[1][0] = false; can_move[1][1] = false; can_move[1][2] = false; can_move[1][3] = false; can_move[1][4] = true;  can_move[1][5] = false; can_move[1][6] = false; can_move[1][7] = false;
    can_move[2][0] = false; can_move[2][1] = false; can_move[2][2] = false; can_move[2][3] = false; can_move[2][4] = true;  can_move[2][5] = false; can_move[2][6] = false; can_move[2][7] = false;
    can_move[3][0] = false; can_move[3][1] = false; can_move[3][2] = false; can_move[3][3] = false; can_move[3][4] = true;  can_move[3][5] = false; can_move[3][6] = false; can_move[3][7] = false;
    can_move[4][0] = true;  can_move[4][1] = true;  can_move[4][2] = true;  can_move[4][3] = true;  can_move[4][4] = false; can_move[4][5] = true;  can_move[4][6] = true;  can_move[4][7] = true;
    can_move[5][0] = false; can_move[5][1] = false; can_move[5][2] = false; can_move[5][3] = false; can_move[5][4] = true;  can_move[5][5] = false; can_move[5][6] = false; can_move[5][7] = false;
    can_move[6][0] = false; can_move[6][1] = false; can_move[6][2] = false; can_move[6][3] = false; can_move[6][4] = true;  can_move[6][5] = false; can_move[6][6] = false; can_move[6][7] = false;
    can_move[7][0] = false; can_move[7][1] = false; can_move[7][2] = false; can_move[7][3] = false; can_move[7][4] = true;  can_move[7][5] = false; can_move[7][6] = false; can_move[7][7] = false;
        
    board_.clearBoard();

    for(unsigned short tFile = 0; tFile < 8; tFile++){
        for(unsigned short tRank = 0; tRank < 8; tRank++){
            board_.board_[rank][file] = test_piece;

            bool expected_check = can_move[tRank][tFile];
            bool actual_check = board_.checkMove(test_piece, file, rank, tFile, tRank, move, no_option);
            ASSERT_EQ(expected_check, actual_check);

            board_.clearBoard();
        }
    }
}

//White Bishop
TEST_F(ChessboardTest, checkMove_whiteBishop_moveEmptySpace){
    unsigned short file = 4;
    unsigned short rank = 4;
    chess::Chessboard::piece test_piece = chess::Chessboard::piece::WHITE_BISHOP;
    chess::Chessboard::action move = chess::Chessboard::action::MOVE;
    chess::Chessboard::action no_option = chess::Chessboard::action::NO_OPTION;

    bool can_move [8][8];
    can_move[0][0] = true;  can_move[0][1] = false; can_move[0][2] = false; can_move[0][3] = false; can_move[0][4] = false; can_move[0][5] = false; can_move[0][6] = false; can_move[0][7] = false;
    can_move[1][0] = false; can_move[1][1] = true;  can_move[1][2] = false; can_move[1][3] = false; can_move[1][4] = false; can_move[1][5] = false; can_move[1][6] = false; can_move[1][7] = true;
    can_move[2][0] = false; can_move[2][1] = false; can_move[2][2] = true;  can_move[2][3] = false; can_move[2][4] = false; can_move[2][5] = false; can_move[2][6] = true;  can_move[2][7] = false;
    can_move[3][0] = false; can_move[3][1] = false; can_move[3][2] = false; can_move[3][3] = true;  can_move[3][4] = false; can_move[3][5] = true;  can_move[3][6] = false; can_move[3][7] = false;
    can_move[4][0] = false; can_move[4][1] = false; can_move[4][2] = false; can_move[4][3] = false; can_move[4][4] = false; can_move[4][5] = false; can_move[4][6] = false; can_move[4][7] = false;
    can_move[5][0] = false; can_move[5][1] = false; can_move[5][2] = false; can_move[5][3] = true;  can_move[5][4] = false; can_move[5][5] = true;  can_move[5][6] = false; can_move[5][7] = false;
    can_move[6][0] = false; can_move[6][1] = false; can_move[6][2] = true;  can_move[6][3] = false; can_move[6][4] = false; can_move[6][5] = false; can_move[6][6] = true;  can_move[6][7] = false;
    can_move[7][0] = false; can_move[7][1] = true;  can_move[7][2] = false; can_move[7][3] = false; can_move[7][4] = false; can_move[7][5] = false; can_move[7][6] = false; can_move[7][7] = true;
        
    board_.clearBoard();

    for(unsigned short tFile = 0; tFile < 8; tFile++){
        for(unsigned short tRank = 0; tRank < 8; tRank++){
            board_.board_[rank][file] = test_piece;

            bool expected_check = can_move[tRank][tFile];
            bool actual_check = board_.checkMove(test_piece, file, rank, tFile, tRank, move, no_option);
            ASSERT_EQ(expected_check, actual_check);

            board_.clearBoard();
        }
    }
}

//White Knight
TEST_F(ChessboardTest, checkMove_whiteKnight_moveEmptySpace){
    unsigned short file = 4;
    unsigned short rank = 4;
    chess::Chessboard::piece test_piece = chess::Chessboard::piece::WHITE_KNIGHT;
    chess::Chessboard::action move = chess::Chessboard::action::MOVE;
    chess::Chessboard::action no_option = chess::Chessboard::action::NO_OPTION;

    bool can_move [8][8];
    can_move[0][0] = false; can_move[0][1] = false; can_move[0][2] = false; can_move[0][3] = false; can_move[0][4] = false; can_move[0][5] = false; can_move[0][6] = false; can_move[0][7] = false;
    can_move[1][0] = false; can_move[1][1] = false; can_move[1][2] = false; can_move[1][3] = false; can_move[1][4] = false; can_move[1][5] = false; can_move[1][6] = false; can_move[1][7] = false;
    can_move[2][0] = false; can_move[2][1] = false; can_move[2][2] = false; can_move[2][3] = true;  can_move[2][4] = false; can_move[2][5] = true;  can_move[2][6] = false; can_move[2][7] = false;
    can_move[3][0] = false; can_move[3][1] = false; can_move[3][2] = true;  can_move[3][3] = false; can_move[3][4] = false; can_move[3][5] = false; can_move[3][6] = true;  can_move[3][7] = false;
    can_move[4][0] = false; can_move[4][1] = false; can_move[4][2] = false; can_move[4][3] = false; can_move[4][4] = false; can_move[4][5] = false; can_move[4][6] = false; can_move[4][7] = false;
    can_move[5][0] = false; can_move[5][1] = false; can_move[5][2] = true;  can_move[5][3] = false; can_move[5][4] = false; can_move[5][5] = false; can_move[5][6] = true;  can_move[5][7] = false;
    can_move[6][0] = false; can_move[6][1] = false; can_move[6][2] = false; can_move[6][3] = true;  can_move[6][4] = false; can_move[6][5] = true;  can_move[6][6] = false; can_move[6][7] = false;
    can_move[7][0] = false; can_move[7][1] = false; can_move[7][2] = false; can_move[7][3] = false; can_move[7][4] = false; can_move[7][5] = false; can_move[7][6] = false; can_move[7][7] = false;
         
    board_.clearBoard();

    for(unsigned short tFile = 0; tFile < 8; tFile++){
        for(unsigned short tRank = 0; tRank < 8; tRank++){
            board_.board_[rank][file] = test_piece;

            bool expected_check = can_move[tRank][tFile];
            bool actual_check = board_.checkMove(test_piece, file, rank, tFile, tRank, move, no_option);
            ASSERT_EQ(expected_check, actual_check);

            board_.clearBoard();
        }
    }
}

//White Pawn
TEST_F(ChessboardTest, checkMove_whitePawn_moveEmptySpaceOffBeginningSpace){
    unsigned short file = 4;
    unsigned short rank = 4;
    chess::Chessboard::piece test_piece = chess::Chessboard::piece::WHITE_PAWN;
    chess::Chessboard::action move = chess::Chessboard::action::MOVE;
    chess::Chessboard::action no_option = chess::Chessboard::action::NO_OPTION;

    bool can_move [8][8];
    can_move[0][0] = false; can_move[0][1] = false; can_move[0][2] = false; can_move[0][3] = false; can_move[0][4] = false; can_move[0][5] = false; can_move[0][6] = false; can_move[0][7] = false;
    can_move[1][0] = false; can_move[1][1] = false; can_move[1][2] = false; can_move[1][3] = false; can_move[1][4] = false; can_move[1][5] = false; can_move[1][6] = false; can_move[1][7] = false;
    can_move[2][0] = false; can_move[2][1] = false; can_move[2][2] = false; can_move[2][3] = false; can_move[2][4] = false; can_move[2][5] = false; can_move[2][6] = false; can_move[2][7] = false;
    can_move[3][0] = false; can_move[3][1] = false; can_move[3][2] = false; can_move[3][3] = false; can_move[3][4] = true;  can_move[3][5] = false; can_move[3][6] = false; can_move[3][7] = false;
    can_move[4][0] = false; can_move[4][1] = false; can_move[4][2] = false; can_move[4][3] = false; can_move[4][4] = false; can_move[4][5] = false; can_move[4][6] = false; can_move[4][7] = false;
    can_move[5][0] = false; can_move[5][1] = false; can_move[5][2] = false; can_move[5][3] = false; can_move[5][4] = false; can_move[5][5] = false; can_move[5][6] = false; can_move[5][7] = false;
    can_move[6][0] = false; can_move[6][1] = false; can_move[6][2] = false; can_move[6][3] = false; can_move[6][4] = false; can_move[6][5] = false; can_move[6][6] = false; can_move[6][7] = false;
    can_move[7][0] = false; can_move[7][1] = false; can_move[7][2] = false; can_move[7][3] = false; can_move[7][4] = false; can_move[7][5] = false; can_move[7][6] = false; can_move[7][7] = false;
         
    board_.clearBoard();

    for(unsigned short tFile = 0; tFile < 8; tFile++){
        for(unsigned short tRank = 0; tRank < 8; tRank++){
            board_.board_[rank][file] = test_piece;

            bool expected_check = can_move[tRank][tFile];
            bool actual_check = board_.checkMove(test_piece, file, rank, tFile, tRank, move, no_option);
            ASSERT_EQ(expected_check, actual_check);

            board_.clearBoard();
        }
    }
}

TEST_F(ChessboardTest, checkMove_whitePawn_moveBeginningSpace){
    unsigned short file = 4;
    unsigned short rank = 6;
    chess::Chessboard::piece test_piece = chess::Chessboard::piece::WHITE_PAWN;
    chess::Chessboard::action move = chess::Chessboard::action::MOVE;
    chess::Chessboard::action no_option = chess::Chessboard::action::NO_OPTION;

    bool can_move [8][8];
    can_move[0][0] = false; can_move[0][1] = false; can_move[0][2] = false; can_move[0][3] = false; can_move[0][4] = false; can_move[0][5] = false; can_move[0][6] = false; can_move[0][7] = false;
    can_move[1][0] = false; can_move[1][1] = false; can_move[1][2] = false; can_move[1][3] = false; can_move[1][4] = false; can_move[1][5] = false; can_move[1][6] = false; can_move[1][7] = false;
    can_move[2][0] = false; can_move[2][1] = false; can_move[2][2] = false; can_move[2][3] = false; can_move[2][4] = false; can_move[2][5] = false; can_move[2][6] = false; can_move[2][7] = false;
    can_move[3][0] = false; can_move[3][1] = false; can_move[3][2] = false; can_move[3][3] = false; can_move[3][4] = false; can_move[3][5] = false; can_move[3][6] = false; can_move[3][7] = false;
    can_move[4][0] = false; can_move[4][1] = false; can_move[4][2] = false; can_move[4][3] = false; can_move[4][4] = true;  can_move[4][5] = false; can_move[4][6] = false; can_move[4][7] = false;
    can_move[5][0] = false; can_move[5][1] = false; can_move[5][2] = false; can_move[5][3] = false; can_move[5][4] = true;  can_move[5][5] = false; can_move[5][6] = false; can_move[5][7] = false;
    can_move[6][0] = false; can_move[6][1] = false; can_move[6][2] = false; can_move[6][3] = false; can_move[6][4] = false; can_move[6][5] = false; can_move[6][6] = false; can_move[6][7] = false;
    can_move[7][0] = false; can_move[7][1] = false; can_move[7][2] = false; can_move[7][3] = false; can_move[7][4] = false; can_move[7][5] = false; can_move[7][6] = false; can_move[7][7] = false;
         
    board_.clearBoard();

    for(unsigned short tFile = 0; tFile < 8; tFile++){
        for(unsigned short tRank = 0; tRank < 8; tRank++){
            board_.board_[rank][file] = test_piece;

            bool expected_check = can_move[tRank][tFile];
            bool actual_check = board_.checkMove(test_piece, file, rank, tFile, tRank, move, no_option);
            ASSERT_EQ(expected_check, actual_check);

            board_.clearBoard();
        }
    }
}

// Black King
TEST_F(ChessboardTest, checkMove_blackKing_moveEmptySpace){
    unsigned short file = 4;
    unsigned short rank = 4;
    chess::Chessboard::piece test_piece = chess::Chessboard::piece::BLACK_KING;
    chess::Chessboard::action move = chess::Chessboard::action::MOVE;
    chess::Chessboard::action no_option = chess::Chessboard::action::NO_OPTION;

    bool can_move [8][8];
    can_move[0][0] = false; can_move[0][1] = false; can_move[0][2] = false; can_move[0][3] = false; can_move[0][4] = false; can_move[0][5] = false; can_move[0][6] = false; can_move[0][7] = false;
    can_move[1][0] = false; can_move[1][1] = false; can_move[1][2] = false; can_move[1][3] = false; can_move[1][4] = false; can_move[1][5] = false; can_move[1][6] = false; can_move[1][7] = false;
    can_move[2][0] = false; can_move[2][1] = false; can_move[2][2] = false; can_move[2][3] = false; can_move[2][4] = false; can_move[2][5] = false; can_move[2][6] = false; can_move[2][7] = false;
    can_move[3][0] = false; can_move[3][1] = false; can_move[3][2] = false; can_move[3][3] = true;  can_move[3][4] = true;  can_move[3][5] = true;  can_move[3][6] = false; can_move[3][7] = false;
    can_move[4][0] = false; can_move[4][1] = false; can_move[4][2] = false; can_move[4][3] = true;  can_move[4][4] = false; can_move[4][5] = true;  can_move[4][6] = false; can_move[4][7] = false;
    can_move[5][0] = false; can_move[5][1] = false; can_move[5][2] = false; can_move[5][3] = true;  can_move[5][4] = true;  can_move[5][5] = true;  can_move[5][6] = false; can_move[5][7] = false;
    can_move[6][0] = false; can_move[6][1] = false; can_move[6][2] = false; can_move[6][3] = false; can_move[6][4] = false; can_move[6][5] = false; can_move[6][6] = false; can_move[6][7] = false;
    can_move[7][0] = false; can_move[7][1] = false; can_move[7][2] = false; can_move[7][3] = false; can_move[7][4] = false; can_move[7][5] = false; can_move[7][6] = false; can_move[7][7] = false;
        
    board_.clearBoard();

    for(unsigned short tFile = 0; tFile < 8; tFile++){
        for(unsigned short tRank = 0; tRank < 8; tRank++){
            board_.board_[rank][file] = test_piece;

            bool expected_check = can_move[tRank][tFile];
            bool actual_check = board_.checkMove(test_piece, file, rank, tFile, tRank, move, no_option);
            ASSERT_EQ(expected_check, actual_check);

            board_.clearBoard();
        }
    }
}

//Black Queen
TEST_F(ChessboardTest, checkMove_blackQueen_moveEmptySpace){
    unsigned short file = 4;
    unsigned short rank = 4;
    chess::Chessboard::piece test_piece = chess::Chessboard::piece::BLACK_QUEEN;
    chess::Chessboard::action move = chess::Chessboard::action::MOVE;
    chess::Chessboard::action no_option = chess::Chessboard::action::NO_OPTION;

    bool can_move [8][8];
    can_move[0][0] = true;  can_move[0][1] = false; can_move[0][2] = false; can_move[0][3] = false; can_move[0][4] = true;  can_move[0][5] = false; can_move[0][6] = false; can_move[0][7] = false;
    can_move[1][0] = false; can_move[1][1] = true;  can_move[1][2] = false; can_move[1][3] = false; can_move[1][4] = true;  can_move[1][5] = false; can_move[1][6] = false; can_move[1][7] = true;
    can_move[2][0] = false; can_move[2][1] = false; can_move[2][2] = true;  can_move[2][3] = false; can_move[2][4] = true;  can_move[2][5] = false; can_move[2][6] = true;  can_move[2][7] = false;
    can_move[3][0] = false; can_move[3][1] = false; can_move[3][2] = false; can_move[3][3] = true;  can_move[3][4] = true;  can_move[3][5] = true;  can_move[3][6] = false; can_move[3][7] = false;
    can_move[4][0] = true;  can_move[4][1] = true;  can_move[4][2] = true;  can_move[4][3] = true;  can_move[4][4] = false; can_move[4][5] = true;  can_move[4][6] = true;  can_move[4][7] = true;
    can_move[5][0] = false; can_move[5][1] = false; can_move[5][2] = false; can_move[5][3] = true;  can_move[5][4] = true;  can_move[5][5] = true;  can_move[5][6] = false; can_move[5][7] = false;
    can_move[6][0] = false; can_move[6][1] = false; can_move[6][2] = true;  can_move[6][3] = false; can_move[6][4] = true;  can_move[6][5] = false; can_move[6][6] = true;  can_move[6][7] = false;
    can_move[7][0] = false; can_move[7][1] = true;  can_move[7][2] = false; can_move[7][3] = false; can_move[7][4] = true;  can_move[7][5] = false; can_move[7][6] = false; can_move[7][7] = true;
        
    board_.clearBoard();

    for(unsigned short tFile = 0; tFile < 8; tFile++){
        for(unsigned short tRank = 0; tRank < 8; tRank++){
            board_.board_[rank][file] = test_piece;

            bool expected_check = can_move[tRank][tFile];
            bool actual_check = board_.checkMove(test_piece, file, rank, tFile, tRank, move, no_option);
            ASSERT_EQ(expected_check, actual_check);

            board_.clearBoard();
        }
    }
}

//Black Rook
TEST_F(ChessboardTest, checkMove_blackRook_moveEmptySpace){
    unsigned short file = 4;
    unsigned short rank = 4;
    chess::Chessboard::piece test_piece = chess::Chessboard::piece::BLACK_ROOK;
    chess::Chessboard::action move = chess::Chessboard::action::MOVE;
    chess::Chessboard::action no_option = chess::Chessboard::action::NO_OPTION;

    bool can_move [8][8];
    can_move[0][0] = false; can_move[0][1] = false; can_move[0][2] = false; can_move[0][3] = false; can_move[0][4] = true;  can_move[0][5] = false; can_move[0][6] = false; can_move[0][7] = false;
    can_move[1][0] = false; can_move[1][1] = false; can_move[1][2] = false; can_move[1][3] = false; can_move[1][4] = true;  can_move[1][5] = false; can_move[1][6] = false; can_move[1][7] = false;
    can_move[2][0] = false; can_move[2][1] = false; can_move[2][2] = false; can_move[2][3] = false; can_move[2][4] = true;  can_move[2][5] = false; can_move[2][6] = false; can_move[2][7] = false;
    can_move[3][0] = false; can_move[3][1] = false; can_move[3][2] = false; can_move[3][3] = false; can_move[3][4] = true;  can_move[3][5] = false; can_move[3][6] = false; can_move[3][7] = false;
    can_move[4][0] = true;  can_move[4][1] = true;  can_move[4][2] = true;  can_move[4][3] = true;  can_move[4][4] = false; can_move[4][5] = true;  can_move[4][6] = true;  can_move[4][7] = true;
    can_move[5][0] = false; can_move[5][1] = false; can_move[5][2] = false; can_move[5][3] = false; can_move[5][4] = true;  can_move[5][5] = false; can_move[5][6] = false; can_move[5][7] = false;
    can_move[6][0] = false; can_move[6][1] = false; can_move[6][2] = false; can_move[6][3] = false; can_move[6][4] = true;  can_move[6][5] = false; can_move[6][6] = false; can_move[6][7] = false;
    can_move[7][0] = false; can_move[7][1] = false; can_move[7][2] = false; can_move[7][3] = false; can_move[7][4] = true;  can_move[7][5] = false; can_move[7][6] = false; can_move[7][7] = false;
        
    board_.clearBoard();

    for(unsigned short tFile = 0; tFile < 8; tFile++){
        for(unsigned short tRank = 0; tRank < 8; tRank++){
            board_.board_[rank][file] = test_piece;

            bool expected_check = can_move[tRank][tFile];
            bool actual_check = board_.checkMove(test_piece, file, rank, tFile, tRank, move, no_option);
            ASSERT_EQ(expected_check, actual_check);

            board_.clearBoard();
        }
    }
}

//Black Bishop
TEST_F(ChessboardTest, checkMove_blackBishop_moveEmptySpace){
    unsigned short file = 4;
    unsigned short rank = 4;
    chess::Chessboard::piece test_piece = chess::Chessboard::piece::BLACK_BISHOP;
    chess::Chessboard::action move = chess::Chessboard::action::MOVE;
    chess::Chessboard::action no_option = chess::Chessboard::action::NO_OPTION;

    bool can_move [8][8];
    can_move[0][0] = true;  can_move[0][1] = false; can_move[0][2] = false; can_move[0][3] = false; can_move[0][4] = false; can_move[0][5] = false; can_move[0][6] = false; can_move[0][7] = false;
    can_move[1][0] = false; can_move[1][1] = true;  can_move[1][2] = false; can_move[1][3] = false; can_move[1][4] = false; can_move[1][5] = false; can_move[1][6] = false; can_move[1][7] = true;
    can_move[2][0] = false; can_move[2][1] = false; can_move[2][2] = true;  can_move[2][3] = false; can_move[2][4] = false; can_move[2][5] = false; can_move[2][6] = true;  can_move[2][7] = false;
    can_move[3][0] = false; can_move[3][1] = false; can_move[3][2] = false; can_move[3][3] = true;  can_move[3][4] = false; can_move[3][5] = true;  can_move[3][6] = false; can_move[3][7] = false;
    can_move[4][0] = false; can_move[4][1] = false; can_move[4][2] = false; can_move[4][3] = false; can_move[4][4] = false; can_move[4][5] = false; can_move[4][6] = false; can_move[4][7] = false;
    can_move[5][0] = false; can_move[5][1] = false; can_move[5][2] = false; can_move[5][3] = true;  can_move[5][4] = false; can_move[5][5] = true;  can_move[5][6] = false; can_move[5][7] = false;
    can_move[6][0] = false; can_move[6][1] = false; can_move[6][2] = true;  can_move[6][3] = false; can_move[6][4] = false; can_move[6][5] = false; can_move[6][6] = true;  can_move[6][7] = false;
    can_move[7][0] = false; can_move[7][1] = true;  can_move[7][2] = false; can_move[7][3] = false; can_move[7][4] = false; can_move[7][5] = false; can_move[7][6] = false; can_move[7][7] = true;
        
    board_.clearBoard();

    for(unsigned short tFile = 0; tFile < 8; tFile++){
        for(unsigned short tRank = 0; tRank < 8; tRank++){
            board_.board_[rank][file] = test_piece;

            bool expected_check = can_move[tRank][tFile];
            bool actual_check = board_.checkMove(test_piece, file, rank, tFile, tRank, move, no_option);
            ASSERT_EQ(expected_check, actual_check);

            board_.clearBoard();
        }
    }
}

//Black Knight
TEST_F(ChessboardTest, checkMove_blackKnight_moveEmptySpace){
    unsigned short file = 4;
    unsigned short rank = 4;
    chess::Chessboard::piece test_piece = chess::Chessboard::piece::BLACK_KNIGHT;
    chess::Chessboard::action move = chess::Chessboard::action::MOVE;
    chess::Chessboard::action no_option = chess::Chessboard::action::NO_OPTION;

    bool can_move [8][8];
    can_move[0][0] = false; can_move[0][1] = false; can_move[0][2] = false; can_move[0][3] = false; can_move[0][4] = false; can_move[0][5] = false; can_move[0][6] = false; can_move[0][7] = false;
    can_move[1][0] = false; can_move[1][1] = false; can_move[1][2] = false; can_move[1][3] = false; can_move[1][4] = false; can_move[1][5] = false; can_move[1][6] = false; can_move[1][7] = false;
    can_move[2][0] = false; can_move[2][1] = false; can_move[2][2] = false; can_move[2][3] = true;  can_move[2][4] = false; can_move[2][5] = true;  can_move[2][6] = false; can_move[2][7] = false;
    can_move[3][0] = false; can_move[3][1] = false; can_move[3][2] = true;  can_move[3][3] = false; can_move[3][4] = false; can_move[3][5] = false; can_move[3][6] = true;  can_move[3][7] = false;
    can_move[4][0] = false; can_move[4][1] = false; can_move[4][2] = false; can_move[4][3] = false; can_move[4][4] = false; can_move[4][5] = false; can_move[4][6] = false; can_move[4][7] = false;
    can_move[5][0] = false; can_move[5][1] = false; can_move[5][2] = true;  can_move[5][3] = false; can_move[5][4] = false; can_move[5][5] = false; can_move[5][6] = true;  can_move[5][7] = false;
    can_move[6][0] = false; can_move[6][1] = false; can_move[6][2] = false; can_move[6][3] = true;  can_move[6][4] = false; can_move[6][5] = true;  can_move[6][6] = false; can_move[6][7] = false;
    can_move[7][0] = false; can_move[7][1] = false; can_move[7][2] = false; can_move[7][3] = false; can_move[7][4] = false; can_move[7][5] = false; can_move[7][6] = false; can_move[7][7] = false;
         
    board_.clearBoard();

    for(unsigned short tFile = 0; tFile < 8; tFile++){
        for(unsigned short tRank = 0; tRank < 8; tRank++){
            board_.board_[rank][file] = test_piece;

            bool expected_check = can_move[tRank][tFile];
            bool actual_check = board_.checkMove(test_piece, file, rank, tFile, tRank, move, no_option);
            ASSERT_EQ(expected_check, actual_check);

            board_.clearBoard();
        }
    }
}

//Black Pawn
TEST_F(ChessboardTest, checkMove_blackPawn_moveEmptySpaceOffBeginningSpace){
    unsigned short file = 4;
    unsigned short rank = 4;
    chess::Chessboard::piece test_piece = chess::Chessboard::piece::BLACK_PAWN;
    chess::Chessboard::action move = chess::Chessboard::action::MOVE;
    chess::Chessboard::action no_option = chess::Chessboard::action::NO_OPTION;

    bool can_move [8][8];
    can_move[0][0] = false; can_move[0][1] = false; can_move[0][2] = false; can_move[0][3] = false; can_move[0][4] = false; can_move[0][5] = false; can_move[0][6] = false; can_move[0][7] = false;
    can_move[1][0] = false; can_move[1][1] = false; can_move[1][2] = false; can_move[1][3] = false; can_move[1][4] = false; can_move[1][5] = false; can_move[1][6] = false; can_move[1][7] = false;
    can_move[2][0] = false; can_move[2][1] = false; can_move[2][2] = false; can_move[2][3] = false; can_move[2][4] = false; can_move[2][5] = false; can_move[2][6] = false; can_move[2][7] = false;
    can_move[3][0] = false; can_move[3][1] = false; can_move[3][2] = false; can_move[3][3] = false; can_move[3][4] = false; can_move[3][5] = false; can_move[3][6] = false; can_move[3][7] = false;
    can_move[4][0] = false; can_move[4][1] = false; can_move[4][2] = false; can_move[4][3] = false; can_move[4][4] = false; can_move[4][5] = false; can_move[4][6] = false; can_move[4][7] = false;
    can_move[5][0] = false; can_move[5][1] = false; can_move[5][2] = false; can_move[5][3] = false; can_move[5][4] = true;  can_move[5][5] = false; can_move[5][6] = false; can_move[5][7] = false;
    can_move[6][0] = false; can_move[6][1] = false; can_move[6][2] = false; can_move[6][3] = false; can_move[6][4] = false; can_move[6][5] = false; can_move[6][6] = false; can_move[6][7] = false;
    can_move[7][0] = false; can_move[7][1] = false; can_move[7][2] = false; can_move[7][3] = false; can_move[7][4] = false; can_move[7][5] = false; can_move[7][6] = false; can_move[7][7] = false;
         
    board_.clearBoard();

    for(unsigned short tFile = 0; tFile < 8; tFile++){
        for(unsigned short tRank = 0; tRank < 8; tRank++){
            board_.board_[rank][file] = test_piece;

            bool expected_check = can_move[tRank][tFile];
            bool actual_check = board_.checkMove(test_piece, file, rank, tFile, tRank, move, no_option);
            ASSERT_EQ(expected_check, actual_check);

            board_.clearBoard();
        }
    }
}

TEST_F(ChessboardTest, checkMove_blackPawn_moveBeginningSpace){
    unsigned short file = 4;
    unsigned short rank = 1;
    chess::Chessboard::piece test_piece = chess::Chessboard::piece::BLACK_PAWN;
    chess::Chessboard::action move = chess::Chessboard::action::MOVE;
    chess::Chessboard::action no_option = chess::Chessboard::action::NO_OPTION;

    bool can_move [8][8];
    can_move[0][0] = false; can_move[0][1] = false; can_move[0][2] = false; can_move[0][3] = false; can_move[0][4] = false; can_move[0][5] = false; can_move[0][6] = false; can_move[0][7] = false;
    can_move[1][0] = false; can_move[1][1] = false; can_move[1][2] = false; can_move[1][3] = false; can_move[1][4] = false; can_move[1][5] = false; can_move[1][6] = false; can_move[1][7] = false;
    can_move[2][0] = false; can_move[2][1] = false; can_move[2][2] = false; can_move[2][3] = false; can_move[2][4] = true;  can_move[2][5] = false; can_move[2][6] = false; can_move[2][7] = false;
    can_move[3][0] = false; can_move[3][1] = false; can_move[3][2] = false; can_move[3][3] = false; can_move[3][4] = true;  can_move[3][5] = false; can_move[3][6] = false; can_move[3][7] = false;
    can_move[4][0] = false; can_move[4][1] = false; can_move[4][2] = false; can_move[4][3] = false; can_move[4][4] = false; can_move[4][5] = false; can_move[4][6] = false; can_move[4][7] = false;
    can_move[5][0] = false; can_move[5][1] = false; can_move[5][2] = false; can_move[5][3] = false; can_move[5][4] = false; can_move[5][5] = false; can_move[5][6] = false; can_move[5][7] = false;
    can_move[6][0] = false; can_move[6][1] = false; can_move[6][2] = false; can_move[6][3] = false; can_move[6][4] = false; can_move[6][5] = false; can_move[6][6] = false; can_move[6][7] = false;
    can_move[7][0] = false; can_move[7][1] = false; can_move[7][2] = false; can_move[7][3] = false; can_move[7][4] = false; can_move[7][5] = false; can_move[7][6] = false; can_move[7][7] = false;
         
    board_.clearBoard();

    for(unsigned short tFile = 0; tFile < 8; tFile++){
        for(unsigned short tRank = 0; tRank < 8; tRank++){
            board_.board_[rank][file] = test_piece;

            bool expected_check = can_move[tRank][tFile];
            bool actual_check = board_.checkMove(test_piece, file, rank, tFile, tRank, move, no_option);
            ASSERT_EQ(expected_check, actual_check);

            board_.clearBoard();
        }
    }
}



/*****************************************************************
*
* Main function for running tests
*
******************************************************************/

int main(int argc, char** argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}