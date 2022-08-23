/********************************************************************************
** Form generated from reading UI file 'frilist.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRILIST_H
#define UI_FRILIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Frilist
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QToolBox *toolBox;
    QWidget *page;
    QWidget *page_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *backButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *Frilist)
    {
        if (Frilist->objectName().isEmpty())
            Frilist->setObjectName(QStringLiteral("Frilist"));
        Frilist->resize(355, 406);
        verticalLayout = new QVBoxLayout(Frilist);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(Frilist);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        toolBox = new QToolBox(Frilist);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 343, 299));
        toolBox->addItem(page, QString::fromUtf8("\345\245\275\345\217\213"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 343, 299));
        toolBox->addItem(page_2, QString::fromUtf8("\347\276\244\347\273\204"));

        verticalLayout->addWidget(toolBox);

        widget = new QWidget(Frilist);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        backButton = new QPushButton(widget);
        backButton->setObjectName(QStringLiteral("backButton"));

        horizontalLayout->addWidget(backButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);


        retranslateUi(Frilist);

        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Frilist);
    } // setupUi

    void retranslateUi(QWidget *Frilist)
    {
        Frilist->setWindowTitle(QApplication::translate("Frilist", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Frilist", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600;\">\345\245\275\345\217\213\345\210\227\350\241\250</span></p></body></html>", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("Frilist", "\345\245\275\345\217\213", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("Frilist", "\347\276\244\347\273\204", Q_NULLPTR));
        backButton->setText(QApplication::translate("Frilist", "\350\277\224\345\233\236", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("Frilist", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Frilist: public Ui_Frilist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRILIST_H
