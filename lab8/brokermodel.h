#ifndef BROKERMODEL_H
#define BROKERMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include <QList>
#include "broker.h"

class BrokerModel : public QAbstractTableModel
{
public:
    BrokerModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;

    void addBroker(const Broker& broker);
    void removeBroker(int row);
    void updateBroker(int row, const Broker& broker);

    QList<Broker> getBrokers();

private:
    QList<Broker> brokers;
};

#endif // BROKERMODEL_H
