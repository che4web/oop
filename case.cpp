#include "case.h"
#include <fstream>
#include <iomanip>


void diff(Vec& T,Vec& dT){
    for(size_t i =1 ; i< T.size()-2;i++)
       dT[i] = T[i+1]+T[i-1]-2*T[i];
    //dT = T.shift(-1) + T.shift(1) -T*2.0;
   // dT[0]=0;
    //dT[T.size()-1]=0;
}

Vec diff(Vec& T){
    Vec tmp(0.0,T.size()); 
    for(size_t i =1 ; i< T.size()-2;i++)
    {
       tmp[i] = T[i+1]+T[i-1]-2*T[i];
    }
    return tmp;
} 

Case::Case(int N, double L)
{
    Lx =L;
    NumPoint =N;
    h = L/N;
    dt = h*h/4.0;
    T = Vec(0.0,NumPoint);
    dT = Vec(0.0,NumPoint);


};
void Case::step()
{
    double  tay = dt/(h*h);
    //for(size_t i =1 ; i< T.size()-2;i++)
   // {
   //     T[i] = T[i] +(T[i+1]+T[i-1]-2*T[i])*tay;
   // }
    
        dT = diff(T);
        //diff(T,dT);
        T = T +dT*tay;

};
void Case::setInitial(Vec T_in)
{
    T = T_in;

};
void Case::write(std::string name)
{
    std::ofstream out;
    out.open(name);
    //std::cout << std::fixed;
    //std::cout.precision(5);
    out << std::setw(15) <<  "x";
    out << std::setw(15) <<  "T";
    out << std::endl;
    for(int i=0;i<NumPoint;i++){
        out << std::setw(15) <<  i*h;
        out << std::setw(15) <<  T[i];
        out << std::endl;
    }
};
