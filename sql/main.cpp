#include "schedule.h"

#include <QApplication>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Schedule schedule;
    schedule.show();

    return app.exec();
}

