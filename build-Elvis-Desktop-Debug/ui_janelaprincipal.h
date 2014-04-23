/********************************************************************************
** Form generated from reading UI file 'janelaprincipal.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JANELAPRINCIPAL_H
#define UI_JANELAPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_janelaprincipal
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_3;

    void setupUi(QWidget *janelaprincipal)
    {
        if (janelaprincipal->objectName().isEmpty())
            janelaprincipal->setObjectName(QStringLiteral("janelaprincipal"));
        janelaprincipal->resize(739, 406);
        gridLayout = new QGridLayout(janelaprincipal);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget = new QWidget(janelaprincipal);
        widget->setObjectName(QStringLiteral("widget"));

        gridLayout->addWidget(widget, 0, 0, 4, 1);

        pushButton = new QPushButton(janelaprincipal);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(janelaprincipal);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(99, 16777215));

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 286, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        pushButton_3 = new QPushButton(janelaprincipal);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 3, 1, 1, 1);


        retranslateUi(janelaprincipal);
        QObject::connect(pushButton_3, SIGNAL(clicked()), janelaprincipal, SLOT(close()));

        QMetaObject::connectSlotsByName(janelaprincipal);
    } // setupUi

    void retranslateUi(QWidget *janelaprincipal)
    {
        janelaprincipal->setWindowTitle(QApplication::translate("janelaprincipal", "janelaprincipal", 0));
        pushButton->setText(QApplication::translate("janelaprincipal", "Polilinha", 0));
        pushButton_2->setText(QApplication::translate("janelaprincipal", "Ret\303\242ngulo", 0));
        pushButton_3->setText(QApplication::translate("janelaprincipal", "Sair", 0));
    } // retranslateUi

};

namespace Ui {
    class janelaprincipal: public Ui_janelaprincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JANELAPRINCIPAL_H
