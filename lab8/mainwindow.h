#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <broker.h>
#include <brokermodel.h>

#include <company.h>
#include <companymodel.h>

#include <deal.h>
#include <dealmodel.h>

#include <dealmediator.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void add_broket_click();
    void delete_broket_click();

    void add_company_click();
    void delete_company_click();
    void undo_company_click();

    void buy_click();
    void sell_click();

private:
    Ui::MainWindow *ui;
    BrokerModel* brokerModel;
    CompanyModel* companyModel;
    DealModel* dealModel;
    DealMediator* dealMediator;
};
#endif // MAINWINDOW_H
