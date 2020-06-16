#include "case.h"

int main(){
    Case A(100,2);
    Vec T_init(0.0,100);
    T_init[50] =0.1;
    A.setInitial(T_init);
    // весь расчет тут 
    for(int i=0;i<10000;i++){
       A.step();
    }

    A.write("case A.txt");
}
