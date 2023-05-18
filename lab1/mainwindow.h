#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void clearText();
    void calculate(char);

private slots:
    void on_addBtn_clicked();

    void on_minusBtn_clicked();

    void on_devideBtn_clicked();

    void on_modBtn_clicked();

    void on_multiplyBtn_clicked();

    void on_secondInput_textChanged(const QString &arg1);

    void on_firstInput_textChanged(const QString &arg1);

    void clearResult();

    void calculation(char);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
