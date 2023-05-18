#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpressionValidator>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // задаём регулярное выражение и привязываем к нему валидатор для проверки вводимого текста
    QRegularExpression reg("-?([0-9]*[.])?[0-9]+");
    ui->firstInput->setValidator(new QRegularExpressionValidator(reg));
    ui->secondInput->setValidator(new QRegularExpressionValidator(reg));

    // конекты для очистки текста и вычисления значения
    connect(this, SIGNAL(clearText()), this, SLOT(clearResult()));
    connect(this, SIGNAL(calculate(char)), this, SLOT(calulation(char)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// вызов сигнала
void MainWindow::on_addBtn_clicked()
{
    emit calculation('+');
}

// вызов сигнала
void MainWindow::on_minusBtn_clicked()
{
    emit calculation('-');
}

// вызов сигнала
void MainWindow::on_devideBtn_clicked()
{
    emit calculation('/');
}

// вызов сигнала
void MainWindow::on_modBtn_clicked()
{
    emit calculation('%');
}

// вызов сигнала
void MainWindow::on_multiplyBtn_clicked()
{
    emit calculation('*');
}

// функция вычисления
void MainWindow::calculation(char operation) {
    // получение чисел с полей в double типе
    double firstNumber = ui->firstInput->text().toDouble();
    double secondNumber = ui->secondInput->text().toDouble();
    double result = 0;

    // операция сложения
    if (operation == '+') {
        result = firstNumber + secondNumber;
        ui->resultInput->setText(QString::number(result));
    }

    // операция вычитания
    if (operation == '-') {
        result = firstNumber - secondNumber;
        ui->resultInput->setText(QString::number(result));
    }

    // операция умножения
    if (operation == '*') {
        result = firstNumber * secondNumber;
        ui->resultInput->setText(QString::number(result));
    }


    // операция деления
    if (operation == '/') {
        if (secondNumber == 0) {
            ui->resultInput->setText("деление на 0");
        } else {
            result = firstNumber / secondNumber;
            ui->resultInput->setText(QString::number(result));
        }
    }

    // операция получения остатка
    if (operation == '%') {
        if (secondNumber == 0) {
            ui->resultInput->setText("деление на 0");
        } else {
            result = fmod(firstNumber, secondNumber);
            ui->resultInput->setText(QString::number(result));
        }
    }

}

// вызов сигнала
void MainWindow::on_secondInput_textChanged(const QString &arg1)
{
    emit clearText();
}


// вызов сигнала
void MainWindow::on_firstInput_textChanged(const QString &arg1)
{
    emit clearText();
}

// функция очищает результат вычислений
void MainWindow::clearResult() {
    ui->resultInput->clear();
}

