#ifndef COMPANY_H
#define COMPANY_H

#include <QObject>
#include <QString>

class Company
{
public:
    Company(int, QString, int, double);
    int getId() const;
    QString getName() const;
    int getAmout() const;
    double getPrice() const;

    void setId(int);
    void setName(QString);
    void setAmount(int);
    void setPrice(double);
private:
    int id;
    QString name;
    int amount;
    double price;
};

#endif // COMPANY_H
