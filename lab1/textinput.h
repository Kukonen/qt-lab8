#ifndef TEXTINPUT_H
#define TEXTINPUT_H

#include <QWidget>

namespace Ui {
class TextInput;
}

class TextInput : public QWidget
{
    Q_OBJECT

public:
    explicit TextInput(QWidget *parent = nullptr);
    ~TextInput();

private:
    Ui::TextInput *ui;
};

#endif // TEXTINPUT_H
