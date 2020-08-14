/********************************************************************************
** Form generated from reading UI file 'save_pop_up.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVE_POP_UP_H
#define UI_SAVE_POP_UP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_save_pop_up
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;

    void setupUi(QDialog *save_pop_up)
    {
        if (save_pop_up->objectName().isEmpty())
            save_pop_up->setObjectName(QString::fromUtf8("save_pop_up"));
        save_pop_up->resize(366, 311);
        pushButton = new QPushButton(save_pop_up);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 180, 75, 23));
        label = new QLabel(save_pop_up);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 70, 161, 16));
        pushButton_2 = new QPushButton(save_pop_up);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 180, 75, 23));

        retranslateUi(save_pop_up);

        QMetaObject::connectSlotsByName(save_pop_up);
    } // setupUi

    void retranslateUi(QDialog *save_pop_up)
    {
        save_pop_up->setWindowTitle(QCoreApplication::translate("save_pop_up", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("save_pop_up", "Yes", nullptr));
        label->setText(QCoreApplication::translate("save_pop_up", "Would you like to SAVE and Exit?", nullptr));
        pushButton_2->setText(QCoreApplication::translate("save_pop_up", "No", nullptr));
    } // retranslateUi

};

namespace Ui {
    class save_pop_up: public Ui_save_pop_up {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVE_POP_UP_H
