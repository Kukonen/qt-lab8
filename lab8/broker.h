#ifndef BROKER_H
#define BROKER_H

#include <QObject>

class Broker
{
public:
    Broker(int id, const QString& name, double money);

    int getId() const;
    QString getName() const;
    double getMoney() const;

    void setId(int id);
    void setName(const QString& name);
    void setMoney(double money);

private:
    int id;
    QString name;
    double money;
};

#endif // BROKER_H
