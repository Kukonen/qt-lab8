#ifndef APARTMENTCALC_H
#define APARTMENTCALC_H

#include <QObject>
#include "estate.h"
#include "fabric.h"

class ApartmentCalc: public Fabric
{
public:
    ApartmentCalc();
    ApartmentCalc(int area, int residents, int months);
    int getCost();
private:
    int area;
    int residents;
    int months;
};
#endif // APARTMENTCALC_H
