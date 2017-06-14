
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

    double operator()(double x)
    {
        return std::sin(x);
    }
};

template <int N>
class Power
{
public:

    double operator()(double x)
    {
        return std::pow(x,N);
    }
};

class Floor
{
public:
    int operator()(double x)
    {
        return std::floor(x);
    }
};



#endif // FUNCTORS_0_H_INCLUDED
