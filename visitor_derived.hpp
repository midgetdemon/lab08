#include <string>
#include "visitor.hpp"
#include "add.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "sub.hpp"
#include "iterator.hpp"

class VisitorLaTeX : public Visitor{
  public:
    std::string expression;
    VisitorLaTeX(){
      expression = "";
    }
    std::string getExpression(){
      return expression;
    }
    virtual void visit_op(Op* node){
      expression += "{";
      expression += node->stringify();
      expression += "}";
    }
    virtual void visit_rand(Rand* node){
      expression += "{";
      expression += node->stringify();
      expression += "}";
    }
    virtual void visit_add_begin(Add* node){
      expression += "{(";
    }
    virtual void visit_add_middle(Add* node){
      expression += "+";
    }
    virtual void visit_add_end(Add* node){
      expression += ")}";
    }
    virtual void visit_sub_begin(Sub* node){
      expression += "{(";
    }
    virtual void visit_sub_middle(Sub* node){
      expression += "-";
    }
    virtual void visit_sub_end(Sub* node){
      expression += ")}";
    }
    virtual void visit_mult_begin(Mult* node){
      expression += "{(";
    }
    virtual void visit_mult_middle(Mult* node){
      expression += "\\cdot";
    }
    virtual void visit_mult_end(Mult* node){
      expression += ")}";
    }
    virtual void visit_div_begin(Div* node){
      expression += "{\\frac";
    }
    virtual void visit_div_middle(Div* node){
      expression += "";
    }
    virtual void visit_div_end(Div* node){
      expression += "}";
    }
    virtual void visit_pow_begin(Pow* node){
      expression += "{(";
    }
    virtual void visit_pow_middle(Pow* node){
      expression += "^";
    }
    virtual void visit_pow_end(Pow* node){
      expression += ")}";
    }
}; 

std::string PrintLaTeX(Base* ptr){
  VisitorLaTeX* myVisitor = new VisitorLaTeX();
  myVisitor->expression = "$";
  Iterator* it = new Iterator(ptr); 
  while (!(it->is_done())){
    it->current_node()->accept(myVisitor, it->current_index()); 
    it->next();
  }
  myVisitor->expression += "$";
  return myVisitor->getExpression(); 
}

class VisitMathML : public Visitor{
  public:
    std::string expression;
    int indent;
    VisitMathML(){
      expression = "";
      indent = 0;
    }
    std::string getExpression(){
      return expression;
    }
    void addIndent(){
      for(int i = 0; i < indent; ++i){
        expression += " ";
      }
    }
    virtual void visit_op(Op* node){
      addIndent();
      expression += "<cn>";
      expression += node->stringify();
      expression += "</cn>\n";
    }
    virtual void visit_rand(Rand* node){
      addIndent();
      expression += "<cn>";
      expression += node->stringify();
      expression += "</cn>\n";
    }
    virtual void visit_add_begin(Add* node){
      addIndent();
      expression += "<apply>\n";
      indent+=1;
      addIndent();
      expression += "<plus/>\n";
    }
    virtual void visit_add_middle(Add* node){
      expression += "";
    }
    virtual void visit_add_end(Add* node){
      indent -= 1;
      addIndent();
      expression += "</apply>\n";
    }
    virtual void visit_sub_begin(Sub* node){
      addIndent();
      expression += "<apply>\n";
      indent+=1;
      addIndent();
      expression += "<sub/>\n";
    }
    virtual void visit_sub_middle(Sub* node){
      expression += "";
    }
    virtual void visit_sub_end(Sub* node){
      indent -= 1;
      addIndent();
      expression += "</apply>\n";
    }
    virtual void visit_mult_begin(Mult* node){
      addIndent();
      expression += "<apply>\n";
      indent+=1;
      addIndent();
      expression += "<times/>\n";
    }
    virtual void visit_mult_middle(Mult* node){
      expression += "";
    }
    virtual void visit_mult_end(Mult* node){
      indent -= 1;
      addIndent();
      expression += "</apply>\n";
    }
    virtual void visit_div_begin(Div* node){
      addIndent();
      expression += "<apply>\n";
      indent+=1;
      addIndent();
      expression += "<divide/>\n";
    }
    virtual void visit_div_middle(Div* node){
      expression += "";
    }
    virtual void visit_div_end(Div* node){
      indent -= 1;
      addIndent();
      expression += "</apply>\n";
    }
    virtual void visit_pow_begin(Pow* node){
      addIndent();
      expression += "<apply>\n";
      indent+=1;
      addIndent();
      expression += "<power/>\n";
    }
    virtual void visit_pow_middle(Pow* node){
      expression += "";
    }
    virtual void visit_pow_end(Pow* node){
      indent -= 1;
      addIndent();
      expression += "</apply>\n";
    }
}; 

std::string PrintMathML(Base* ptr){
  VisitMathML* myVisitor = new VisitMathML();
  myVisitor->expression = "<math>\n";
  myVisitor->indent = 1;
  Iterator* it = new Iterator(ptr); 
  while (!(it->is_done())){
    it->current_node()->accept(myVisitor, it->current_index()); 
    it->next();  
  }
  myVisitor->expression += "</math>";
  return myVisitor->getExpression(); 
}
