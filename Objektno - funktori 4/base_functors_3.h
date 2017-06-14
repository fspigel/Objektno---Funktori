#ifndef BASE_FUNCTORS_H_INCLUDED
#define BASE_FUNCTORS_H_INCLUDED

#include <cmath>

class Sin
{
public:
    enum {NumParams = 1};
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
    enum {NumParams = 1};
    using Param1T = double;
    using ReturnT = double;

    ReturnT operator()(Param1T x)
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

class SumXY{
public:
   enum {NumParams = 2};
   using Param1T = float;
   using Param2T = float;
   using ReturnT = float;
   ReturnT operator()(Param1T x, Param2T y)
    {
        return x+y;
    }
};
class SumXYZ{
public:
   enum {NumParams = 3};
   using Param1T = float;
   using Param2T = float;
   using Param3T = float;
   using ReturnT = float;
   ReturnT operator()(Param1T x, Param2T y, Param3T z)
    {
        return x+y+z;
    }
};



#endif // BASE_FUNCTORS_H_INCLUDED
