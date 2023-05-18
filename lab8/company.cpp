#include "company.h"

// класс - тип для компании
Company::Company(int id, QString name, int amount, double price)
    :id(id), name(name), amount(amount), price(price)
{}

int Company::getId() const {
    return id;
}
QString Company::getName() const {
    return name;
}
int Company::getAmout() const {
    return amount;
}
double Company::getPrice() const  {
    return price;
}

void Company::setId(int id) {
    this->id = id;
}
void Company::setName(QString name) {
    this->name = name;
}
void Company::setAmount(int amount) {
    this->amount = amount;
}
void Company::setPrice(double price) {
    this->price = price;
}
