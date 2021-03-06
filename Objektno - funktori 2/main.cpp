#include <typeinfo>
#include "base_functors_1.h"
#include "funkt1.h"

int main()
{
    std::cout << "test1\n";
    Sin sin;
    Power<3> pow3;

    print_values(pow3*sin, 0.0, 2.0, 5);

    Floor floor;
    Power<2> pow2;
    assert( typeid( (floor*pow2)(0.0)) == typeid(int));

    print_values(floor*pow2, 0.0, 6.0, 6);

    print_values(sin*pow2*floor, 0.0, 6.0, 6);
}
