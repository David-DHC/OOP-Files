第一题：list可以，queue不行。原因：对这两种容器进行重新封装，则会调用未特化版本的Container类，这将会导致调用list和queue中的begin()、end()迭代器，和insert()等函数。list中有这些，但是queue中没有。

第二题：只使用模板是可以的，方法是把"BasicContainer.h"中声明的虚函数改成“~BasicContainer() {}”、“void insert(const A &x){}”、“A find(int k){}”。只使用虚函数是不可以的，因为表示容器中元素类型的class A无法用非模板的方式（如auto）实现