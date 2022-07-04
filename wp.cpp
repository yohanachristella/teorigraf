#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX_VERTEX 109
 int n=0,color;                                         
 int V[MAX_VERTEX][MAX_VERTEX];         
 int Derajat[MAX_VERTEX];                       
 int Warna[MAX_VERTEX];                       
 int V_Sort[MAX_VERTEX];
void MasukanGraph()
{
 int i=0,j=0,val=1;
 printf ("Masukan Jumlah Vertex : ");
 scanf ("%d",&n);
 printf ("Tekan 0 Jika Vertex Sudah Tidak ada yang terhubung!\n");
 for(i=0;i<n;i++){
  printf ("Masukan V->%d : \n",i+1); 
   j=0;
   while(1)
   {
    scanf("%d",&val);
    if(val==0)
    {
     V[i][0]=j;
     break;
   }
   V[i][++j] = val;
   }
 }
 printf("\n=====================DATA Graph======================\nTotal Vertex= %d\n",n);
    printf("Vertex Derjat \tVertex Yang Terhubung\n");
    for(i=0;i<n;++i)
    {
        printf("%d\t%d\t",(i+1),V[i][0]);
        for(j=1;j<=V[i][0];j++) printf("%d ",V[i][j]);
        printf("\n");
    } 
}
int cek(int x,int y)
{
 int j=0;
 for(j=1;j<=V[x][0];j++)
 {
  if(y == (V[x][j]-1))
  {
   return 1;
  }
 }
 return 0;
}
void Pewarnaan()
{
 int i=0,j=0,k=0,temp=0,a=0;
 int TempWarna[MAX_VERTEX];
 for(i=0;i<n;i++)
 {
  Derajat[i] = V[i][0];
  V_Sort[i]=i;
 }
 for (i=0;i<n-1;i++)
 {
  k = i;
  for(j=i+1;j<n;j++)
  {
   if(Derajat[j]>Derajat[k])
   {
    k=j;
   }
  }
  if(k!=i)
  {
   temp=Derajat[i];
   Derajat[i] = Derajat[k];
   Derajat[k] = temp;
   
   temp=V_Sort[i];
   V_Sort[i] = V_Sort[k];
   V_Sort[k] = temp;
  }
 }
 //algoritma welch-powell
 for(i=0;i<n;i++)
 {
  Warna[i]=0;
 }
 color=0;
 for(i=0;i<n;i++)
 {
  if(Warna[V_Sort[i]]==0)
  {
   color++;
   Warna[V_Sort[i]] = color;
   TempWarna[0]=1;
   TempWarna[1]=V_Sort[i];
   
   for(j=i+1;j<n;j++)
   {
    if((Warna[V_Sort[j]]==0)&&(!cek(V_Sort[i],V_Sort[j])))
    {
     for(k=2;k<=TempWarna[0];k++)
     {
      if(cek(TempWarna[k],V_Sort[j]))
      {
       goto next;
      }
     }
     Warna[V_Sort[j]]=color;
     TempWarna[0]+=1;
     TempWarna[TempWarna[0]]=V_Sort[j];
    }
    next:
     a=0;
   }
  }
 }
 
}
void Hasil()
{
 
 int i=0,j=0;
 printf ("\nSorting : \n");
 printf ("\nVertex\tDerajat\tVertex Yang Terhubung\n");
 for (i=0;i<n;i++)
 {
  printf ("%d\t%d\t",V_Sort[i]+1,V[V_Sort[i]][0]);
  for(j=1;j<=V[V_Sort[i]][0];j++)
  {
   printf ("%d ",V[V_Sort[i]][j]);
  }
  printf ("\n");
 }
 printf ("\nHasil : \n");
 printf ("\nVertex\tWarna\n");
 for(i=0;i<n;i++)
 {
  printf ("%d\t%d\n",i+1,Warna[i]);
 }
 printf ("\nBilangan Kromatik : %d",color);
}
int main()
{
 MasukanGraph();
 Pewarnaan();
 Hasil();
 return 0;
}
