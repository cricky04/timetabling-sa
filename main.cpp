#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#include<vector>
using namespace std;
FILE*fin=fopen("input.txt", "r");
FILE*fout=fopen("output.txt", "w");
struct classinfo
{
    int stn;
    int ccode,student[100];
    int lx,ly,lz;
    int cmax;
};
struct group
{
    struct classinfo gclass[100];
    int schk[100];
    int gcn;
    int gmax;
};
int gn;
int subn;
vector<int> mintemp;
classinfo sub[100];
group a[100];
int main()
{
    int i,n,j,t,k;
    fscanf(fin,"%d",&subn);
    for(i=0;i<=99;i++)
    {
        a[i].gcn=0;
        a[i].gmax=0;
    }
    for(i=1;i<=subn;i++)
    {
        fscanf(fin,"%d",&t);//classcode
        fscanf(fin,"%d",&n);//studentnumber
        fscanf(fin,"%d %d %d",&sub[i].lx,&sub[i].ly,&sub[i].lz);
        fscanf(fin,"%d",&sub[i].cmax);
        sub[i].ccode=t;
        sub[i].stn=n;
        for(j=1;j<=n;j++)
        {
            fscanf(fin,"%d",&sub[i].student[j]);
        }
    }
    for(i=1;i<=subn;i++)
    {
        if(sub[i].stn<=20)
        {
            mintemp.push_back(i);
        }
        else
        {
            a[(i-mintemp.size())/4*4+4].gclass[++(a[(i-mintemp.size())/4*4+4].gcn)]=sub[i];
            a[(i-mintemp.size())/4*4+4].gcn++;
            if(a[(i-mintemp.size())/4*4+4].gmax<sub[i].cmax)
            {
                a[(i-mintemp.size())/4*4+4].gmax=sub[i].cmax;
            }
            a[(i-mintemp.size())/4*4+1].gclass[++(a[(i-mintemp.size())/4*4+1].gcn)]=sub[i];
            a[(i-mintemp.size())/4*4+1].gcn++;
            if(a[(i-mintemp.size())/4*4+1].gmax<sub[i].cmax)
            {
                a[(i-mintemp.size())/4*4+1].gmax=sub[i].cmax;
            }
            a[(i-mintemp.size())/4*4+2].gclass[++(a[(i-mintemp.size())/4*4+2].gcn)]=sub[i];
            a[(i-mintemp.size())/4*4+2].gcn++;
            if(a[(i-mintemp.size())/4*4+2].gmax<sub[i].cmax)
            {
                a[(i-mintemp.size())/4*4+2].gmax=sub[i].cmax;
            }
            a[(i-mintemp.size())/4*4+3].gclass[++(a[(i-mintemp.size())/4*4+3].gcn)]=sub[i];
            a[(i-mintemp.size())/4*4+3].gcn++;
            if(a[(i-mintemp.size())/4*4+3].gmax<sub[i].cmax)
            {
                a[(i-mintemp.size())/4*4+3].gmax=sub[(i-mintemp.size())].cmax;
            }
        }
    }
    i=mintemp.size();
    while(i>0)
    {
        i--;
        for(j=1;j<=90;j++)
        {
            if(a[j].gcn==0)
            {
                t=mintemp.back();
                if(mintemp.size()==0) break;
                mintemp.pop_back();
                a[j].gcn++;
                a[j].gclass[a[j].gcn]=sub[t];
                break;
            }
        }
    }
    i=1;
    while(a[i].gcn!=0)
    {
        t=a[i].gcn;
        for(j=1;j<=t;j++)
        {
            if(a[i].gclass[j].ccode==0) a[i].gcn--;
        }
        i++;
    }
    i=1;
    while(a[i].gcn!=0)
    {
        fprintf(fout,"%d %d\n",i, a[i].gcn);
        j=1;
        while(a[i].gcn>0)
        {
            if(a[i].gclass[j].ccode==0) j++;
            else
            {
                fprintf(fout,"%d %d %d %d %d\n",a[i].gclass[j].lz,a[i].gclass[j].lx,a[i].gclass[j].ly,a[i].gclass[j].cmax,a[i].gclass[j].ccode);
                for(k=1;k<=a[i].gclass[j].stn;k++)
                {
                    fprintf(fout,"%d ",k);
                }
                fprintf(fout,"\n");
                a[i].gcn--;
                j++;
            }
        }
        i++;
    }
}
