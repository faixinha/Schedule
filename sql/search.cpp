#include "search.h"

#include <QtGui>
#include <QTextEdit>

Search::Search(QWidget *parent)
    : QDialog(parent)
{
    labelName = new QLabel(tr("Nome:"));
    findEditName = new QLineEdit;
    labelName->setBuddy(findEditName);

    labelPhone = new QLabel(tr("Telefone: "));
    findEditPhone = new QLineEdit;
    findEditPhone->setInputMask("(99)9999-9999");
    labelPhone->setBuddy(findEditPhone);

    findContactButton = new QPushButton(tr("Procurar"));
    findContactButton->setCheckable(true);
    findContactButton->setDefault(true);

    removeButton = new QPushButton(tr("Remover"));

    exitButton = new QPushButton(tr("Sair"));

    buttonBox = new QDialogButtonBox(Qt::Vertical);
    buttonBox->addButton(findContactButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(removeButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(exitButton, QDialogButtonBox::ActionRole);

    extension = new QWidget;

    textEdit = new QTextEdit(this);
    textEdit->setObjectName(QString::fromUtf8("textEdit"));

    QHBoxLayout *layoutNameH = new QHBoxLayout;
    layoutNameH->addWidget(labelName);
    layoutNameH->addWidget(findEditName);

    QHBoxLayout *layoutPhoneH = new QHBoxLayout;
    layoutPhoneH->addWidget(labelPhone);
    layoutPhoneH->addWidget(findEditPhone);
    //layoutPhone->addStretch(1);

    QHBoxLayout *layoutButtonsH = new QHBoxLayout;
    layoutButtonsH->addWidget(findContactButton);
    layoutButtonsH->addWidget(removeButton);
    layoutButtonsH->addWidget(exitButton);

    QVBoxLayout *extensionLayoutV = new QVBoxLayout;
    extensionLayoutV->setMargin(0);
    extensionLayoutV->addWidget(textEdit);

    extension->setLayout(extensionLayoutV);

    QVBoxLayout *layoutButtonsV = new QVBoxLayout;
    layoutButtonsV->addLayout(layoutButtonsH);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addLayout(layoutNameH, 0, 0);
    mainLayout->addLayout(layoutPhoneH, 1, 0);
    mainLayout->addLayout(layoutButtonsV, 2, 0);
    mainLayout->addWidget(extension, 3, 0, 1, 2);
    setLayout(mainLayout);

    setWindowTitle(tr("Consulta"));

    extension->hide();
}

