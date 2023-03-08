#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filedata.h"

FileData::FileData()
{
    strcpy(name, "SLS150_ADCP_2_20211211113000.dat");

    fid = fopen(name, "rb");

    fseek(fid, 38, SEEK_SET);
    fread(&cellNum, sizeof(char), 1, fid);
    pingLength = 32 + 32 + (2 + cellNum * 8) * 2 + (2 + cellNum * 4) + 48 + 32 + 16;

    fseek(fid, 0, SEEK_END);
    count = ftell(fid);
    Ping_Num = count / (32 + 32 + 2 * (cellNum * 8 + 2) + (cellNum * 4 + 2) + 96);

    printf("cellNum=%d\n", cellNum);
    printf("pingLength=%d\n", pingLength);
    printf("count=%d\n", count);
    printf("Ping_Num=%d\n", Ping_Num);

    RTC_year = (unsigned char *)malloc(Ping_Num);
    RTC_month = (unsigned char *)malloc(Ping_Num);
    RTC_day = (unsigned char *)malloc(Ping_Num);
    RTC_hour = (unsigned char *)malloc(Ping_Num);
    RTC_min = (unsigned char *)malloc(Ping_Num);
    RTC_sec = (unsigned char *)malloc(Ping_Num);

    V1 = (double *)malloc(sizeof(double) * cellNum * Ping_Num);
    V2 = (double *)malloc(sizeof(double) * cellNum * Ping_Num);
    V3 = (double *)malloc(sizeof(double) * cellNum * Ping_Num);
    V4 = (double *)malloc(sizeof(double) * cellNum * Ping_Num);

    E1 = (unsigned short *)malloc(sizeof(unsigned short) * cellNum * Ping_Num);
    E2 = (unsigned short *)malloc(sizeof(unsigned short) * cellNum * Ping_Num);
    E3 = (unsigned short *)malloc(sizeof(unsigned short) * cellNum * Ping_Num);
    E4 = (unsigned short *)malloc(sizeof(unsigned short) * cellNum * Ping_Num);

    Cor1 = (unsigned char *)malloc(sizeof(unsigned char) * cellNum * Ping_Num);
    Cor2 = (unsigned char *)malloc(sizeof(unsigned char) * cellNum * Ping_Num);
    Cor3 = (unsigned char *)malloc(sizeof(unsigned char) * cellNum * Ping_Num);
    Cor4 = (unsigned char *)malloc(sizeof(unsigned char) * cellNum * Ping_Num);

    BTV1 = (double *)malloc(sizeof(double) * cellNum * Ping_Num);
    BTV2 = (double *)malloc(sizeof(double) * cellNum * Ping_Num);
    BTV3 = (double *)malloc(sizeof(double) * cellNum * Ping_Num);
    BTV4 = (double *)malloc(sizeof(double) * cellNum * Ping_Num);

    BTDepth1 = (double *)malloc(sizeof(double) * cellNum * Ping_Num);
    BTDepth2 = (double *)malloc(sizeof(double) * cellNum * Ping_Num);
    BTDepth3 = (double *)malloc(sizeof(double) * cellNum * Ping_Num);
    BTDepth4 = (double *)malloc(sizeof(double) * cellNum * Ping_Num);

    BTE1 = (unsigned short *)malloc(sizeof(unsigned short) * cellNum * Ping_Num);
    BTE2 = (unsigned short *)malloc(sizeof(unsigned short) * cellNum * Ping_Num);
    BTE3 = (unsigned short *)malloc(sizeof(unsigned short) * cellNum * Ping_Num);
    BTE4 = (unsigned short *)malloc(sizeof(unsigned short) * cellNum * Ping_Num);

    BTCor1 = (unsigned char *)malloc(sizeof(unsigned char) * cellNum * Ping_Num);
    BTCor2 = (unsigned char *)malloc(sizeof(unsigned char) * cellNum * Ping_Num);
    BTCor3 = (unsigned char *)malloc(sizeof(unsigned char) * cellNum * Ping_Num);
    BTCor4 = (unsigned char *)malloc(sizeof(unsigned char) * cellNum * Ping_Num);

    BTP1 = (unsigned char *)malloc(sizeof(unsigned char) * cellNum * Ping_Num);
    BTP2 = (unsigned char *)malloc(sizeof(unsigned char) * cellNum * Ping_Num);
    BTP3 = (unsigned char *)malloc(sizeof(unsigned char) * cellNum * Ping_Num);
    BTP4 = (unsigned char *)malloc(sizeof(unsigned char) * cellNum * Ping_Num);

    Pressure = (double *)malloc(sizeof(double) * cellNum * Ping_Num);
    Temp = (double *)malloc(sizeof(double) * cellNum * Ping_Num);
    Roll = (double *)malloc(sizeof(double) * cellNum * Ping_Num);
    Pitch = (double *)malloc(sizeof(double) * cellNum * Ping_Num);
    Heading = (double *)malloc(sizeof(double) * cellNum * Ping_Num);

    WOE = (unsigned char *)malloc(sizeof(unsigned char) * cellNum * Ping_Num);
    NOS = (unsigned char *)malloc(sizeof(unsigned char) * cellNum * Ping_Num);

    Voltage = (unsigned short *)malloc(sizeof(unsigned short) * cellNum * Ping_Num);
    Check_Sum = (unsigned short *)malloc(sizeof(unsigned short) * cellNum * Ping_Num);

    fseek(fid, 0, SEEK_SET);
    char tmp_data[256];
    short short_data[256];
    unsigned short ushort_data[256];
    for (int ind = 0; ind < Ping_Num; ind++)
    {
        //***********
        fread(tmp_data, 1, 2, fid);

        fread(short_data, 2, 1, fid);
        fread(short_data, 2, 1, fid);
        fread(short_data, 2, 1, fid);
        fread(short_data, 2, 1, fid);
        fread(short_data, 2, 1, fid);
        fread(short_data, 2, 1, fid);
        fread(short_data, 2, 1, fid);
        fread(short_data, 2, 1, fid);
        fread(tmp_data, 1, 14, fid);

        //***********
        fread(tmp_data, 1, 2, fid);
        fread(short_data, 2, 1, fid);
        fread(short_data, 2, 1, fid);
        fread(tmp_data, 1, 1, fid);
        fread(short_data, 2, 1, fid);
        fread(tmp_data, 1, 1, fid);
        fread(tmp_data, 1, 1, fid);

        fread(tmp_data, 1, 1, fid);
        fread(tmp_data, 1, 1, fid);
        fread(tmp_data, 1, 1, fid);
        fread(tmp_data, 1, 1, fid);
        fread(tmp_data, 1, 1, fid);
        fread(tmp_data, 1, 1, fid);

        fread(tmp_data, 1, 1, fid);
        fread(tmp_data, 1, 1, fid);
        fread(tmp_data, 1, 1, fid);

        fread(tmp_data, 1, 1, fid);
        fread(tmp_data, 1, 1, fid);
        fread(tmp_data, 1, 1, fid);

        fread(short_data, 2, 1, fid);

        fread(RTC_year + ind, 1, 1, fid);
        fread(RTC_month + ind, 1, 1, fid);
        fread(RTC_day + ind, 1, 1, fid);
        fread(RTC_hour + ind, 1, 1, fid);
        fread(RTC_min + ind, 1, 1, fid);
        fread(RTC_sec + ind, 1, 1, fid);
        fread(tmp_data, 1, 1, fid);

        //***********
        fread(tmp_data, 1, 2, fid);

        for (int index = 0; index < cellNum; index++)
        {
            fread(short_data, 2, 1, fid);
            V1[cellNum * ind + index] = short_data[0] / 1000.0;

            fread(short_data, 2, 1, fid);
            V2[cellNum * ind + index] = short_data[0] / 1000.0;

            fread(short_data, 2, 1, fid);
            V3[cellNum * ind + index] = short_data[0] / 1000.0;

            fread(short_data, 2, 1, fid);
            V4[cellNum * ind + index] = short_data[0] / 1000.0;
        }

        //***********
        fread(tmp_data, 1, 2, fid);

        for (int index = 0; index < cellNum; index++)
        {
            fread(E1 + cellNum * ind + index, 2, 1, fid);
            fread(E2 + cellNum * ind + index, 2, 1, fid);
            fread(E3 + cellNum * ind + index, 2, 1, fid);
            fread(E4 + cellNum * ind + index, 2, 1, fid);
        }

        //***********
        fread(tmp_data, 1, 2, fid);

        for (int index = 0; index < cellNum; index++)
        {
            fread(Cor1 + cellNum * ind + index, 1, 1, fid);
            fread(Cor2 + cellNum * ind + index, 1, 1, fid);
            fread(Cor3 + cellNum * ind + index, 1, 1, fid);
            fread(Cor4 + cellNum * ind + index, 1, 1, fid);
        }

        //***********
        fread(tmp_data, 1, 2, fid);

        fread(short_data, 2, 1, fid);
        BTV1[ind] = short_data[0] / 1.0;
        fread(short_data, 2, 1, fid);
        BTV2[ind] = short_data[0] / 1.0;
        fread(short_data, 2, 1, fid);
        BTV3[ind] = short_data[0] / 1.0;
        fread(short_data, 2, 1, fid);
        BTV4[ind] = short_data[0] / 1.0;

        fread(ushort_data, 2, 1, fid);
        BTDepth1[ind] = ushort_data[0] / 100.0;
        fread(ushort_data, 2, 1, fid);
        BTDepth2[ind] = ushort_data[0] / 100.0;
        fread(ushort_data, 2, 1, fid);
        BTDepth3[ind] = ushort_data[0] / 100.0;
        fread(ushort_data, 2, 1, fid);
        BTDepth4[ind] = ushort_data[0] / 100.0;

        fread(BTE1 + ind, 2, 1, fid);
        fread(BTE2 + ind, 2, 1, fid);
        fread(BTE3 + ind, 2, 1, fid);
        fread(BTE4 + ind, 2, 1, fid);

        fread(BTCor1 + ind, 1, 1, fid);
        fread(BTCor2 + ind, 1, 1, fid);
        fread(BTCor3 + ind, 1, 1, fid);
        fread(BTCor4 + ind, 1, 1, fid);

        fread(BTP1 + ind, 1, 1, fid);
        fread(BTP2 + ind, 1, 1, fid);
        fread(BTP3 + ind, 1, 1, fid);
        fread(BTP4 + ind, 1, 1, fid);

        fread(tmp_data, 1, 14, fid);

        //***********
        fread(tmp_data, 1, 2, fid);

        fread(ushort_data, 2, 1, fid);
        Pressure[ind] = ushort_data[0] / 10.0;

        fread(short_data, 2, 1, fid);
        Temp[ind] = short_data[0] / 100.0;

        fread(short_data, 2, 1, fid);
        Roll[ind] = short_data[0] / 10.0;

        fread(short_data, 2, 1, fid);
        Pitch[ind] = short_data[0] / 10.0;

        fread(short_data, 2, 1, fid);
        Heading[ind] = short_data[0] / 100.0;

        fread(WOE + ind, 1, 1, fid);
        fread(short_data, 2, 1, fid);
        fread(short_data, 2, 2, fid);

        fread(NOS + ind, 1, 1, fid);
        fread(short_data, 2, 1, fid);
        fread(short_data, 2, 2, fid);

        fread(tmp_data, 1, 6, fid);

        //***********
        fread(tmp_data, 1, 2, fid);

        fread(Voltage + ind, 2, 1, fid);
        fread(tmp_data, 1, 10, fid);
        fread(Check_Sum + ind, 2, 1, fid);
        // printf("Temp[%d]=%.2lf\n", ind, Temp[ind]);
    }
}

