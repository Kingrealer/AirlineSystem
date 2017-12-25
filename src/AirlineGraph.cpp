#include "AirlineGraph.h"

AirlineGraph::AirlineGraph()
{
    LoadAirport();
    LoadAirline();
    ShowAirlineGraph();
}

AirlineGraph::~AirlineGraph()
{
    //dtor
}

void AirlineGraph::GenerateAirport()
{
    //ofstream outfile;
}

void AirlineGraph::LoadAirport()
{
    Array AirportArray;
    ifstream infile;
    string s;
    infile.open("Airport.json");
    ostringstream tmp;
    tmp<<infile.rdbuf();
    s=tmp.str();
    AirportArray.parse(s);
    mAirportNumber=AirportArray.size();
    cout<<mAirportNumber<<endl;
    mAirportHeadArray=new Airport*[mAirportNumber];
    for(int i=0;i<mAirportNumber;i++)
    {
        mAirportHeadArray[i]=new Airport();
        mAirportHeadArray[i]->No=AirportArray.get<Object>(i).get<Number>("���");
        mAirportHeadArray[i]->mAirportName=AirportArray.get<Object>(i).get<String>("����");
        mAirportHeadArray[i]->mShortName=AirportArray.get<Object>(i).get<String>("��������");
        mAirportHeadArray[i]->mLocation=AirportArray.get<Object>(i).get<String>("����");
    }
    //cout<<AirportArray.json();
}

void AirlineGraph::LoadAirline()
{
    Array AirlineArray;
    ifstream infile;
    string s;
    infile.open("Airline.json");
    ostringstream tmp;
    tmp<<infile.rdbuf();
    s=tmp.str();
    AirlineArray.parse(s);
    mAirlineNumber=AirlineArray.size();
    cout<<mAirlineNumber;
    mAirlineArray=new Airline*[mAirlineNumber];
    for(int i=0;i<mAirlineNumber;i++)
    {
        mAirlineArray[i]=new Airline();
        mAirlineArray[i]->mAirlineName=AirlineArray.get<Object>(i).get<String>("�����");
        mAirlineArray[i]->mCompany=AirlineArray.get<Object>(i).get<String>("��˾");
        mAirlineArray[i]->mDepartureAirport=AirlineArray.get<Object>(i).get<String>("��ɻ���");
        mAirlineArray[i]->mArrivalAirport=AirlineArray.get<Object>(i).get<String>("�������");
        mAirlineArray[i]->mDepartureTime=AirlineArray.get<Object>(i).get<String>("���ʱ��");
        mAirlineArray[i]->mArrivalTime=AirlineArray.get<Object>(i).get<String>("����ʱ��");
        mAirlineArray[i]->mAirplaneModel=AirlineArray.get<Object>(i).get<String>("����");
        mAirlineArray[i]->mDepartureCity=AirlineArray.get<Object>(i).get<String>("��ʼ����");
        mAirlineArray[i]->mArrivalCity=AirlineArray.get<Object>(i).get<String>("�������");
        mAirlineArray[i]->mPrice=AirlineArray.get<Object>(i).get<Number>("�۸�");
        mAirlineArray[i]->mDiscount=AirlineArray.get<Object>(i).get<Number>("����ۿ�");
        mAirlineArray[i]->mCapacity=AirlineArray.get<Object>(i).get<Number>("����");
        mAirlineArray[i]->mCurrentNumber=AirlineArray.get<Object>(i).get<Number>("��ǰ����");

        Airport* airport=FindAirportByName(mAirlineArray[i]->mDepartureAirport);
        //cout<<mAirlineArray[i]->mAirlineName<<endl;
        if(airport!=NULL)
        {
            //cout<<airport->mAirportName;
            InsertAirline(airport,mAirlineArray[i]);
        }
    }
    //cout<<AirlineArray.json();
}

Airport* AirlineGraph::FindAirportByName(string name)
{
    for(int i=0;i<mAirportNumber;i++)
    {
        if(mAirportHeadArray[i]->mAirportName==name)
        {

            //cout<<mAirportHeadArray[i]->mAirportName;
            return mAirportHeadArray[i];
        }
    }
    return NULL;
}

void AirlineGraph::InsertAirline(Airport* airport,Airline* airline)
{
    Airline* line=airport->mAdjAirline;
    if(line==NULL)
    {
        airport->mAdjAirline=airline;
    }else
    {
        //cout<<line->mAirlineName;
        while(line->mNextAirline!=NULL)
        {
            line=line->mNextAirline;
        }
        line->mNextAirline=airline;
    }
}

void AirlineGraph::ShowAirlineGraph()
{
    cout.setf(ios::left);
    cout<<endl;

    for(int i=0;i<mAirportNumber;i++)
    {
        cout<<endl;
        cout<<"======================================================================================================================";
        Airport* airport=mAirportHeadArray[i];
        Airline* airline=airport->mAdjAirline;
        cout<<endl<<"��"<<airport->mLocation<<" - "<<airport->mAirportName<<"��"<<"\t"<<endl<<endl;
        while(airline!=NULL)
        {
            cout<<airline->mAirlineName<<"\t";
            /*cout<<setw(25)<<airline->mAirlineName<<setw(25);
            cout<<airline->mCompany<<setw(35);
            cout<<airline->mDepartureAirport<<setw(25);
            cout<<airline->mArrivalAirport<<setw(25);
            cout<<airline->mDepartureTime<<setw(13);
            cout<<airline->mArrivalTime<<setw(13);
            cout<<airline->mAirplaneModel<<setw(13);
            cout<<airline->mDepartureCity<<setw(13);
            cout<<airline->mArrivalCity;
            cout<<endl;*/
            airline=airline->mNextAirline;
        }
    }
    cout<<endl<<"======================================================================================================================"<<endl;
}
