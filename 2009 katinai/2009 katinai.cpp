#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
struct abc{

    char vardas[20];
    int minute;
    int sekundes;
    int laikas;
};
int main()

{
    int n, skaicius, begikai, kiek=0;
struct abc abc[99]; // visi begikai
struct abc rez[99]; // begikai, atrenkami is grupes kaip nugaletojai
struct abc rez2[99]; // visi begikai, kurie laimejo savo grupes, t.y. galutinis sarasas
    ifstream fr("U2.txt");
    ofstream fd("U2rez.txt");
    fr >> n;
    for (int i=0; i<n; i++)
    {
        fr >> skaicius;
        for (int j=0; j<skaicius; j++)
        {
            fr.ignore();
            fr.get(abc[j].vardas, 20);
            fr >> abc[j].minute;
            fr >> abc[j].sekundes;
            abc[j].laikas=(abc[j].minute*60)+abc[j].sekundes;
        }
        for (int j=0; j<skaicius; j++)
        {

            begikai=skaicius/2; // suskaiciuojama, kiek begiku pateks i galutini sarasa
            for (int a=0; a<skaicius; a++)
            {
                for (int b=a+1; b<skaicius; b++)
                {
                    struct abc temp;
                    if (abc[b].laikas<abc[a].laikas)
                    {
                        temp=abc[a];
                        abc[a]=abc[b];
                        abc[b]=temp;

                            }


                }
            }

            for (int x=0; x<begikai; x++) // pries tai begikai isrikiuoti pagal laika, todel i rez pateks tik laimetojai
            {
                rez[x]=abc[x];

            }



}
        for (int i=0; i<begikai; i++) //  grupiu laimetojai ivedami i galutini sarasa
            {

                rez2[kiek]=rez[i];

                kiek++;
            }

     for (int a=0; a<kiek; a++) // rikiuojamas galutinis sarasas
            {
                for (int b=a+1; b<kiek; b++)
                {
                    struct abc temp;
                    if (rez2[b].laikas<rez2[a].laikas)
                    {
                        temp=rez2[a];
                        rez2[a]=rez2[b];
                        rez2[b]=temp;


}}}}
for (int i=0; i<kiek; i++)
        {
            cout << rez2[i].vardas << " ";
            cout << rez2[i].laikas/60 << " ";
            cout << rez2[i].laikas%60 << endl;

        }

return 0;}
