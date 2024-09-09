#include <iostream>

using namespace std;

char* MonthName(int);

int main(int argc, char* argv[])
{
    cout << MonthName(stoi(argv[1])) << endl;
}

char* MonthName(int n)
{
    static char* name[] = 
    {
        (char*)"illegal month",
        (char*)"january",
        (char*)"february",
        (char*)"march",
        (char*)"april",
        (char*)"may",
        (char*)"june",
        (char*)"july",
        (char*)"august",
        (char*)"september",
        (char*)"october",
        (char*)"november",
        (char*)"december"
    };

    return (n < 1 || n > 12) ? name[0] : name[n];
}