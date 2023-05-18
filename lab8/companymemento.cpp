#include "companymemento.h"

CompanyMemento::CompanyMemento() {}
CompanyMemento::CompanyMemento(Company* company)
{
    this->companies.append(Company(
                               company->getId(),
                               company->getName(),
                               company->getAmout(),
                               company->getPrice()
                           ));
}
// получение удалённой компании и
// удаление ей из списка удалённых
Company CompanyMemento::getCompany() {
    Company company = Company(
                companies.last().getId(),
                companies.last().getName(),
                companies.last().getAmout(),
                companies.last().getPrice()
            );
    companies.removeLast();
    return company;
}

// добавление в список удалённых компаний
void CompanyMemento::setCompany(Company company) {
    this->companies.append(company);
}
