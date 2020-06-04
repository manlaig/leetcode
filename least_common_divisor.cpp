#include <iostream>

// the LCD of 2 numbers also divides the remainder when one is divided by the other
/*
    lcd(15, 10) -> lcd(10, 5) -> lcd(5, 0) -> 5
*/
int lcd(int a, int b)
{
    a = a > b ? a : b;
    b = a > b ? b : a;

    if(b == 0)
        return a;
    return lcd(b, a % b);
}

int main()
{
    std::cout << lcd(15, 10) << std::endl;
    std::cout << lcd(39, 27) << std::endl;
}