/********************************************************************************
** Form generated from reading UI file 'dialoge.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGE_H
#define UI_DIALOGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialoge
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QFontComboBox *fontComboBox;
    QSpacerItem *horizontalSpacer_7;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_8;
    QToolButton *toolButton_2;
    QToolButton *toolButton;
    QToolButton *toolButton_3;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *backButton;

    void setupUi(QWidget *dialoge)
    {
        if (dialoge->objectName().isEmpty())
            dialoge->setObjectName(QStringLiteral("dialoge"));
        dialoge->resize(730, 700);
        dialoge->setMinimumSize(QSize(0, 700));
        gridLayout = new QGridLayout(dialoge);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        label_2 = new QLabel(dialoge);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalSpacer_6 = new QSpacerItem(150, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_6);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 4, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textBrowser = new QTextBrowser(dialoge);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        fontComboBox = new QFontComboBox(dialoge);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        fontComboBox->setCurrentIndex(-1);

        horizontalLayout->addWidget(fontComboBox);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        comboBox = new QComboBox(dialoge);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        toolButton_2 = new QToolButton(dialoge);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy);
        toolButton_2->setMinimumSize(QSize(40, 40));
        toolButton_2->setMaximumSize(QSize(40, 40));
        toolButton_2->setCheckable(true);

        horizontalLayout->addWidget(toolButton_2);

        toolButton = new QToolButton(dialoge);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        sizePolicy.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy);
        toolButton->setMinimumSize(QSize(40, 40));
        toolButton->setMaximumSize(QSize(40, 40));

        horizontalLayout->addWidget(toolButton);

        toolButton_3 = new QToolButton(dialoge);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(40, 40));
        toolButton_3->setMaximumSize(QSize(40, 40));

        horizontalLayout->addWidget(toolButton_3);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        textEdit = new QTextEdit(dialoge);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout_2->addWidget(textEdit);


        gridLayout->addLayout(verticalLayout_2, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(dialoge);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label = new QLabel(dialoge);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        backButton = new QPushButton(dialoge);
        backButton->setObjectName(QStringLiteral("backButton"));

        horizontalLayout_2->addWidget(backButton);


        gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 2);


        retranslateUi(dialoge);

        comboBox->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(dialoge);
    } // setupUi

    void retranslateUi(QWidget *dialoge)
    {
        dialoge->setWindowTitle(QApplication::translate("dialoge", "Form", Q_NULLPTR));
        label_2->setText(QApplication::translate("dialoge", "\347\276\244\350\201\212\345\220\215", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("dialoge", "8", Q_NULLPTR)
         << QApplication::translate("dialoge", "9", Q_NULLPTR)
         << QApplication::translate("dialoge", "10", Q_NULLPTR)
         << QApplication::translate("dialoge", "11", Q_NULLPTR)
         << QApplication::translate("dialoge", "12", Q_NULLPTR)
         << QApplication::translate("dialoge", "13", Q_NULLPTR)
         << QApplication::translate("dialoge", "14", Q_NULLPTR)
         << QApplication::translate("dialoge", "15", Q_NULLPTR)
         << QApplication::translate("dialoge", "16", Q_NULLPTR)
         << QApplication::translate("dialoge", "17", Q_NULLPTR)
         << QApplication::translate("dialoge", "18", Q_NULLPTR)
         << QApplication::translate("dialoge", "19", Q_NULLPTR)
         << QApplication::translate("dialoge", "20", Q_NULLPTR)
         << QApplication::translate("dialoge", "21", Q_NULLPTR)
         << QApplication::translate("dialoge", "22", Q_NULLPTR)
        );
        toolButton_2->setText(QApplication::translate("dialoge", "\345\212\240\347\262\227", Q_NULLPTR));
        toolButton->setText(QApplication::translate("dialoge", "\344\277\235\345\255\230\350\256\260\345\275\225", Q_NULLPTR));
        toolButton_3->setText(QApplication::translate("dialoge", "\346\270\205\347\251\272\350\256\260\345\275\225", Q_NULLPTR));
        pushButton->setText(QApplication::translate("dialoge", "\345\217\221\351\200\201\346\266\210\346\201\257", Q_NULLPTR));
        label->setText(QApplication::translate("dialoge", "\345\234\250\347\272\277\347\224\250\346\210\267\357\274\2327\344\272\272", Q_NULLPTR));
        backButton->setText(QApplication::translate("dialoge", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class dialoge: public Ui_dialoge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGE_H
