#ifndef TABLETEMPLATE_H
#define TABLETEMPLATE_H

#include <QObject>
#include <QAbstractTableModel>

class TableTemplate : public QAbstractTableModel
{
public:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;

    void addDeal(const Object& item);
    void removeDeal(int row);
    void updateDeal(int row, const Object& item);
};

#endif // TABLETEMPLATE_H
