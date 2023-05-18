#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    // задаём регулярное выражение и привязываем к нему валидатор для проверки вводимого текста
    QRegularExpression reg("([0-9]*[.])?[0-9]+");
    ui->height->setValidator(new QRegularExpressionValidator(reg));
    ui->wight->setValidator(new QRegularExpressionValidator(reg));

    QComboBox* type = ui->type;
    QPushButton *btn = ui->btn;

    QLineEdit *ledit1 = ui->height;
    QLineEdit *ledit2 = ui->wight;

    // конекты
    connect(type, &QComboBox::currentIndexChanged, this, &MainWindow::changePriceByType);
    connect(btn, &QPushButton::clicked, this, &MainWindow::calculate);

    connect(ledit1, &QLineEdit::textChanged, this, &MainWindow::clearResult);
    connect(ledit2, &QLineEdit::textChanged, this, &MainWindow::clearResult);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// показываем стоимость при изменении QComboBox
void MainWindow::changePriceByType(int index) {
    if (index == 0) {
        ui->cost->setText("100 рублей");
    }
    if (index == 1) {
        ui->cost->setText("200 рублей");
    }
    if (index == 2) {
        ui->cost->setText("300 рублей");
    }
    ui->result->clear();
}

void MainWindow::calculate() {
    double height = ui->height->text().toDouble();
    double width = ui->wight->text().toDouble();

    // смотрим можно ли отрезать корректный кусок ткани
    if (fmod(height, 0.5) != 0 || fmod(width, 0.5) != 0) {
        ui->result->setText("Мы не сможем продать рулон с такими габаритами");
        return;
    }

    // Измеряем размер ткани и расчитываем стоимость в зависимости от цены
    double size =height * width;
    int currentIndex = ui->type->currentIndex();
    if (currentIndex == 0) {
        ui->result->setText("Итоговая стоимость: " + QString::number(size*100) + " рублей");
    }
    if (currentIndex == 1) {
        ui->result->setText("Итоговая стоимость: " + QString::number(size*200) + " рублей");
    }
    if (currentIndex == 2) {
        ui->result->setText("Итоговая стоимость: " + QString::number(size*300) + " рублей");
    }
}

// очищаем поле результата при изменении какого-либо параметра
void MainWindow::clearResult() {
    ui->result->clear();
}
