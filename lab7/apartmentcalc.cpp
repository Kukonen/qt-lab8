#include "apartmentcalc.h"

ApartmentCalc::ApartmentCalc()
{

}
ApartmentCalc::ApartmentCalc(int area, int residents, int months) {
    this->area = area;
    this->residents = residents;
    this->months = months;
}
// расчёт стоимости
int ApartmentCalc::getCost() {
    int cost = 100;
    cost *= this->area;
    cost *= this->residents;
    switch (this->months) {
        case 0:
        // цена за все 6 месяцев
            cost *= 6;
            break;
        case 1:
        // получаем скидку в 1 месяц при периоде в 12 месяцев
            cost *= 11;
            break;
        case 2:
        // получаем скидку в 2 месяца при периоде в 18 месяцев
            cost *= 16;
            break;
        }
    return cost;
}
