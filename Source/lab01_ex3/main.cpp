#include <iostream>

using namespace std;

int main()
{
    int age;

    cout << "What is your age: ";
    cin >> age;
    cout << endl;

    cout << "Your target heart rate is between " << (0.6 * (220 - age)) << " and " << (0.75 * (220 - age)) << " bpm." << endl;
    return 0;
}
