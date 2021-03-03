#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"

class Add: public Base{
	private:
		Base* left;
		Base* right;
	public:
		Add(Base* leftNode, Base* rightNode): Base(){
			left = leftNode;
			right = rightNode;
		}
		double evaluate(){
			return left->evaluate() + right->evaluate();
		}
		std::string stringify(){
			return "(" + left->stringify() + "+" + right->stringify() + ")";
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
				visitor->visit_add_begin(this);
			}
			else if (index == 1){
				visitor->visit_add_middle(this);
			}
			else {
				visitor->visit_add_end(this);
			}
		}

};

#endif
