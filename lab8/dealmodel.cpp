#include "dealmodel.h"

DealModel::DealModel(QObject* parent)
    : QAbstractTableModel(parent)
{
}

// количество строк
int DealModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return deals.count();
}

// количество столбцов
int DealModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return 5;
}

// информация о сделках в табблице
QVariant DealModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= deals.count() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        const Deal& deal = deals.at(index.row());

        if (index.column() == 0)
            return deal.getBrokerId();
        else if (index.column() == 1)
            return deal.getCompanyId();
        else if (index.column() == 2)
            return deal.getAmout();
        else if (index.column() == 3)
            return deal.getCost();
        else if (index.column() == 4)
            return deal.getType();
    }

    return QVariant();
}

// заголовки таблицы
QVariant DealModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
    {
        if (section == 0)
            return tr("id брокера");
        else if (section == 1)
            return tr("id компании");
        else if (section == 2)
            return tr("Количество");
        else if (section == 3)
            return tr("Сумма сделки");
        else if (section == 4)
            return tr("Тип");
    }

    return QVariant();
}

// установка значений в таблицу
bool DealModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
        int row = index.row();
        Deal& deal = deals[row];

        if (index.column() == 0)
            deal.setBrokerId(value.toInt());
        else if (index.column() == 1)
            deal.setCompanyId(value.toInt());
        else if (index.column() == 2)
            deal.setAmount(value.toInt());
        else if (index.column() == 3)
            deal.setCost(value.toDouble());
        else if (index.column() == 4)
            deal.setType(value.toString());

        emit dataChanged(index, index, { Qt::DisplayRole, Qt::EditRole });
        return true;
    }

    return false;
}

// настройки таблицы (здесь мы уже делаем её не редактируемой)
Qt::ItemFlags DealModel::flags(const QModelIndex& index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index);
}

// добавляем сделку
void DealModel::addDeal(const Deal& deal)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    deals.append(deal);
    endInsertRows();
}

// удаляем сделку
void DealModel::removeDeal(int row)
{
    beginRemoveRows(QModelIndex(), row, row);
    deals.removeAt(row);
    endRemoveRows();
}

// обновляем сделку
void DealModel::updateDeal(int row, const Deal& deal)
{
    deals[row] = deal;
    QModelIndex topLeft = index(row, 0);
    QModelIndex bottomRight = index(row, columnCount() - 1);
    emit dataChanged(topLeft, bottomRight, { Qt::DisplayRole, Qt::EditRole });
}
