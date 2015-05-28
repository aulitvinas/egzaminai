#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int k, nr[12], laikai[40], laikasz[12], laikass[12], numer=0, start[4];
ifstream fd("U1.txt");
ofstream fr("U1rez.txt");
void duomenys ()
{
    int penketas=0;
    fd >> k;
    for (int i=0; i<k; i++)
    {   int kiek=0;
        fd >> nr[i];
        fd >> kiek;

        for (int j=0; j<kiek; j++)
        {
            fd >> laikai[j];
            if (laikai[j]>0) laikasz[i]=laikasz[i]+laikai[j];
            if (laikai[j]<0) laikass[i]=laikass[i]+(laikai[j]*-1);

            ;}
        if (laikai[0]>0) {start[penketas]=nr[i]; penketas++;}
        }

}

int reiksme (int k, int laikas[12], int nr[12])
{
    int max=0, numer=0;
    for (int i=0; i<k; i++)
    {

        if (laikas[i]>max) {max=laikas[i]; numer=nr[i];}

    }
      fr << numer << " ";
        fr << max << " ";
        fr << endl;

    return max;

}
int main()
{
    int daugmin=0, mazmin=0;
    duomenys (); //
    std::sort (start, start+5);
    for (int i=0; i<5; i++)
    {
        fr << start[i] <<" " ;

    }
    fr << endl;
    daugmin= reiksme (k, laikasz, nr);
    mazmin= reiksme (k, laikass, nr);


    return 0;
}
