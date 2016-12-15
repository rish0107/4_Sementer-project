#include"header.h"
#include"prof.c"
#include"lucky.c"

int main()
{
	int ch;
	do
    {
        printf("\n\n1-angry professor\n2-lucky no\n3-EXIT\n");                   //PROGRAM MENU
        printf("\nPLEASE ENTER THE CHOICE NUMBER TO ACCESS THE ABOVE MENU ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                prof();                                                         //CALLING A FUNCTION PROF
                break;
            case 2:
                lucky();                                                        //CALLING A FUNCTION TO CALCULATE A LUCKY NUMBER
                break;
            case 3:
                break;                                                          //EXIT THE MENU
            default:
                if(!(ch<='9' && ch>='0'))
                {
                    if( ch == (char)3 || ch == (char)13)
                    continue;
                    else
                    {
                        printf("\nYOU ENTER THE WRONG CHOICE...PLEEASE ENTER THE APPROPIRATE CHOICE\n");    //INVALID INPUT
                        return ;
                    }
                }
        }
    }while(ch != 3);
    return 0;
}
