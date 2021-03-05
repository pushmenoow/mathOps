#include "mathoperations.h"
#include "ui_mathoperations.h"
#include "QString"
#include <math.h>

mathOperations::mathOperations(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mathOperations)
{
    QWidget::setFixedSize(344, 390);
    ui->setupUi(this);

    //Determinant connections
    connect(ui->buttonCalcDet, SIGNAL(clicked()), this, SLOT(detA()));
    connect(ui->buttonClearDet, SIGNAL(clicked()), this, SLOT(clearDefaultDet()));
    connect(ui->buttonCloseDet, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));

    //Function connections
    connect(ui->buttonCalcFunc, SIGNAL(clicked()), this, SLOT(eqCalc()));
    connect(ui->buttonClearFunc, SIGNAL(clicked()), this, SLOT(clearDefaultFunc()));
    connect(ui->buttonCloseFunc, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
    connect(ui->buttonSimplifyFunc, SIGNAL(clicked()), this, SLOT(simplifyFunc()));
    connect(ui->buttonHideSimplification, SIGNAL(clicked()), this, SLOT(hideSimplification()));

    //Visibility turning off for function tab
    ui->buttonHideSimplification->setVisible(false);
    ui->labelNote->setVisible(false);
    ui->label_18->setVisible(false); ui->label_19->setVisible(false);
    ui->label_20->setVisible(false); ui->label_21->setVisible(false);
    ui->label_22->setVisible(false); ui->label_23->setVisible(false);
    ui->label_24->setVisible(false); ui->label_25->setVisible(false);
    ui->label_26->setVisible(false); ui->label_27->setVisible(false);
    ui->label_28->setVisible(false); ui->label_29->setVisible(false);
    ui->label_30->setVisible(false); ui->label_31->setVisible(false);
    ui->label_32->setVisible(false); ui->label_33->setVisible(false);
    ui->label_37->setVisible(false); ui->label_39->setVisible(false);
    ui->label_40->setVisible(false); ui->label_41->setVisible(false);
}

//Determinant logic
void mathOperations::detA()
{
    QString a, b, c, d, e, f, g, h, i;
    double mas[9];

    //Filling matrix with values
    a = ui->lineEditA->text(); mas[0] = a.toDouble();
    b = ui->lineEditB->text(); mas[1] = b.toDouble();
    c = ui->lineEditC->text(); mas[2] = c.toDouble();
    d = ui->lineEditD->text(); mas[3] = d.toDouble();
    e = ui->lineEditE->text(); mas[4] = e.toDouble();
    f = ui->lineEditF->text(); mas[5] = f.toDouble();
    g = ui->lineEditG->text(); mas[6] = g.toDouble();
    h = ui->lineEditH->text(); mas[7] = h.toDouble();
    i = ui->lineEditI->text(); mas[8] = i.toDouble();

    //Determinant calculation
    double det = mas[0] * mas[4] * mas[8] +
                 mas[1] * mas[5] * mas[6] +
                 mas[2] * mas[3] * mas[7] -
                 mas[2] * mas[4] * mas[6] -
                 mas[1] * mas[3] * mas[8] -
                 mas[0] * mas[5] * mas[7];

    //Determinant output
    ui->labelOpsDet->setText(QString::number(mas[0], 'f', 2) + " * " +
                      QString::number(mas[4], 'f', 2) + " * " +
                      QString::number(mas[8], 'f', 2) + " +\n" +
                      QString::number(mas[1], 'f', 2) + " * " +
                      QString::number(mas[5], 'f', 2) + " * " +
                      QString::number(mas[6], 'f', 2) + " +\n" +
                      QString::number(mas[2], 'f', 2) + " * " +
                      QString::number(mas[3], 'f', 2) + " * " +
                      QString::number(mas[7], 'f', 2) + " -\n" +
                      QString::number(mas[2], 'f', 2) + " * " +
                      QString::number(mas[4], 'f', 2) + " * " +
                      QString::number(mas[6], 'f', 2) + " -\n" +
                      QString::number(mas[1], 'f', 2) + " * " +
                      QString::number(mas[3], 'f', 2) + " * " +
                      QString::number(mas[8], 'f', 2) + " -\n" +
                      QString::number(mas[0], 'f', 2) + " * " +
                      QString::number(mas[5], 'f', 2) + " * " +
                      QString::number(mas[7], 'f', 2) + " = ");
    ui->labelResultDet->setText("= " + QString::number(det, 'f', 2));
}

