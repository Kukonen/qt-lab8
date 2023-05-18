#include "deal.h"

// класс-тип для сделок
Deal::Deal(int brokerId, int companyId, int amount, double cost, QString type)
:brokerId(brokerId), companyId(companyId), amount(amount), cost(cost), type(type)
{ }

int Deal::getBrokerId() const {
    return brokerId;
}
int Deal::getCompanyId() const {
    return companyId;
}
int Deal::getAmout() const {
    return amount;
}
double Deal::getCost() const  {
    return cost;
}

QString Deal::getType() const  {
    return type;
}

void Deal::setBrokerId(int brokerId) {
    this->brokerId = brokerId;
}
void Deal::setCompanyId(int companyId) {
    this->companyId = companyId;
}
void Deal::setAmount(int amount) {
    this->amount = amount;
}
void Deal::setCost(double cost) {
    this->cost = cost;
}
void Deal::setType(QString type) {
    this->type = type;
}
