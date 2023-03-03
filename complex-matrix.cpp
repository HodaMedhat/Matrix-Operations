#include <iostream>
#include<iostream>
#include<string>
#include<cstdlib>
#include<math.h>
#include <sstream>
#define rr 100
#define cc 100
using namespace std;
class Complex
{
    float real;
    float imag;
    float mag;
    float phase;
public:
    void set_complex(float r,float i)
    {
        real=r;
        imag=i;
        mag=sqrt(pow(real,2)+pow(imag,2));
        phase=atan2(imag,real);
    }

    float get_real()
    {
        return real;
    }

    float get_imag()
    {
        return imag;
    }

    float get_mag()
    {
        return mag;
    }

    float get_phase()
    {
        return phase;
    }

    Complex add(Complex c1)
    {
        Complex c;
        float r=real+c1.get_real();
        float i=imag+c1.get_imag();
        c.set_complex(r,i);
        return c;
    }

    Complex minusc(Complex c1)
    {
        Complex c;
        float r=real-c1.get_real();
        float i=imag-c1.get_imag();
        c.set_complex(r,i);
        return c;
    }

    Complex multi(Complex c1)
    {
        Complex c;
        float m2=mag*c1.get_mag();
        float ph2=phase+c1.get_phase();
        float r=m2*cos(ph2);
        float i=m2*sin(ph2);
        c.set_complex(r,i);
        return c;
    }

    void set_complex(string s)
    {
        for(int j=0; unsigned(j)<s.length()-1; j++)
        {
            int m=s.find('-');
            int p=s.find('+');
            int f=s.find('i');
            int w=1;
            string temp;
            if(m==0)
                m=s.find('-',m+1);
            if(p<0)
            {
                temp=s.substr(0,m);
                real=atof(temp.c_str());
                temp=s.substr(m,f-m+1);
                imag=atof(temp.c_str());
                mag=sqrt(pow(real,2)+pow(imag,2));
                phase=atan2(imag,real);
            }
            if(m<p&&p>0&&m>0)
            {
                temp=s.substr(0,m);
                real=atof(temp.c_str());
                temp=s.substr(m,f-m+1);
                imag=atof(temp.c_str());
                mag=sqrt(pow(real,2)+pow(imag,2));
                phase=atan2(imag,real);
                w=0;
            }
            if(w==0)
                break;
            if(m<0)
            {
                temp=s.substr(0,p);
                real=atof(temp.c_str());
                temp=s.substr(p,f-p+1);
                imag=atof(temp.c_str());
                mag=sqrt(pow(real,2)+pow(imag,2));
                phase=atan2(imag,real);
            }
            if(p<m&&m>0&&p>0)
            {
                temp=s.substr(0,p);
                real=atof(temp.c_str());
                temp=s.substr(p,f-p+1);
                imag=atof(temp.c_str());
                mag=sqrt(pow(real,2)+pow(imag,2));
                phase=atan2(imag,real);
                w=2;
            }
            if(w==2)
                break;
        }
    }

