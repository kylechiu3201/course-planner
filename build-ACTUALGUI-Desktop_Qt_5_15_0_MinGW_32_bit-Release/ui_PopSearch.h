/********************************************************************************
** Form generated from reading UI file 'PopSearch.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPSEARCH_H
#define UI_POPSEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PopSearch
{
public:
    QComboBox *comboBox;
    QCheckBox *checkBox_6;
    QPushButton *pushButton_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTableWidget *Table;
    QDoubleSpinBox *doubleSpinBox;
    QCheckBox *checkBox_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_7;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_3;
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QLabel *label;
    QCheckBox *checkBox_9;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;

    void setupUi(QWidget *PopSearch)
    {
        if (PopSearch->objectName().isEmpty())
            PopSearch->setObjectName(QString::fromUtf8("PopSearch"));
        PopSearch->resize(841, 621);
        comboBox = new QComboBox(PopSearch);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(240, 140, 69, 22));
        checkBox_6 = new QCheckBox(PopSearch);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setGeometry(QRect(40, 500, 101, 21));
        QFont font;
        font.setPointSize(10);
        checkBox_6->setFont(font);
        pushButton_2 = new QPushButton(PopSearch);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 560, 71, 21));
        QFont font1;
        font1.setPointSize(9);
        pushButton_2->setFont(font1);
        checkBox_3 = new QCheckBox(PopSearch);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(40, 380, 161, 21));
        checkBox_3->setFont(font);
        checkBox_4 = new QCheckBox(PopSearch);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(40, 420, 151, 21));
        checkBox_4->setFont(font);
        label_2 = new QLabel(PopSearch);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 90, 111, 16));
        QFont font2;
        font2.setPointSize(11);
        label_2->setFont(font2);
        doubleSpinBox_2 = new QDoubleSpinBox(PopSearch);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(240, 260, 71, 31));
        scrollArea = new QScrollArea(PopSearch);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(400, 50, 401, 521));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 399, 519));
        Table = new QTableWidget(scrollAreaWidgetContents);
        if (Table->columnCount() < 4)
            Table->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        Table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        Table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        Table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        Table->setObjectName(QString::fromUtf8("Table"));
        Table->setGeometry(QRect(0, 0, 401, 521));
        scrollArea->setWidget(scrollAreaWidgetContents);
        doubleSpinBox = new QDoubleSpinBox(PopSearch);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(240, 210, 71, 31));
        doubleSpinBox->setMinimumSize(QSize(71, 31));
        doubleSpinBox->setMaximum(4.000000000000000);
        checkBox_5 = new QCheckBox(PopSearch);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(40, 460, 71, 21));
        checkBox_5->setFont(font);
        lineEdit = new QLineEdit(PopSearch);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(200, 40, 111, 20));
        lineEdit_2 = new QLineEdit(PopSearch);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(200, 90, 113, 20));
        label_4 = new QLabel(PopSearch);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(190, 220, 41, 16));
        label_4->setFont(font);
        checkBox_8 = new QCheckBox(PopSearch);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        checkBox_8->setGeometry(QRect(40, 580, 101, 21));
        checkBox_8->setFont(font);
        checkBox_2 = new QCheckBox(PopSearch);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(40, 340, 121, 21));
        checkBox_2->setFont(font);
        checkBox_7 = new QCheckBox(PopSearch);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setGeometry(QRect(40, 540, 91, 21));
        checkBox_7->setFont(font);
        label_5 = new QLabel(PopSearch);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(190, 270, 47, 16));
        label_5->setFont(font);
        label_6 = new QLabel(PopSearch);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(70, 140, 91, 16));
        label_6->setFont(font2);
        label_3 = new QLabel(PopSearch);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 210, 101, 21));
        label_3->setFont(font2);
        pushButton = new QPushButton(PopSearch);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(210, 500, 111, 31));
        pushButton->setFont(font2);
        checkBox = new QCheckBox(PopSearch);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(40, 270, 101, 21));
        checkBox->setFont(font);
        label = new QLabel(PopSearch);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 40, 51, 21));
        label->setFont(font2);
        checkBox_9 = new QCheckBox(PopSearch);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));
        checkBox_9->setGeometry(QRect(40, 310, 151, 17));
        checkBox_9->setFont(font);
        label_7 = new QLabel(PopSearch);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(520, 10, 161, 41));
        label_8 = new QLabel(PopSearch);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(550, 10, 161, 41));
        label_9 = new QLabel(PopSearch);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(170, 170, 211, 51));
        label_10 = new QLabel(PopSearch);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(210, 70, 91, 21));

        retranslateUi(PopSearch);

        QMetaObject::connectSlotsByName(PopSearch);
    } // setupUi

    void retranslateUi(QWidget *PopSearch)
    {
        PopSearch->setWindowTitle(QCoreApplication::translate("PopSearch", "Form", nullptr));
        checkBox_6->setText(QCoreApplication::translate("PopSearch", "Non-Western", nullptr));
        pushButton_2->setText(QCoreApplication::translate("PopSearch", "Back", nullptr));
        checkBox_3->setText(QCoreApplication::translate("PopSearch", "Humanities and the Arts", nullptr));
        checkBox_4->setText(QCoreApplication::translate("PopSearch", "Social and  Behavioral", nullptr));
        label_2->setText(QCoreApplication::translate("PopSearch", "Course Number:", nullptr));
        QTableWidgetItem *___qtablewidgetitem = Table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("PopSearch", "Major", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = Table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("PopSearch", "Course #", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = Table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("PopSearch", "Avg GPA", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = Table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("PopSearch", "Credit Hours", nullptr));
        checkBox_5->setText(QCoreApplication::translate("PopSearch", "Western", nullptr));
        label_4->setText(QCoreApplication::translate("PopSearch", "Lower", nullptr));
        checkBox_8->setText(QCoreApplication::translate("PopSearch", "Composition", nullptr));
        checkBox_2->setText(QCoreApplication::translate("PopSearch", "Liberal Education", nullptr));
        checkBox_7->setText(QCoreApplication::translate("PopSearch", "US Minority", nullptr));
        label_5->setText(QCoreApplication::translate("PopSearch", "Upper", nullptr));
        label_6->setText(QCoreApplication::translate("PopSearch", "Credit Hours:", nullptr));
        label_3->setText(QCoreApplication::translate("PopSearch", "Average GPA:", nullptr));
        pushButton->setText(QCoreApplication::translate("PopSearch", "Search", nullptr));
        checkBox->setText(QCoreApplication::translate("PopSearch", "Average GPA", nullptr));
        label->setText(QCoreApplication::translate("PopSearch", "Major:", nullptr));
        checkBox_9->setText(QCoreApplication::translate("PopSearch", "Highest to Lowest GPA", nullptr));
        label_7->setText(QCoreApplication::translate("PopSearch", "<html><head/><body><p><span style=\" font-size:14pt; color:#00aa00;\">Sucessfully Added!</span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("PopSearch", "<html><head/><body><p><span style=\" font-size:14pt; color:#ff0000;\">Add Failed!</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("PopSearch", "<html><head/><body><p align=\"center\"><span style=\" font-size:9pt; color:#ff0800;\">Upper cannot be less than Lower!</span></p></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("PopSearch", "<html><head/><body><p><span style=\" font-size:9pt; color:#ff0000;\">Invalid number!</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PopSearch: public Ui_PopSearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPSEARCH_H
