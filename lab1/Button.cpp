#include <QPushButton>
#include <mainwindow.h>

class Button : public QPushButton {
signals:
    void calculate(char);

private slots:

    void calculation(char);
};

void Button::calculation(char operation) {
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
