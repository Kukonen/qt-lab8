#include "calculationfacade.h"

CalculationFacade::CalculationFacade(QObject *parent) : QObject(parent)
{
}
int CalculationFacade::getCost(Estate *value)
{
    // создаём фабрику
    HouseFactory *h = new HouseFactory();
    // получаем из фабрики класс взавосимости от типа жилья
    Fabric* componecnt = h->getByType(value);

    // возвращаем стоимость
    return componecnt->getCost();

}
