#include <iostream>
#include <Windows.h>
#include "headers_include.hpp"

USING_MY_MATH_
USING_BR_EXCEPT_

template <class T>
void print_4variables(
    const point<T>& coordinate_1d,
    const point<T>& coordinate_2d,
    const point<T>& coordinate_3d,
    const point<T>& coordinate_4d
    )
{
    cout << VARIABLE_NAME(coordinate_1d) << ":\n";
    cout << coordinate_1d << "\n";

    cout << VARIABLE_NAME(coordinate_2d) << ":\n";
    cout << coordinate_2d << "\n";

    cout << VARIABLE_NAME(coordinate_3d) << ":\n";
    cout << coordinate_3d << "\n";

    cout << VARIABLE_NAME(coordinate_4d) << ":\n";
    cout << coordinate_4d << "\n";
}

int main(int argc, char* argv[])
{
    point<int> coordinate_1d(1, 1);
    point<int> coordinate_2d(2, 2);
    point<int> coordinate_3d(3, 3);
    point<int> coordinate_4d(4, 4);
    cout << "Before operations:\n\n";
    print_4variables(coordinate_1d,coordinate_2d, coordinate_3d, coordinate_4d);
    
    coordinate_4d -= coordinate_1d;
    coordinate_3d -= coordinate_2d;

    coordinate_1d += coordinate_4d;
    coordinate_2d += coordinate_3d;
    
    cout << "\n\n\nAfter operation1:\n\n";
    print_4variables(coordinate_1d,coordinate_2d, coordinate_3d, coordinate_4d);

    
    coordinate_4d -= 1;
    coordinate_3d -= 1;

    coordinate_1d += 1;
    coordinate_2d += 1;
    
    cout << "\n\n\nAfter operation2:\n\n";
    print_4variables(coordinate_1d,coordinate_2d, coordinate_3d, coordinate_4d);
    
    point<string> coordinate(2);

    
    system("pause");

    return 0;
}
