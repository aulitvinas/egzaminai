#include <iostream>
#include <fstream>
using namespace std;
int n, lytis[99], puse[99], dydis[99], rand;
 ifstream fr("U1.txt");
    ofstream fd("U1rez.txt");
void nuskaitymas (int rand)
{
    fr >> n;
    for (int i=0; i<n; i++)
    {
        fr >> lytis[i];
        fr >> puse[i];
        fr >> dydis[i];
    }




}
int poros (int skaicius, int lytis[], int puse[], int dydis[], int n)
{
    int poros=0;
    for (int i=0;i<n;i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if ((lytis[i]==skaicius)&&(skaicius==lytis[j])&&(puse[i]!=puse[j])&&(dydis[i]==dydis[j]))
            {
                poros++;
                puse[i]=0;
                puse[j]=0;
                dydis[i]=0;
                dydis[j]=0;
            }
        }

    }

    return poros;
}
int liko (int skaicius, int dydis[], int lytis[], int n)
{
    int liko=0;
    for (int i=0; i<n; i++)
    {
        if ((dydis[i]!=0)&&(skaicius==lytis[i])) liko++;
    }
    return liko;
}
int main()

{
    int porosM, porosV, likoV, likoM;
    nuskaitymas (rand);
    porosM=poros(4, lytis, puse, dydis, n);
    fd << porosM << endl;
    porosV=poros(3, lytis, puse, dydis, n);
    fd << porosV << endl;
    likoM=liko(4, dydis, lytis, n);
    fd << likoM << endl;
    likoV=liko(3, dydis, lytis, n);
    fd << likoV << endl;








return 0;}
