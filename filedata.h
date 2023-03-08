#ifndef FILEDATA_H
#define FILEDATA_H

#include <string>

class FileData
{
public:
    FileData();
    ~FileData();

    void writeData(const std::string &name);

public:
    char name[256];
    FILE *fid;

    char cellNum;
    int pingLength;
    int count;
    int Ping_Num;

    unsigned char *RTC_year;
    unsigned char *RTC_month;
    unsigned char *RTC_day;
    unsigned char *RTC_hour;
    unsigned char *RTC_min;
    unsigned char *RTC_sec;

    double *V1;
    double *V2;
    double *V3;
    double *V4;

    unsigned short *E1;
    unsigned short *E2;
    unsigned short *E3;
    unsigned short *E4;

    unsigned char *Cor1;
    unsigned char *Cor2;
    unsigned char *Cor3;
    unsigned char *Cor4;

    double *BTV1;
    double *BTV2;
    double *BTV3;
    double *BTV4;

    double *BTDepth1;
    double *BTDepth2;
    double *BTDepth3;
    double *BTDepth4;

    unsigned short *BTE1;
    unsigned short *BTE2;
    unsigned short *BTE3;
    unsigned short *BTE4;

    unsigned char *BTCor1;
    unsigned char *BTCor2;
    unsigned char *BTCor3;
    unsigned char *BTCor4;

    unsigned char *BTP1;
    unsigned char *BTP2;
    unsigned char *BTP3;
    unsigned char *BTP4;

    double *Pressure;
    double *Temp;
    double *Roll;
    double *Pitch;
    double *Heading;

    unsigned char *WOE;
    unsigned char *NOS;

    unsigned short *Voltage;
    unsigned short *Check_Sum;
};

#endif