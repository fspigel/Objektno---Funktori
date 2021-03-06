#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <cassert>
#include <iostream>

/** Kompozicija dva funkcijska objekta ponovo je
     funkcijski objekt.
     Composer(fo1,fo2)  ----   fo2 o fo1.
*/

template<typename T, int N>
class Base : public T{
public:
    Base(T & t) : T(t) {}
    Base(T const & t) : T(t) {}
};

template <typename FO1, typename FO2>
class Composer : private Base<FO1, 1>, private Base<FO2, 2>
{
public:
    using Param1T = typename FO1::Param1T;
    using Return1T = typename FO2::Return1T;

    /** KOnstruktor kompozicije fo2 o fo1 */
    Composer(Base<FO1, 1> f1, Base<FO2, 2> f2) : Base<FO1,1>(f1), Base<FO2,2>(f2) {}
    Composer() : Base<FO1, 1>(FO1()), Base<FO2, 2>(FO2()){}

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
    Base<F1, 1> b1(f1);
    Base<F2, 2> b2(f2);
    return Composer<F2, F1>(b2, b1);
}


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
