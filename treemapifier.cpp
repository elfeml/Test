#include "maininterfacewindow.h"
#include <QApplication>
#include "GL/freeglut.h"
#include "GL/glut.h"
#include <windows.h>
int main(int argc, char *argv[])
{
       // glutInit(&argc, argv);
//        glutInitWindowSize(640,480);
//        glutInitWindowPosition(10,10);
//        glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
//        glutMainLoop();
    QApplication a(argc, argv);
    MainInterfaceWindow w;
    w.show();

    return a.exec();
}
