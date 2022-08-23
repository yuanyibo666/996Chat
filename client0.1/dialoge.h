#ifndef DIALOGE_H
#define DIALOGE_H

#include <QWidget>
#include <QTcpSocket>
#include <QTableWidgetItem>
#include <QDateTime>
#include <QComboBox>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QColorDialog>

namespace Ui {
class dialoge;
}

class dialoge : public QWidget
{
    Q_OBJECT
public:
    explicit dialoge(QTcpSocket *s,QString _ID, QString _name, QWidget *parent = 0);
    ~dialoge();
    void set_my_ID_and_name (QString ID, QString  name);
    QString get_ID(){return ID;}
    void set_member(QString mID,QString mname);//设置显示群成员

    void (QComboBox:: * cbxSingal)(const QString &text) = &QComboBox::currentIndexChanged;


private slots:
    void on_backButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::dialoge *ui;
    QString  ID;
    QString  name;
    QString  my_ID;
    QString  my_name;
    QTcpSocket *socket;
    QDateTime current_date_time;
    QColorDialog color;

};

#endif // DIALOGE_H
