#include<iostream>
#include<fstream>
#include<string>
#define BUZZ_SIZE 1024
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





void allDataDisplay()
{
    FILE *signalFile,*bitDataFile;
    char charecter;
    char buff[BUZZ_SIZE];
    cout<<endl<<"  Source  text : ";
    bitDataFile = fopen("textfiles/enteredDataFile.txt", "r+");
    while (!feof(bitDataFile))
    {
        fscanf(bitDataFile,"%c",&charecter);
        if(charecter!='~'){
            cout<<charecter;
          }

    }
   fclose(bitDataFile);
    cout<<endl<<endl;
    showSignal();

    cout<<endl<<"    Receiver signal to bit stream  : ";
    signalFile = fopen("textfiles/receiverBitStream.txt", "r+");

    fgets(buff, BUZZ_SIZE, signalFile);
    cout<<buff<<endl;
    fclose(signalFile);


   cout<<endl<<"     Receiver retrived text  : ";
    signalFile = fopen("textfiles/bitToText.txt", "r+");
    fgets(buff, BUZZ_SIZE, signalFile);
    cout<<buff<<endl;
    fclose(signalFile);
}

int main()
{
string a;
cout<<"  press any key to continue : ";
cin>>a;
   allDataDisplay();
   cout<<endl<<endl;
    return 0;
}




