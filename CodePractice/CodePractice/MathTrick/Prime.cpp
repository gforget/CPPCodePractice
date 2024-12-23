#include "Prime.h"

int Prime::gcd(int a, int b)
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool Prime::IsACoprimeOf(int Value, int Coprime)
{
    return gcd(Value, Coprime) == 1;
}
