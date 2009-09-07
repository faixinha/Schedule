#include "register.h"

#include <QDate>
#include <QDateEdit>
#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QRadioButton>
#include <QtDebug>
#include <QVBoxLayout>

Register::Register(QWidget *parent) : QDialog(parent)
{
    labelName = new QLabel(tr("Nome"));
    lineEditName = new QLineEdit;
    labelName->setBuddy(lineEditName);

    labelBirthday = new QLabel(tr("Data do Nascimento"));
    birthdayEdit = new QDateEdit(QDate::currentDate());
    //dateEdit->setDateRange(QDate(1900, 1, 1), QDate(2009, 1, 1));
    labelBirthday->setBuddy(birthdayEdit);

    labelEmail = new QLabel(tr("E-mail"));
    lineEditEmail = new QLineEdit;
    labelEmail->setBuddy(lineEditEmail);

    labelSexo = new QLabel(tr("Sexo"));
    maleButton = new QRadioButton("Masculino", this );
    femaleButton = new QRadioButton("Feminino", this);
    maleButton->setChecked(1);

    labelMobilePhone = new QLabel(tr("Telefone Celular"));
    lineEditMobilePhone = new QLineEdit;
    lineEditMobilePhone->setInputMask("(99)9999-9999");
    labelName->setBuddy(lineEditMobilePhone);

    labelFixedPhone = new QLabel(tr("Telefone Convencional"));
    lineEditFixedPhone = new QLineEdit;
    lineEditFixedPhone->setInputMask("(99)9999-9999");
    labelName->setBuddy(lineEditFixedPhone);

    QPushButton *buttonAdd;
    buttonAdd = new QPushButton( "Adicionar" );
    connect( buttonAdd, SIGNAL(clicked()), this, SLOT(addClicked()) );

    QPushButton *buttonCancel;
    buttonCancel = new QPushButton( "Cancelar" );
    connect( buttonCancel, SIGNAL(clicked()), this, SLOT(cancelClicked()) );

    QPushButton *buttonClean;
    buttonClean = new QPushButton( "Limpar" );
    connect( buttonClean, SIGNAL(clicked()), this, SLOT(clearClicked()) );

    QDialogButtonBox *box = new QDialogButtonBox( Qt::Horizontal );
    box->addButton( buttonClean, QDialogButtonBox::AcceptRole);
    box->addButton( buttonCancel, QDialogButtonBox::AcceptRole );
    box->addButton( buttonAdd, QDialogButtonBox::AcceptRole );

    //-------------------- Layout na Horizontal ------------------
    QHBoxLayout *layoutNomeH = new QHBoxLayout;
    layoutNomeH->addWidget(labelName);
    layoutNomeH->addWidget(lineEditName);

    QHBoxLayout *layoutEmailH = new QHBoxLayout;
    layoutEmailH->addWidget(labelEmail);
    layoutEmailH->addWidget(lineEditEmail);
    //layoutEmail->addWidget(lineEditName);

    QHBoxLayout *layoutBirthdayH = new QHBoxLayout;
    layoutBirthdayH->addWidget(labelBirthday);
    layoutBirthdayH->addWidget(birthdayEdit);

    QHBoxLayout *layoutSexoH = new QHBoxLayout;
    layoutSexoH->addWidget(labelSexo);
    layoutSexoH->addWidget(maleButton);
    layoutSexoH->addWidget(femaleButton);

    QHBoxLayout *layoutMobilePhoneH = new QHBoxLayout;
    layoutMobilePhoneH->addWidget(labelMobilePhone);
    layoutMobilePhoneH->addWidget(lineEditMobilePhone);

    QHBoxLayout *layoutFixedPhoneH = new QHBoxLayout;
    layoutFixedPhoneH->addWidget(labelFixedPhone);
    layoutFixedPhoneH->addWidget(lineEditFixedPhone);

    QHBoxLayout *layoutBoxH = new QHBoxLayout;
    layoutBoxH->addWidget(box);

    //--------------------- Layout na Vertical --------------------
    QVBoxLayout *layoutNomeV = new QVBoxLayout;
    layoutNomeV->addLayout(layoutNomeH);
    layoutNomeV->addStretch(1);

    QVBoxLayout *layoutEmailV = new QVBoxLayout;
    layoutEmailV->addLayout(layoutEmailH);
    layoutEmailV->addStretch(1);

    QVBoxLayout *layoutBirthdayV = new QVBoxLayout;
    layoutBirthdayV->addLayout(layoutBirthdayH);
    layoutBirthdayV->addStretch(1);

    QVBoxLayout *layoutSexoV = new QVBoxLayout;
    layoutSexoV->addLayout(layoutSexoH);
    layoutSexoV->addStretch(1);

    QVBoxLayout *layoutMobilePhoneV = new QVBoxLayout;
    layoutMobilePhoneV->addLayout(layoutMobilePhoneH);
    layoutMobilePhoneV->addStretch(1);

    QVBoxLayout *layoutFixedPhoneV = new QVBoxLayout;
    layoutFixedPhoneV->addLayout(layoutFixedPhoneH);
    layoutFixedPhoneV->addStretch(1);

    QVBoxLayout *layoutBoxV = new QVBoxLayout;
    layoutBoxV->addLayout(layoutBoxH);
    layoutBoxV->addStretch(1);

    //---------------------- Layout Grid ---------------------
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addLayout(layoutNomeV, 0, 0);
    mainLayout->addLayout(layoutEmailV, 1, 0);
    mainLayout->addLayout(layoutBirthdayV, 2, 0);
    mainLayout->addLayout(layoutSexoV, 3, 0);
    mainLayout->addLayout(layoutMobilePhoneV, 4, 0);
    mainLayout->addLayout(layoutFixedPhoneV, 5, 0);
    mainLayout->addLayout(layoutBoxV, 6, 0);
    setLayout(mainLayout);

    setWindowTitle("Formulario de Cadastro");
}

