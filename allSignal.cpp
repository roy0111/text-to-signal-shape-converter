////all signal draw


#include<string.h>
#include<iostream>
#include<fstream>
#include<graphics.h>
using namespace std;


void signal()
{


    int gd = DETECT, gm;
    /* initialization of graphic mode */
    initgraph(&gd, &gm, NULL);



    FILE *bitFile;
    char charecter,prev;
    int x2=30,shift2=10,y2=340,xp2=0;
    int flag3=0,x3=30,shift3=10,xp3=0,y3=200;
    int x1=30,y1=30;
    int x=35;
    int len1=5,flag1=0;
    int len=10;
    line(40,10,40, 1000);
    line(10,102,1000,102);
    line(10,382,1000,382);
    line(10,160,1000,160);
    line(10,260,1000,260);


    prev ='0';
    bitFile = fopen("textfiles/transmitedBitStream.txt", "r+");

    while (!feof(bitFile))
    {
        fscanf(bitFile,"%c",&charecter);
        if(charecter=='1' && prev=='0')
        {
            line(x1+len,y1+70,40+len,30+70);
            line(x1+len,30,x1+len,30+70);

        }
        else if(charecter=='1')
        {
            line(x1+len,y1+70,40+len,30+70);

        }
        else if(charecter=='0'&& prev=='0')
        {
            line(x1+len,y1,40+len, 30);

        }
        else if(charecter=='0')
        {
            line(x1+len,y1,40+len, 30);
            line(x1+len,30,x1+len,30+70);

        }
        len=len+12;


        ///////////////////////////////////

        if(charecter=='0')
        {
            if(prev=='0')
            {
                line(x+len1,130,x+len1,190);
            }
            line(x+len1,130,x+len1+6, 130);
            len1=len1+6;
            line(x+len1,190,x+len1+6,190);
            line(x+len1,130,x+len1,190);

        }

        else if(charecter=='1')
        {
            if(prev=='1')
            {
                line(x+len1,130,x+len1,190);
            }
            line(x+len1,190,x+len1+6, 190);
            len1=len1+6;
            line(x+len1,130,x+len1+6,130);
            line(x+len1,130,x+len1,190);
        }
        len1=len1+6;

        ////////////////////////////////////////

        if(charecter=='1' )
        {
            flag3++;
            flag3=flag3%2;
        }

        if(charecter=='0')
        {
            line(x3+shift3,260-2,x3+10+shift3,260-2);
            line(xp3,y3,xp3,260-2);
            xp3=x3+10+shift3;
            y3=260;
        }

        else if(charecter=='1'&&flag3==1)
        {
            line(x3+shift3,220,x3+10+shift3,220);
            line(xp3,y3,xp3,220);
            xp3=x3+10+shift3;
            y3=220;
        }
        else if(charecter=='1'&&flag3==0)
        {
            line(x3+shift3,300,x3+10+shift3,300);
            line(xp3,y3,xp3,300);
            xp3=x3+10+shift3;
            y3=300;
        }
        shift3=shift3+12;
  /////////////////////////////

        if(charecter=='0')
        {
            line(x2+shift2,y2,x2+10+shift2,y2);
        }

        else if(charecter=='1')
        {
            if(y2==340)
            {
                y2=380;
                xp2=340;
            }
            else if(y2==380)
            {
                y2=340;
                xp2=380;
            }
            line(x2+shift2,y2,x2+10+shift2,y2);
            line(x2+shift2,y2,x2+shift2,xp2);
        }

        shift2=shift2+12;




        prev=charecter;

    }

    delay(2000);
    getch();
    closegraph();
    fclose(bitFile);

}

int main()
{
    signal();

    return 0;
}



