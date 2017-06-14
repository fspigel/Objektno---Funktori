#include <iostream>
#include "base_functors_3.h"
#include "funkt3.h"
#include "print_3.h"


int main()
{
    std::cout << "test3\n";
    Sin sin;
    Power<3> pow3;
    Composer<Power<3>,Power<3>> err(pow3,pow3);
    print_values(err, 0.0, 2.0, 5);
    print_values(pow3*sin, 0.0, 2.0,5);

    Floor floor;
    Power<2> pow2;
    print_values(pow2*floor, 0.0, 6.0, 6);

    Composer<Floor, Power<2>> comp2(floor,pow2);
    Composer<Composer<Floor,Power<2>>, Sin> comp3(comp2,sin);

    print_values(comp3, 0.0, 6.0, 6);
    print_values(sin*pow2*floor, 0.0, 6.0, 6);

    CosXY cosXY;
    SumXY sumXY;
    print_2Dvalues(sumXY, 0.0, 6.0, 6, 0.0, 2.0, 3);
    print_2Dvalues(sin*pow2*cosXY, 0.0, 6.0, 6, 0.0, 2.0, 3);


    std::cout << std::endl << "Shenky je glup lolol sve radi";
 //   std::cout << (pow2*cosXY)(1,2,3);
    return 0;
}
