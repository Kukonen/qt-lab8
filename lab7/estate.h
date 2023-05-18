#ifndef ESTATE_H
#define ESTATE_H
#include <QObject>
class Estate : public QObject
{
    Q_OBJECT
public:
    enum EstateType {
        ECONOM,
        LUXURIOUS,
        TOWN_HOUSE,
        COTTAGE
    };
    explicit Estate(QObject *parent = nullptr);
    EstateType getType() const;
    Estate(int age, int area, int residents, int months, int type, QString owner);
    int getAge();
    void setAge(int);
    int getArea();
    void setArea(int);
    int getResidents();
    void setResidents(int);
    int getMonths();
    void setMonths(int);
    EstateType getType();
    void setType(EstateType);
    QString getOwner();
    void setOwner(QString);
private:
    int age;
    int area;
    int residents;
    int months;
    EstateType type;
    QString owner;

};
#endif // ESTATE_H
