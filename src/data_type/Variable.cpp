/*
        Name: Variable.cpp
        Copyright: Apache 2.0
        Author: CLimber-Rong
        Date: 01/12/23 19:52
        Description: 变量类，Variable类存储着一个DataType*数据（也就是值）
            * 当需要给每个变量（包括数组元素等）赋值时，只需改变DataType*数据即可
*/

#ifndef VARIABLE_CPP
#define VARIABLE_CPP

#include "DataType.hpp"

namespace stamon {
namespace datatype {
class Variable {
 public:
  DataType* data;
};
}  // namespace datatype
}  // namespace stamon

#endif