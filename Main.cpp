#include <iostream>
#include <chrono>
#include <thread>
#include "Mare.hpp"
#include "Mare.cpp"
#include "Nds.hpp"
#include "Nds.cpp"
using namespace std;

int main()
{
    Mare board = Mare();
    cout<<board.printAMare();
    return 0;
}
