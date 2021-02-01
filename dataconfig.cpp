#include "dataconfig.h"


int data1[4][4]={
    {1,1,1,1},
    {1,0,1,1},
    {0,0,0,1},
    {1,0,1,1}
};

DataConfig::DataConfig(QObject *parent) : QObject(parent)
{
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            mdata.push_back(data1[i][j]);
        }
    }
}
