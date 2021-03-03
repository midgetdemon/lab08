#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include <stdexcept>

class Div : public Base {
	private:
		Base * left;
		Base * right;
	public:
		Div(Base* leftNode, Base* rightNode) : Base(){
			left = leftNode;
			right = rightNode;
			if(right->evaluate() < 0.000001){
				throw std::invalid_argument("Divide by zero");
			}
		}
		virtual double evaluate(){
			return left->evaluate()/right->evaluate();
		}
		virtual std::string stringify(){
			return "(" + left->stringify() + "/" + right->stringify() + ")";
		}
		virtual int number_of_children(){
                        return 2;
                }
                virtual Base* get_child(int i){
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
                                visitor->visit_div_begin(this);
                        }
                        else if (index == 1){
                                visitor->visit_div_middle(this);
                        }
                        else {
                                visitor->visit_div_end(this);
                        }
                }
};
#endif
