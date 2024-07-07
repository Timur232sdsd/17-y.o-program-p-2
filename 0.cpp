#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){

int D=3, i, s=0, dMin[D], dMinN[D], n, a, b, d, r, r0, j, k;

ifstream Fin("27-3a.txt");

Fin>>n;

for(i=0;i<n;i++) {
  Fin >> a>> b;

  s +=min(a,b);

  d=abs(a-b);

  r=d%D;

  if (r>0) {for(j=0; j<D; j++)dMinN[j]=dMin[j];

    for(k=1;k<D;k++)
      {
      r0=(r+k)%D;
      dMinN[r0]= min(d+dMin[k],dMin[r0]);}

  dMinN[r0]= min(d, dMinN[r]);
  for (j=0;j<D;j++)dMin[j]=dMinN[j];}}
  
if (s%D==0) cout<<s;
  else cout<<s+dMin[D-s%D];

}