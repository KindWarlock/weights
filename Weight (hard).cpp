#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n, ost, left[3], right[3];
    int* pleft;                      //чтобы не плодить новые счетчики
    int* pright;
    ofstream output ("output.dat");
    if (!output.is_open()) {
        cout << "Could not create a file" << endl;
        return -4;
    }
    output << "  m  |   Left   |   Right  " << endl << "---------------------------" << endl; // M лежит на левой чаше
    for (int m = 30; m <= 200; m++) {
        if (m >= 100) output << m << "  | ";
        else output << m << "   | ";
        n = m;
        pleft = left;
        pright = right;
        for (int i = 1; i < 101; i *= 10) {
            ost = n % 10;
            switch (ost)
            {
            case 1:
                *pright = i;
                *pleft = 0;
                break;
            case 2:
                *pright = 2 * i;
                *pleft = 0;
                break;
            case 3:
                *pright = 5 * i;
                *pleft = 2 * i;
                break;
            case 4:
                *pright = 5 * i;
                *pleft = i;
                break;
            case 5:
                *pright = 5 * i;
                *pleft = 0;
                break;
            case 6:
                *pright = i;
                *pleft = 5 * i;
                n += 5;
                break;
            case 7:
                *pright = 2 * i;
                *pleft = 5 * i;
                n += 5;
                break;
            case 8:
                *pright = 0;
                *pleft = 2 * i;
                n += 5;
                break;
            case 9:
                *pright = 0;
                *pleft = i;
                n += 5;
                break;
            default:
                *pright = 0;
                *pleft = 0;
                n += 5;
                break;
            }
            n /= 10;
            pright++;
            pleft++;
        }
        for (int i = 0; i < 3; i++) {
            if (!left[i]) {                         //чтобы соответствующие разряды были друг под другом
                switch (i) {
                case 0:
                    output << "  ";
                    break;
                case 1:
                    output << "   ";
                    break;
                case 2:
                    output << "    ";
                    break;
                }
                continue;
            }
            output << left[i] << " ";
        }
        output << "| ";
        for (int i = 0; i < 3; i++) {
            if (!right[i]) {
                switch (i) {
                case 0:
                    output << "  ";
                    break;
                case 1:
                    output << "   ";
                    break;
                case 2:
                    output << "    ";
                    break;
                }
                continue;
            }
            output << right[i] << " ";
        }
        output << endl;
    }
    out.close();
    return(0);
}
