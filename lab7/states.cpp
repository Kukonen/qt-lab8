#include "states.h"
States::States(QObject *parent) : QObject(parent)
{
    actualData = nullptr;
}
States::~States()
{
    // delete: actualData
    if(actualData){
        delete actualData;
        actualData = nullptr;
    }
    // delete and cleare: arra
        qDeleteAll(array);
        array.clear();
}

// кнопка возвращения
void States::undo(){
    if (hasStates()) {
        actualData = getLastData();
        array.removeAt(array.size() - 1);
    } else {
        actualData = nullptr;
    }
    // обновление
    emit notifyObservers();
}

// проверка есть ли предыдущие запомненые действия
bool States::hasStates(){
    return !array.empty();
}

// получение последнего добавленного элемента
Estate* States::getLastData(){
    return array.at(array.size() - 1);
}

Estate* States::getActualData(){
    return actualData;
}

// добавление нового запоминаемого значения
void States::add(Estate *value){
    if (actualData != nullptr) {
        array.append(actualData);
    }

    actualData = value;
}
