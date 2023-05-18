#include "companymodel.h"

CompanyModel::CompanyModel(QObject* parent)
    : QAbstractTableModel(parent)
{
}

QList<Company> CompanyModel::getCompanies() {
    return companies;
}

// кол-во строчек
int CompanyModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return companies.count();
}

// кол-во столбцов
int CompanyModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return 4;
}

// информация о строке
QVariant CompanyModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= companies.count() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        const Company& company = companies.at(index.row());

        if (index.column() == 0)
            return company.getId();
        else if (index.column() == 1)
            return company.getName();
        else if (index.column() == 2)
            return company.getAmout();
        else if (index.column() == 3)
            return company.getPrice();
    }

    return QVariant();
}

// заголовки таблицы
QVariant CompanyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
    {
        if (section == 0)
            return tr("id");
        else if (section == 1)
            return tr("Название компании");
        else if (section == 2)
            return tr("К-во акций");
        else if (section == 3)
            return tr("Цена");
    }

    return QVariant();
}

// установление данных в строку
bool CompanyModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
        int row = index.row();
        Company& company = companies[row];

        if (index.column() == 0)
            company.setId(value.toInt());
        else if (index.column() == 1)
            company.setName(value.toString());
        else if (index.column() == 2)
            company.setAmount(value.toInt());
        else if (index.column() == 3)
            company.setPrice(value.toDouble());

        emit dataChanged(index, index, { Qt::DisplayRole, Qt::EditRole });
        return true;
    }

    return false;
}

// настройки таблицы (возможность редактирования)
Qt::ItemFlags CompanyModel::flags(const QModelIndex& index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

// добавление компании в таблицу
void CompanyModel::addCompany(const Company& broker)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    companies.append(broker);
    endInsertRows();
}

// удаление компании из таблицы
void CompanyModel::removeCompany(int row)
{
    Company company = Company(
                companies.at(row).getId(),
                companies.at(row).getName(),
                companies.at(row).getAmout(),
                companies.at(row).getPrice()
            );
    companyMemento.setCompany(companies.at(row));
    beginRemoveRows(QModelIndex(), row, row);
    companies.removeAt(row);
    endRemoveRows();
}

// обновление строки с компанией
void CompanyModel::updateCompany(int row, const Company& broker)
{
    companies[row] = broker;
    QModelIndex topLeft = index(row, 0);
    QModelIndex bottomRight = index(row, columnCount() - 1);
    emit dataChanged(topLeft, bottomRight, { Qt::DisplayRole, Qt::EditRole });
}

// возвращение удалённой компании
void CompanyModel::undo()
{
    Company company = companyMemento.getCompany();
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    companies.append(company);
    endInsertRows();
}
