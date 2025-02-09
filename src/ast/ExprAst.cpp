/*
        Name: ExprAst.cpp
        Copyright: Apache 2.0
        Author: CLimber-Rong
        Date: 28/07/23 15:48
        Description: 在这里定义与表达式有关的Ast节点
*/

#ifndef EXPRAST_CPP
#define EXPRAST_CPP

#include "Ast.hpp"

namespace stamon {
namespace ast {
enum _LeftPostfixType {
  // 左值后缀类型定义
  LeftPostfixMemberType = 0,  // 左值成员后缀
  LeftPostfixElementType      // 左值下标后缀
};
enum _BinaryOperatorType {
  // 双目运算符类型定义
  BinaryLogicORType = 0,      // 逻辑或
  BinaryLogicANDType,         // 逻辑与
  BinaryBitORType,            // 按位或
  BinaryBitXORType,           // 按位异或
  BinaryBitANDType,           // 按位与
  BinaryEqualityType,         // 是否相等
  BinaryInequalityType,       // 是否不相等
  BinaryBigThanType,          // 大于
  BinaryLessThanType,         // 小于
  BinaryBigThanOrEqualType,   // 大等于
  BinaryLessThanOrEqualType,  // 小等于
  BinaryLeftShiftType,        // 左移位
  BinaryRightShiftType,       // 右移位
  BinaryAddType,              // 加法
  BinarySubType,              // 减法
  BinaryMultType,             // 乘法
  BinaryDiviType,             // 除法
};
enum _UnaryOperatorType {
  // 单目运算符类型定义
  UnaryPositiveType = 0,  // 正
  UnaryNegative,          // 负
  UnaryNotType,           // 非
  UnaryInverseType        // 按位反
};

class AstExpression : public AstNode {
 public:
  AstExpression(AstLeftValue* LeftValue, AstExpression* expr) : AstNode() {
    children->add((AstNode*)LeftValue);
    children->add((AstNode*)expr);
  }
  AstExpression(AstBinary* value) : AstNode() {
    children->add((AstNode*)value);
  }
  virtual int getType() { return AstExpressionType; }
};
class AstLeftValue : public AstNode {
 public:
  AstLeftValue(AstIdentifier* iden, ArrayList<AstNode*>* postfix) : AstNode() {
    children = postfix;
    children->insert(0, (AstNode*)iden);
  }
  virtual int getType() { return AstLeftValueType; }
};
class AstLeftPostfix : public AstNode {
  int postfix_type;

 public:
  virtual int getPostfixType() { return postfix_type; }
  AstLeftPostfix(int PostfixType, AstNode* value) : AstNode() {
    children->add((AstNode*)value);
  }
  virtual int getType() { return AstLeftPostfixType; }
};
class AstBinary : public AstNode {
  int operator_type;

 public:
  virtual int getOperatorType() { return operator_type; }
  AstBinary(int OperatorType, AstNode* left, AstNode* right) : AstNode() {
    operator_type = OperatorType;
    children->add((AstNode*)left);
    children->add((AstNode*)right);
  }
  virtual int getType() { return AstBinaryType; }
};
class AstUnary : public AstNode {
  int operator_type;

 public:
  virtual int getOperatorType() { return operator_type; }
  AstUnary(int OperatorType, AstNode* value) : AstNode() {
    operator_type = OperatorType;
    children->add((AstNode*)value);
  }
  AstUnary(AstNode* value, ArrayList<AstNode*>* postfix) : AstNode() {
    children = postfix;
    children->insert(0, (AstNode*)value);
  }
  virtual int getType() { return AstUnaryType; }
};
class AstPostfix : public AstNode {
  int postfix_type;

 public:
  virtual int getPostfixType() { return postfix_type; }
  AstPostfix(int PostfixType, AstNode* value) : AstNode() {
    postfix_type = PostfixType;
    children->add((AstNode*)value);
  }
  virtual int getType() { return AstPostfixType; }
};
class AstArrayLiteral : public AstNode {
 public:
  AstArrayLiteral(AstExpression* expr) : AstNode() {
    children->add((AstNode*)expr);
  }
  virtual int getType() { return AstArrayLiteralType; }
};
class AstListLiteral : public AstNode {
 public:
  AstListLiteral(ArrayList<AstNode*>* exprs) : AstNode() { children = exprs; }
  virtual int getType() { return AstListLiteralType; }
};

}  // namespace ast
}  // namespace stamon

#endif