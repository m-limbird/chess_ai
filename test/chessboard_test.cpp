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
    board_.printBoard();
    EXPECT_TRUE(true);
}

/*****************************************************************
*
* TEST FUNCTION: check_move
*
* note: Unit tests for the printBoard of the Chessboard class
*
*****************************************************************/

TEST_F(ChessboardTest, checkMove){
    
    //board_.checkMove();
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