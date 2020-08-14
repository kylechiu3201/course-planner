#ifndef DEGREEPOPUP_H
#define DEGREEPOPUP_H

#include <QWidget>

namespace Ui {
class DegreePopUp;
}

class DegreePopUp : public QWidget
{
    Q_OBJECT

public:
    explicit DegreePopUp(QWidget *parent = nullptr);
    ~DegreePopUp();

private:
    Ui::DegreePopUp *ui;
};

#endif // DEGREEPOPUP_H
