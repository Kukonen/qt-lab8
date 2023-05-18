#ifndef COMPANYMODEL_H
#define COMPANYMODEL_H

#include <QObject>
#include <company.h>
#include <companymemento.h>
#include <QAbstractTableModel>

class CompanyModel  : public QAbstractTableModel
{
public:
    CompanyModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;

    void addCompany(const Company& broker);
    void removeCompany(int row);
    void updateCompany(int row, const Company& broker);
    void undo();

    QList<Company> getCompanies();

private:
    QList<Company> companies;
    //QList<Company> deletedCompanies;
    CompanyMemento companyMemento;
};

#endif // COMPANYMODEL_H
