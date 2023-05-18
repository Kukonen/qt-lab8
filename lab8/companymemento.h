#ifndef COMPANYMEMENTO_H
#define COMPANYMEMENTO_H

#include <QObject>
#include <company.h>

// часть паттерна Memento, а именно Originator
class CompanyMemento
{
public:
    CompanyMemento();
    CompanyMemento(Company*);
    Company getCompany();
    void setCompany(Company);
private:
    QList<Company> companies;
};

#endif // COMPANYMEMENTO_H
