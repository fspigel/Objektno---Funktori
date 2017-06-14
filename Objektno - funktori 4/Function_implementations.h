
#ifndef FUNCTORS_0_H_INCLUDED
#define FUNCTORS_0_H_INCLUDED

#include <cmath>
#include <iostream>
#include <cassert>
#include "base_functors_3.h"

/**  Kreiramo funkcijske objekte klasu koja pravi kompoziciju
*    tih objekata.
*/

using namespace std;

class Sin
{
public:
    enum {NumParams = 1};
    using Param1T = double;
    using Return1T = double;

    Return1T operator()(Param1T x)
    {
        return std::sin(x);
    }
};

template <int N>
class Power
{
public:
    enum {NumParams = 1};
    using Param1T = double;
    using Return1T = double;

    Return1T operator()(Param1T x)
    {
        return std::pow(x,N);
    }
};

class Floor{
    public:
    enum {NumParams = 1};
    using Param1T = double;
    using ReturnT = int;
    ReturnT operator()(Param1T x)
    {
        return std::floor(x);
    }
};

class CosXY{
public:
   enum {NumParams = 2};
   using Param1T = float;
   using Param2T = float;
   using ReturnT = float;
   ReturnT operator()(Param1T x, Param2T y)
    {
        return std::cos(x*y);
    }
};



#endif // FUNCTORS_0_H_INCLUDED
