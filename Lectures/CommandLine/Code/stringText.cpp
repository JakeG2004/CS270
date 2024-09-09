#include <iostream>

using namespace std;

int main(void)
{
    char* S[7] = 
    {
        "0 zero",
        "1 one",
        "2 two",
        "3 three",
        "4 four",
        "5 five",
        "6 six"
    };

    S[3] = "Hello World!";

    cout << S[3] << endl;

    for(int i = 0; i < 7; i++)
    {
        cout << i << " " << S[i] << endl;
    }
}