#include <iostream>
#include <chrono>
#include <thread>
#include "Mare.hpp"
#include "Mare.cpp"
using namespace std;

int main()
{
    Mare board = Mare();
    cout<<board.printAMare();
    return 0;
}
