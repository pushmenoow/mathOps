#ifndef MATHOPERATIONS_H
#define MATHOPERATIONS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class mathOperations; }
QT_END_NAMESPACE

class mathOperations : public QMainWindow
{
    Q_OBJECT

public:
    mathOperations(QWidget *parent = nullptr);
    ~mathOperations();

private slots:
    void detA();
    void eqCalc();
    void clearDefaultDet();
    void clearDefaultFunc();
    void simplifyFunc();
    void hideSimplification();

private:
    Ui::mathOperations *ui;
};
#endif // MATHOPERATIONS_H
