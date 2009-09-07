#include "schedule.h"

#include "register.h"

#include <QDialogButtonBox>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

Schedule::Schedule() : QDialog(0)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QDialogButtonBox *box = new QDialogButtonBox(Qt::Horizontal);

    QPushButton *button = new QPushButton("Sair");
    box->addButton(button, QDialogButtonBox::AcceptRole);

    button = new QPushButton("Ajuda");
    box->addButton(button, QDialogButtonBox::AcceptRole);

    button = new QPushButton("Consulta");
    box->addButton(button, QDialogButtonBox::AcceptRole);

    button = new QPushButton("Cadastro");
    box->addButton(button, QDialogButtonBox::AcceptRole);

    layout->addWidget(new QLabel("Agendinha"));
    layout->addWidget(box);

    setWindowTitle("AGENDA");

    connect(button, SIGNAL(clicked()), this, SLOT(sairClicked()));
    //connect(button, SIGNAL(clicked()), qApp, SLOT(aboutQt()));
    connect(button, SIGNAL(clicked()), this, SLOT(searchContact()));
    connect(button, SIGNAL(clicked()), this, SLOT(registerForm()));
}

void Schedule::registerForm()
{
    Register *registerContact = new Register(this);
    registerContact->show();
}

void Schedule::searchContact()
{
    /* TODO */
}

void Schedule::sairClicked()
{
    QWidget::close();
}

