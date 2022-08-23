/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QListView *backlistView;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *changeButton;
    QSpacerItem *verticalSpacer_5;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *IDlabel;
    QLineEdit *IDlineEdit;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *Pswlabel;
    QLineEdit *PswlineEdit;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *loginButton;
    QPushButton *registButton;
    QPushButton *forgetButton;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *hideButton;
    QPushButton *maxButton;
    QPushButton *closeButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(584, 460);
        backlistView = new QListView(Widget);
        backlistView->setObjectName(QStringLiteral("backlistView"));
        backlistView->setGeometry(QRect(0, -10, 331, 491));
        backlistView->setStyleSheet(QLatin1String("background-image: url(:/pic/backgroud0.jpg);\n"
"no-repeat center;border:0px;\n"
""));
        widget_5 = new QWidget(Widget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(20, 10, 301, 451));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(widget_5);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        widget_4 = new QWidget(widget_5);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        changeButton = new QPushButton(widget_4);
        changeButton->setObjectName(QStringLiteral("changeButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(changeButton->sizePolicy().hasHeightForWidth());
        changeButton->setSizePolicy(sizePolicy1);
        changeButton->setMinimumSize(QSize(120, 120));
        changeButton->setMaximumSize(QSize(120, 120));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        changeButton->setFont(font);
        changeButton->setStyleSheet(QLatin1String("QPushButton{\n"
"background-image: url(:/pic/backgroud0.jpg);\n"
"background-color: rgb(184, 231, 255);\n"
"color:black;\n"
"border-radius:60px;\n"
"border:2px groove gray;\n"
"border-style:outset;\n"
"}\n"
""));

        horizontalLayout_3->addWidget(changeButton);


        verticalLayout->addWidget(widget_4);

        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        widget_3 = new QWidget(widget_5);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        IDlabel = new QLabel(widget_3);
        IDlabel->setObjectName(QStringLiteral("IDlabel"));

        horizontalLayout_2->addWidget(IDlabel);

        IDlineEdit = new QLineEdit(widget_3);
        IDlineEdit->setObjectName(QStringLiteral("IDlineEdit"));

        horizontalLayout_2->addWidget(IDlineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_3);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        widget_2 = new QWidget(widget_5);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        Pswlabel = new QLabel(widget_2);
        Pswlabel->setObjectName(QStringLiteral("Pswlabel"));

        horizontalLayout->addWidget(Pswlabel);

        PswlineEdit = new QLineEdit(widget_2);
        PswlineEdit->setObjectName(QStringLiteral("PswlineEdit"));

        horizontalLayout->addWidget(PswlineEdit);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget_2);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        widget = new QWidget(widget_5);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        loginButton = new QPushButton(widget);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        sizePolicy1.setHeightForWidth(loginButton->sizePolicy().hasHeightForWidth());
        loginButton->setSizePolicy(sizePolicy1);
        loginButton->setMinimumSize(QSize(90, 30));
        loginButton->setMaximumSize(QSize(90, 30));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(8);
        loginButton->setFont(font1);
        loginButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-radius:15px;\n"
"background-image: url(:/pic/backgroud0.jpg);\n"
"border:1px groove gray;\n"
"border-style:outset;\n"
"}\n"
""));

        gridLayout->addWidget(loginButton, 0, 1, 1, 1);

        registButton = new QPushButton(widget);
        registButton->setObjectName(QStringLiteral("registButton"));
        sizePolicy1.setHeightForWidth(registButton->sizePolicy().hasHeightForWidth());
        registButton->setSizePolicy(sizePolicy1);
        registButton->setMinimumSize(QSize(90, 30));
        registButton->setMaximumSize(QSize(90, 30));
        registButton->setFont(font1);
        registButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-radius:15px;\n"
