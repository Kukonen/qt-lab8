#ifndef DEALMEDIATOR_H
#define DEALMEDIATOR_H

#include <QObject>
#include <dealmodel.h>
#include <deal.h>
#include <broker.h>
#include <brokermodel.h>
#include <companymodel.h>
#include <QChar>
#include <QList>
#include <company.h>

class DealMediator
{
public:
    DealMediator(DealModel*, CompanyModel*, BrokerModel*);
    void operate(int, int, int, QChar);
private:
    DealModel* dealModel;
    CompanyModel* companyModel;
    BrokerModel* brokerModel;
};

#endif // DEALMEDIATOR_H
