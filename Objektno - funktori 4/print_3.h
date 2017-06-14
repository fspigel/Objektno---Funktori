#ifndef PRINT_H_INCLUDED
#define PRINT_H_INCLUDED

#include <cassert>


template <typename FO>
void print_values(FO fo, typename FO::Param1T left, typename FO::Param1T right, int N)
{
    assert(N > 0);
    for(int i=0; i<=N; ++i){

        std::cout << fo(left + i*(right-left)/N) << ( (i==N)? "\n" : ", " );
    }
}

template <typename FO>
void print_2Dvalues(FO fo, typename FO::Param1T leftX, typename FO::Param1T rightX, int N,
                           typename FO::Param2T leftY, typename FO::Param2T rightY, int M)
{
    assert(N > 0);
    assert(M > 0);
    for(int i=0; i<=N; ++i){
       for(int j=0; j<=M; ++j){
        std::cout << fo(leftX + i*(rightX-leftX)/N, leftY + j*(rightY-leftY)/M) << ( (j==M)? "\n" : ", " );
       }
    }
}



#endif // PRINT_H_INCLUDED
