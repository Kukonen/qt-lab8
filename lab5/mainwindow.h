#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QList<double> mas;
    void showOrigin();
    void showModify();
    QFile file;
private slots:
    void showElementByIndex();
    void deleteElementByIndex();
    void deleteElementByQua();

    void addElement();
    void sumElements();
    void sumOddElements();
    void sumZadanie();

    void getCollection();
    void saveCollection();
    void clearCollection();

    void selectFile();
};
#endif // MAINWINDOW_H
