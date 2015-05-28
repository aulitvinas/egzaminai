#include <iostream>
#include <fstream>

using namespace std;
int klientai, km, x[50], y[50], nuvaziuota, nuvaziuotat=0;
void duomenys (int x[50], int y[50])
{
    ifstream fd("U1.txt");
    fd >> klientai;
    fd >> km;
    for (int i=0; i<klientai; i++)
    {
        fd >> x[i];
        fd >> y[i];
}
}
int atstumas (int x, int y)
{
    if (x<0) x=x*(-1);
    if (y<0) y=y*(-1);
    nuvaziuota=2*(x+y);
    return nuvaziuota;

}
void rezultatai (int i, int nuvaziuotat)
{
    ofstream fr("U1Rez.txt");
    fr << klientai-i << " ";
    fr << nuvaziuotat;
    fr. close();

}


int main()
{
    duomenys(x, y);
    int i=0;
    if (klientai>=i)
    {

       while (nuvaziuotat<=km)
    {
            nuvaziuota=atstumas(x[i], y[i]);
            nuvaziuotat=nuvaziuotat+nuvaziuota;
            i++;
    }}
    rezultatai (i, nuvaziuotat);

    return 0;
}
