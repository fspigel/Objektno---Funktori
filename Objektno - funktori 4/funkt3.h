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

class Dummy{
    Dummy() = delete;
    Dummy(Dummy const &) = delete;
    public:
    using ParamT = Dummy;
};

template <bool C, typename Ta, typename Tb>
struct IfThenElse;

template <typename Ta, typename Tb>
struct IfThenElse<true, Ta, Tb>{using type = Ta;};

template <typename Ta, typename Tb>
struct IfThenElse<false, Ta, Tb>{using type = Tb;};

template<typename FO, int NN>
struct Parameter;

template<typename FO>
struct Parameter<FO, 1>{using ParamT = typename FO::Param1T;};

template<typename FO>
struct Parameter<FO, 2>{using ParamT = typename FO::Param2T;};

template<typename FO>
struct Parameter<FO, 3>{using ParamT = typename FO::Param3T;};

template <typename FO, int NN>
struct ParamT{
   using type = typename IfThenElse<(NN<=FO::NumParams),
                                     Parameter<FO,NN>,
                                     Dummy
                                    >::type::ParamT;
};


template <typename FO1, typename FO2>
class Composer : private Base<FO1, 1>, private Base<FO2, 2>
{
public:
    enum {NumParams = FO1::NumParams};
    using Param1T = typename ParamT<FO1,1>::type;
    using Param2T = typename ParamT<FO1,2>::type;
    using Param3T = typename ParamT<FO1,3>::type;

    using ReturnT = typename FO2::ReturnT;

    /** KOnstruktor kompozicije fo2 o fo1 */
    Composer(Base<FO1, 1> f1, Base<FO2, 2> f2) : Base<FO1,1>(f1), Base<FO2,2>(f2) {}
    Composer() : Base<FO1, 1>(FO1()), Base<FO2, 2>(FO2()){}

    ReturnT operator()(Param1T x)
    {
        return fo2(fo1(x));
    }
    ReturnT operator()(Param1T x, Param2T y)
    {
        return fo2(fo1(x, y));
    }
    ReturnT operator()(Param1T x, Param2T y, Param3T z)
    {
        return fo2(fo1(x, y, z));
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
