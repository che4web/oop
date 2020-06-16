#include "case.h"
#include <fstream>
#include <iomanip>

Case::Case(int N, double L)
{
    Lx =L;
    NumPoint =N;
    h = L/N;
    dt = h*h/4.0;
    T = Vec(0.0,NumPoint);


};
void Case::step()
{
    for(size_t i =1 ; i< T.size()-2;i++)
    {
        T[i] = T[i] +dt*(T[i+1]+T[i-1]-2*T[i])/(h*h);
    }

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
