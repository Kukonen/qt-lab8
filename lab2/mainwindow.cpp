#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCheckBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // подсказки при наведении
    ui->c1->setToolTip("100 рублей");
    ui->c2->setToolTip("200 рублей");
    ui->c3->setToolTip("300 рублей");
    ui->c4->setToolTip("400 рублей");
    ui->c5->setToolTip("500 рублей");
    ui->c6->setToolTip("600 рублей");

    // обявление checkbox'ов
    QCheckBox* c1 = ui->c1;
    QCheckBox* c2 = ui->c2;
    QCheckBox* c3 = ui->c3;
    QCheckBox* c4 = ui->c4;
    QCheckBox* c5 = ui->c5;
    QCheckBox* c6 = ui->c6;

    // конекты для каждого checkbox'а
    connect(c1, &QCheckBox::stateChanged, this, &MainWindow::changePrice);
    connect(c2, &QCheckBox::stateChanged, this, &MainWindow::changePrice);
    connect(c3, &QCheckBox::stateChanged, this, &MainWindow::changePrice);
    connect(c4, &QCheckBox::stateChanged, this, &MainWindow::changePrice);
    connect(c5, &QCheckBox::stateChanged, this, &MainWindow::changePrice);
    connect(c6, &QCheckBox::stateChanged, this, &MainWindow::changePrice);
}

// функция изменения цены
void MainWindow::changePrice() {

    int price = 0;
    QString check = "Автомобиль 40000 рублей\n";
    int discontPrice = 0;

    // проверяем активин ли checkbox, если активен, то
    // прибавляем к общей цене стоимость товара и
    // приписываем в чек эту позицию
    if (ui->c1->checkState()) {
        price += 100;
        check += "Шины 100 рублей\n";
    }
    if (ui->c2->checkState()) {
        price += 200;
        check += "Диски 200 рублей\n";
    }
    if (ui->c3->checkState()) {
        price += 300;
        check += "Каско 300 рублей\n";
    }
    if (ui->c4->checkState()) {
        price += 400;
        check += "ОСАГО 400 рублей\n";
    }
    if (ui->c5->checkState()) {
        price += 500;
        check += "Кондиционер 500 рублей\n";
    }
    if (ui->c6->checkState()) {
        price += 600;
        check += "Сигнализация 600 рублей\n";
    }

    // проверяем взяты ли все комплектующие, если да, то
    // отображаем уведомление о скидке и уменьшаем цену на 10%,
    if (price == 2100) {
        ui->discont->setText("Вы получаете скидку 10% в " + QString::number(price * 0.1) + " рублей");
        discontPrice = price * 0.9;
        // прибавляем цену автомобиля
        discontPrice += 40000;
        ui->discontPrice->setText("Итог: " + QString::number(discontPrice) + " рублей");
    } else {
        ui->discont->clear();
        ui->discontPrice->clear();
    }

    // прибавляем цену автомобиля
    price += 40000;

    // отображаем цену и чек
    ui->price->setText(QString::number(price) + " рублей");
    ui->check->setText(check);
}

MainWindow::~MainWindow()
{
    delete ui;
}
