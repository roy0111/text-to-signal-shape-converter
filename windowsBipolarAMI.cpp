////bipolar AMI signal draw
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
    char charecter;


             int flag=0,x=20,shift=10,xp=0,y=0;
             line(30,10,30, 130);
            line(10,82,1000,82);

    bitFile = fopen("textfiles/transmitedBitStream.txt", "r+");

    while (!feof(bitFile))
    {
        fscanf(bitFile,"%c",&charecter);

        if(charecter=='1' )
        {
           flag++;
           flag=flag%2;
        }

    if(charecter=='0')
        {
              line(x+shift,80,x+10+shift,80);
              line(xp,y,xp,80);
              xp=x+10+shift;
              y=80;
        }

        else if(charecter=='1'&&flag==1)
        {
            line(x+shift,40,x+10+shift,40);
              line(xp,y,xp,40);
              xp=x+10+shift;
              y=40;
        }
        else if(charecter=='1'&&flag==0)
        {
            line(x+shift,120,x+10+shift,120);
              line(xp,y,xp,120);
              xp=x+10+shift;
              y=120;
        }
          shift=shift+12;

    }
    delay(70);
    getch();
    closegraph();
    fclose(bitFile);

}

int main(){
   transmitterSignalDraw();
return 0;
}