void Register::addClicked()
{
    QString sexo;

    //------- Contact's Name -------
    QString nomeDigitado = lineEditName->text();

    QString eMail = lineEditEmail->text();
    if (eMail == "")
        eMail = "E-mail nao informado";

    //------- Contact's birthday -------
    /* TODO */
    /*QDateEdit *teste = new QDateEdit();//(QDate::currentDate());
    teste = birthdayEdit->date();
    qDebug() << teste;
    */
    QString birthday = "Nao informado";

    //------- Contact's Sexo -------
    if (femaleButton->isChecked())
        sexo = "feminino";

    if (maleButton->isChecked())
        sexo = "masculino";

    //------- Contact's phone -------
    QString telefoneCelular = lineEditMobilePhone->text();
    QString telefoneFixo = lineEditFixedPhone->text();

    if (nomeDigitado == ""){
        QMessageBox::information(this, tr("Empty Field"),
            tr("Please enter a name."));
        return;
    }

    if ( telefoneCelular == "" || telefoneFixo == "" ) {
        QMessageBox::information(this, tr("Empty Field"),
            tr("Please enter a phone."));
        return;
    }
    QWidget::close();
}

void Register::clearClicked()
{
    QString nomeDigitado = lineEditName->text();
    QString emailDigitado = lineEditEmail->text();

    /* TODO: BIRTHDAY */

    QString telefoneCelular = lineEditMobilePhone->text();
    QString telefoneConvencional = lineEditFixedPhone->text();

    if ((nomeDigitado == "" && telefoneCelular == "" && telefoneConvencional == "" )) {
        QMessageBox::information(this, tr("Empty Fields"),
            tr("There's nothing to be cleaned."));
        return;
    }
    lineEditName->clear();
    lineEditEmail->clear();

    /* TODO: BIRTHDAY */

    maleButton->setChecked(1);
    lineEditMobilePhone->clear();
    lineEditFixedPhone->clear();
}

void Register::cancelClicked()
{
    QWidget::close();
}

