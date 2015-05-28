#include <fstream>
#include <iostream>
using namespace std;
ifstream fr("U1.txt");
ofstream fd("U1rez.txt");
int n, pirm[99], antr[99], trec[99];
int blogvien=0, blogdu=0, blogtrys=0, bosas;
void blogiausia(int i)
{
    int min=99;
    bool lygu=false;
    if ((pirm[i]==antr[i])&&(antr[i]==trec[i]))
    {
        if (bosas==1) blogvien++;
        if (bosas==2) blogdu++;
        if (bosas==3) blogtrys++;
        lygu=true;
    }
    if ((pirm[i]==antr[i])&&(trec[i]>pirm[i]))
        {
            if (bosas==1) blogvien++;
                if (bosas==2) blogdu++;
                if (bosas==3) blogtrys++;
                lygu=true;
        }
    if ((pirm[i]==antr[i])&&(trec[i]<pirm[i]))
        {
            blogtrys++;
            lygu=true;
        }
    if ((antr[i]==trec[i])&&(pirm[i]>antr[i]))
        {
            if (bosas==1) blogvien++;
            if (bosas==2) blogdu++;
            if (bosas==3) blogtrys++;
                lygu=true;
        }
    if ((antr[i]==trec[i])&&(antr[i]>pirm[i]))
        {
            blogvien++;
            lygu=true;
        }
    if ((pirm[i]==trec[i])&&(antr[i]>pirm[i]))
        {
            if (bosas==1) blogvien++;
            if (bosas==2) blogdu++;
                if (bosas==3) blogtrys++;
                lygu=true;
        }
    if ((pirm[i]==trec[i])&&(antr[i]<pirm[i]))
        {
            blogdu++;
            lygu=true;
        }




    if (lygu==false)
   {
        if (pirm[i]<min) min=pirm[i];
        if (antr[i]<min) min=antr[i];
        if (trec[i]<min) min=trec[i];


    if (min==pirm[i]) blogvien++;
    if (min==antr[i]) blogdu++;
    if (min==trec[i]) blogtrys++;
    }


}
int zaidimas()

{
    int max=0, blogiausias;

    if (blogvien>max) max=blogvien;
    if (blogdu>max) max=blogdu;
    if (blogtrys>max) max=blogtrys;
    if (max==blogvien) blogiausias=1;
    if (max==blogdu) blogiausias=2;
    if (max==blogtrys) blogiausias=3;

              return blogiausias;
}


int main()
{
    int blogzaid;
    fr >> n;
    for (int i=0; i<n; i++)
    {
        fr >> pirm[i];
        fr >> antr[i];
        fr >> trec[i];

    }
    fr >> bosas;
    for (int i=0; i<n; i++)
    {
        blogiausia(i);
    }
    blogzaid=zaidimas();
    cout << blogvien << " ";
    cout << blogdu << " ";
    cout << blogtrys << endl;
    cout << bosas;


}
