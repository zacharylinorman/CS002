#include <iostream>

using namespace std;

int main()
{
    int num1, num2;
    cout << "Enter the first integer: ";
    cin >> num1;
    cout << endl;

    cout << "Enter the second integer: ";
    cin >> num2;
    cout << endl;

    cout << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
    cout << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
    cout << num1 << " / " << num2 << " = " << (num1 / num2) << endl;
    cout << num1 << " % " << num2 << " = " << (num1 % num2) << endl;

    return 0;
}
