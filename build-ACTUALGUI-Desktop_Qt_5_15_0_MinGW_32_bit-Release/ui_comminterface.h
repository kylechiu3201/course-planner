/********************************************************************************
** Form generated from reading UI file 'comminterface.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMINTERFACE_H
#define UI_COMMINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommInterface
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QLabel *label_4;
    QTableWidget *tableWidget;
    QWidget *page_2;
    QLabel *label_2;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QScrollBar *verticalScrollBar;
    QTreeWidget *treeWidget;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QWidget *page_3;
    QLabel *label_3;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QTableWidget *tableWidget_2;
    QTableWidget *tableWidget_3;
    QLabel *label;
    QLabel *label_5;

    void setupUi(QWidget *CommInterface)
    {
        if (CommInterface->objectName().isEmpty())
            CommInterface->setObjectName(QString::fromUtf8("CommInterface"));
        CommInterface->resize(751, 511);
        CommInterface->setAutoFillBackground(false);
        stackedWidget = new QStackedWidget(CommInterface);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(40, 20, 711, 461));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        pushButton_5 = new QPushButton(page);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(460, 170, 81, 20));
        pushButton_6 = new QPushButton(page);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(460, 210, 81, 21));
        pushButton_7 = new QPushButton(page);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(50, 330, 91, 51));
        pushButton_8 = new QPushButton(page);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(450, 330, 131, 51));
        label_4 = new QLabel(page);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(240, 40, 121, 51));
        tableWidget = new QTableWidget(page);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget->rowCount() < 7)
            tableWidget->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem7);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(190, 120, 211, 261));
        tableWidget->setMinimumSize(QSize(0, 261));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(260, 30, 171, 61));
        pushButton_9 = new QPushButton(page_2);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(60, 320, 151, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Calibri"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        pushButton_9->setFont(font);
        pushButton_10 = new QPushButton(page_2);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(500, 320, 151, 71));
        pushButton_10->setFont(font);
        scrollArea = new QScrollArea(page_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(230, 110, 231, 281));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 229, 279));
        verticalScrollBar = new QScrollBar(scrollAreaWidgetContents);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(210, 0, 21, 281));
        verticalScrollBar->setOrientation(Qt::Vertical);
        treeWidget = new QTreeWidget(scrollAreaWidgetContents);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(0, 0, 211, 281));
        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(90, 160, 101, 51));
        QFont font1;
        font1.setPointSize(10);
        pushButton_3->setFont(font1);
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(90, 230, 101, 51));
        pushButton_2->setFont(font1);
        pushButton = new QPushButton(page_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(500, 210, 111, 71));
        pushButton_4 = new QPushButton(page_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(500, 130, 111, 23));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        label_3 = new QLabel(page_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 20, 281, 61));
        pushButton_11 = new QPushButton(page_3);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(110, 370, 121, 51));
        pushButton_12 = new QPushButton(page_3);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(440, 370, 101, 51));
        tableWidget_2 = new QTableWidget(page_3);
        if (tableWidget_2->columnCount() < 2)
            tableWidget_2->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        if (tableWidget_2->rowCount() < 6)
            tableWidget_2->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(3, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(4, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(5, __qtablewidgetitem15);
        QFont font2;
        font2.setPointSize(6);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font2);
        tableWidget_2->setItem(0, 0, __qtablewidgetitem16);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(30, 140, 291, 211));
        tableWidget_3 = new QTableWidget(page_3);
        if (tableWidget_3->columnCount() < 2)
            tableWidget_3->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem18);
        if (tableWidget_3->rowCount() < 7)
            tableWidget_3->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(3, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(4, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(5, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(6, __qtablewidgetitem25);
        tableWidget_3->setObjectName(QString::fromUtf8("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(340, 140, 291, 211));
        label = new QLabel(page_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 100, 81, 20));
        label_5 = new QLabel(page_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(440, 100, 111, 20));
        stackedWidget->addWidget(page_3);

        retranslateUi(CommInterface);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(CommInterface);
    } // setupUi

    void retranslateUi(QWidget *CommInterface)
    {
        CommInterface->setWindowTitle(QCoreApplication::translate("CommInterface", "Form", nullptr));
        pushButton_5->setText(QCoreApplication::translate("CommInterface", "Save", nullptr));
        pushButton_6->setText(QCoreApplication::translate("CommInterface", "Exit", nullptr));
        pushButton_7->setText(QCoreApplication::translate("CommInterface", "View Degree Info", nullptr));
        pushButton_8->setText(QCoreApplication::translate("CommInterface", "View Plan/Add Courses", nullptr));
        label_4->setText(QCoreApplication::translate("CommInterface", "<html><head/><body><p><span style=\" font-size:16pt;\">Student Info</span></p></body></html>", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("CommInterface", "Data", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("CommInterface", "Student Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("CommInterface", "Major", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("CommInterface", "Start Year", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("CommInterface", "Total Cred Hours", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("CommInterface", "Degree Cred Hours", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("CommInterface", "GPA", nullptr));
        label_2->setText(QCoreApplication::translate("CommInterface", "<html><head/><body><p><span style=\" font-size:22pt;\">Student Plan</span></p></body></html>", nullptr));
        pushButton_9->setText(QCoreApplication::translate("CommInterface", "Student Info", nullptr));
        pushButton_10->setText(QCoreApplication::translate("CommInterface", "Degree Requirements", nullptr));
        pushButton_3->setText(QCoreApplication::translate("CommInterface", "Add Course", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CommInterface", "Remove Course", nullptr));
        pushButton->setText(QCoreApplication::translate("CommInterface", "Update Grade", nullptr));
        pushButton_4->setText(QCoreApplication::translate("CommInterface", "Add Semester Note", nullptr));
        label_3->setText(QCoreApplication::translate("CommInterface", "<html><head/><body><p><span style=\" font-size:22pt;\">Degree Requirements</span></p></body></html>", nullptr));
        pushButton_11->setText(QCoreApplication::translate("CommInterface", "View Plan/Add Courses", nullptr));
        pushButton_12->setText(QCoreApplication::translate("CommInterface", "Student Info", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("CommInterface", "Num Taken", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("CommInterface", "Num Left", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_2->verticalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("CommInterface", "Foundations", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_2->verticalHeaderItem(1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("CommInterface", "Core", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_2->verticalHeaderItem(2);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("CommInterface", "Gen Electives", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_2->verticalHeaderItem(3);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("CommInterface", "EE Foundation", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_2->verticalHeaderItem(4);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("CommInterface", "Adv Comp", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_2->verticalHeaderItem(5);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("CommInterface", "Capstone", nullptr));

        const bool __sortingEnabled = tableWidget_2->isSortingEnabled();
        tableWidget_2->setSortingEnabled(false);
        tableWidget_2->setSortingEnabled(__sortingEnabled);

        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("CommInterface", "Num Taken", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("CommInterface", "Num Left", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_3->verticalHeaderItem(0);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("CommInterface", "Western", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_3->verticalHeaderItem(1);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("CommInterface", "Non-West", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_3->verticalHeaderItem(2);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("CommInterface", "Libed", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_3->verticalHeaderItem(3);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("CommInterface", "Soc/Behav", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_3->verticalHeaderItem(4);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("CommInterface", "US Min", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_3->verticalHeaderItem(5);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("CommInterface", "Hum/Arts", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_3->verticalHeaderItem(6);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("CommInterface", "Compos", nullptr));
        label->setText(QCoreApplication::translate("CommInterface", "Major Specific", nullptr));
        label_5->setText(QCoreApplication::translate("CommInterface", "General Requirements", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommInterface: public Ui_CommInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMINTERFACE_H
