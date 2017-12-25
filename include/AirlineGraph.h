#ifndef AIRLINEGRAPH_H
#define AIRLINEGRAPH_H
#include "Airport.h"
#include "Airline.h"
#include "jsonxx.h"
#include <fstream>
#include <iomanip>

using std::setw;
using namespace jsonxx;

//����ͼ
class AirlineGraph
{
    public:
        AirlineGraph();
        virtual ~AirlineGraph();
        int mAirportNumber;                 //�������
        int mAirlineNumber;                 //���߱��
        Airport** mAirportHeadArray;        //����ͷָ��
        Airline** mAirlineArray;            //����ͷָ��
        Airport* FindAirportByName(string name);
        void InsertAirline(Airport* airport,Airline* airline);
        void ShowAirlineGraph();            //չʾ����
        void WriteAirlineJson();            //д��json
        void FindByAirlineName(string name);//ͨ������Ų���
    protected:

    private:
        Array GenerateAirlineJson();
        void LoadAirport();                 //�������
        void LoadAirline();                 //���뺽��
};

#endif // AIRLINEGRAPH_H
