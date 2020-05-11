#include <cstdlib>
#include <iostream>
#include <string>   // string
#include <sstream>  // stringstream
#include <stack>    // stack
#include <vector>   // vector
#include <cctype>   // isdigit()
using namespace std;
// define const variable for readability
const int OPERATOR = 0; 
const int OPERAND  = 1;

class Expression {
// constructor
public: 
  Expression();
  Expression(const char*);

// public member function
public:
  double eval(); // get eval result

// private data member
private: 
  stack<double> operandStack; // stack to store operand
  stack<char> operatorStack;  // stack to store operator
  string infix;               // string to hold infix expression
  vector<pair<int, string> > suffix; // vector to hold suffix expression

// private member function
private:
  string char2str(const char &);      // convert char to string
  string dbl2str(const double &);     // convert double to string
  double str2dbl(const string &);     // convert string to double
  bool isoperator(const char &);      // identify whether it is an operator
  void parseOperand(const double &);  // parse operand to operandStack
  void parseOperator(const char &);   // parse operator to operatorStack
  int operatorPriority(const char&); // define operator priority
  void toSuffix(void);        // convert infix to suffix
  double calculate(const string &, const double &, const double &); // calculate result by operator and operand
};

// constructor
Expression::Expression() {

}

// constructor
Expression::Expression(const char *val) {
  this->infix = string(val); // fill infix by constructor
  this->toSuffix();          // convert infix to suffix
}

// convert char to string
string Expression::char2str(const char &c) {
  stringstream ss;
  ss << c;

  return ss.str();
}

// convert double to string
string Expression::dbl2str(const double &d) {
  stringstream ss;
  ss << d;
  
  return ss.str();
}

// convert string to double
double Expression::str2dbl(const string &s) {
  stringstream ss(s);
  double d;
  ss >> d;

  return d;
}

// identify whether it is an operator
bool Expression::isoperator(const char &c) {
  switch(c) {
    case '(' :
    case ')' :
    case '+' :
    case '-' :
    case '*' :
    case '/' : return true;
    default  : return false;
  }
}

// parse operand to operandStack
void Expression::parseOperand(const double &dOperand) {
  suffix.push_back(make_pair(OPERAND, dbl2str(dOperand)));
}

// parse operator to operatorStack
void Expression::parseOperator(const char &cOperator) {
  if (operatorStack.empty() || cOperator == '(') {
    operatorStack.push(cOperator);
  }
  else {
    if (cOperator == ')') {
      while(operatorStack.top() != '(') {
        suffix.push_back(make_pair(OPERATOR, char2str(operatorStack.top())));
        operatorStack.pop();

        if (operandStack.empty()) break;
      }
      // Remove '('
      operatorStack.pop();
    }
    else { // not ')'
      while(operatorPriority(cOperator) <= operatorPriority(operatorStack.top()) && !operatorStack.empty()) {
        suffix.push_back(make_pair(OPERATOR, char2str(operatorStack.top())));
        operatorStack.pop();

        if (operatorStack.empty()) 
          break;
      }
      operatorStack.push(cOperator);
    }
  }
}

// define operator priority
int Expression::operatorPriority(const char &cOperator) {
  switch(cOperator) {
    case '*' :
    case '/' : return 3;
    case '+' :
    case '-' : return 2;
    case '(' : return 1;
    default  : return 0;
  }
}

// Convert infix to suffix
// Algorithm : Parse infix string one char by one char. If char 
//             is operator, check if _operand is "", if not, let 
//             _operand to operandStack, and make _operand string 
//             clear, then let operator to operatorStack. If char 
//             is digit, concatenate to _operand string.
void Expression::toSuffix(void) {
  string _operand;
  for(string::iterator p = infix.begin(); p != infix.end(); ++p) {
    if (isoperator(*p)) {
      if (_operand != "") {
        parseOperand(str2dbl(_operand));
        _operand.clear();
      }
      parseOperator(*p);
    } else if (isdigit(*p)) 
      _operand.push_back(*p);
  }

  // If _operand is not "", let _operand to operandStack.
  if (_operand != "")
    parseOperand(str2dbl(_operand));

  // If operatorStack is not empty, push it to suffix vector until
  // operatorStack is empty.
  while(!operatorStack.empty()) {
    suffix.push_back(make_pair(OPERATOR,char2str(operatorStack.top())));
    operatorStack.pop();
  }
}

// calculate result by operator and operand
double Expression::calculate(const string &op, const double &operand1, const double &operand2) {
  if (op == "+") 
    return operand2 + operand1;
  else if (op == "-") 
    return operand2 - operand1;
  else if (op == "*")
    return operand2 * operand1;
  else if (op == "/")
    return operand2 / operand1;
  else
    return 0;
}

// get eval result
double Expression::eval(void) {
  // Clear OperandStack
  while(!operandStack.empty())
    operandStack.pop();

  for(vector<pair<int, string> >::iterator iter = suffix.begin(); iter != suffix.end(); ++iter) {
    if (iter->first == OPERATOR) {
      double operand1 = operandStack.top();
      operandStack.pop();
      double operand2 = operandStack.top();
      operandStack.pop();
      operandStack.push(calculate(iter->second, operand1, operand2));
    }
    else if (iter->first == OPERAND) {
      operandStack.push(str2dbl(iter->second));
    }
  }

  return operandStack.top();
}
int main(int argc, char *argv[])
{
    Expression x1("10+20*5");
    cout << "x1=" << x1.eval() << endl;

    Expression x2("5*20+10+1+2-3+99");
    cout << "x2=" << x2.eval() << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
