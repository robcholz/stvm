/*
        Name: Ast
        Copyright: Apache 2.0
        Author: CLimber-Rong
        Date: 28/07/23 16:44
        Description:
        * 这里对Ast进行了基本的定义
        * 如果你想要引用所有的Ast源码，只要写入以下代码即可：
        #include"Ast.hpp"
        using namespace stamon::ast;
*/

#ifndef AST_HPP
#define AST_HPP

#include "ArrayList.hpp"

namespace stamon {
namespace ast {
// Ast类型定义，详细作用见doc/虚拟机AST设计.md
enum _AstType {
  AstNodeType = 0,
  AstProgramType,
  AstDefClassType,
  AstAnonClassType,
  AstAnonMethodType,
  AstBlockType,
  AstCompoundBlockType,
  AstBreakType,
  AstIfStatementType,
  AstWhileStatementType,
  AstForStatementType,
  AstReturnStatementType,
  AstSFNType,
  AstExpressionType,
  AstLeftValueType,
  AstLeftPostfixType,
  AstBinaryType,
  AstUnaryType,
  AstPostfixType,
  AstIdentifierType,
  AstNumberType,
  AstStringType,
  AstNullType,
  AstArrayLiteralType,
  AstListLiteralType,
  AstTypeNum  // Ast总数
};

// Ast类定义，详细实现见同目录的其他源码
class AstNode;
class AstProgram;
class AstDefClass;
class AstAnonClass;
class AstAnonMethod;
class AstBlock;
class AstCompoundBlock;
class AstBreak;
class AstIfStatement;
class AstWhileStatement;
class AstForStatement;
class AstReturnStatement;
class AstSFN;
class AstExpression;
class AstLeftValue;
class AstLeftPostfix;
class AstBinary;
class AstUnary;
class AstPostfix;
class AstIdentifier;
class AstNumber;
class AstString;
class AstNull;
class AstArrayLiteral;
class AstListLiteral;

class AstNode {
 protected:
  ArrayList<AstNode*>* children;

 public:
  AstNode() {
    // 构造函数
    children = new ArrayList<AstNode*>();
  }
  virtual int ChildrenNum() {
    // 子节点数量
    return children->size();
  }
  virtual ArrayList<AstNode*>* Children() {
    // 获得子节点列表
    return children;
  }
  virtual int getType() {
    // 获得节点类型
    return AstNodeType;
  }
};
}  // namespace ast
}  // namespace stamon

#include "CodeLogicAst.cpp"
#include "ExprAst.cpp"
#include "LeafAst.cpp"
#include "SfnAst.cpp"

#endif
