#ifndef AIRPORT_H
#define AIRPORT_H
#include <string>
#include <Airline.h>
using namespace std;

class Airport
{
    public:
        Airport();                  //���캯��
        virtual ~Airport();
        int No;                     //�������
        string mLocation;           //�����ص�
        string mAirportName;        //��������
        string mShortName;          //������д
        Airline* mAdjAirline;       //�����ڽӶ���
    protected:

    private:
};

#endif // AIRPORT_H
