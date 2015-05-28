#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int n=0, k;
struct pora
{
    string vardas1;
    string vardas2;
    int technika[10];
    int artistiskumas[10];
    };


ifstream fd("U2.txt");
ofstream fr("U2rez.txt");
void duomenys (struct pora &pora[])
{
    fd >> n;
    fd >> k;
    for (int i=0; i<n; i++)
    {
        fd >> pora[i].vardas1;
        fd >> pora[i].vardas2;
            for (int j=0; j<k; j++)
            {
                fd >> pora[i].technika[j];
            }
            for (int j=0; j<k; j++)
            {
                fd >> pora[i].artistiskumas[j];
            }
    }


}
int skaiciuoti (int balai [10])
{   int max=0, min=11, isviso=0;
    for (int i=0; i<k; i++)
    {
        if (balai[i]>max) max=balai[i];
        if (balai[i]<min) min=balai[i];
        isviso=isviso+balai[i];
    }
    isviso=isviso-max-min;
    return isviso;
}

void rikiuoti (struct pora pora[], int sumbalsai[]) // cia struct pora pora, jei pora tai fail
{
    struct pora temp;
    int temp2;
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (sumbalsai[j]>sumbalsai[i])
            {
                temp=pora[i];
                pora[i]=pora[j];
                pora[j]=temp;
                temp2=sumbalsai[i];
                sumbalsai[i]=sumbalsai[j];
                sumbalsai[j]=temp2;
            }
        }
    }
}

int main()

{   int balai[10], sumbalsai[10], dalinbal;
    struct pora pora[100];
    duomenys (pora);

    for (int i=0; i<n; i++)
    {

        for (int j=0; j<k; j++)
        {
            balai[j]=pora[i].technika[j];
        }
        dalinbal=skaiciuoti (balai);
        sumbalsai[i]=sumbalsai[i]+dalinbal;
        for (int j=0; j<k; j++)

        {
             balai[j]=pora[i].artistiskumas[j];
        }
        dalinbal=skaiciuoti (balai);
        sumbalsai[i]=sumbalsai[i]+dalinbal;
}

    rikiuoti (pora, sumbalsai);

    for (int i=0; i<n; i++)

    {
        fr << pora[i].vardas1 << " " << pora[i].vardas2 << " " << sumbalsai[i] << endl;


    }






return 0;

}
