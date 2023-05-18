#include "estate.h"

Estate::Estate(QObject *parent)
    : QObject{parent}
{

}

// конструктор с заполнением всех полей
Estate::Estate(int age, int area, int residents, int months, int type, QString owner) {
    this->age = age;
    this->area = area;
    this->residents = residents;
    this->months = months;
    // в QComboBox результатом является число порядковый номер
    // значения, поэтому нам необходима структура перевода его в
    // значения enum
    switch (type) {
            case 0:
                this->type = Estate::EstateType::ECONOM;
                break;
            case 1:
                this->type = Estate::EstateType::LUXURIOUS;
                break;
            case 2:
                this->type = Estate::EstateType::TOWN_HOUSE;
                break;
            case 3:
                this->type = Estate::EstateType::COTTAGE;
                break;
        }
    this->owner = owner;
}

// гетеры и сетеры
int Estate::getAge() {
    return this->age;
}
void Estate::setAge(int age) {
    this->age = age;
}
int Estate::getArea() {
    return this->area;
}
void Estate::setArea(int area) {
    this->area = area;
}
int Estate::getResidents() {
    return this->residents;
}
void Estate::setResidents(int residents) {
    this->residents = residents;
}
int Estate::getMonths() {
    return this->months;
}
void Estate::setMonths(int months) {
    this->months = months;
}
Estate::EstateType Estate::getType() {
    return this->type;
}
void Estate::setType(EstateType type) {
    this->type = type;
}
QString Estate::getOwner() {
    return this->owner;
}
void Estate::setOwner(QString owner) {
    this->owner = owner;
}
