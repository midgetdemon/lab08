#ifndef __POW_HPP__
#define __POW_HPP__

#include <cmath>
#include "base.hpp"

class Pow : public Base{
	private:
		Base * left;
		Base * right;
	public: 
		Pow(Base * leftNode, Base * rightNode) : Base(){
			left = leftNode;
			right = rightNode;
		}
		double evaluate(){
			return pow(left->evaluate(), right->evaluate());
		}
		std::string stringify(){
			return "(" + left->stringify() + "**" + right->stringify() + ")"; 
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
                                visitor->visit_pow_begin(this);
                        }
                        else if (index == 1){
                                visitor->visit_pow_middle(this);
                        }
                        else {
                                visitor->visit_pow_end(this);
                        }
                }
};
#endif  
