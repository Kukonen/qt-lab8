#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btnUndo->setEnabled(false);

    // регистрация слушателя
     connect(&info, SIGNAL(notifyObservers()), this, SLOT(update()));
     connect(ui->btnCalc, SIGNAL(pressed()), this, SLOT(btnCalcPressed()));
     connect(ui->btnUndo, SIGNAL(pressed()), this, SLOT(btnUndoPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::update()
{
    auto value = info.getActualData();
    if(value != nullptr){
        fillForm(value);
    }
    // update btnUndo state
    ui->btnUndo->setEnabled(info.hasStates());
    showCost(value);
    // setting value to NULL
    value = nullptr;
}
// private slots
void MainWindow::btnCalcPressed()
{
    auto value = processForm();
    if (value != nullptr) {
        showCost(value);
        info.add(value);
        ui->btnUndo->setEnabled(true);
        // setting value to NULL
        value = nullptr;
    }
}
void MainWindow::btnUndoPressed()
{
    info.undo();
}

// private
Estate *MainWindow::processForm()
{
    QString owner = ui->owner->text();
    QString age = ui->age->text();
    QString residents = ui->residents->text();
    QString area = ui->area->text();
    int period = ui->period->currentIndex();
    int estateType = ui->estateType->currentIndex();
    return new Estate(age.toInt(), area.toInt(), residents.toInt(), period, estateType, owner);
}

// заполняем форму
void MainWindow::fillForm(Estate *value)
{
    // вносим значения в поля формы
    ui->residents->setText(QString::number(value->getResidents()));
    ui->owner->setText(value->getOwner());
    ui->age->setText(QString::number(value->getAge()));
    ui->area->setText(QString::number(value->getArea()));
    ui->period->setCurrentIndex(value->getMonths());
    // взависимости от type значения enum изменяем значение QComboBox
    switch (value->getType()) {
            case Estate::EstateType::ECONOM:
                ui->estateType->setCurrentIndex(0);
                break;
            case Estate::EstateType::LUXURIOUS:
                ui->estateType->setCurrentIndex(1);
                break;
            case Estate::EstateType::TOWN_HOUSE:
                ui->estateType->setCurrentIndex(2);
                break;
            case Estate::EstateType::COTTAGE:
                ui->estateType->setCurrentIndex(3);
                break;
        }
}

void MainWindow::showCost(Estate *value)
{
    // получаем стоимость из фасада
    ui->cost->setText(QString::number(CalculationFacade::getCost(value)));
}

