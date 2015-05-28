#include <iostream>
#include <fstream>
using namespace std;

struct zvejys
{
    char vardas[9];
    int kartai;
    int zuvys1[30];
    int zuvys11;
    int zuvys2[30];
    int zuvys22;
    int zuvys3[30];
    int zuvys33;
    int isviso;
};
struct zvejys zvejys[99];
int n=0;
void nuskaitymas()
{
    ifstream fr("U2.txt");
    fr >> n;
    for (int i=0; i<n; i++)
    {   fr.ignore(1, '\n');
        fr.read(zvejys[i].vardas, 9);
        fr >> zvejys[i].kartai;
            for (int j=0; j<zvejys[i].kartai; j++)
            {
                fr >> zvejys[i].zuvys1[j];
                fr >> zvejys[i].zuvys2[j];
                fr >> zvejys[i].zuvys3[j];
            }
    }

}
int funkcija (struct zvejys[99], int n)
{   int max=0, nr;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<zvejys[i].kartai; j++)
        {
            zvejys[i].zuvys11=zvejys[i].zuvys11+zvejys[i].zuvys1[j];
            zvejys[i].zuvys22=zvejys[i].zuvys22+zvejys[i].zuvys2[j];
            zvejys[i].zuvys33=zvejys[i].zuvys33+zvejys[i].zuvys3[j];
            zvejys[i].isviso=zvejys[i].isviso+zvejys[i].zuvys1[j]+zvejys[i].zuvys2[j]+zvejys[i].zuvys3[j];
        }
        if (zvejys[i].isviso>max) {max=zvejys[i].isviso; nr=i;}

    }
    return nr;

}
void vaizdavimas(int geriausias)
{

    ofstream fd("U2rez.txt");
    for (int i=0; i<n; i++)
    {

        cout << zvejys[i].vardas << " ";
          if ((zvejys[i].zuvys11>=0)&&(zvejys[i].zuvys11<10))   cout << zvejys[i].zuvys11 << "    ";
          if ((zvejys[i].zuvys11>=10)&&(zvejys[i].zuvys11<100))   cout << zvejys[i].zuvys11 << "   ";
          if ((zvejys[i].zuvys11>=100)&&(zvejys[i].zuvys11<1000))   cout << zvejys[i].zuvys11 << "  ";
          if ((zvejys[i].zuvys22>=0)&&(zvejys[i].zuvys22<10))   cout << zvejys[i].zuvys22 << "    ";
          if ((zvejys[i].zuvys22>=10)&&(zvejys[i].zuvys22<100))   cout << zvejys[i].zuvys22 << "   ";
          if ((zvejys[i].zuvys22>=100)&&(zvejys[i].zuvys22<1000))   cout << zvejys[i].zuvys22 << "  ";
          if ((zvejys[i].zuvys33>=0)&&(zvejys[i].zuvys33<10))   cout << zvejys[i].zuvys33 << "    ";
          if ((zvejys[i].zuvys33>=10)&&(zvejys[i].zuvys33<100))   cout << zvejys[i].zuvys33 << "   ";
          if ((zvejys[i].zuvys33>=100)&&(zvejys[i].zuvys33<1000))   cout << zvejys[i].zuvys33 << "  ";

            cout << endl;

    }
    cout << zvejys[geriausias].vardas;
    cout << zvejys[geriausias].isviso;
}
int main()


{
        int geriausias;
        nuskaitymas();
        geriausias=funkcija(zvejys, n);
        vaizdavimas(geriausias);


}
