#ifndef CHANGEPOP_H
#define CHANGEPOP_H

#include <QWidget>

namespace Ui {
class ChangePop;
}

class ChangePop : public QWidget
{
    Q_OBJECT

public:
    explicit ChangePop(QWidget *parent = nullptr);
    ~ChangePop();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ChangePop *ui;
};

#endif // CHANGEPOP_H
