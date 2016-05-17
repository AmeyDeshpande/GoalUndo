/**
 * Unit Tests for GoalUndo class
**/

#include <gtest/gtest.h>
#include "GoalUndo.h"
#include <string.h>

using namespace std;

class GoalUndoTest : public ::testing::Test
{
	protected:
		GoalUndoTest(){}
		virtual ~GoalUndoTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(GoalUndoTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
TEST(GoalUndoTest, addOperationToTestGoal)
{
	GoalUndo test;
	string op = "newoperation";
	string goal = "newgoal";
	test.addOperation(goal,op);	
	ASSERT_EQ(test.getGoal(),goal);
}
TEST(GoalUndoTest, test_addOpertionEmpty)
{
	GoalUndo test;
	string empty = "";
	test.addOperation(empty,empty);
	test.addOperation(empty);
	ASSERT_EQ(test.getOperations(),empty);
	ASSERT_EQ(test.getGoal(),empty);
}
TEST(GoalUndoTest, test_addOpertionToTestOperation)
{
	GoalUndo test;
	string op = "newoperation";
	string goal = "newgoal";
	string empty = "";
	test.addOperation(op);
	ASSERT_EQ(test.getOperations(),op);
}
TEST(GoalUndoTest, test_addOpertionAndUndo)
{
	GoalUndo test;
	string op = "newoperation";
	string empty = "";
	test.addOperation(empty);
	test.addOperation(op);
	ASSERT_EQ(test.getOperations(),op);
	test.undoOperation(op);
	ASSERT_EQ(test.getGoal(),op);
}
TEST(GoalUndoTest, test_getOperations)
{
	GoalUndo test;
	string op = "newoperation";
	string goal = "newgoal";
	string op2 = "anotheroperation";
	string resultant_op = "newoperation anotheroperation";
	test.addOperation(goal,op);
	test.addOperation(op2);
	ASSERT_EQ(test.getOperations(),resultant_op);
}
TEST(GoalUndoTest, test_getOperations2)
{
	GoalUndo test;
	string op = "newoperation";
	string goal = "newgoal";
	string op2 = "anotheroperation";
	string resultant_op = "newoperation anotheroperation";
	test.addOperation(goal,op);
	test.addOperation	(op2);
	ASSERT_EQ(test.getOperations(),resultant_op);
}
TEST(GoalUndoTest, test_undoOperation)
{
	GoalUndo test;
	string op = "newoperation";
	string goal = "newgoal";
	string op2 = "anotheroperation";
	string resultant_op = "newoperation anotheroperation";
	test.addOperation(goal,op);
	test.addOperation	(op2);
	ASSERT_EQ(test.getOperations(),resultant_op);
	test.undoOperation();
	ASSERT_EQ(test.getOperations(),op);
	ASSERT_EQ(test.getOperations(),op2);
}
TEST(GoalUndoTest, test_undoOperation2)
{
	GoalUndo test;
	string op = "newoperation";
	string goal = "newgoal";
	test.addOperation(goal,op);
	test.undoOperation();
	ASSERT_EQ(test.getOperations(),"");
}
TEST(GoalUndoTest, test_undoOperation3)
{
	GoalUndo test;
	string op = "newoperation";
	string goal = "newgoal";
	test.addOperation(goal,op);
	test.undoOperation();
	test.undoOperation();
	ASSERT_EQ(test.getOperations(),"");
}
TEST(GoalUndoTest, test_undoOperationMultipleOperations)
{
	GoalUndo test;
	string op = "newoperation";
	string goal = "newgoal";
	string op2 = "anotheroperation";
	string op3 = "operation3";
	string resultant_op = "newoperation anotheroperation operation3";
	string resultant_op2 = "newoperation anotheroperation";
	test.addOperation(goal,op);
	test.addOperation(op2);
	test.addOperation(op3);
	ASSERT_EQ(test.getOperations(),resultant_op);
	test.undoOperation();
	ASSERT_EQ(test.getOperations(),resultant_op2);
}

