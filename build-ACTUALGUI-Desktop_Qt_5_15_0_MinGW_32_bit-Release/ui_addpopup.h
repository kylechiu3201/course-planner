/********************************************************************************
** Form generated from reading UI file 'addpopup.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPOPUP_H
#define UI_ADDPOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddPopUp
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QComboBox *comboBox_2;
    QLabel *label_5;
    QPushButton *pushButton_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton_3;

    void setupUi(QWidget *AddPopUp)
    {
        if (AddPopUp->objectName().isEmpty())
            AddPopUp->setObjectName(QString::fromUtf8("AddPopUp"));
        AddPopUp->resize(598, 468);
        lineEdit = new QLineEdit(AddPopUp);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(220, 190, 151, 20));
        label = new QLabel(AddPopUp);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 190, 61, 20));
        lineEdit_2 = new QLineEdit(AddPopUp);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(220, 230, 151, 20));
        label_2 = new QLabel(AddPopUp);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 230, 81, 16));
        label_3 = new QLabel(AddPopUp);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(210, 10, 241, 81));
        label_4 = new QLabel(AddPopUp);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(160, 270, 41, 16));
        comboBox = new QComboBox(AddPopUp);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(220, 270, 151, 22));
        pushButton = new QPushButton(AddPopUp);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 340, 75, 23));
        comboBox_2 = new QComboBox(AddPopUp);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(190, 140, 211, 22));
        label_5 = new QLabel(AddPopUp);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(120, 140, 47, 13));
        pushButton_2 = new QPushButton(AddPopUp);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 340, 75, 23));
        label_6 = new QLabel(AddPopUp);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(210, 90, 201, 41));
        label_7 = new QLabel(AddPopUp);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(250, 90, 161, 41));
        label_8 = new QLabel(AddPopUp);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(380, 220, 121, 31));
        pushButton_3 = new QPushButton(AddPopUp);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(440, 140, 101, 23));

        retranslateUi(AddPopUp);

        QMetaObject::connectSlotsByName(AddPopUp);
    } // setupUi

    void retranslateUi(QWidget *AddPopUp)
    {
        AddPopUp->setWindowTitle(QCoreApplication::translate("AddPopUp", "Form", nullptr));
        label->setText(QCoreApplication::translate("AddPopUp", "Major:", nullptr));
        label_2->setText(QCoreApplication::translate("AddPopUp", "Course Number:", nullptr));
        label_3->setText(QCoreApplication::translate("AddPopUp", "<html><head/><body><p><span style=\" font-size:28pt;\">Add Course</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("AddPopUp", "Grade:", nullptr));
        pushButton->setText(QCoreApplication::translate("AddPopUp", "Add", nullptr));
        label_5->setText(QCoreApplication::translate("AddPopUp", "Semester:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AddPopUp", "Done", nullptr));
        label_6->setText(QCoreApplication::translate("AddPopUp", "<html><head/><body><p><span style=\" font-size:14pt; color:#00aa00;\">Sucessfully Added!</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("AddPopUp", "<html><head/><body><p><span style=\" font-size:14pt; color:#ff0000;\">Add Failed!</span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("AddPopUp", "<html><head/><body><p><span style=\" font-size:10pt; color:#ff0000;\">Invalid Number!</span></p></body></html>", nullptr));
        pushButton_3->setText(QCoreApplication::translate("AddPopUp", "Advanced Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPopUp: public Ui_AddPopUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPOPUP_H
