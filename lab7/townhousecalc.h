#ifndef TOWNHOUSECALC_H
#define TOWNHOUSECALC_H

#include <QObject>
#include "estate.h"
#include "fabric.h"

class TownhouseCalc : public Fabric
{
public:
    TownhouseCalc();
    TownhouseCalc(int area, int residents, int months);
    int getCost();
private:
    int area;
    int residents;
    int months;
};
#endif // TOWNHOUSECALC_H
