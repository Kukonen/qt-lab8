#include "dealmediator.h"

DealMediator::DealMediator(DealModel* dealModel, CompanyModel* companyModel, BrokerModel* brokerModel)
{
    this->dealModel = dealModel;
    this->companyModel = companyModel;
    this->brokerModel = brokerModel;
}

// идея type в том, что при значении 's' - происходит продажа, а при 'b' - покупка
void DealMediator::operate(int brokerId, int companyId, int amount, QChar type) {

    QList<Company> companies = companyModel->getCompanies();
    QList<Broker> brokers = brokerModel->getBrokers();
    int companyRow = 0, brokerRow = 0;
    double price;

    // ннаходиим индекс и цену компании с которой происходит сделка
    for (int i = 0; i < companies.count(); ++i) {
        if (companies.at(i).getId() == companyId) {
            companyRow = companies.at(i).getId();
            price = companies.at(i).getPrice();
            // если число акций при покупке < акций которые есть в компании
            if (companies.at(i).getAmout() < amount && type == 'b') {
                return;
            }
        }
    }

    // техническая заминка
    companyRow -= 1;

    // ннаходиим индекс и брокера
    for (int i = 0; i < companies.count(); ++i) {
        if (brokers.at(i).getId() == brokerId) {
            brokerRow = brokers.at(i).getId();
            // если у брокера недостаточно средств
            if (brokers.at(i).getMoney() < price * amount && type == 'b') {
                return;
            }
        }

    }

    // ещё одна техническая заминка
    brokerRow -= 1;

    // если не нашли такую компанию или брокера
    if (companyRow < 0 || companyRow > companies.size() || brokerRow < 0 || brokerRow > brokers.size()) {
        return;
    }



    QString typeString = "Неизвестная ситуация";

    // в зависимости покупаем мы или продаём, увеличиваем
    // или уменьшаем цену и кол-во акций
    // изменяем счёт брокера
    if (type == 'b') {
        typeString = "Покупка";
        companyModel->updateCompany(companyRow,
            Company(companies.at(companyRow).getId(),
                        companies.at(companyRow).getName(),
                        companies.at(companyRow).getAmout() - amount,
                        companies.at(companyRow).getPrice() * 1.1
        ));
        brokerModel->updateBroker(brokerRow,
            Broker(brokers.at(brokerRow).getId(),
                   brokers.at(brokerRow).getName(),
                   brokers.at(brokerRow).getMoney() - price * amount
        ));
    } else if(type == 's') {
        typeString = "Продажа";
        companyModel->updateCompany(companyRow,
            Company(companies.at(companyRow).getId(),
                        companies.at(companyRow).getName(),
                        companies.at(companyRow).getAmout() + amount,
                        companies.at(companyRow).getPrice() * 0.9
        ));
        brokerModel->updateBroker(brokerRow,
            Broker(brokers.at(brokerRow).getId(),
                   brokers.at(brokerRow).getName(),
                   brokers.at(brokerRow).getMoney() + price * amount
        ));
    }


    double cost = price * amount;

    // добавляем сделку
    dealModel->addDeal(Deal(brokerId, companyId, amount, cost, typeString));
}
