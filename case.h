#pragma once
#include <valarray>
#include <string>

using Vec = std::valarray<double>;
/*
class  Field
{
public:
    Vec F;
    std::string name;
};
*/
class Case
{
public:
    int NumPoint;
    double Lx;
    Vec T;
    Vec dT;
    
    double dt;
    double h;
    Case(int NumPoint,double L);
    void setInitial(Vec );
    void step();
    void write(std::string);
};
