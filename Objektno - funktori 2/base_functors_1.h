
#ifndef FUNCTORS_0_H_INCLUDED
#define FUNCTORS_0_H_INCLUDED

#include <cmath>
#include <iostream>
#include <cassert>

/**  Kreiramo funkcijske objekte klasu koja pravi kompoziciju
*    tih objekata.
*/

using namespace std;

class Sin
{
public:
    using Param1T = double;
    using ReturnT = double;

    ReturnT operator()(Param1T x)
    {
        return std::sin(x);
    }
};

template <int N>
class Power
{
public:
    using Param1T = double;
    using ReturnT = double;

    ReturnT operator()(Param1T x)
    {
        return std::pow(x,N);
    }
};

class Floor
{
public:
    using Param1T = double;
    using ReturnT = int;

    ReturnT operator()(Param1T x)
    {
        return std::floor(x);
    }
};



#endif // FUNCTORS_0_H_INCLUDED
