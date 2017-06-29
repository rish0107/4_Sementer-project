#include <iostream>                             //HEADER FILE
#include<fstream>                               //HEADER FILE
#include<string.h>                              //HEADER FILE

using namespace std;

void minsp(int [1002][1002],int);               //FUNCTION DECLARATION
void user(int [1002][1002],ifstream &);         //FUNCTION DECLARATION
int check(char []);                             //FUNCTION DECLARATION


//function to create a minimum spanning tree
void minsp(int a[1002][1002],int e)
{
    int mi,q,p,visted[1000]={0},k=0,s[30];
    while(--e)                                          //loop to check the circuit
    {
        mi=9999;
        if(e==1){
            for(int i=0;i<=1000;i++)
            {
                if(visted[i]==1)
                {
                    s[k++]=i;
                }
            }
            for(int i=0;i<k;i++)
            {
                int cnt=s[i];
                for(int j=0;j<1001;j++)
                {
                    if(a[cnt][j]==-1)
                    {
                        if(visted[j]==-98||visted[j]==1)
                        {
                            visted[cnt]=-98;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=1000;i++)                                    //loop to connect minimum weighted edges
        {
            for(int j=1;j<=1000;j++)
              {
                    if((a[i][j]!=0 &&a[i][j]<mi &&i!=j &&a[i][j]!=-1)&&(visted[i]==0||visted[i]==-98))
                    {
                         mi=a[i][j];
                         p=i;
                         q=j;
                    }
               }

        }
        a[p][q]=-1;
        a[q][p]=-1;
        visted[p]++;
        visted[q]++;
    }

}

void user(int a[1002][1002],ifstream &myfile)
{
    int n,s,d,f=0;
    myfile>>n;
    for(int i=0;i<n;i++)                        //LOOP TO CKECH THE QUARIES
    {
        myfile>>s>>d;
        if(a[s][d]==-1 ||a[d][s]==-1)
        {
            f++;
        }
    }
    for(int i=f;i>0;i--)                       //FINDING GCD
    {
        if(f%i==0 && n%i==0)
        {
            f=f/i;
            n=n/i;
            break;
        }
    }
    cout<<f<<"/"<<n<<endl;
    return;
}


int check(char s[50])
{
    ifstream infile;
    infile.open(s);
    char alpha1;
    if(infile)
    {
        infile>>alpha1;
         //CHECK FILE IS EMPTY OR NOT
         if(infile=='\0')
        {
              cout<<"\tFILE IS EMPTY PLEASE PROVIDE INPUT"<<endl;
              return 1;
        }
        else
        while(infile>>alpha1)                                 //LOOP TO CHECK CHARACTERS AND SPECIAL CHARACTERS
        {
            if(alpha1 == -1)
               break;
             if((alpha1<='9' && alpha1>='0'))
             {
                  if(alpha1 == '\n' || alpha1 == '\t' || alpha1 == ' ' || alpha1 == '-' || alpha1 == (char)3 || alpha1 == (char)13)
                     continue;
             }
             else
             {
                cout <<"\nCHARACTERS OR SPECIAL SYMBOLS FOUND...PLEASE MODIFY YOUR INPUT\n"<<endl;
                return 1 ;
             }
        }
    }
    else
    {
        cout<<"\tFILE NOT FOUND"<<endl;
        return 1;
    }

    infile.close();
    return 0;
}

int a[1002][1002]={0};
//char s[50];
int main()
{
    char s[50];
    cout<<"PLEASE ENTER THE FILE NAME..!!!"<<endl;
    gets(s);                                        //ASKING FILE NAME
    int i,src,dest,n,wt,vertex,test;
    if(check(s))                                    //CALLING A FUNCTION A CHECK
    {
        return 0;
    }
    else
    {
        ifstream myfile;
        myfile.open(s);
        myfile>>test;
        for(int j=0;j<test;j++)                       //LOOP TO INITIALIZE MATRIX TO ZERO
        {
             for(int o=0;o<1000;o++)
                  {
                      for(int y=0;y<1000;y++)
                      {
                          a[o][y]=0;
                      }
                  }

              myfile>>vertex;
              myfile>>n;
              for(i=0;i<n;i++)                          //LOOP TO READ THE NODES AND COAST
              {
                    myfile>>src>>dest>>wt;
                    a[src][dest]=wt;
                    a[dest][src]=wt;
              }
        minsp(a,vertex);                                //FUNCTION TO MAKE A MINIMAL SPANNING TREE
        user(a,myfile);                                 //FUNCTION TO CHECK QURIES
        }
    }
    return 0;
}

