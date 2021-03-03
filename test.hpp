#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"
#include "add.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "sub.hpp"
#include "rand.hpp"
#include "pow.hpp"


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

#endif
