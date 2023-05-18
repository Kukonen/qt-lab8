#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // инициализация таблицы брокера
    brokerModel = new BrokerModel(this);
    brokerModel->addBroker(Broker(1, "John", 1000.0));
    brokerModel->addBroker(Broker(2, "Jane", 2000.0));
    brokerModel->addBroker(Broker(3, "Bob", 3000.0));
    ui->tableBroker->setModel(brokerModel);

    // инициализация таблицы компании
    companyModel = new CompanyModel(this);
    companyModel->addCompany(Company(1, "Apple", 10000, 140.0));
    companyModel->addCompany(Company(2, "Amazon", 300000, 2500.0));
    companyModel->addCompany(Company(3, "Microsoft", 200, 30.0));
    ui->tableCompany->setModel(companyModel);


    // инициализация таблице сделок
    dealModel = new DealModel(this);
    ui->tableDeal->setModel(dealModel);

    // иннициализация объекта для паттерна медиатора
    dealMediator = new DealMediator(dealModel, companyModel, brokerModel);

    // конекты
    connect(ui->add_broker_btn, &QPushButton::clicked, this, &MainWindow::add_broket_click);
    connect(ui->delete_broker_btn, &QPushButton::clicked, this, &MainWindow::delete_broket_click);

    connect(ui->add_company_btn, &QPushButton::clicked, this, &MainWindow::add_company_click);
    connect(ui->delete_company_btn, &QPushButton::clicked, this, &MainWindow::delete_company_click);
    connect(ui->undo_company_btn, &QPushButton::clicked, this, &MainWindow::undo_company_click);

    connect(ui->buy_btn, &QPushButton::clicked, this, &MainWindow::buy_click);
    connect(ui->sell_btn, &QPushButton::clicked, this, &MainWindow::sell_click);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// кнопка добавления брокера
void MainWindow::add_broket_click() {
    int newId = brokerModel->rowCount() + 1;
    brokerModel->addBroker(Broker(newId, "", 0.0));
}
// кнопка удаления брокера
void MainWindow::delete_broket_click() {
    brokerModel->removeBroker(0);
}

// кнопка добавления компании
void MainWindow::add_company_click() {
    int newId = companyModel->rowCount() + 1;
    companyModel->addCompany(Company(newId, "", 0, 0.0));
}

// кнопка удаления компании
void MainWindow::delete_company_click() {
    companyModel->removeCompany(0);
}
// кнопка возвращения удалённой компании
void MainWindow::undo_company_click() {
    companyModel->undo();
}
// кнопка сделки - покупки
void MainWindow::buy_click() {
    int brokerId = ui->brokerInput->text().toInt();
    int companyId = ui->companyInput->text().toInt();
    int amount = ui->amountInput->text().toInt();
    dealMediator->operate(brokerId, companyId, amount, 'b');
}
// кнопка сделки - продажи
void MainWindow::sell_click() {
    int brokerId = ui->brokerInput->text().toInt();
    int companyId = ui->companyInput->text().toInt();
    int amount = ui->amountInput->text().toInt();
    dealMediator->operate(brokerId, companyId, amount, 's');
}


