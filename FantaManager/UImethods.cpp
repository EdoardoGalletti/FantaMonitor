#include "UImethods.h"

UImethods::UImethods()
{

}

void UImethods::AlignToCenter(QWidget* window){
    QList<QScreen *> AvailableScreens;
    AvailableScreens = QGuiApplication::screens();
    QScreen* screen = AvailableScreens.first();
    window->setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    window->size(),
                    screen->availableGeometry()
                    )
                );
}
