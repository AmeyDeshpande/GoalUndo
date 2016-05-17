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
TEST(GoalUndoTest, test_getGoal)
{
	GoalUndo test;
	string op = "newoperation";
	string goal = "newgoal";
	string empty = "";
	test.addOperation(goal,op);
	ASSERT_EQ(test.getGoal(),"newgoal");
	test.undoOperation();
	ASSERT_EQ(test.getGoal(),empty);
}
TEST(GoalUndoTest, test_undoOperationWithArg)
{
	GoalUndo test;
	string op = "newoperation";
	string goal = "newgoal";
	string empty = "";
	test.addOperation(goal,op);
	test.undoOperation("newoperation");
	ASSERT_EQ(test.getGoal(),goal);
}
TEST(GoalUndoTest, test_undoOperationWithArg2)
{
	GoalUndo test;
	string op = "newoperation";
	string goal = "newgoal";
	string empty = "";
	test.addOperation(goal,op);
	test.undoOperation("newoperation");
	test.undoOperation("newoperation");
	ASSERT_EQ(test.getGoal(),goal);
}
TEST(GoalUndoTest, test_undoOperationWithArg3)
{
	GoalUndo test;
	test.undoOperation("newoperation");	
	string op = "newoperation";
	string op2 = "anotheroperation";
	string goal = "newgoal";
	string empty = "";
	test.addOperation(goal,op);
	test.addOperation(goal,op2);
	test.undoOperation("any_operation");
	test.undoOperation("newoperation");
	ASSERT_EQ(test.getGoal(),goal);
}
TEST(GoalUndoTest, test_undoOperationWithArg4)
{
	GoalUndo test;
	string op = "newoperation";
	string goal = "newgoal";   
	string empty = "";
	test.addOperation(goal,op);	
	test.undoOperation("any_operation");
	test.undoOperation("newoperation");
	test.undoOperation("any_operation");
	ASSERT_EQ(test.getGoal(),goal);
}
TEST(GoalUndoTest, test_moreThanOneGoal)
{
	GoalUndo test;
	string op = "newoperation";
	string goal = "newgoal";
	string empty = "";
	string goal2 = "anothergoal";
	string op2 = "anotheroperation";
	test.addOperation(goal,op);
	test.addOperation(goal2,op2);
	ASSERT_EQ(test.getOperations(),op2);
	test.undoGoal();
	ASSERT_EQ(test.getOperations(),op);
}
TEST(GoalUndoTest, test_undoGoal)
{
	GoalUndo test;
	string op = "newoperation";
	string goal = "newgoal";
	string empty = "";
	test.addOperation(goal,op);
	test.undoGoal();
	ASSERT_EQ(test.getGoal(),empty);
}
TEST(GoalUndoTest, test_undoGoalMoreThanOneGoal)
{
	GoalUndo test;
	string op = "newoperation";
	string goal = "newgoal";
	string op2 = "anotheroperation";
	string goal2 = "anothergoal";
	string empty = "";
	test.addOperation(goal,op);
	test.addOperation(goal2,op2);
	test.undoGoal();
	test.undoGoal();
	ASSERT_EQ(test.getGoal(),empty);
}
