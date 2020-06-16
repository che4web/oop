#include <vector>
#include <valarray>
#include <iostream>

int main(){

    std::valarray<double> A ={ 1.0,2,3,4};
    std::valarray<double> B ={ 10,20,30,40};
    std::valarray<double> C = {};

    C = A+B;
    std::cout<< "test" <<std::endl;
    for(auto item :C){
        std::cout << item<<std::endl ;
    }


}
