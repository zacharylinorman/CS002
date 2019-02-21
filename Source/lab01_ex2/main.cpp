#include <iostream>

using namespace std;

int main()
{
    double num1, num2, num3, num4, num5, num6;
    double sum;

    cout << "Enter six fp numbers on a single line, separated by spaces: ";
    cin >> num1 >> num2 >> num3 >> num4 >> num5 >> num6;
    cout << endl;

    cout << "Sum of " << num1 << " + " << num2 << " + " << num3 << " + " << num4 << " + " << num5 << " + " << num6 << " = " << (sum = (num1 + num2 + num3 + num4 + num5 + num6)) << endl;
    cout << "Average = " << (sum/6) << endl;

    return 0;
}
