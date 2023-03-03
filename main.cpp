#include<iostream>
#include<string>
#include<cstdlib>
#include<math.h>
#include <sstream>
#define rr 100
#define cc 100
using namespace std;
float det(float ar[][cc],int n);
int main(){
int i=0,j=0,k=0,h=0,f=0,r1=0,r2=0,c1=0,c2=0,p1=0,p2=0,pos=0,x=0,p=0,ot=0;
string str1,str2,e1;
char op;
string temp1;
float temp2,dt=0,tem=0,dtemp=0;
float temp[rr][cc]={{0}};
getline(cin,str1);
cin>>op ;
cin.ignore(256,'\n');
if(op=='^'){cin>>x;cin.ignore();}
if(op=='+'||op=='-'||op=='*'||op=='/'){
getline(cin,str2);}
string arss[rr][cc];
float ar1[rr][cc]={{0}};
float ar2[rr][cc]={{0}};
float arsf[rr][cc]={{0}};
float artf[rr][cc]= {{0}};
//for string 1
pos =str1.find(' ');
 e1=str1.substr(1,pos -1);
ar1[0][0]=atof(e1.c_str());
for(i=pos;unsigned(i)<str1.length()-1;i++){
    if(str1[i]==';') {j++;r1=j;k=0;}
    if(str1[i]==' ') {k++;if(j==0)ot=k;c1=k; }
    if(str1[i]!=' '&&str1[i]!=';'&&(str1[i-1]==' '||str1[i-1]==';')){
       p1=str1.find(' ',p1+1);
       p2=str1.find(';',p2+1);
      if(p2<p1){
       temp1=str1.substr(i,p2-i);}
       else{temp1=str1.substr(i,p1-i);}
       temp2=atof(temp1.c_str());
       ar1[j][k] =temp2;}}
 pos=0,p1=0,p2=0;
 //for string 2
if(op=='+'||op=='-'||op=='*'||op=='/'){
pos =str2.find(' ');
 e1=str2.substr(1,pos -1);
ar2[0][0]=atof(e1.c_str());
for(i=pos;unsigned(i)<str2.length()-1;i++){
    if(str2[i]==';') {h++;r2=h;f=0;}
    if(str2[i]==' ') {f++;c2=f; }
    if(str2[i]!=' '&&str2[i]!=';'&&(str2[i-1]==' '||str2[i-1]==';')){
       p1=str2.find(' ',p1+1);
       p2=str2.find(';',p2+1);
      if(p2<p1){
       temp1=str2.substr(i,p2-i);}
       else{temp1=str2.substr(i,p1-i);}
       temp2=atof(temp1.c_str());
       ar2[h][f] =temp2;}}}

//for +
if(op=='+'){ if(r1!=r2||c1!=c2){cout<<"ERROR";}
else{ cout<<"[";
for(i=0;i<=r1;i++){
   for(j=0;j<=c1;j++){
        arsf[i][j]= ar1[i][j]+ ar2[i][j];
        cout<<arsf[i][j];
        if(j==c1)break;
        cout<<" ";}
       if(i<r1){cout<<";";}}
        cout<<"]";}}

//for -
if(op=='-'){
        if(r1!=r2||c1!=c2){cout<<"ERROR";}
else {cout<<"[";
for(i=0;i<=r1;i++){
   for(j=0;j<=c1;j++){
        arsf[i][j]= ar1[i][j]- ar2[i][j];
        cout<<arsf[i][j];
        if(j==c1)break;
        cout<<" ";}
       if(i<r1){cout<<";";}}
        cout<<"]";}}
//for *
  if(op=='*'){
    if(r2!=c1){cout<<"ERROR";}
    else{
    for(i=0;i<=r1;i++){
      for(j=0;j<=c1;j++){
        for(k=0;k<=c2;k++){
           arsf[i][k]+=ar1[i][j]*ar2[j][k];}}}
     cout<<"[";
     for(i=0;i<=r1;i++){
        for(j=0;j<=c2;j++){
            cout<<arsf[i][j];
            if(j==c2)break;
            cout<<" ";
               }if(i<r1){cout<<";";}
        }cout<<"]";}}
//for ^
if(op=='^'){
if(r1!=c1){cout<<"ERROR";}
else if(x<=0){cout<<"ERROR";}
else{
 for(i=0;i<=r1;i++){
  for(j=0;j<=c1;j++){
    artf[i][j]=ar1[i][j];}}

  for(f=2;f<=x;f++){
      for(h=0;h<=r1;h++){
          for(p=0;p<=c1;p++){
              arsf[h][p]=0;}}
              h=0;p=0;
    for(i=0;i<=r1;i++){
     for(j=0;j<=c1;j++){
        for(k=0;k<=c1;k++){
            arsf[i][k]+=artf[i][j]*ar1[j][k];}}}
            for(h=0;h<=r1;h++){
                for(p=0;p<=c1;p++){
                    artf[h][p]=arsf[h][p];}}}

          cout<<"[";
       for(i=0;i<=r1;i++){
         for(j=0;j<=c1;j++){
            cout<<arsf[i][j];
            if(j==c1)break;
            cout<<" ";
               }if(i<r1){cout<<";";}
        }cout<<"]";}}
   //for مقلوب
 if(op=='T'){if(ot!=c1){cout<<"ERROR";}
else{
    cout<<"[";
     for(j=0;j<=c1;j++){
            for(i=0;i<=r1;i++){
            arsf[j][i]=ar1[i][j];
        cout<<arsf[j][i];
        if(i==r1)break;
            cout<<" ";
               }if(j<c1){cout<<";";}
        }cout<<"]";}}
//for المحدد
if(op=='D'){
if(r1!=c1){cout<<"ERROR";}
else{ float res=1;
res=det(ar1,c1);
  cout<<res;}}
//for المعكوس
if(op=='I'){
if(r1!=c1){cout<<"ERROR";}
else{int s=1;;i=0;dt=det(ar1,c1);int z=0;
   while(i<=c1){j=0;
    while(j<=c1){h=0;p=0;
      while(p<c1&&h<=c1){f=0;k=0;int w=1;
         if(i==0&&p==0)h=1;
        while(k<c1&&f<=c1){int w1=1;
            if(j==0&&k==0)f=1;
               tem=ar1[h][f];
               temp[p][k]=tem;

            if(f!=j){f++;w1=0;}
            if(f==j){f+=2;if(w1==0)f--;}
            k++;}
          p++;
          if(h!=i){h++;w=0;}
          if(h==i){h+=2;if(w==0)h--;}}
               dtemp=det(temp,c1-1);
               s=pow(-1,j+z);
               arsf[i][j]=s*(dtemp/dt);
                j++;}i++;z++;}

    cout<<"[";
       for(j=0;j<=r1;j++){
         for(i=0;i<=c1;i++){
           artf[j][i]=arsf[i][j];
            cout<<artf[j][i];
            if(i==c1)break;
            cout<<" ";
               }if(j<r1){cout<<";";}
        }cout<<"]";}}



//for لقسمة
if(op=='/'){
 if(r2!=c1){cout<<"ERROR";}
     else if(r2!=c2){cout<<"ERROR";}
    else{int s=1;;i=0;dt=det(ar2,c2);int z=0;
   while(i<=c2){j=0;
    while(j<=c2){h=0;p=0;
      while(p<c2&&h<=c2){f=0;k=0;int w=1;
         if(i==0&&p==0)h=1;
        while(k<c2&&f<=c2){int w1=1;
            if(j==0&&k==0)f=1;
               tem=ar2[h][f];
               temp[p][k]=tem;

            if(f!=j){f++;w1=0;}
            if(f==j){f+=2;if(w1==0)f--;}
            k++;}
          p++;
          if(h!=i){h++;w=0;}
          if(h==i){h+=2;if(w==0)h--;}}
               dtemp=det(temp,c2-1);
               s=pow(-1,j+z);
               arsf[i][j]=s*(dtemp/dt);
                j++;}i++;z++;}

for(j=0;j<=r2;j++){
         for(i=0;i<=c2;i++){
           temp[j][i]=arsf[i][j];}}

   for(i=0;i<=r1;i++){
      for(j=0;j<=c1;j++){
        for(k=0;k<=c2;k++){
           artf[i][k]+=ar1[i][j]*temp[j][k];}}}
     cout<<"[";
     for(i=0;i<=r1;i++){
        for(j=0;j<=c2;j++){
            cout<<artf[i][j];
            if(j==c2)break;
            cout<<" ";
               }if(i<r1){cout<<";";}
        }cout<<"]";}}



return 0 ;}

float det(float ar[][cc],int n){
float temp[rr][cc];
int i=0,j=0,k=0,h=0,f=0,o=1;
float dete=0;float tem=0;float dt=0;
  if(n==0){dete=ar[0][0]; }
  else if(n==1){
   dete=ar[0][0]*ar[1][1]-ar[0][1]*ar[1][0];    }
  else{i=0;
   while(i<=n){h=1;j=0;
     while(j<n&&h<=n){f=0;k=0;
       while(k<n&&f<=n){int w=1;
            if(i==0&&k==0)f=1;
               tem=ar[h][f];
               temp[j][k]=tem;
            k++;
            if(f!=i){f++;w=0;}
            if(f==i){f+=2;if(w==0)f--;}}
                            h++;j++;}
    dt=det(temp,j-1);
    dete+=o*ar[0][i]*dt;
    o*=-1;i++;} }
    return dete;}
