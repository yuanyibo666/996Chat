#ifndef REGIST_H
#define REGIST_H

#include <QWidget>
#include<QTcpSocket>
#include<QHostAddress>
#include<QMessageBox>
#include<QDebug>
namespace Ui {
class regist;
}

class regist : public QWidget
{
    Q_OBJECT

public:
    explicit regist(QTcpSocket *s, QWidget *parent = 0);
    ~regist();
    void register_feedback(QString msg);
    QTcpSocket *socket;
private slots:
    void on_pushButton_clicked();

    void on_delete2botton_clicked();

    void on_delete1Botton_clicked();

    void on_backButton_clicked();

private:
    Ui::regist *ui;

signals:
    void back_to_widget();

};

#endif // REGIST_H
