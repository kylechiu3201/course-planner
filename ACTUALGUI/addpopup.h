#ifndef ADDPOPUP_H
#define ADDPOPUP_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include "PopSearch.h"

namespace Ui {
class AddPopUp;
}

class AddPopUp : public QWidget
{
    Q_OBJECT

public:
    explicit AddPopUp(QWidget *parent = nullptr);
    void set_up();
    ~AddPopUp();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddPopUp *ui;
    QLineEdit * cour_major;
    QLineEdit * cour_num;
    QComboBox * cour_grade;
    PopSearch* sch;
};

#endif // ADDPOPUP_H
