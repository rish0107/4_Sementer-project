#include"header.h"

void prof()
{
    char alpha1 = '\0',chr1 = '\0',filename1[100];
    int n,p,i,tm,l,c,counter=0,count1=0,j=0;
    long int t=0;
    FILE *f;
    printf("ENTER FILE NAME TO TAKE INPUT : ");              // ASKING FOR FILE NAME
    scanf("%s",&filename1);
    f = fopen(filename1, "r");                              //OPEN FILE IN READ MODE
    if(!f)
    {
        printf("\nFILE NOT FOUND!!");
        return;
    }

    while(alpha1 = fgetc(f))                                 //LOOP TO CHECK CHARACTERS AND SPECIAL CHARACTERS
    {

        if(alpha1 == -1)
            break;
        if(!(alpha1<='9' && alpha1>='0'))
        {
            if(alpha1 == '\n' || alpha1 == '\t' || alpha1 == ' ' || alpha1 == '-' || alpha1 == (char)3 || alpha1 == (char)13)
                continue;
            else
            {
                printf("\nCHARACTERS OR SPECIAL SYMBOLS FOUND...PLEASE MODIFY YOUR INPUT\n");
                return ;
            }
        }
    }
    rewind(f);                                                //PUT THE CURSOR AT THE BEGINNING OF THE FILE

    if((chr1=fgetc(f)) == EOF)                                //TO CHECK WHEATHER THE FILE IS EMPTY OR NOT
    {
        printf("\nTHERE IS NO INPUT IN A FILE...PLEASE ENTER THE INPUT");
    }

    while((chr1=fgetc(f))!=EOF)                               //LOOP TO CALCULTE NUMBER OF INPUTS
    {
        if(chr1 == '\n')
            counter=counter + 1;
    }
    rewind(f);                                                //PUT THE CURSOR AT THE BEGINNING OF THE FILE
    fscanf(f,"%ld",&t);
                                                              //NUMBER OF TEST CASES PRESENT IN THE FILE
    if(t>(counter/2))
    {
        printf("OUT OF RANGE... PLEASE ENTER THE VALID NUMBER OF TEST CASES");
       for(i=1;i<=(counter/2);i++)
        {
            c=0;
            fscanf(f, "%d%d",&n,&p);
            c = check(n, &f);                                //FUNCTION TO COUNT HOW MANY STUDENTS ARE ON TIME
            display1(c,p,n);                                 //FUNCTION TO DISPLAY THE OUTPUT
        }
    }
    else
    {
        if((counter/2)!=t)
            printf("\nNUMBER OF INPUTS ARE LESS");
        for(i=1;i<=t;i++)
        {
            c=0;
            fscanf(f, "%d%d",&n,&p);
            c = check(n, &f);                                //FUNCTION TO COUNT HOW MANY STUDENTS ARE ON TIME
            display1(c,p,n);                                 //FUNCTION TO DISPLAY THE OUTPUT
        }
    }
    fclose(f);                                               //FUNCTION TO CL0SE THE FILE
}

int check(int n, FILE **f)                                   //FUNCTION TO COUNT HOW MANY STUDENTS ARE PRESENT
{
    int c=0,tm,j;
     for(j=1;j<=n;j++)
        {
           fscanf(*f, "%d",&tm);                            //TIME AT WHICH STUDENT REACHES THE CLASS
           if(tm<=0)
            c++;
        }
    return (c);                                              //RETURNING THE VALUE OF HOW MANY STUDENTS ARE PRESENT
}

void display1(int c,int p,int n)                             //FUNCTION TO DISPLAY THE RESULT
{
          if(n<p)                                            //NUMBER OF STUDENT ARE LESS THEN REQUIRED
         {
            printf("\nTOTAL STRENGTH OF CLASS IS LESS THAN THAT IS REQUIRED");
         }
         else
         {
            if(p<=c)                                          //CLASS WILL HELD
            printf("\nON");
            else                                              //CLASS IS CANCELLED
            printf("\nOFF");
         }
}
