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
int x, y, x1,y1, n, k, ejimas, ivykdyta[99], kiek=0;

bool tikslas=false;
struct abc abc;
ifstream fr("U2.txt");
ofstream fd("U2rez.txt");
fr >> x >> y >> x1 >> y1 >> n;

for (int i=0; i<n; i++)
{
    abc.x=x;
    abc.y=y;
    fr >> k;
    for (int j=0; j<k; j++)
    {



        fr >> ejimas;
        if (ejimas==1) {abc.y++; ivykdyta[kiek]=ejimas; kiek++;}
        if (ejimas==2) {abc.x++; ivykdyta[kiek]=ejimas; kiek++;}
        if (ejimas==3) {abc.y--; ivykdyta[kiek]=ejimas; kiek++;}
        if (ejimas==4) {abc.x--; ivykdyta[kiek]=ejimas; kiek++;}
        if ((abc.y==y1) && (abc.x==x1))
        {
            tikslas=true;

            cout << "pasiektas tikslas   ";
            for (int i=0; i<kiek; i++)
            {
            cout << ivykdyta[i] << " ";
            }
            cout << kiek << endl;


    }



    }
    kiek=0;
    if (tikslas==false) {cout << "sekos pabaiga       ";
    for (int i=0; i<k; i++)
        {
            cout << ivykdyta[i] << " ";

        }
        cout << endl;

    }
 tikslas=false;

}
return 0;}