    void print_complex()
    {
        cout<<real;
        if(imag!=0)
        {
            if(imag<0)
            {
                cout<<imag<<"i";
            }
            else if(imag>0)
            {
                cout<<"+"<<imag<<"i";
            }
        }
    }
};
int main()
{
    int i=0,j=0,k=0,h=0,f=0,r1=0,r2=0,c1=0,c2=0,p1=0,p2=0,pos=0,x=0,p=0,ot=0;
    string str1,str2,e1;
    //str1="[10+13i 7+2i 12+19i;6+15i 12+17i 1+19i;12+9i 15+5i 4+1i;9+15i 5+18i 15+12i]";
    //str2="[18+14i 4+17i;16+10i 9+10i;1+12i 9+6i]";
    char op;
    string temp1;
    float dt=0,tem=0,dtemp=0;
    Complex temp2;
    float temp[rr][cc]= {{0}};
    getline(cin,str1);
    cin>>op ;
    cin.ignore(256,'\n');
    if(op=='^')
    {
        cin>>x;
        cin.ignore();
    }
    if(op=='+'||op=='-'||op=='*'||op=='/')
    {
        getline(cin,str2);
    }
    string arss[rr][cc];
    Complex ar1[rr][cc];
    Complex ar2[rr][cc];
    Complex arsf[rr][cc];
    Complex artf[rr][cc];
    Complex c;
    //for string 1
    pos =str1.find(' ');
    e1=str1.substr(1,pos -1);
    temp2.set_complex(e1);
    ar1[0][0]=temp2;
    for(i=pos; unsigned(i)<str1.length()-1; i++)
    {
        if(str1[i]==';')
        {
            j++;
            r1=j;
            k=0;
        }
        if(str1[i]==' ')
        {
            k++;
            if(j==0)
                ot=k;
            c1=k;
        }
        if(str1[i]!=' '&&str1[i]!=';'&&(str1[i-1]==' '||str1[i-1]==';'))
        {
            p1=str1.find(' ',p1+1);
            p2=str1.find(';',p2+1);
            if(p2<p1)
            {
                temp1=str1.substr(i,p2-i);
            }
            else
            {
                temp1=str1.substr(i,p1-i);
            }
            temp2.set_complex(temp1);
            ar1[j][k]=temp2;
        }
    }
    pos=0,p1=0,p2=0;
    //for string 2
    if(op=='+'||op=='-'||op=='*'||op=='/')
    {
        pos =str2.find(' ');
        e1=str2.substr(1,pos -1);
        temp2.set_complex(e1);
        ar2[0][0]=temp2;
        for(i=pos; unsigned(i)<str2.length()-1; i++)
        {
            if(str2[i]==';')
            {
                h++;
                r2=h;
                f=0;
            }
            if(str2[i]==' ')
            {
                f++;
                c2=f;
            }
            if(str2[i]!=' '&&str2[i]!=';'&&(str2[i-1]==' '||str2[i-1]==';'))
            {
                p1=str2.find(' ',p1+1);
                p2=str2.find(';',p2+1);
                if(p2<p1)
                {
                    temp1=str2.substr(i,p2-i);
                }
                else
                {
                    temp1=str2.substr(i,p1-i);
                }
                temp2.set_complex(temp1);
                ar2[h][f] =temp2;
            }
        }
    }

    //for +
    if(op=='+')
    {
        if(r1!=r2||c1!=c2)
        {
            cout<<"ERROR";
        }
        else
        {
            cout<<"[";
            for(i=0; i<=r1; i++)
            {
                for(j=0; j<=c1; j++)
                {
                    arsf[i][j]=ar1[i][j].add(ar2[i][j]);
                    arsf[i][j].print_complex();
                    if(j==c1)
                        break;
                    cout<<" ";
                }
                if(i<r1)
                {
                    cout<<";";
                }
            }
            cout<<"]";
        }
    }

    //for -
    if(op=='-')
    {
        if(r1!=r2||c1!=c2)
        {
            cout<<"ERROR";
        }
        else
        {
            cout<<"[";
            for(i=0; i<=r1; i++)
            {
                for(j=0; j<=c1; j++)
                {
                    arsf[i][j]= ar1[i][j].minusc(ar2[i][j]);
                    arsf[i][j].print_complex();
                    if(j==c1)
                        break;
                    cout<<" ";
                }
                if(i<r1)
                {
                    cout<<";";
                }
            }
            cout<<"]";
        }
    }
    //for *
    if(op=='*')
    {
        if(r2!=c1)
        {
            cout<<"ERROR";
        }
        else
        {
            for(i=0; i<=r1; i++)
            {
                for(j=0; j<=c1; j++)
                {
                    for(k=0; k<=c2; k++)
                    {
                        c=ar1[i][j].multi(ar2[j][k]);
                        arsf[i][k]=arsf[i][k].add(c);
                    }
                }
            }
            cout<<"[";
            for(i=0; i<=r1; i++)
            {
                for(j=0; j<=c2; j++)
                {
                    arsf[i][j].print_complex();
                    if(j==c2)
                        break;
                    cout<<" ";
                }
                if(i<r1)
                {
                    cout<<";";
                }
            }
            cout<<"]";
        }
    }
    return 0;
}
