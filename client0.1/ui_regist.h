/********************************************************************************
** Form generated from reading UI file 'regist.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGIST_H
#define UI_REGIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_regist
{
public:
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_9;
    QLabel *IDlabel_3;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *delete1Botton;
    QSpacerItem *horizontalSpacer_10;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_12;
    QLabel *Pswlabel_2;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *delete2botton;
    QSpacerItem *horizontalSpacer_13;
    QWidget *widget_7;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_7;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *backButton;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_17;
    QPushButton *hideButton;
    QPushButton *maxButton;
    QPushButton *closeButton;
    QListView *backlistView;

    void setupUi(QWidget *regist)
    {
        if (regist->objectName().isEmpty())
            regist->setObjectName(QStringLiteral("regist"));
        regist->resize(331, 491);
        widget_5 = new QWidget(regist);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(0, 220, 331, 61));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        IDlabel_3 = new QLabel(widget_5);
        IDlabel_3->setObjectName(QStringLiteral("IDlabel_3"));

        horizontalLayout_5->addWidget(IDlabel_3);

        lineEdit = new QLineEdit(widget_5);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_5->addWidget(lineEdit);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);

        delete1Botton = new QPushButton(widget_5);
        delete1Botton->setObjectName(QStringLiteral("delete1Botton"));

        horizontalLayout_5->addWidget(delete1Botton);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);

        widget_6 = new QWidget(regist);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(0, 280, 331, 61));
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_12);

        Pswlabel_2 = new QLabel(widget_6);
        Pswlabel_2->setObjectName(QStringLiteral("Pswlabel_2"));

        horizontalLayout_6->addWidget(Pswlabel_2);

        lineEdit_2 = new QLineEdit(widget_6);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_6->addWidget(lineEdit_2);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_14);

        delete2botton = new QPushButton(widget_6);
        delete2botton->setObjectName(QStringLiteral("delete2botton"));

        horizontalLayout_6->addWidget(delete2botton);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_13);

        widget_7 = new QWidget(regist);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setGeometry(QRect(0, 340, 331, 151));
        gridLayout_2 = new QGridLayout(widget_7);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalSpacer_6 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 2, 1, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_7, 0, 1, 1, 1);

        pushButton = new QPushButton(widget_7);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 1, 1, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_15, 1, 4, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_16, 1, 0, 1, 1);

        backButton = new QPushButton(widget_7);
        backButton->setObjectName(QStringLiteral("backButton"));

        gridLayout_2->addWidget(backButton, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 2, 1, 1);

        widget_8 = new QWidget(regist);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setGeometry(QRect(190, 20, 136, 51));
        horizontalLayout_7 = new QHBoxLayout(widget_8);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_17);

        hideButton = new QPushButton(widget_8);
        hideButton->setObjectName(QStringLiteral("hideButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hideButton->sizePolicy().hasHeightForWidth());
        hideButton->setSizePolicy(sizePolicy);
        hideButton->setMinimumSize(QSize(30, 30));
        hideButton->setMaximumSize(QSize(30, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        hideButton->setFont(font);
        hideButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-radius:15px;\n"
"background-image: url(:/pic/backgroud0.jpg);\n"
"border:1px groove gray;\n"
"border-style:outset;\n"
"}\n"
""));

        horizontalLayout_7->addWidget(hideButton);

        maxButton = new QPushButton(widget_8);
        maxButton->setObjectName(QStringLiteral("maxButton"));
        maxButton->setMinimumSize(QSize(30, 30));
        maxButton->setMaximumSize(QSize(30, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        maxButton->setFont(font1);
        maxButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-radius:15px;\n"
"background-image: url(:/pic/backgroud0.jpg);\n"
"border:1px groove gray;\n"
"border-style:outset;\n"
"}\n"
""));

        horizontalLayout_7->addWidget(maxButton);

        closeButton = new QPushButton(widget_8);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setMinimumSize(QSize(30, 30));
        closeButton->setMaximumSize(QSize(30, 30));
        closeButton->setFont(font1);
        closeButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-radius:15px;\n"
"background-image: url(:/pic/backgroud0.jpg);\n"
"border:1px groove gray;\n"
"border-style:outset;\n"
"}\n"
""));

        horizontalLayout_7->addWidget(closeButton);

        backlistView = new QListView(regist);
        backlistView->setObjectName(QStringLiteral("backlistView"));
        backlistView->setGeometry(QRect(-10, 20, 341, 491));
        backlistView->setStyleSheet(QLatin1String("background-image: url(:/pic/backgroud0.jpg);\n"
"no-repeat center;border:0px;\n"
""));
        backlistView->raise();
        widget_5->raise();
        widget_6->raise();
        widget_7->raise();
        widget_8->raise();

        retranslateUi(regist);

        QMetaObject::connectSlotsByName(regist);
    } // setupUi

    void retranslateUi(QWidget *regist)
    {
        regist->setWindowTitle(QApplication::translate("regist", "Form", Q_NULLPTR));
        IDlabel_3->setText(QApplication::translate("regist", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        delete1Botton->setText(QApplication::translate("regist", "\346\270\205\347\251\272", Q_NULLPTR));
        Pswlabel_2->setText(QApplication::translate("regist", "\345\257\206 \347\240\201\357\274\232", Q_NULLPTR));
        delete2botton->setText(QApplication::translate("regist", "\346\270\205\347\251\272", Q_NULLPTR));
        pushButton->setText(QApplication::translate("regist", "\346\263\250\345\206\214", Q_NULLPTR));
        backButton->setText(QApplication::translate("regist", "\350\277\224\345\233\236", Q_NULLPTR));
        hideButton->setText(QApplication::translate("regist", "-", Q_NULLPTR));
        maxButton->setText(QApplication::translate("regist", "\342\226\241", Q_NULLPTR));
        closeButton->setText(QApplication::translate("regist", "\303\227", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class regist: public Ui_regist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGIST_H
