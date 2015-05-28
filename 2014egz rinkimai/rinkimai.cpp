#include <fstream>
#include <iostream>
using namespace std;

int taskai[2];
void skaiciuoti(int balsai [], int taskai [])
{
     int max=0, nr;

    if ((balsai[0]==balsai[1]) && (balsai[1]==balsai[2]))
    {taskai[0]=taskai[0]; taskai[1]=taskai[1]; taskai[2]=taskai[2];} //break neleido

    else{
        for (int i=0; i<3; i++)
        {
            if (balsai[i]>max) {max=balsai[i]; nr=i;}

        }
        int lygiosios=0, nr1,  nr2;
        for (int i=0; i<3; i++)
        {
            for (int j=i+1; j<3; j++)
            {
            if ((balsai[i]==balsai[j])&&(balsai[i]==max&&(balsai[j]==max))) {lygiosios=1; nr1=i; nr2=j;}
            }
                }
            if (lygiosios>0)
                {
                    taskai[nr1]=taskai[nr1]+2;
                    taskai[nr2]=taskai[nr2]+2;
                }
        else
        taskai[nr]=taskai[nr]+4;}



}
int laimejo (int taskai [], int direktorius [])
{
    int lygiosios=0, nr, max=0;

    for (int i=0; i<3; i++)
    {
        if (taskai[i]>max) {max=taskai[i]; nr=i;}

    }
    for (int i=0; i<3; i++)
    {
        for (int j=i+1; j<3; j++)
        {
            if ((taskai[i]==taskai[j])&&(taskai[i]==max&&(taskai[j]==max))) lygiosios=1;
        }
    }
     max=0;
        if (lygiosios==0)
        {
            return nr;
        }
        else
            for (int i=0; i<3; i++)
            {
            taskai[i]=taskai[i]+direktorius[i];
            if (taskai[i]>max) max=i;
            }
            return max;

}
 int total[99];// jei maziau 8 prasidedavo nesamones

int main()
{
int n, balsai[99];
ifstream fd ("U1.txt");
ofstream fr ("U1rez.txt");
fd >> n;

for (int i=0; i<n; i++)
{
    for (int j=0; j<3;j++)
    {
        fd >> balsai[j];
        total[j]=total[j]+balsai[j];

}

    skaiciuoti (balsai, taskai);

}
for (int i=0; i<3;i++)
    {
         fr << total[i] << " ";

    }
    fr << endl;
    for (int i=0; i<3;i++)
    {
         fr << taskai[i] << " ";
    }
    fr << endl;


int direktorius[2], logotipas=0;
for (int i=0; i<3; i++)
{
    fd >> direktorius[i];
}
    logotipas=(laimejo(taskai, direktorius))+1;
    fr << logotipas;







return 0;}
