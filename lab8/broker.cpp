#include "broker.h"

// класс-тип для брокера
Broker::Broker(int id, const QString& name, double money)
    : id(id), name(name), money(money)
{
}

int Broker::getId() const
{
    return id;
}

QString Broker::getName() const
{
    return name;
}

double Broker::getMoney() const
{
    return money;
}

void Broker::setId(int id)
{
    this->id = id;
}

void Broker::setName(const QString& name)
{
    this->name = name;
}

void Broker::setMoney(double money)
{
    this->money = money;
}
