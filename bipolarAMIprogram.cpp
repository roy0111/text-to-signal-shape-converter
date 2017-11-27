#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;


void signalGenarateFunction()
{
    FILE *bitFile,*signalFile;
    char charecter,prev;

    signalFile = fopen("textfiles/signalBipolarAMI.txt", "w+");
    bitFile = fopen("textfiles/transmitedBitStream.txt", "r+");

    short flag=0;
    while (!feof(bitFile))
    {
        fscanf(bitFile,"%c",&charecter);
        if(charecter=='1')
        {
            flag=(flag+1)%2;
        }

        if(charecter=='1'&&flag==1)
        {
            fprintf(signalFile,"%s","___");
        }
        else
        {
            fprintf(signalFile,"%s","   ");
        }

    }
    fclose(bitFile);
    fprintf(signalFile,"\n");

////////////////////////////////////////////////////////////////////
    prev='0';flag=0;
    bitFile = fopen("textfiles/transmitedBitStream.txt", "r+");
    while (!feof(bitFile))
    {
        fscanf(bitFile,"%c",&charecter);
        if(charecter=='1')
        {
            flag=(flag+1)%2;
        }
         if(charecter=='1'&&prev=='1')
        {
            fprintf(signalFile,"%s","|  ");
        }

        else if(charecter=='1'&&prev=='0'&&flag==1)
        {
            fprintf(signalFile,"%s","|  ");
        }
        else if(charecter=='0'&&prev=='1'&&flag==1)
        {
            fprintf(signalFile,"%s","|  ");
        }
        else
        {
            fprintf(signalFile,"%s","   ");
        }

      prev=charecter;
    }
    fprintf(signalFile,"\n");

//////////////////////////////////////////////
    bitFile = fopen("textfiles/transmitedBitStream.txt", "r+");
     prev='0';flag=0;
    while (!feof(bitFile))
    {
        fscanf(bitFile,"%c",&charecter);
        if(charecter=='1')
        {
            flag=(flag+1)%2;
        }
        if(charecter=='0'&&prev=='1'&&flag==1)
        {
            fprintf(signalFile,"%s","|__");
        }
        else if(charecter=='0'&&prev=='1'&&flag==0)
        {
            fprintf(signalFile,"%s","___");
        }
        else if(charecter=='1'&&prev=='0'&&flag==1)
        {
            fprintf(signalFile,"%s","|  ");
        }
        else if(charecter=='1'&&prev=='1')
        {
            fprintf(signalFile,"%s","|  ");
        }
        else if(charecter=='0'&&prev=='0')
        {
            fprintf(signalFile,"%s","___");
        }
        else
        {
            fprintf(signalFile,"%s","   ");
        }
     prev=charecter;
    }
    fclose(bitFile);
    fprintf(signalFile,"\n");

        //////////////////////////////////////////////////////
         prev='0';flag=0;
    bitFile = fopen("textfiles/transmitedBitStream.txt", "r+");
    while (!feof(bitFile))
    {
        fscanf(bitFile,"%c",&charecter);
        if(charecter=='1')
        {
            flag=(flag+1)%2;
        }
         if(charecter=='1'&&prev=='1')
        {
            fprintf(signalFile,"%s","|  ");
        }

        else if(charecter=='1'&&prev=='0'&&flag==0)
        {
            fprintf(signalFile,"%s","|  ");
        }
        else if(charecter=='0'&&prev=='1'&&flag==0)
        {
            fprintf(signalFile,"%s","|  ");
        }
        else
        {
            fprintf(signalFile,"%s","   ");
        }

      prev=charecter;
    }
    fprintf(signalFile,"\n");
    //////////////////////////////////////////////////

    bitFile = fopen("textfiles/transmitedBitStream.txt", "r+");
    prev='0';flag=0;
    while (!feof(bitFile))
    {
        fscanf(bitFile,"%c",&charecter);
        if(charecter=='1')
        {
            flag=(flag+1)%2;
        }
        if(charecter=='1'&&flag==1&&prev=='1')
        {
            fprintf(signalFile,"%s","|  ");
        }
        else if(charecter=='1'&&flag==0&&prev=='1')
        {
            fprintf(signalFile,"%s","|__");
        }
      else if(charecter=='1'&&flag==0&&prev=='0')
        {
            fprintf(signalFile,"%s","|__");
        }
      else if(charecter=='0'&&flag==0&&prev=='1'){
        fprintf(signalFile,"%s","|  ");
      }
        else{
                  fprintf(signalFile,"%s","   ");
        }
        prev=charecter;
    }

    fclose(bitFile);
    fclose(signalFile);
}

void bitDisplay(){
    FILE *bitFile;
    char charecter;
  cout<<endl<<"  Bit stream :  ";
    bitFile = fopen("textfiles/transmitedBitStream.txt", "r+");
    while (!feof(bitFile))
    {
            fscanf(bitFile,"%c",&charecter);
            cout<<charecter;
    }
    fclose(bitFile);
    cout<<endl;
}

void signalDraw(){
    FILE *signalFile;
    char charecter;

    signalFile = fopen("textfiles/signalBipolarAMI.txt", "r+");
    while (!feof(signalFile))
    {
            fscanf(signalFile,"%c",&charecter);
            cout<<charecter;
    }
    fclose(signalFile);
}
int main()
{
  char c;
  cout<<"press any key to continue: ";
  cin>>c;
    bitDisplay();
    signalGenarateFunction();
    signalDraw();
    cout<<endl<<endl<<"\t\t!!! Bipolar-AMI encoding  technique\n";
    return 0;
}
