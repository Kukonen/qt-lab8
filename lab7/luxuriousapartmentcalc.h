#ifndef LUXURIOUSAPARTMENTCALC_H
#define LUXURIOUSAPARTMENTCALC_H

#include <QObject>
#include "estate.h"
#include "fabric.h"

class LuxuriousApartmentCalc : public Fabric
{
public:
    LuxuriousApartmentCalc();
    LuxuriousApartmentCalc(int area, int residents, int months);
    int getCost();
private:
    int area;
    int residents;
    int months;
};


#endif // LUXURIOUSAPARTMENTCALC_H
