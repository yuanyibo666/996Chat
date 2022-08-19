#include "dialogue.h"
#include "ui_dialogue.h"

dialogue::dialogue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dialogue)
{
    ui->setupUi(this);
}

dialogue::~dialogue()
{
    delete ui;
}
