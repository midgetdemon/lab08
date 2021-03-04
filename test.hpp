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
**/
TEST(VisitorTests, SimpleExpressions){
  Base* simpleAdd = new Add(new Op(3), new Op(4));
  EXPECT_EQ("${({3.000000}+{4.000000})}$", PrintLaTeX(simpleAdd));
  EXPECT_EQ("<math>\n <apply>\n  <plus/>\n  <cn>3.000000</cn>\n  <cn>4.000000</cn>\n </apply>\n</math>", PrintMathML(simpleAdd));
  delete simpleAdd;
  Base* simpleDiv = new Div(new Op(8), new Op(4));
  EXPECT_EQ("${\\frac{8.000000}{4.000000}}$", PrintLaTeX(simpleDiv));
  EXPECT_EQ("<math>\n <apply>\n  <divide/>\n  <cn>8.000000</cn>\n  <cn>4.000000</cn>\n </apply>\n</math>", PrintMathML(simpleDiv));
  delete simpleDiv;
  Base* simpleMult = new Mult(new Op(3), new Op(6));
  EXPECT_EQ("${({3.000000}\\cdot{6.000000})}$", PrintLaTeX(simpleMult));
  EXPECT_EQ("<math>\n <apply>\n  <times/>\n  <cn>3.000000</cn>\n  <cn>6.000000</cn>\n </apply>\n</math>", PrintMathML(simpleMult));
  delete simpleMult;
  Base* simplePow = new Pow(new Op(6), new Op(2));
  EXPECT_EQ("${({6.000000}^{2.000000})}$", PrintLaTeX(simplePow));
  EXPECT_EQ("<math>\n <apply>\n  <power/>\n  <cn>6.000000</cn>\n  <cn>2.000000</cn>\n </apply>\n</math>", PrintMathML(simplePow));
  delete simplePow;
  Base* simpleSub = new Sub(new Op(7), new Op(5));
  EXPECT_EQ("${({7.000000}-{5.000000})}$", PrintLaTeX(simpleSub));
  EXPECT_EQ("<math>\n <apply>\n  <minus/>\n  <cn>7.000000</cn>\n  <cn>5.000000</cn>\n </apply>\n</math>", PrintMathML(simpleSub));
  delete simpleSub;
}

TEST(VisitorTests, ComplexExpressions){
  Base* complex1 = new Mult(new Div(new Op(4), new Op(2)), new Pow(new Op(2), new Op(3)));
  EXPECT_EQ("${({\\frac{4.000000}{2.000000}}\\cdot{({2.000000}^{3.000000})})}$", PrintLaTeX(complex1));
  EXPECT_EQ("<math>\n <apply>\n  <times/>\n  <apply>\n   <divide/>\n   <cn>4.000000</cn>\n   <cn>2.000000</cn>\n  </apply>\n  <apply>\n   <power/>\n   <cn>2.000000</cn>\n   <cn>3.000000</cn>\n  </apply>\n </apply>\n</math>", PrintMathML(complex1));
  delete complex1;
  Base* complex2 = new Pow(new Op(2), new Add(new Sub(new Op(3), new Op(2)), new Op(5)));
  EXPECT_EQ("${({2.000000}^{({({3.000000}-{2.000000})}+{5.000000})})}$", PrintLaTeX(complex2));
  EXPECT_EQ("<math>\n <apply>\n  <power/>\n  <cn>2.000000</cn>\n  <apply>\n   <plus/>\n   <apply>\n    <minus/>\n    <cn>3.000000</cn>\n    <cn>2.000000</cn>\n   </apply>\n   <cn>5.000000</cn>\n  </apply>\n </apply>\n</math>", PrintMathML(complex2));
  delete complex2;
}

#endif
