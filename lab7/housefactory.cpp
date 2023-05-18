#include "housefactory.h"

HouseFactory::HouseFactory()
{

}

Fabric* HouseFactory::getByType(Estate *value) {
    // взависимости от типа жилья
    // возвращаем класс жилья
    switch (value->getType()) {
        case Estate::EstateType::ECONOM:
            return new ApartmentCalc(value->getArea(), value->getResidents(), value->getMonths());

        case Estate::EstateType::LUXURIOUS:
            return new LuxuriousApartmentCalc(value->getArea(), value->getResidents(), value->getMonths());

        case Estate::EstateType::TOWN_HOUSE:
            return new TownhouseCalc(value->getArea(), value->getResidents(), value->getMonths());

        case Estate::EstateType::COTTAGE:
            return new CottageCalc(value->getArea(), value->getResidents(), value->getMonths());

        default:
            return nullptr;
        }
}