FileData::~FileData()
{

    free(Check_Sum);
    free(Voltage);
    free(NOS);
    free(WOE);
    free(Heading);
    free(Pitch);
    free(Roll);
    free(Temp);
    free(Pressure);

    free(BTP4);
    free(BTP3);
    free(BTP2);
    free(BTP1);

    free(BTCor4);
    free(BTCor3);
    free(BTCor2);
    free(BTCor1);

    free(BTE4);
    free(BTE3);
    free(BTE2);
    free(BTE1);

    free(BTDepth4);
    free(BTDepth3);
    free(BTDepth2);
    free(BTDepth1);

    free(BTV4);
    free(BTV3);
    free(BTV2);
    free(BTV1);

    free(Cor4);
    free(Cor3);
    free(Cor2);
    free(Cor1);

    free(E4);
    free(E3);
    free(E2);
    free(E1);

    free(V4);
    free(V3);
    free(V2);
    free(V1);

    free(RTC_sec);
    free(RTC_min);
    free(RTC_hour);
    free(RTC_day);
    free(RTC_month);
    free(RTC_year);

    fclose(fid);
}

void FileData::writeData(const std::string &name)
{
    FILE *fp = fopen(name.c_str(), "wt");
    for (int i = 0; i < Ping_Num; i++)
    {
        for (int j = 0; j < cellNum; j++)
        {
            fprintf(fp, "%9.6lf\t", V1[cellNum * i + j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}