#include <fstream>
#include <iostream>
using namespace std;
struct abc
{
    int x;
    int y;
};
int main()
{
    struct abc abc;
    int x0, y0, n, ivykdyta[99], ejimas, k, ejimai;
    bool tikslas=false;
    ifstream fr("U2.txt");
    ofstream fd("U2rez.txt");
    fr >> x0;
    fr >> y0;
    fr >> n;
    for (int i=0; i<n; i++)
    {
        abc.x=x0;
        abc.y=y0;
        fr >> k;
        ejimai=0;
        tikslas=false;
        for (int j=0; j<k; j++)
        {
            fr >> ejimas;
            if (ejimas==1) {abc.x++; abc.y++;}
            if (ejimas==2) {abc.x++; abc.y--;}
            if (ejimas==3) {abc.x--; abc.y--;}
            if (ejimas==4) {abc.x--; abc.y++;}
            ejimai++;
            ivykdyta[j]=ejimas;
            if ((abc.x==x0)&&(abc.y==y0))
            {   tikslas=true;
                cout << "Pasiektas tikslas   ";
                for (int l=0; l<ejimai; l++)
                {
                    cout << ivykdyta[l] << " ";
                }
                cout << ejimai << endl;

            }
        }
        if (tikslas==false)
        {
            cout << "sekos pabaiga       ";
            for (int l=0; l<ejimai; l++)
                {
                    cout << ivykdyta[l] << " ";
                }
                cout << ejimai << " ";
                cout << abc.x << " ";
                cout << abc.y << endl;
        }

    }
}