//Function logic
void mathOperations::eqCalc()
{
   double a = ui->lineEditInputFunc->text().toDouble();
   if(a == 0) {
       ui->labelResultFunc->setText("f(" + QString::number(a) + ") is NaN (Not-a-Number)");
   } else {
       double sx = (qSin(M_PI * a)) / (2 * a);
       double fx = qTan(sx);
       ui->labelResultFunc->setText("f(" + QString::number(a) + ") = " + QString::number(fx, 'f', 8));
   }
}

//Clear Determinant Button
void mathOperations::clearDefaultDet()
{
    ui->lineEditA->setText("0");
    ui->lineEditB->setText("0");
    ui->lineEditC->setText("0");
    ui->lineEditD->setText("0");
    ui->lineEditE->setText("0");
    ui->lineEditF->setText("0");
    ui->lineEditG->setText("0");
    ui->lineEditH->setText("0");
    ui->lineEditI->setText("0");
    ui->labelOpsDet->setText("");
    ui->labelResultDet->setText("");
}

//Clear Function Button
void mathOperations::clearDefaultFunc()
{
    ui->labelResultFunc->setText("f(x) =");
    ui->lineEditInputFunc->setText("0");
}

//Simplify Function Button
void mathOperations::simplifyFunc()
{

    //Visibility turning on for function tab
    ui->buttonSimplifyFunc->setVisible(false);
    ui->buttonHideSimplification->setVisible(true);
    ui->labelNote->setVisible(true);
    ui->label_18->setVisible(true); ui->label_19->setVisible(true);
    ui->label_20->setVisible(true); ui->label_21->setVisible(true);
    ui->label_22->setVisible(true); ui->label_23->setVisible(true);
    ui->label_24->setVisible(true); ui->label_25->setVisible(true);
    ui->label_26->setVisible(true); ui->label_27->setVisible(true);
    ui->label_28->setVisible(true); ui->label_29->setVisible(true);
    ui->label_30->setVisible(true); ui->label_31->setVisible(true);
    ui->label_32->setVisible(true); ui->label_33->setVisible(true);
    ui->label_37->setVisible(true); ui->label_39->setVisible(true);
    ui->label_40->setVisible(true); ui->label_41->setVisible(true);

    ui->groupFunc->setGeometry(10, 5, 311, 145);
    ui->groupCalcResultFunc->setGeometry(10, 255, 311, 56);
    ui->groupInputDefFunc->setGeometry(10, 190, 311, 56);
    ui->labelResultFunc->setGeometry(10, 23, 291, 20);
    ui->labelEqualsInputFunc->setGeometry(10, 23, 30, 20);
    ui->lineEditInputFunc->setGeometry(30, 23, 80, 20);
}

//Hide Simplification Button
void mathOperations::hideSimplification()
{
    ui->groupFunc->setGeometry(10, 5, 311, 70);
    ui->groupCalcResultFunc->setGeometry(10, 218, 311, 93);
    ui->groupInputDefFunc->setGeometry(10, 120, 311, 93);
    ui->labelResultFunc->setGeometry(10, 40, 291, 20);
    ui->labelEqualsInputFunc->setGeometry(10, 40, 30, 20);
    ui->lineEditInputFunc->setGeometry(30, 40, 80, 20);

    //Visibility turning off for function tab
    ui->buttonSimplifyFunc->setVisible(true);
    ui->buttonHideSimplification->setVisible(false);
    ui->labelNote->setVisible(false);
    ui->label_18->setVisible(false); ui->label_19->setVisible(false);
    ui->label_20->setVisible(false); ui->label_21->setVisible(false);
    ui->label_22->setVisible(false); ui->label_23->setVisible(false);
    ui->label_24->setVisible(false); ui->label_25->setVisible(false);
    ui->label_26->setVisible(false); ui->label_27->setVisible(false);
    ui->label_28->setVisible(false); ui->label_29->setVisible(false);
    ui->label_30->setVisible(false); ui->label_31->setVisible(false);
    ui->label_32->setVisible(false); ui->label_33->setVisible(false);
    ui->label_37->setVisible(false); ui->label_39->setVisible(false);
    ui->label_40->setVisible(false); ui->label_41->setVisible(false);
}

mathOperations::~mathOperations()
{
    delete ui;
}
