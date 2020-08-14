/********************************************************************************
** Form generated from reading UI file 'notepopup.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEPOPUP_H
#define UI_NOTEPOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NotePopUp
{
public:
    QLabel *label_5;
    QComboBox *comboBox_2;
    QLabel *label;
    QTextEdit *textEdit;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *label_2;

    void setupUi(QWidget *NotePopUp)
    {
        if (NotePopUp->objectName().isEmpty())
            NotePopUp->setObjectName(QString::fromUtf8("NotePopUp"));
        NotePopUp->resize(512, 419);
        label_5 = new QLabel(NotePopUp);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 70, 47, 13));
        comboBox_2 = new QComboBox(NotePopUp);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(140, 70, 211, 22));
        label = new QLabel(NotePopUp);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 30, 181, 20));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        textEdit = new QTextEdit(NotePopUp);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(160, 180, 171, 141));
        pushButton_2 = new QPushButton(NotePopUp);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 350, 75, 23));
        lineEdit = new QLineEdit(NotePopUp);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 130, 361, 20));
        label_2 = new QLabel(NotePopUp);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 130, 47, 13));

        retranslateUi(NotePopUp);

        QMetaObject::connectSlotsByName(NotePopUp);
    } // setupUi

    void retranslateUi(QWidget *NotePopUp)
    {
        NotePopUp->setWindowTitle(QCoreApplication::translate("NotePopUp", "Form", nullptr));
        label_5->setText(QCoreApplication::translate("NotePopUp", "Semester:", nullptr));
        label->setText(QCoreApplication::translate("NotePopUp", "Add Note to a Semester", nullptr));
        textEdit->setHtml(QCoreApplication::translate("NotePopUp", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("NotePopUp", "Done", nullptr));
        label_2->setText(QCoreApplication::translate("NotePopUp", "Input:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NotePopUp: public Ui_NotePopUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEPOPUP_H
