#include <iostream>
#include "base_functors_2.h"
#include "funkt2.h"

 int main()
{
    std::cout << "test2\n";
    Sin sin;
    Power<3> pow3;
    Composer<Power<3>,Power<3>> err(pow3,pow3);
    print_values(err, 0.0, 2.0, 5);
    print_values(pow3*sin, 0.0, 2.0,5);

    Floor floor;
    Power<2> pow2;
    print_values(pow2*floor, 0.0, 6.0, 6);

    Composer<Floor, Power<2>> comp2(floor,pow2);
    //Where is default ctor used ( Composer() )?
    Composer<Composer<Floor,Power<2>>, Sin> comp3(comp2,sin);

    print_values(comp3, 0.0, 6.0, 6);
    print_values(sin*pow2*floor, 0.0, 6.0, 6);

    return 0;
}
