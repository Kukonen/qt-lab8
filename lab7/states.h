#include <QObject>
#include <estate.h>

class States : public QObject
{
    Q_OBJECT
public:
    explicit States(QObject *parent = nullptr);
    ~States();
    void undo();
    bool hasStates();
    Estate *getActualData();
    void add(Estate *value);
    Estate *actualData;
private:
    QList<Estate *> array;
    Estate* getLastData();
signals:
    void notifyObservers();
};
