/********************************************************************************
** Form generated from reading UI file 'removepopup.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOVEPOPUP_H
#define UI_REMOVEPOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RemovePopUp
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_7;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit_2;

    void setupUi(QWidget *RemovePopUp)
    {
        if (RemovePopUp->objectName().isEmpty())
            RemovePopUp->setObjectName(QString::fromUtf8("RemovePopUp"));
        RemovePopUp->resize(582, 455);
        pushButton = new QPushButton(RemovePopUp);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 330, 75, 23));
        lineEdit = new QLineEdit(RemovePopUp);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(210, 180, 151, 20));
        label_3 = new QLabel(RemovePopUp);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 10, 261, 81));
        label_6 = new QLabel(RemovePopUp);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(200, 80, 201, 41));
        label_2 = new QLabel(RemovePopUp);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 220, 81, 16));
        pushButton_2 = new QPushButton(RemovePopUp);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 330, 75, 23));
        label_5 = new QLabel(RemovePopUp);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(110, 130, 47, 13));
        label = new QLabel(RemovePopUp);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 180, 61, 20));
        label_7 = new QLabel(RemovePopUp);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(240, 80, 161, 41));
        comboBox_2 = new QComboBox(RemovePopUp);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(180, 130, 211, 22));
        lineEdit_2 = new QLineEdit(RemovePopUp);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(210, 220, 151, 20));

        retranslateUi(RemovePopUp);

        QMetaObject::connectSlotsByName(RemovePopUp);
    } // setupUi

    void retranslateUi(QWidget *RemovePopUp)
    {
        RemovePopUp->setWindowTitle(QCoreApplication::translate("RemovePopUp", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("RemovePopUp", "Remove", nullptr));
        label_3->setText(QCoreApplication::translate("RemovePopUp", "<html><head/><body><p><span style=\" font-size:28pt;\">Remove Course</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("RemovePopUp", "<html><head/><body><p><span style=\" font-size:14pt; color:#00aa00;\">Successfully Removed!</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("RemovePopUp", "Course Number:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("RemovePopUp", "Done", nullptr));
        label_5->setText(QCoreApplication::translate("RemovePopUp", "Semester:", nullptr));
        label->setText(QCoreApplication::translate("RemovePopUp", "Major:", nullptr));
        label_7->setText(QCoreApplication::translate("RemovePopUp", "<html><head/><body><p><span style=\" font-size:14pt; color:#ff0000;\">Remove Failed!</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RemovePopUp: public Ui_RemovePopUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOVEPOPUP_H
