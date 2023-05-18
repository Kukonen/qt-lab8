#ifndef COTTAGECALC_H
#define COTTAGECALC_H

#include "estate.h"
#include "fabric.h"

class CottageCalc : public Fabric
{
public:
    CottageCalc();
    CottageCalc(int area, int residents, int months);
    int getCost();
private:
    int area;
    int residents;
    int months;
};

#endif // COTTAGECALC_H
