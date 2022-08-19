#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <QWidget>

namespace Ui {
class dialogue;
}

class dialogue : public QWidget
{
    Q_OBJECT

public:
    explicit dialogue(QWidget *parent = 0);
    ~dialogue();

private:
    Ui::dialogue *ui;
};

#endif // DIALOGUE_H
