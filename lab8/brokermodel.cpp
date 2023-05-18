#include "brokermodel.h"

BrokerModel::BrokerModel(QObject* parent)
    : QAbstractTableModel(parent)
{
}

// количество строк
int BrokerModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return brokers.count();
}

// количество столбцов
int BrokerModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return 3;
}
// данные о строках в таблице
QVariant BrokerModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= brokers.count() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        const Broker& broker = brokers.at(index.row());

        if (index.column() == 0)
            return broker.getId();
        else if (index.column() == 1)
            return broker.getName();
        else if (index.column() == 2)
            return broker.getMoney();
    }

    return QVariant();
}
// заголовки в таблицах
QVariant BrokerModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
    {
        if (section == 0)
            return tr("id");
        else if (section == 1)
            return tr("Имя");
        else if (section == 2)
            return tr("Счёт");
    }

    return QVariant();
}
// установка данных в таблице
bool BrokerModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
        int row = index.row();
        Broker& broker = brokers[row];

        if (index.column() == 0)
            broker.setId(value.toInt());
        else if (index.column() == 1)
            broker.setName(value.toString());
        else if (index.column() == 2)
            broker.setMoney(value.toDouble());

        emit dataChanged(index, index, { Qt::DisplayRole, Qt::EditRole });
        return true;
    }

    return false;
}

// установки (настройки) данных о таблице (то что её можно редактировать)
Qt::ItemFlags BrokerModel::flags(const QModelIndex& index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}
// добавление брокера в таблицу
void BrokerModel::addBroker(const Broker& broker)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    brokers.append(broker);
    endInsertRows();
}
// удаление брокера из таблицы
void BrokerModel::removeBroker(int row)
{
    beginRemoveRows(QModelIndex(), row, row);
    brokers.removeAt(row);
    endRemoveRows();
}
// обновление данных о брокере в таблице
void BrokerModel::updateBroker(int row, const Broker& broker)
{
    brokers[row] = broker;
    QModelIndex topLeft = index(row, 0);
    QModelIndex bottomRight = index(row, columnCount() - 1);
    emit dataChanged(topLeft, bottomRight, { Qt::DisplayRole, Qt::EditRole });
}

// получение списка брокеров
QList<Broker> BrokerModel::getBrokers() {
    return brokers;
}

