#include <iostream>
#include <functional>
#include "matrix.h"
#include <time.h>
#include <cstdlib>
using namespace std;

#define check_equal(x, y)  do { if ((x) != y) std::cout << ": expected " << y << " got " << (x) << '\n'; } while(0)

int ROWS = 10;
int COLS = 20;


Matrix init_matrix()
{
    int n = 0;
    Matrix m1(ROWS, COLS);
    for (int row = 0; row < ROWS; ++row)
        for (int col = 0; col < COLS; ++col)
            m1(row,col) = ++n;
    return m1;
}

inline void check_equal_matrix( Matrix& m1,Matrix& m2, function<double(double)> f)
{
    for (int row = 0; row < ROWS; ++row)
        for (int col = 0; col < COLS; ++col)
            check_equal(m2(row,col),f(m1(row,col)));

    std::cout<<".";
}

inline void check_equal_matrix( Matrix& m1,Matrix& m2,Matrix& m3, function<double(double,double)> f)
{
    for (int row = 0; row < ROWS; ++row)
        for (int col = 0; col < COLS; ++col)
            check_equal(m2(row,col),f(m1(row,col),m3(row,col)));

    std::cout<<".";
}
void test_time2()
{
    srand(static_cast<unsigned int>(time(0))); 
    Matrix m1(ROWS*ROWS,COLS*COLS);
    Matrix m2(ROWS*ROWS,COLS*COLS);

    clock_t start = clock();
    for (int i=0; i<ROWS*ROWS; ++i)
    {
        for (int j=0; j < COLS*COLS; ++j)
        {
           m1(i,j) = (rand()%100)/100.0;
           m2(i,j) = (rand()%100)/100.0;
        }
    }
    for (int i=0; i<100000; ++i)
    {
        m1=m1*m2;
    }
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
  	printf("The time: %f seconds\n", seconds);
}

int main()
{

    Matrix m1 = init_matrix();
    Matrix m2 = init_matrix();
    Matrix m3 = init_matrix();
    
    std::cout<<m1<<std::endl;


    std::cout<<"+=";
    m2=m1;
    m2 += 2.0;
    check_equal_matrix(m1,m2,[](double x){return x+2.0;});

    std::cout<<"-=";
    m2=m1;
    m2 -= 2.0;
    check_equal_matrix(m1,m2,[](double x){return x-2.0;});

    std::cout<<"/=";
    m2=m1;
    m2 /= 2.0;
    check_equal_matrix(m1,m2,[](double x){return x/2.0;});
    
    std::cout<<"*=";
    m2=m1;
    m2 *= 2;
    check_equal_matrix(m1,m2,[](double x){return x*2.0;});

    std::cout<<"*d";
    m2 = m1*2.0;
    check_equal_matrix(m1,m2,[](double x){return x*2.0;});

    std::cout<<"d*";
    m2 = 2.0*m1;
    check_equal_matrix(m1,m2,[](double x){return x*2.0;});
    std::cout<<"/d";
    m2 = m1/2.0;
    check_equal_matrix(m1,m2,[](double x){return x/2.0;});
    std::cout<<"d/";
    m2 = 2.0/m1;
    check_equal_matrix(m1,m2,[](double x){return 2.0/x;});

    std::cout<<"+d";
    m2 = m1+2.0;
    check_equal_matrix(m1,m2,[](double x){return x+2.0;});
    std::cout<<"d+";
    m2 = 2.0+m1;
    check_equal_matrix(m1,m2,[](double x){return x+2.0;});

    std::cout<<"-d";
    m2 = m1-2.0;
    check_equal_matrix(m1,m2,[](double x){return x-2.0;});
    std::cout<<"d-";
    m2 = 2.0-m1;
    check_equal_matrix(m1,m2,[](double x){return 2.0-x;});
    m3 *=3;

    std::cout<<"M+M";
     m2 = m1+m3;
     check_equal_matrix(m1,m2,m3,[](double x, double y){return x+y;});

    std::cout<<"M/M";
     m2 = m1/m3;
     check_equal_matrix(m1,m2,m3,[](double x,double y){return x/y;});
    std::cout<<"M*M";
     m2 = m1*m3;
     check_equal_matrix(m1,m2,m3,[](double x,double y){return x*y;});

    std::cout<<"M-M ";
     m2 = m1-m3;
     check_equal_matrix(m1,m2,m3,[](double x,double y){return x-y;});


    std::cout<<"M+M*2+M";
     m2 = m1+ m1*2.0+m1;
     check_equal_matrix(m1,m2,[](double x){return x +x*2.0+x;});
    std::cout<<"\n";
    std::cout << m2<<std::endl;
    std::cout << "done\n";
     test_time2();


    return 0;
}
