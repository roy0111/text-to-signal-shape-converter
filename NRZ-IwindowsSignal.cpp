
////NRZ-I signal draw

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

             int x=20,shift=10,y=40,xp=0;
             line(30,10,30, 130);
             line(10,82,1000,82);

    bitFile = fopen("textfiles/transmitedBitStream.txt", "r+");

    while (!feof(bitFile))
    {
        fscanf(bitFile,"%c",&charecter);


    if(charecter=='0')
        {
              line(x+shift,y,x+10+shift,y);
        }

    else if(charecter=='1')
    {
          if(y==40){
            y=80;
            xp=40;
          }
         else if(y==80){
            y=40;
            xp=80;
          }
            line(x+shift,y,x+10+shift,y);
            line(x+shift,y,x+shift,xp);
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

