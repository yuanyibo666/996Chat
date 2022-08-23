#include "dialoge.h"
#include "ui_dialoge.h"

dialoge::dialoge(QTcpSocket *s,QString _ID, QString _name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dialoge)
{
    ui->setupUi(this);
    ID = _ID;
    name = _name;
    socket = s;
    this->setWindowTitle(name);

    connect(ui->fontComboBox,&QFontComboBox::currentFontChanged,this,[=](const QFont &f){
        ui->textBrowser->setCurrentFont(f);
        ui->textBrowser->setFocus();
    });

      connect(ui->comboBox,cbxSingal,this,[=](const QString &text){
          ui->textBrowser->setFontPointSize(text.toDouble());
          ui->textBrowser->setFocus();
      });


      connect(ui->toolButton_2,&QToolButton::clicked,this,[=](bool checked){
            if(checked)
            {
                ui->textBrowser->setFontWeight(QFont::Bold);
            }
            else
            {
                ui->textBrowser->setFontWeight(QFont::Normal);
            }
            ui->textBrowser->setFocus();
        });

      connect(ui->toolButton,&QToolButton::clicked,this,[=](){
                  if(ui->textBrowser->document()->isEmpty())
                  {
                      QMessageBox::warning(this,"警告","聊天记录为空，无法保存！",QMessageBox::Ok);
                  }
                  else
                  {
                      QString fName = QFileDialog::getSaveFileName(this,"保存聊天记录","聊天记录","(*.txt)");
                      if(!fName.isEmpty())
                      {
                          //保存名称不为空再做保存操作
                          QFile file(fName);
                          file.open(QIODevice::WriteOnly | QFile::Text);

                          QTextStream stream(&file);
                          stream << ui->textBrowser->toPlainText();
                          file.close();
                      }
                  }
              });

      connect(ui->toolButton_3,&QToolButton::clicked,[=](){
          ui->textBrowser->clear();
      });

//      connect(ui->toolButton_4,&QToolButton::clicked,this,[=](){
//             color_1 = QColorDialog::getColor(color,this); //color对象可以在widget.h中定义私有成员
//              ui->textBrowser->setTextColor(color);
//              ui->textBrowser->setFocus();

//          });

}

void dialoge::set_my_ID_and_name (QString ID, QString  name)
{
    my_ID=ID;
    my_name=name;
}

void dialoge::set_member(QString mID, QString mname)
{
    QLabel* new_member = new QLabel;
    new_member->setText(mID+" "+mname);
    ui->verticalLayout_3->addWidget(new_member);
}

dialoge::~dialoge()
{
    delete ui;
}

void dialoge::on_backButton_clicked()
{
    this->hide();
}

void dialoge::on_pushButton_clicked()
{
    QString chat_content = ui->textEdit->toPlainText();
    qDebug()<<chat_content;
    current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy-MM-dd&&hh:mm:ss.zzz");
    //ID和name的获取
    QString msg = "signalmsg|" + my_ID + "|" + ID + "|" + current_date + chat_content;
    socket->write(msg.toLocal8Bit());
    ui->textBrowser->append(current_date);
    ui->textBrowser->append(name);
    ui->textBrowser->append(chat_content);
    ui->textBrowser->append("------");

    ui->textEdit->clear();
}
