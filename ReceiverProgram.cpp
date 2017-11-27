
#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#define BUZZ_SIZE 1024
using namespace std;




void showData()
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
    cout<<endl;


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

void bitToText()
{
    FILE *textFile,*bitDataFile;
    textFile = fopen("textfiles/bitToText.txt", "w");
    bitDataFile = fopen("textfiles/receiverBitStream.txt", "r+");
    while (!feof(bitDataFile))
    {
        int i=0,sum=0;
        char charecter[8],charecter1;

        for(i=7; i>=0; i--)
        {
            fscanf(bitDataFile,"%c",&charecter1);
            if(charecter1=='0'||charecter1=='1')
            {
                charecter[i]=charecter1;
            }

        }
        for(i=0; i<=7; i++)
        {
            if(charecter[i]=='0')
            {
                sum=sum;
            }
            else if(charecter[i]=='1')
            {
                sum=sum+pow(2,i);
            }
        }
        // cout<<sum<<" ";
        if(sum==0||sum>127)    //for NILL detection
        {

            fclose(bitDataFile);
            fclose(textFile);
            return;
        }
        else
        {
        //cout<<sum<<" ";
            fprintf(textFile,"%c",(char)sum);
        }
    }

    fclose(bitDataFile);
    fclose(textFile);
}

void receiverSignalToBit()
{
    FILE *signalFile,*bitDataFile;
    char charecter1,charecter2,charecter3;
    signalFile = fopen("textfiles/signalFile.txt", "r+");
    bitDataFile = fopen("textfiles/receiverBitStream.txt", "w+");
    while (!feof(signalFile))
    {
        fscanf(signalFile,"%c%c%c",&charecter1,&charecter2,&charecter3);
        if(charecter1=='\n')
        {
            break;
        }

        if(charecter1==' ')
        {
            fprintf(bitDataFile,"%c",'1');
        }
        else if(charecter1=='_')
        {
            fprintf(bitDataFile,"%c",'0');
        }
    }
    fclose(bitDataFile);
    fclose(signalFile);
}



int main()
{
string a;
cout<<"press any key to continue : ";
cin>>a;
    receiverSignalToBit();
    bitToText();
    showData();
cout<<"\n\t\t!!! Data Received."<<endl;
    return 0;
}




