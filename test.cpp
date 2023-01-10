#include <iostream>
#include "Mare.hpp"
using namespace std;

int main()
{
    string s = "s";
    char mar[12][12];
    string p1 = "p";
    M::Mare board = M::Mare(s, mar, p1);

    board.printAMare();
}
