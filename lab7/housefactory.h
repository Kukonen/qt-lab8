#ifndef HOUSEFACTORY_H
#define HOUSEFACTORY_H

#include <QObject>
#include <estate.h>
#include <apartmentcalc.h>
#include <luxuriousapartmentcalc.h>
#include <townhousecalc.h>
#include <cottagecalc.h>
#include <fabric.h>


class HouseFactory
{
public:
    HouseFactory();
    Fabric* getByType(Estate *value);
};

#endif // HOUSEFACTORY_H
