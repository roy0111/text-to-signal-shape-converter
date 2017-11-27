#include<stdio.h>
#include<string.h>
#include<iostream>
#include<fstream>
#define BUZZ_SIZE 99999
using namespace std;

void showSignal()
{
    FILE *signalFile,*bitDataFile;
    char charecter;
    char buff[BUZZ_SIZE];
    cout<<endl<<"    bit stream : ";
    bitDataFile = fopen("textfiles/transmitedBitStream.txt", "r+");
       fgets(buff, BUZZ_SIZE, bitDataFile);
    cout<<buff<<endl;


    cout<<endl<<"   using NRZ- L Encoding teachnic."<<endl;
    signalFile = fopen("textfiles/signalFile.txt", "r+");
    while (!feof(signalFile))
    {
        fscanf(signalFile,"%c",&charecter);
        cout<<charecter;
    }
    fclose(bitDataFile);
    fclose(signalFile);
       cout<<endl<<endl;
}


void signalGenarateFunction()
{
    FILE *bitFile,*signalFile;
    char charecter,prev;

    signalFile = fopen("textfiles/signalFile.txt", "w+");
    bitFile = fopen("textfiles/transmitedBitStream.txt", "r+");


    while (!feof(bitFile))       //convert 0 into ____
    {
        fscanf(bitFile,"%c",&charecter);
        if(charecter=='0')
        {
            fprintf(signalFile,"%s","___");
        }
        else if(charecter=='1')
        {
            fprintf(signalFile,"%s","   ");
        }

    }
    fclose(bitFile);
    //////////////////////////////////////////////////////
    fprintf(signalFile,"\n");
    prev='0';
    bitFile = fopen("textfiles/transmitedBitStream.txt", "r+");
    while (!feof(bitFile))                   //second signal line(transition |)
    {
        fscanf(bitFile,"%c",&charecter);
        if(charecter!=prev)
        {
            fprintf(signalFile,"%s","|  ");
        }
        else
        {
            fprintf(signalFile,"%s","   ");
        }
        prev=charecter;
    }
    fclose(bitFile);

    fprintf(signalFile,"\n");
    //////////////////////////////////////////////////
    prev ='0';
    bitFile = fopen("textfiles/transmitedBitStream.txt", "r+");
    while (!feof(bitFile))                             //convert 1 into ~~~~
    {
        fscanf(bitFile,"%c",&charecter);
        if(charecter=='1' && prev=='0')
        {
            fprintf(signalFile,"%s","|__");
        }
        else if(charecter=='1')
        {
            fprintf(signalFile,"%s","___");
        }
        else if(charecter=='0'&& prev=='0')
        {
            fprintf(signalFile,"%s","   ");
        }
        else if(charecter=='0')
        {
            fprintf(signalFile,"%s","|  ");
        }
        prev=charecter;
    }
    fclose(bitFile);
    fclose(signalFile);
}

void dataConvertIntoBit(int dataAscii){
  FILE *dataFile;
  int remainder;
  int j=7;
  char bitStream[9];

   for(int  i=0;i<8;i++){
    bitStream[i]='0';
   }

    while(dataAscii != 0) {
      remainder = dataAscii%2;
      dataAscii = dataAscii/2;
       if(remainder==1){
           bitStream[j]='1';
        }
        j--;
    }

   dataFile = fopen("textfiles/transmitedBitStream.txt", "a+");
   for(int  i=0;i<8;i++){
    fprintf(dataFile,"%c",bitStream[i]);
   }
   fclose(dataFile);
}

void dataConvertIntoDec(){
    FILE *dataFile;
    char charecter;
    int dataAscii;
    dataFile = fopen("textfiles/enteredDataFile.txt", "r+");
    while (!feof(dataFile)) {
      fscanf(dataFile,"%c",&charecter);
      dataAscii=int(charecter);
      if(charecter!='~'){
        dataConvertIntoBit(dataAscii);
      }

    }
 fclose(dataFile);
}

void readData(){
    FILE *dataFile;
    string dataText;

    cout<<"enter data (don't enter ~ ) : ";
    getline(cin,dataText);

    dataFile = fopen("textfiles/enteredDataFile.txt", "w+");
    int len=dataText.length();
    for(int i=0;i<len;i++){
    fprintf(dataFile,"%c",dataText.at(i));
    }
    fprintf(dataFile,"%c",'~');
  fclose(dataFile);
}

void eraseFromFile(){
   FILE *dataFile;
    dataFile = fopen("textfiles/transmitedBitStream.txt", "w");
    //fprintf(dataFile,"%c",' ');
fclose(dataFile);
}
int main(){
   eraseFromFile();
   readData();
   dataConvertIntoDec();
   signalGenarateFunction();
   showSignal();
  cout<<"\n\t!!! Transmission complete.\n\n";
return 0;
}

