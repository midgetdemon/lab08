#include <iostream>
#include "visitor.hpp"
#include "visitor_derived.hpp"

int main() {
  std::cout << "First expression: 1+(5-0)" << std::endl;
  Base* test1 = new Add(new Op(1), new Sub(new Op(5), new Op(0)));
  std::cout << PrintLaTeX(test1) << std::endl;
  std::cout << PrintMathML(test1) << std::endl;
  std::cout << std::endl;
  std::cout << "Second expression: 5^2" << std::endl;
  Base* test2 = new Pow(new Op(5), new Op(2));
  std::cout << PrintLaTeX(test2) << std::endl;
  std::cout << PrintMathML(test2) << std::endl;
  std::cout << std::endl;
  std::cout << "Third expression: 2*5" << std::endl;
  Base* test3 = new Mult(new Op(2), new Op(5));
  std::cout << PrintLaTeX(test3) << std::endl;
  std::cout << PrintMathML(test3) << std::endl;
  std::cout << std::endl;
  std::cout << "Fourth expression: 2/3" << std::endl;
  Base* test4 = new Div(new Op(2), new Op(3));
  std::cout << PrintLaTeX(test4) << std::endl;
  std::cout << PrintMathML(test4) << std::endl;
  std::cout << std::endl;
  std::cout << "Fifth expression: (2*5)/(5^2)" << std::endl;
  Base* test5 = new Div(new Mult(new Op(2), new Op(5)), new Pow(new Op(5), new Op(2)));
  std::cout << PrintLaTeX(test5) << std::endl;
  std::cout << PrintMathML(test5) << std::endl;
  delete test1;
  delete test2;
  delete test3;
  delete test4;
  delete test5;
}
