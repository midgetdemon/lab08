#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult: public Base{
	private:
		Base* left;
		Base* right;
	public:
		Mult(Base* leftNode, Base* rightNode): Base(){
			left = leftNode;
			right = rightNode;
		}
		~Mult(){
			delete left;
			delete right;
		}
		double evaluate(){
			return left->evaluate()*right->evaluate();
		}
		std::string stringify(){
			return "(" + left->stringify() + "*" + right->stringify() + ")";
		}
		int number_of_children(){
                        return 2;
                }
                Base* get_child(int i){
                        if (i == 0){
                                return left;
                        }
                        if (i == 1){
                                return right;
                        }
                        return nullptr;
                }
		virtual void accept (Visitor* visitor, int index){
                        if (index == 0){
                                visitor->visit_mult_begin(this);
                        }
                        else if (index == 1){
                                visitor->visit_mult_middle(this);
                        }
                        else {
                                visitor->visit_mult_end(this);
                        }
                }
};

#endif
