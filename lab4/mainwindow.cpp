#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // регулярные выражения для валидации ввода
    QRegularExpression reg("[0-9]+");
    ui->count->setValidator(new QRegularExpressionValidator(reg));

    QRadioButton* r1_1 = ui->r1_1;
    QRadioButton* r1_2 = ui->r1_2;
    QRadioButton* r1_3 = ui->r1_3;

    QRadioButton* r2_1 = ui->r2_1;
    QRadioButton* r2_2 = ui->r2_2;

    QLineEdit* lineEdit = ui->count;

    QPushButton* btn = ui->btn;

    // конекты
    connect(r1_1, &QRadioButton::clicked, this, &MainWindow::clear);
    connect(r1_2, &QRadioButton::clicked, this, &MainWindow::clear);
    connect(r1_3, &QRadioButton::clicked, this, &MainWindow::clear);

    connect(r2_1, &QRadioButton::clicked, this, &MainWindow::clear);
    connect(r2_2, &QRadioButton::clicked, this, &MainWindow::clear);

    connect(lineEdit, &QLineEdit::textChanged, this, &MainWindow::clear);

    connect(btn, &QPushButton::clicked, this, &MainWindow::calculate);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// очищаем результат и скидку при изменении каких-дибо параметов
void MainWindow::clear() {
    ui->result->clear();
    ui->discont->clear();
}

void MainWindow::calculate() {
    int price = ui->count->text().toInt();

    // изменение цены в зависимости от размера фото
    if (ui->r1_1->isChecked()) {
        price *= 20;
    } else if (ui->r1_2->isChecked()) {
        price *= 35;
    } else if (ui->r1_3->isChecked()) {
        price *= 55;
    } else {
        price = 0;
    }

    // изменение цены в зависимости от типа бумаги
    if (ui->r2_1->isChecked()) {
        price *= 10;
    } else if (ui->r2_2->isChecked()) {
        price *= 20;
    } else {
        price = 0;
    }

    // если покупатель заплатит больше 2000, то вывести сообщение о скидки и расчитать скидку
    if (price >= 2000) {
        ui->result->setText(QString::number(price * 0.9) + " рублей");
        ui->discont->setText("Вы получаете спидку 10% (" + QString::number(price * 0.1) + " рублей)");
    } else {
        ui->result->setText(QString::number(price) + " рублей");
    }
}

