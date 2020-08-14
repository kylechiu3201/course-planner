#include "degreepopup.h"
#include "ui_degreepopup.h"

DegreePopUp::DegreePopUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DegreePopUp)
{
    ui->setupUi(this);
}

DegreePopUp::~DegreePopUp()
{
    delete ui;
}