"background-image: url(:/pic/backgroud0.jpg);\n"
"border:1px groove gray;\n"
"border-style:outset;\n"
"}\n"
""));

        gridLayout->addWidget(registButton, 1, 1, 1, 1);

        forgetButton = new QPushButton(widget);
        forgetButton->setObjectName(QStringLiteral("forgetButton"));
        sizePolicy1.setHeightForWidth(forgetButton->sizePolicy().hasHeightForWidth());
        forgetButton->setSizePolicy(sizePolicy1);
        forgetButton->setMinimumSize(QSize(90, 30));
        forgetButton->setMaximumSize(QSize(90, 30));
        forgetButton->setFont(font1);
        forgetButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-radius:15px;\n"
"background-image: url(:/pic/backgroud0.jpg);\n"
"border:1px groove gray;\n"
"border-style:outset;\n"
"}\n"
""));

        gridLayout->addWidget(forgetButton, 1, 2, 1, 1);

        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setMinimumSize(QSize(90, 30));
        cancelButton->setMaximumSize(QSize(90, 30));
        cancelButton->setFont(font1);
        cancelButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-radius:15px;\n"
"background-image: url(:/pic/backgroud0.jpg);\n"
"border:1px groove gray;\n"
"border-style:outset;\n"
"}\n"
""));

        gridLayout->addWidget(cancelButton, 0, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);


        verticalLayout->addWidget(widget);

        widget_6 = new QWidget(Widget);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(200, 0, 136, 51));
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        hideButton = new QPushButton(widget_6);
        hideButton->setObjectName(QStringLiteral("hideButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(hideButton->sizePolicy().hasHeightForWidth());
        hideButton->setSizePolicy(sizePolicy2);
        hideButton->setMinimumSize(QSize(30, 30));
        hideButton->setMaximumSize(QSize(30, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setWeight(50);
        hideButton->setFont(font2);
        hideButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-radius:15px;\n"
"background-image: url(:/pic/backgroud0.jpg);\n"
"border:1px groove gray;\n"
"border-style:outset;\n"
"}\n"
""));

        horizontalLayout_4->addWidget(hideButton);

        maxButton = new QPushButton(widget_6);
        maxButton->setObjectName(QStringLiteral("maxButton"));
        maxButton->setMinimumSize(QSize(30, 30));
        maxButton->setMaximumSize(QSize(30, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setWeight(75);
        maxButton->setFont(font3);
        maxButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-radius:15px;\n"
"background-image: url(:/pic/backgroud0.jpg);\n"
"border:1px groove gray;\n"
"border-style:outset;\n"
"}\n"
""));

        horizontalLayout_4->addWidget(maxButton);

        closeButton = new QPushButton(widget_6);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setMinimumSize(QSize(30, 30));
        closeButton->setMaximumSize(QSize(30, 30));
        closeButton->setFont(font3);
        closeButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-radius:15px;\n"
"background-image: url(:/pic/backgroud0.jpg);\n"
"border:1px groove gray;\n"
"border-style:outset;\n"
"}\n"
""));

        horizontalLayout_4->addWidget(closeButton);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        changeButton->setText(QApplication::translate("Widget", "\345\210\207\346\215\242\350\264\246\345\217\267", Q_NULLPTR));
        IDlabel->setText(QApplication::translate("Widget", "\350\264\246\345\217\267\357\274\232", Q_NULLPTR));
        Pswlabel->setText(QApplication::translate("Widget", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        loginButton->setText(QApplication::translate("Widget", "\347\231\273\345\275\225", Q_NULLPTR));
        registButton->setText(QApplication::translate("Widget", "\346\263\250\345\206\214", Q_NULLPTR));
        forgetButton->setText(QApplication::translate("Widget", "\345\277\230\350\256\260\345\257\206\347\240\201", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("Widget", "\345\217\226\346\266\210", Q_NULLPTR));
        hideButton->setText(QApplication::translate("Widget", "-", Q_NULLPTR));
        maxButton->setText(QApplication::translate("Widget", "\342\226\241", Q_NULLPTR));
        closeButton->setText(QApplication::translate("Widget", "\303\227", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
