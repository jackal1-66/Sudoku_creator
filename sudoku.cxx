#include "sudoku.h"

sudoku::sudoku(){
    numbers = new int *[9];
    for(int i = 0; i < 9; i++){
        numbers[i] = new int[9];
        for(int a = 0; a<9; a++){
            numbers[i][a]=0;
        }
    }
}

sudoku::~sudoku(){
    delete numbers;
    std::cout << "\nClosing Sudoku\n";
}

void sudoku::print(){
    for(int i = 0; i < 9; i++){
        for(int a = 0; a<9; a++){
            std::cout << numbers[i][a] << "  ";
        }
    std::cout << '\n';    
    }
}

void sudoku::randomize(){
    srand(time(NULL));
    for(int i = 0; i < 9; i++){
        for(int a = 0; a<9; a++){
            if(i == 0){                   
                if(a == 0){
                    numbers[i][a] = rand() % 9 + 1;
                }
                else{
                    numbers[i][a] = rand() % 9 + 1;
                    for(int l = 0; l<9; l++){
                        if(a == l){
                            continue;
                        }
                        else if(numbers[i][a]==numbers[i][l]){
                            numbers[i][a] = rand() % 9 + 1;
                            l = -1;
                        }
                    }                                         
                }                    
            }
            else{
                if(a == 0){
                    numbers[i][a] = rand() % 9 + 1;
                    for(int l = 0; l<9; l++){
                        if(l == i){
                            continue;
                        }
                        else if(numbers[i][a]==numbers[l][a]){
                            numbers[i][a] = rand() % 9 + 1;
                            l = -1;
                        }
                    }
                }
                else{
                    numbers[i][a] = rand() % 9 + 1;
                    for(int k = 0; k<9; k++){
                        if(numbers[i][a]==numbers[i][k]){
                            if(k == a){
                                continue;
                            }
                            else{
                                numbers[i][a] = rand() % 9 + 1;
                            std::cout << "\nChanging horizontal number i = " << i << " a = " << a << " equal to i = " << i << " and k = " << k << '\n';
                            k = -1;
                            }                            
                        }
                        else if(numbers[i][a]==numbers[k][a]){
                            if(k == i){
                                continue;
                            }
                            else{
                                numbers[i][a] = rand() % 9 + 1;
                                std::cout << "\nChanging vertical number i = " << i << " a = " << a << " equal to k = " << k << " and a = " << a << '\n';
                                k = -1;
                            }                                    
                        }
                    }                                         
                }            
            }
        } 
         
    }
}

