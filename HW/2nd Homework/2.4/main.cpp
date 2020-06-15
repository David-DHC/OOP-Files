#include <iostream>
#include "Example.h"

using namespace std;

void create_example(int n) {

    cout << "--------create_example is ready--------\n";

    Example* e[10];

    for (int i = 0; i < n; i++)
        e[i] = new Example(i);

    Example *e6 = new Example(2333);

    for (int i = 0; i < n; i++)
        e[i]->getData();

    for (int i = 0; i < n; i++)
        delete e[i];

    e6->getData();

    cout << "--------create_example is over--------\n";
}

Example e1(23);

int main() {

    cout << "--------main_function is ready--------\n";

    Example e2(233);

    create_example(3);

    Example e7(23333);
    e1.getData();
    e2.getData();
    e7.getData();

    cout << "--------main_function is over---------\n";

    return 0;
}