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
		double evaluate(){
			return left->evaluate()/right->evaluate();
		}
		std::string stringify(){
			return "(" + left->stringify() + "/" + right->stringify() + ")";
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
};
#endif
