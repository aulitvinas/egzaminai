#include <fstream>
#include <iostream>

using namespace std;
int sumaf (int nom, int nominalai[], int stud[])
{
    int suma=0;
    for (int i=0; i<nom; i++)
    {
        suma=suma+(stud[i]*nominalai[i]);

    }
    return suma;

}
int main()
{
    int nominalaiG[99], nominalaiE[99], nomG, nomE, studG[99], studE[99], suma1, suma2;
    ifstream fr("U1.txt");
    ofstream fd("U1rez.txt");
    fr >> nomG;
    for (int i=0; i<nomG; i++)
    {
        fr >> nominalaiG[i];

    }
     for (int i=0; i<nomG; i++)
    {
        fr >> studG[i];

    }
    fr >> nomE;
      for (int i=0; i<nomE; i++)
    {
        fr >> nominalaiE[i];

    }
          for (int i=0; i<nomE; i++)
    {
        fr >> studE[i];

    }
    suma1=sumaf (nomG, nominalaiG, studG);
    suma2=sumaf (nomE, nominalaiE, studE);
    int reznomE[99], reznomG[99], rezmonE[99], rezmonG[99];
    int isvis1=0, isvis2=0;
    for (int i=0; i<nomG; i++)
    {

        rezmonE[i]=(suma1/nominalaiE[i]);
        suma1=suma1-(rezmonE[i]*nominalaiE[i]);

}
    for (int i=0; i<nomE; i++)
    {
        fd << nominalaiE[i] << " ";
        fd << rezmonE[i] << " \n";
        isvis1=isvis1+rezmonE[i];

    }
    fd << isvis1 << "\n";
    for (int i=0; i<nomE; i++)
    {

        rezmonG[i]=(suma2/nominalaiG[i]);
        suma2=suma2-(rezmonG[i]*nominalaiG[i]);

}
    for (int i=0; i<nomE; i++)
    {
        fd << nominalaiG[i] << " ";
        fd << rezmonG[i] << " \n";
        isvis2=isvis2+rezmonG[i];

    }
    fd << isvis2;



return 0;}
