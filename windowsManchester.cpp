////MANCHESTER signal draw

#include<graphics.h>
#include<string.h>
#include<iostream>
#include<fstream>

using namespace std;


void transmitterSignalDraw()
{
    int gd = DETECT, gm;
    /* initialization of graphic mode */
    initgraph(&gd, &gm, NULL);

    FILE *bitFile;
    char charecter,prev;


    int x=35;
    int len=5;
    line(40,10,40, 130);
    line(10,60,500,60);
    prev ='0';
    bitFile = fopen("textfiles/transmitedBitStream.txt", "r+");

    while (!feof(bitFile))
    {
        fscanf(bitFile,"%c",&charecter);


        if(charecter=='0')
        {
            if(prev=='0')
            {
                line(x+len,30,x+len,90);
            }
            line(x+len,30,x+len+5, 30);
            len=len+5;
            line(x+len,90,x+len+5,90);
            line(x+len,30,x+len,90);

        }

        else if(charecter=='1')
        {
            if(prev=='1')
            {
                line(x+len,30,x+len,90);
            }
            line(x+len,90,x+len+5, 90);
            len=len+5;
            line(x+len,30,x+len+5,30);
            line(x+len,30,x+len,90);
        }
        len=len+5;
        prev=charecter;
    }
    delay(90);
    getch();
    closegraph();
    fclose(bitFile);

}

int main()
{
    transmitterSignalDraw();
    return 0;
}


