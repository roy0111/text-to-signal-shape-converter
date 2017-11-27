////NRZ-L signal draw

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


           int x1=30,y1=30,x2=40,y2=30;
          int len=10;
             line(40,10,40, 130);
             line(10,102,1000,102);
    prev ='0';
    bitFile = fopen("textfiles/transmitedBitStream.txt", "r+");

    while (!feof(bitFile))                            
    {
        fscanf(bitFile,"%c",&charecter);
        if(charecter=='1' && prev=='0')
        {
              line(x1+len,y1+70,x2+len, y2+70);
              line(x1+len,y2,x1+len,y2+70);

        }
        else if(charecter=='1')
        {
              line(x1+len,y1+70,x2+len, y2+70);

        }
        else if(charecter=='0'&& prev=='0')
        {
              line(x1+len,y1,x2+len, y2); 

        }
        else if(charecter=='0')
        {
              line(x1+len,y1,x2+len, y2); 
              line(x1+len,y2,x1+len,y2+70);

        } 
        len=len+12;
        prev=charecter;
      
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

