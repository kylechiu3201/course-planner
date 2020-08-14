/********************************************************************************
** Form generated from reading UI file 'changepop.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPOP_H
#define UI_CHANGEPOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangePop
{
public:
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label_8;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_6;
    QLineEdit *lineEdit_2;
    QLabel *label_7;
    QComboBox *comboBox;
    QPushButton *pushButton;

    void setupUi(QWidget *ChangePop)
    {
        if (ChangePop->objectName().isEmpty())
            ChangePop->setObjectName(QString::fromUtf8("ChangePop"));
        ChangePop->resize(592, 409);
        label_3 = new QLabel(ChangePop);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 0, 241, 81));
        lineEdit = new QLineEdit(ChangePop);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(210, 150, 151, 20));
        label_2 = new QLabel(ChangePop);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 190, 81, 16));
        label_8 = new QLabel(ChangePop);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(370, 180, 121, 31));
        pushButton_2 = new QPushButton(ChangePop);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 300, 75, 23));
        label_4 = new QLabel(ChangePop);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(150, 230, 41, 16));
        label = new QLabel(ChangePop);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 150, 81, 20));
        label_6 = new QLabel(ChangePop);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(180, 80, 201, 41));
        lineEdit_2 = new QLineEdit(ChangePop);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(210, 190, 151, 20));
        label_7 = new QLabel(ChangePop);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(210, 80, 161, 41));
        comboBox = new QComboBox(ChangePop);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(210, 230, 151, 22));
        pushButton = new QPushButton(ChangePop);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 300, 75, 23));

        retranslateUi(ChangePop);

        QMetaObject::connectSlotsByName(ChangePop);
    } // setupUi

    void retranslateUi(QWidget *ChangePop)
    {
        ChangePop->setWindowTitle(QCoreApplication::translate("ChangePop", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("ChangePop", "<html><head/><body><p><span style=\" font-size:28pt;\">Change Grade</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("ChangePop", "Course Number:", nullptr));
        label_8->setText(QCoreApplication::translate("ChangePop", "<html><head/><body><p><span style=\" font-size:10pt; color:#ff0000;\">Invalid Number!</span></p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ChangePop", "Done", nullptr));
        label_4->setText(QCoreApplication::translate("ChangePop", "Grade:", nullptr));
        label->setText(QCoreApplication::translate("ChangePop", "Course Major:", nullptr));
        label_6->setText(QCoreApplication::translate("ChangePop", "<html><head/><body><p><span style=\" font-size:14pt; color:#00aa00;\">Sucessfully Changed!</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("ChangePop", "<html><head/><body><p><span style=\" font-size:14pt; color:#ff0000;\">Change Failed!</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("ChangePop", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangePop: public Ui_ChangePop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPOP_H
