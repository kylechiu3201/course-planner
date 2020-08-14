#ifndef COMMINTERFACE_H
#define COMMINTERFACE_H

#include <QWidget>
#include "save_pop_up.h"
#include "addpopup.h"
#include "removepopup.h"
#include <QTableWidget>
#include <QComboBox>
#include <vector>
#include "Student/Student.h"
#include "changepop.h"
#include "notepopup.h"

namespace Ui {
class CommInterface;
}

class CommInterface : public QWidget
{
    Q_OBJECT

public:
    explicit CommInterface(QWidget *parent = nullptr);
    void set_item();
    AddPopUp* get_pop();
    RemovePopUp * get_remove_pop();
    ChangePop * get_change_pop();
    NotePopUp * get_note_pop();
    void set_deg_table();
    void set_eng_table();
    ~CommInterface();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void showPopUp(save_pop_up * popup);

    void tree_load();

    void tree_destr();

    void enterEvent(QEvent* event);

private:
    Ui::CommInterface *ui;
    QTableWidgetItem *newItem;

    save_pop_up *savepop;
    AddPopUp *addpop;
    RemovePopUp *removepop;
    ChangePop *changepop;
    NotePopUp *notepop;
};

#endif // COMMINTERFACE_H
