#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct miestai
{
    char miestas[20];
    char apskritis[13];
    int gyventojai;

};
struct rez
{
    char apskritis[13];
    int minimumas=99999999;
    int isviso=0;
};
int main()

{   int n, isvis=0;
    bool yra=false;
    ifstream fr("U2.txt");
    ofstream fd("U2rez.txt");
    struct miestai miestai[103];
    struct rez rez[20];
    fr >> n;
    for (int i=0; i<n; i++)
    {
        fr.ignore();
        fr.get(miestai[i].miestas, 20);

        fr.get(miestai[i].apskritis, 13);

        fr >> miestai[i].gyventojai;
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (strcmp(miestai[i].apskritis, rez[j].apskritis)==0) // !!!
            {
                yra=true;
            }
        }
        if (!yra)
        {
            for (int k=0; k<13; k++)
            {
                  rez[isvis].apskritis[k]=miestai[i].apskritis[k];
            }
            isvis++;

        }
        yra=false;


    }

    for (int i=0; i<isvis; i++)
    {

        for (int j=0; j<n; j++)
        {
            if (strcmp(miestai[j].apskritis,rez[i].apskritis)==0)
            {
                rez[i].isviso=rez[i].isviso+miestai[j].gyventojai;
                if (miestai[j].gyventojai<rez[i].minimumas) rez[i].minimumas=miestai[j].gyventojai;

            }
        }

    }

      for (int i=0; i<isvis; i++)
      {
          for (int j=i+1; j<isvis; j++)
          {struct rez temp;
            if (rez[j].isviso<rez[i].isviso)
            {
                temp=rez[i];
                rez[i]=rez[j];
                rez[j]=temp;

}
}
           for (int i=0; i<isvis; i++)
      {
          for (int j=0; j<isvis; j++)
          {struct rez temp;

        if ((rez[j].isviso==rez[i].isviso)&&(rez[j].apskritis!=rez[i].apskritis))
            {
                if (strcmp(rez[j].apskritis, rez[i].apskritis)<0)
                {

                temp=rez[i];
                rez[i]=rez[j];
                rez[j]=temp;
                }
                ;}
          }}}

for (int i=0; i<isvis; i++)
{
    cout << rez[i].apskritis;
    cout << rez[i].isviso << endl;
}


}





