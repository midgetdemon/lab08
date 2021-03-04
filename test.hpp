#ifndef __TEST_HPP__
#define __TEST_HPP__

#include "gtest/gtest.h"
#include "add.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "sub.hpp"
#include "rand.hpp"
#include "pow.hpp"
#include "visitor.hpp"
#include "visitor_derived.hpp"

TEST(AddTest, GetChild){
	Op* one = new Op(5);
	Op* two = new Op(6);
	Add* test = new Add(one, two);
	EXPECT_EQ(test->get_child(0), one); 
}

TEST(AddTest, NumChildren){
	Op* one = new Op(2);
        Op* two = new Op(9);
        Add* test = new Add(one, two);
        EXPECT_EQ(test->number_of_children(), 2);
}

TEST(SubTest, GetChild){
        Op* one = new Op(5);
        Op* two = new Op(6);
        Sub* test = new Sub(one, two);
        EXPECT_EQ(test->get_child(1), two);
}

TEST(SubTest, NumChildren){
        Op* one = new Op(5);
        Op* two = new Op(6);
        Sub* test = new Sub(one, two);
        EXPECT_EQ(test->number_of_children(), 2);
}

TEST(MultTest, GetChild){
        Op* one = new Op(5);
        Op* two = new Op(6);
        Mult* test = new Mult(one, two);
        EXPECT_EQ(test->get_child(0), one);
}

TEST(MultTest, NumChildren){
        Op* one = new Op(5);
        Op* two = new Op(6);
        Mult* test = new Mult(one, two);
        EXPECT_EQ(test->number_of_children(), 2);
}

TEST(DivTest, GetChild){
        Op* one = new Op(5);
        Op* two = new Op(6);
        Div* test = new Div(one, two);
        EXPECT_EQ(test->get_child(1), two);
}

TEST(DivTest, NumChildren){
        Op* one = new Op(5);
        Op* two = new Op(6);
        Div* test = new Div(one, two);
        EXPECT_EQ(test->number_of_children(), 2);
}

TEST(PowTest, GetChild){
        Op* one = new Op(5);
        Op* two = new Op(6);
        Pow* test = new Pow(one, two);
        EXPECT_EQ(test->get_child(0), one);
}

TEST(PowTest, NumChildren){
        Op* one = new Op(5);
        Op* two = new Op(6);
        Pow* test = new Pow(one, two);
    	EXPECT_EQ(test->number_of_children(), 2);
}

TEST(OpTest, GetChild){
        Op* test = new Op(5);
        EXPECT_EQ(test->get_child(1), nullptr);
}

TEST(OpTest, NumChildren){
        Op* test  = new Op(5);
        EXPECT_EQ(test->number_of_children(), 0);
}

TEST(RandTest, GetChild){
        Rand* test = new Rand(); 
        EXPECT_EQ(test->get_child(1), nullptr);
}

TEST(RandTest, NumChildren){
        Rand* test = new Rand(); 
        EXPECT_EQ(test->number_of_children(), 0);
}
/**
TEST(LatexTest, Basic){
	Base* test = new Add(new Op(1), new Sub(new Op(5), new Op(0)));
	EXPECT_EQ(PrintLaTeX(test), "${({1}+{({5}-{0})})}$"); 	

}
**/	
TEST(LatexTest, Basic){
        Base* test2 = new Pow(new Op(5), new Op(2));
        EXPECT_EQ(PrintLaTeX(test2), "${({1}+{({5}-{0})})}$");   
}

TEST(MathMLTest, Basic){
	Base* test = new Add(new Op(1), new Sub(new Op(5), new Op(0)));
	EXPECT_EQ(PrintMathML(test), "<math>
  <apply>
    <plus/>
    <cn>1</cn>
    <apply>
      <minus/>
      <cn>5</cn>
      <cn>0</cn>
    </apply>
  </apply>
</math>"); 
}










#endif
