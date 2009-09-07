#include "schedule.h"

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
}

