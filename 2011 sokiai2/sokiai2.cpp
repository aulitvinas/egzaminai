#include <fstream>
#include <iostream>

using namespace std;
int npor, nteisT, nteisA;
ifstream fr("U2.txt");
ofstream fd("U2rez.txt");
struct pora
{
    char vardai[20];
    int tech[10];
    int art[10];
    int balai=0;
};
struct pora pora[99];

void nuskaitymas()
{
    fr >> npor;
    fr >> nteisT;
    fr >> nteisA;
    for (int i=0; i<npor; i++)
    {
        fr.ignore();
        fr.get(pora[i].vardai, 20);
        for (int j=0; j<nteisT; j++)
        {
            fr >> pora[i].tech[j];
        }
        for (int k=0; k<nteisA; k++)
        {
            fr >> pora[i].art[k];
        }
    }
}
int balai(int teisejai, int balai[])
{
    int max=0, min=99, suma=0;
    for (int j=0; j<teisejai; j++)
    {
        if (balai[j]>max) max=balai[j];
        if (balai[j]<min) min=balai[j];
        suma=suma+balai[j];
    }
    suma=suma-max-min;
    return suma;


}
void rikiavimas()
{
    for (int i=0; i<npor; i++)
    {
        for (int j=i+1; j<npor; j++)
        {
            if (pora[j].balai>pora[i].balai)
            {
                struct pora temp;
                temp=pora[i];
                pora[i]=pora[j];
                pora[j]=temp;
            }
        }
    }
}
int main()


{
    int balaiA, balaiT, balsai[99];
    nuskaitymas();
    for (int i=0; i<npor; i++)
    {
        for (int j=0; j<nteisT; j++)
        {
            balsai[j]=pora[i].tech[j];
        }
        balaiT=balai(nteisT, balsai);
        for (int j=0; j<nteisA; j++)
        {
            balsai[j]=pora[i].art[j];
        }
        balaiA=balai(nteisA, balsai);
        pora[i].balai=pora[i].balai+balaiT+balaiA;

    }
    rikiavimas();
   for (int i=0; i<npor; i++)
   {
       cout << pora[i].vardai;
       cout << pora[i].balai << endl;
   }



return 0;}
