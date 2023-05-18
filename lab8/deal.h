#ifndef DEAL_H
#define DEAL_H

#include <QObject>
#include <QString>

class Deal
{
public:
    Deal(int, int, int, double, QString);

    int getBrokerId() const;
    int getCompanyId() const;
    int getAmout() const;
    double getCost() const;
    QString getType() const;

    void setBrokerId(int);
    void setCompanyId(int);
    void setAmount(int);
    void setCost(double);
    void setType(QString);
private:
    int brokerId;
    int companyId;
    int amount;
    double cost;
    QString type;
};

#endif // DEAL_H
