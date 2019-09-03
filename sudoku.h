#ifndef SUDOKU_H
#define SUDOKU_H
#include <iostream>
#include <stdlib.h>
#include <time.h>

class sudoku{
    public:
        sudoku();
        ~sudoku();
        int getxy(int, int);
        void setxy(int, int);
        void randomize();
        void print();
        bool duplicate();
    private:
        int ** numbers;    
};

#endif
