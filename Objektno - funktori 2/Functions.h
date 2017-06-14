#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <cassert>
#include <iostream>

/** Kompozicija dva funkcijska objekta ponovo je
     funkcijski objekt.
     Composer(fo1,fo2)  ----   fo2 o fo1.
*/

template <typename FO1, typename FO2>
class Composer
{
public:
    using Param1T = typename FO1::Param1T;
    using Return1T = typename FO2::Return1T;

    /** KOnstruktor kompozicije fo2 o fo1 */
    Composer(FO1 f1, FO2 f2) : fo1(f1), fo2(f2) {}
    Composer(){}


    Return1T operator()(Param1T x)
    {
        return fo2(fo1(x));
    }
private:
    FO1 fo1;
    FO2 fo2;
};

template<typename F1, typename F2>
Composer<F2, F1> operator*(F1 f1, F2 f2){
    return Composer<F2, F1>(f2, f1);}


template <typename FO>
void print_values(FO fo, double left, double right, int N)
{
    assert(N > 0);
    for(int i=0; i<=N; ++i)
    {
        std::cout << fo(left + i*(right-left)/N) << ( (i==N)? "\n" : ", " );
    }
}

#endif // FUNCTIONS_H_INCLUDED
