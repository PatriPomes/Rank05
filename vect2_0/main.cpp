#include "vect2.hpp"

int main()
{
    vect2 v1;           // 0, 0
    vect2 v2(1, 2);     // 1, 2
    const vect2 v3(v2); // 1, 2
    vect2 v4 = v2;      // 1, 2

    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v1: " << "{" << v1[0] << ", " << v1[1] << "}" << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v3: " << v3 << std::endl;
    std::cout << "v4: " << v4 << std::endl;

    std::cout << v4++ << std::endl; // 1, 2
    std::cout << ++v4 << std::endl; // 3, 4

    std::cout << v4-- << std::endl; // 3, 4
    std::cout << --v4 << std::endl; // 1, 2

    vect2 v5 = (v2 += v3); // 2, 4
    std::cout << "(v2 += v3): " << v5 << std::endl;

    vect2 v6 = (v1 -= v2); // -2, -4
    std::cout << "(v1 -= v2): " << v6 << std::endl;

    vect2 v7 = (v2 = v3 + v3 * 2); // 3, 6
    std::cout << "(v2 = v3 + v3 * 2): " << v7 << std::endl;

    vect2 v8 = (v2 = 3 * v2); // 9, 18
    std::cout << "(v2 = 3 * v2) " << v8 << std::endl;

    vect2 v9 = (v2 += v2 += v3); // 20, 40
    std::cout << "(v2 += v2 += v3) " << v9 << std::endl;

    vect2 v10 = (v1 *= 42); // -84, -168
    std::cout << "(v1 *= 42) " << v10 << std::endl;

    v1 = v1 - v1 + v1;
    std::cout << "v1: " << v1 << std::endl;

    std::cout << "-v2: " << -v2 << std::endl;
    std::cout << "v1[1]: " << v1[1] << std::endl;
    v1[1] = 12;
    std::cout << "v1[1]: " << v1[1] << std::endl;
    std::cout << "v3[1]: " << v3[1] << std::endl;
    std::cout << "v1 == v3: " << (v1 == v3) << std::endl;
    std::cout << "v1 == v1: " << (v1 == v1) << std::endl;
    std::cout << "v1 != v3: " << (v1 != v3) << std::endl;
    std::cout << "v1 != v1: " << (v1 != v1) << std::endl;

    return (0);
}