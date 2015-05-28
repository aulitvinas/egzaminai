#include <iostream>
#include <fstream>
int n, m;
using namespace std;
struct dievas
{
    char vardas[10];
    int metimai[10];
};
struct dievas dievas[100];
void duomenys ()
{
    ifstream fr("U2.txt");
    fr >> n;
    fr >> m;
    for (int i=0; i<n; i++)
    {

            fr.ignore();
            fr.get(dievas[i].vardas, 10);
            cout << dievas[i].vardas;

        for (int j=0; j<m; j++)
        {

            fr >> dievas[i].metimai[j];


            }
    }

}

void skaiciuot (struct dievas dievas[])
{
    int taskai[n], max=0, maxnr=0;
    for (int i=0; i<n; i++)
    {
        taskai[i]=0;
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (dievas[i].metimai[j]%2==0) taskai[i]=taskai[i]+dievas[i].metimai[j];
            else taskai[i]=taskai[i]-dievas[i].metimai[j];

}
    }
    for (int i=0; i<n; i++)
    {
        if (taskai[i]>max) {max=taskai[i], maxnr=i;}
    }
    ofstream fd ("U2rez.txt");
    fd << dievas[maxnr].vardas << " ";
    fd << max;


}


int main()
{

    duomenys();
    skaiciuot(dievas);

    return 0;
}


