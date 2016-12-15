#include"header.h"

void lucky()
{
    FILE *fp;
    long unsigned int  sum=0,i=0,t=0;
    long unsigned int  num,max;
    int l=0,c=0,count=0,counters=0;
    char alpha2 = '\0',chrs = '\0',filename2[100];
    printf("ENTER FILE NAME TO TAKE INPUT : ");                 //ASKING FOR FILENAME
    scanf("%s",filename2);
    fp=fopen(filename2,"r");                                    //OPEN A FILE IN READ MODE
    if(!fp)
    {
        printf("\nFILE NOT FOUND!!");
        return;
    }

    while(alpha2 = fgetc(fp))                                   //LOOP TO CHECK CHARACTERS AND SPECIAL CHARACTERS
    {
        if(alpha2 == -1)
            break;
        if(!(alpha2<='9' && alpha2>='0'))
        {
            if(alpha2 == '\n' || alpha2 == '\t' || alpha2 == ' ' || alpha2 == '-' || alpha2 == (char)3 || alpha2 == (char)13)
                continue;
            else
            {
                printf("\nCHARACTERS OR SPRCIAL SYNBOLS FOUND PLEASE MODIFY YOUR INPUT\n");
                return ;
            }
        }
    }
    rewind(fp);                                             //PUT THE CURSOR AT THE BEIGINING OF THE FILE


    if((chrs=fgetc(fp)) == EOF)                             //TO CHECK WHEATHER THE FILE IS EMPTY OR NOT
    {
        printf("\nTHERE IS NO INPUT IN A FILE...PLEASE ENTER THE INPUT");
    }

    while((chrs=fgetc(fp))!=EOF)                            //LOOP TO COUNT NUMBER OF INPUTS
    {
        if(chrs == '\n')
            counters=counters + 1;
    }
    rewind(fp);                                              //PUT THE CURSOR AT THE BEIGINING OF THE FILE

    fscanf(fp,"%lu",&t);

    if(t>counters)
    {
        printf("OUT OF RANGE...PLEASE ENTER THE VALID NUMBER OF TEST CASES");
            for(i=1;i<=counters;i++)
            {
                c++;
                if(c<=t)
                {
                    max=0;
                    fscanf(fp,"%lu",&num);                  //NUMBER TO CHECK
                    sum=add(num);                           //FUNCTION CALL TO CALCUNATE THE SUM OF DIGITS OF A NUMBER
                    max=diff(num);                          //FUNCTION TO CALCULATE THE MAXIMUM DIFFERENCE BETWEEN THE DIGITS
                    display2(max,sum);                      //FUNCTION CALL TO DISPLAY THE OUTPUT
                }
                else
                {
                    return ;
                }
            }
    }
    else
    {
        if(counters!=t)                                     //CONDITION TO CHECK NUMBER OF TEST CASES
        printf("\nNUMBER OF INPUT ARE LESS ");
        {
            for(i=1;i<=t;i++)
            {
                c++;
                if(c<=t)
                {
                    max=0;
                    fscanf(fp,"%lu",&num);                  //NUMBER TO CHECK
                    sum=add(num);                           //FUNCTION CALL TO CALCUNATE THE SUM OF DIGITS OF A NUMBER
                    max=diff(num);                          //FUNCTION TO CALCULATE THE MAXIMUM DIFFERENCE BETWEEN THE DIGITS
                    display2(max,sum);                      //FUNCTION CALL TO DISPLAY THE OUTPUT
                }
    	        else
      	        {
         	   return ;                                 //FUNCTION TO DISPLAY THE OUTPUT
  	        }
           }
        }
        fclose(fp);                                        //CLOSE FILE
    }
}
long unsigned int add(long unsigned int num)               //FUNCTION TO CALCULATE THE SUM
{
    int r;
    long unsigned int sum=0;
    while(num!=0)
        {
            r=num%10;
            sum=sum+r;
            num=num/10;
        }
        return(sum);                                   //RETURN THE VALUE OF SUM WITH CALLING FUNCTION
}

long unsigned int diff(long unsigned int n)           //FUNCTION TO CALCULATE THE MAXIMUM DIFFRENCE
{
    int r,flag=0,d=0,s=0;
    long unsigned int maxdiff=0,l=0;
    while(n!=0)
        {
            r=n%10;
            if(flag==0)
            {
                s=r;
                d=s-r;
                maxdiff=d;
                flag++;
            }
            else
            {
                d=s-r;
                s=r;
                if(d<0)
                {
                    l=-999;
                }
                else if(d>=maxdiff)
                maxdiff=d;
             }
            n=n/10;
        }
        if(l==-999)
        return (l);                                           //DIFFERENCE BETWEEN THE DIGIT IS NEGATIVE
        else
        return(maxdiff);                                      //RETURN THE VALUE OF MAXDIFF TO CALLINF FUNCTION
}
void display2(long unsigned int max,long unsigned int sum)    //FUNCTION TO DISPLAY THE OUTPUT
{
        if(max==-999)
        {
            printf("\nNA");                                   //NUMBER IS NOT LUCKY
        }
        else
        {
            printf("\n%lu,%lu",max,sum);                     //NUMBER IS LUCKY
        }
}
