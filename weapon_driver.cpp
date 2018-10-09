#include <iostream>

#include "weapon.h"

using namespace std;

int main() {
        Weapon test;
        test.print(cout);
        cout << endl;

        Weapon test2("test2", 5, 1, 2, 12, true);
        test2.print(cout);
        cout << endl;

        Weapon test3("test3", 0, 0, 0, 0, false);
        test3.print(cout);
        cout << endl;

        return 0;
}