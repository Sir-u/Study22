#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
    ifstream in("names.txt");
    int count = 0;

    char buf[1000];

    while (in)
    {
        cout << "while in" << endl;
        in.getline(buf, 100);
        cout << buf << endl;
        for (int n = 0; n < 36; n++)
        {
            
            if (buf[n] == 'M')
            {
                cout << "if in" << endl;
                cout << buf[n] << endl;
                count++;
                cout << "if out" << endl;
            }
        }

        cout << "while out" << endl;
    }
    cout << count << endl;
}