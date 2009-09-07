#include "schedule.h"

#include "register.h"
#include "search.h"

#include <QApplication>
#include <QDialogButtonBox>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

Schedule::Schedule() : QDialog(0)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QDialogButtonBox *box = new QDialogButtonBox(Qt::Horizontal);

    QPushButton *button = new QPushButton("Sair");
    connect(button, SIGNAL(clicked()), this, SLOT(sairClicked()));
    box->addButton(button, QDialogButtonBox::AcceptRole);

    button = new QPushButton("Ajuda");
    connect(button, SIGNAL(clicked()), qApp, SLOT(aboutQt()));
    box->addButton(button, QDialogButtonBox::AcceptRole);

    button = new QPushButton("Consulta");
    connect(button, SIGNAL(clicked()), this, SLOT(searchContact()));
    box->addButton(button, QDialogButtonBox::AcceptRole);

    button = new QPushButton("Cadastro");
    connect(button, SIGNAL(clicked()), this, SLOT(registerForm()));
    box->addButton(button, QDialogButtonBox::AcceptRole);

    layout->addWidget(new QLabel("Agendinha"));
    layout->addWidget(box);

    setWindowTitle("AGENDA");
   }

void Schedule::registerForm()
{
    Register *registerContact = new Register(this);
    registerContact->show();
}

void Schedule::searchContact()
{
    Search *search = new Search(this);
    search->show();
}

void Schedule::sairClicked()
{
    QWidget::close();
}

