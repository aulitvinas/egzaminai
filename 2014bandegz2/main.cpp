#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
struct abc
    {
        string savivaldybe;
        int mokyklos;
        string apskritis;

    };
struct rez
    {
        string apskritis;
        int savivaldybes;
        int mokyklos;

    };



int main()
{
    ifstream fd("U1.txt");
    int apskr=0, n;
    fd >> n;
    bool yra;
    struct abc test[100];
    struct rez rez[100];
    for (int i=0; i<n; i++)
    {
        fd >> test[i].savivaldybe;
        fd >> test[i].mokyklos;
        fd >> test[i].apskritis;


    }
    for (int i=0; i<n; i++)
    {


        yra=false;
        for (int j=0; j<10; j++)
        {

            if(test[i].apskritis==rez[j].apskritis)

                               {
                                   yra = true;
                               }
                }

             if(!yra){



                        rez[apskr].apskritis=test[i].apskritis;
                        rez[apskr].savivaldybes=0;
                        rez[apskr].mokyklos = 0;
                        apskr++;
            }

}
    for (int i=0; i<n; i++)
    {
        int max=0;
        for (int j=0; j<apskr; j++)
        {
            if (test[i].apskritis==rez[j].apskritis)
                {rez[j].savivaldybes++; max=test[i].mokyklos;
                if (max>rez[j].mokyklos) rez[j].mokyklos=max;}


        }

    }

ofstream fr("U1rez.txt");

struct rez temp;
for (int i=0; i<apskr; i++)
{
    for (int j=i+1; j<apskr; j++)
{
    if (rez[j].mokyklos>rez[i].mokyklos)
    {
        temp=rez[i];
        rez[i]=rez[j];
        rez[j]=temp;

    }
    if (rez[j].mokyklos==rez[i].mokyklos)
    {
        if (rez[j].apskritis<rez[i].apskritis)
            {
                temp=rez[i];
                rez[i]=rez[j];
                rez[j]=temp;
            }
    }
}}



for (int i=0; i<apskr; i++)

{
    cout << rez[i].apskritis << " " << rez[i].savivaldybes << " " << rez[i].mokyklos << endl;
}




    return 0;
}
