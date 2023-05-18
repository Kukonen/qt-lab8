#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // добавляем значения
    mas.append(3.3);
    mas.append(3.2);
    mas.append(-2.0);
    mas.append(5.);
    mas.append(5.2);
    mas.append(-5.2);
    mas.append(3.3);
    mas.append(3.3);

    // отображаем значения
    showOrigin();
    showModify();

    // регулярные выражения
    QRegularExpression regInt("[0-9]+");
    QRegularExpression regDouble("-?([0-9]*[.])?[0-9]+");
    ui->index_lineEdit->setValidator(new QRegularExpressionValidator(regInt));
    ui->element_qua_lineEdi->setValidator(new QRegularExpressionValidator(regDouble));
    ui->elementNumber_lineEdit->setValidator(new QRegularExpressionValidator(regDouble));

    // получение ссылок на элементы ui
    QPushButton* btn_get_by_index = ui->btn_get_index;
    QPushButton* btn_delete_by_index = ui->btn_delete_index;
    QPushButton* btn_delete_by_qua = ui->btn_delete_qua;

    QPushButton* btn_add = ui->add_btn;
    QPushButton* btn_sum = ui->sum_btn;
    QPushButton* btn_odd_sum = ui->sum_odd_btn;
    QPushButton* btn_sum_zadanie = ui->sum_zadanie;

    QPushButton* btn_getCollection = ui->getCollection_btn;
    QPushButton* btn_saveCollection = ui->saveCollection_btn;
    QPushButton* btn_clearCollection = ui->clearCollection_btn;

    QPushButton* btn_selectFile = ui->selectFile_btn;


    // коннекты
    connect(btn_get_by_index, &QPushButton::clicked, this, &MainWindow::showElementByIndex);
    connect(btn_delete_by_index, &QPushButton::clicked, this, &MainWindow::deleteElementByIndex);
    connect(btn_delete_by_qua, &QPushButton::clicked, this, &MainWindow::deleteElementByQua);

    connect(btn_add, &QPushButton::clicked, this, &MainWindow::addElement);
    connect(btn_sum, &QPushButton::clicked, this, &MainWindow::sumElements);
    connect(btn_odd_sum, &QPushButton::clicked, this, &MainWindow::sumOddElements);
    connect(btn_sum_zadanie, &QPushButton::clicked, this, &MainWindow::sumZadanie);

    connect(btn_getCollection, &QPushButton::clicked, this, &MainWindow::getCollection);
    connect(btn_saveCollection, &QPushButton::clicked, this, &MainWindow::saveCollection);
    connect(btn_clearCollection, &QPushButton::clicked, this, &MainWindow::clearCollection);

    connect(btn_selectFile, &QPushButton::clicked, this, &MainWindow::selectFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// отображение элементов
void MainWindow::showElementByIndex() {
    // получение элементов с ui
    double index = ui->index_lineEdit->text().toInt();
    try {
        if (index >= 0 && index < mas.size()) {
            double num = mas[index];
            ui->element_qua_lineEdi->setText(QString::number(num));
        }
    } catch(...) {

    }
    // отображение элементов
    showOrigin();
    showModify();
}

// удаление элемента по индексу
void MainWindow::deleteElementByIndex() {
    double index = ui->index_lineEdit->text().toInt();
    try {
        mas.removeAt(index);
    } catch(...) {

    }
    // отображение элементов
    showOrigin();
    showModify();
}

// удаление элемента по значению
void MainWindow::deleteElementByQua() {
    double deleted = ui->element_qua_lineEdi->text().toDouble();
    try {
        for (int i = 0; i < mas.size(); ++i) {
            for (int j = 0; j < mas.size(); ++j) {
                if (mas[j] == deleted) {
                    mas.removeAt(j);
                }
            }
        }
    } catch(...) {

    }
    // отображение элементов
    showOrigin();
    showModify();
}

// изначальный спосок всех элементов подряд
void MainWindow::showOrigin() {
    QString st = "";
    for (int i = 0; i < mas.size(); ++i) {
        st += QString::number(mas[i]);
        st += "\n";
    }
    ui->collectionOrigin->setText(st);
}

// отображение по варианту
void MainWindow::showModify() {
    QString st = "";
    for (int i = 0; i < mas.size(); ++i) {
        if (mas[i] < 0) {
            st += QString::number(mas[i]) + "\n";
        }
    }
    for (int i = 0; i < mas.size(); ++i) {
        if (mas[i] == 0) {
            st += QString::number(mas[i]) + "\n";
        }
    }
    for (int i = 0; i < mas.size(); ++i) {
        if (mas[i] > 0) {
            st += QString::number(mas[i]) + "\n";
        }
    }
    ui->collectionEdit->setText(st);
}

// добавление элемента
void MainWindow::addElement() {
    double elem = ui->elementNumber_lineEdit->text().toDouble();

    mas.append(elem);
    // отображение элементов
    showOrigin();
    showModify();
}
// сумма элементов
void MainWindow::sumElements() {
    double sum = 0;
    for (int i = 0; i < mas.size(); ++i) {
        sum += mas[i];
    }

    ui->sum_lineEdit->setText(QString::number(sum));
}
// сумма чётных
void MainWindow::sumOddElements() {
    double sum = 0;
    for (int i = 0; i < mas.size(); ++i) {
        if (fmod(mas[i], 2) == 0 && mas[i] == round(mas[i])) {
            sum += mas[i];
        }
    }

    ui->sum_lineEdit->setText(QString::number(sum));

}

// сумма по заданию
void MainWindow::sumZadanie() {
    double sum = 0, first = 0, second = 0;
    for (int i = 0; i < mas.size(); ++i) {
        if(mas[i] < 0) {
            if (first == 0) {
                first = -1;
            } else {
                break;
            }
        } else {
            if (first != 0) {
                sum += mas[i];
            }
        }
    }

    ui->sum_lineEdit->setText(QString::number(sum));
}

// получение коллекции из файла
void MainWindow::getCollection() {
    QList<double> newList;
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        while(!file.atEnd())
        {
            double num = file.readLine().toDouble();
            newList.append(num);
        }
        file.close();
        mas = newList;
        showOrigin();
        showModify();
    }
}
// сохранение коллекции в файл
void MainWindow::saveCollection() {
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream writeStream(&file);
        for (int i = 0; i < mas.size(); ++i) {
            writeStream << mas[i] << "\n";
        };
        file.close();
    }
}

// уделение всх элементов из коллекции
void MainWindow::clearCollection() {
    mas.clear();
    // отображение элементов
    showOrigin();
    showModify();
}

// функция выбора файла
void MainWindow::selectFile() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open A File", "C://OOP/5");

    file.setFileName(fileName);
}
