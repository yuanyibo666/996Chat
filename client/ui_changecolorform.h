/********************************************************************************
** Form generated from reading UI file 'changecolorform.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGECOLORFORM_H
#define UI_CHANGECOLORFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeColorForm
{
public:
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *ptnPink;
    QPushButton *ptnBlue;
    QPushButton *ptnRed;
    QPushButton *ptnOrange;
    QPushButton *ptnYellow;
    QPushButton *ptnGreen;

    void setupUi(QWidget *ChangeColorForm)
    {
        if (ChangeColorForm->objectName().isEmpty())
            ChangeColorForm->setObjectName(QStringLiteral("ChangeColorForm"));
        ChangeColorForm->resize(409, 317);
        label = new QLabel(ChangeColorForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 41, 41));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        gridLayoutWidget = new QWidget(ChangeColorForm);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 50, 403, 251));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        ptnPink = new QPushButton(gridLayoutWidget);
        ptnPink->setObjectName(QStringLiteral("ptnPink"));
        ptnPink->setMaximumSize(QSize(110, 110));

        gridLayout->addWidget(ptnPink, 0, 2, 1, 1);

        ptnBlue = new QPushButton(gridLayoutWidget);
        ptnBlue->setObjectName(QStringLiteral("ptnBlue"));
        ptnBlue->setMaximumSize(QSize(110, 110));

        gridLayout->addWidget(ptnBlue, 0, 1, 1, 1);

        ptnRed = new QPushButton(gridLayoutWidget);
        ptnRed->setObjectName(QStringLiteral("ptnRed"));
        ptnRed->setMaximumSize(QSize(110, 110));
        ptnRed->setCursor(QCursor(Qt::ArrowCursor));
        ptnRed->setAutoFillBackground(false);

        gridLayout->addWidget(ptnRed, 0, 0, 1, 1);

        ptnOrange = new QPushButton(gridLayoutWidget);
        ptnOrange->setObjectName(QStringLiteral("ptnOrange"));
        ptnOrange->setMaximumSize(QSize(110, 110));

        gridLayout->addWidget(ptnOrange, 1, 0, 1, 1);

        ptnYellow = new QPushButton(gridLayoutWidget);
        ptnYellow->setObjectName(QStringLiteral("ptnYellow"));
        ptnYellow->setMaximumSize(QSize(110, 110));

        gridLayout->addWidget(ptnYellow, 1, 1, 1, 1);

        ptnGreen = new QPushButton(gridLayoutWidget);
        ptnGreen->setObjectName(QStringLiteral("ptnGreen"));
        ptnGreen->setMaximumSize(QSize(110, 110));

        gridLayout->addWidget(ptnGreen, 1, 2, 1, 1);


        retranslateUi(ChangeColorForm);

        QMetaObject::connectSlotsByName(ChangeColorForm);
    } // setupUi

    void retranslateUi(QWidget *ChangeColorForm)
    {
        ChangeColorForm->setWindowTitle(QApplication::translate("ChangeColorForm", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("ChangeColorForm", "\347\272\257\350\211\262", Q_NULLPTR));
        ptnPink->setText(QString());
        ptnBlue->setText(QString());
        ptnRed->setText(QString());
        ptnOrange->setText(QString());
        ptnYellow->setText(QString());
        ptnGreen->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChangeColorForm: public Ui_ChangeColorForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGECOLORFORM_H
