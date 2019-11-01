#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

const int width = 500, height = 500;

float rad = 0, alpha = 0, beta = 0;
double pos_x = 0, pos_y = 0, pos_z = 0;
double scale11 = 1, scale22 = 1, scale33 = 1;

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);

// Displays
void grid();
void square();

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}

void init(void)
{
    glClearColor(1, 1, 1, 1); // Cor do buffer
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1000, 1000); // Projeção ortogonal
}

void grid(void)
{
    int i;
    glLineWidth(1.0f);
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_LINES);
    for (i = 0; i <= width; i += 10)
    {
        glVertex2d(0, i);
        glVertex2d(width, i);

        glVertex2d(i, 0);
        glVertex2d(i, height);
    }

    // Eixo X
    glColor3f(1, 0, 0);
    glVertex2d(0, height / 2);
    glVertex2d(width, height / 2);

    // Eixo Y
    glColor3f(0, 0, 1);
    glVertex2d(width / 2, 0);
    glVertex2d(width / 2, height);

    glEnd();
}

void square(void)
{
    glColor3f(0.2, 0.0, 0.4);
    glBegin(GL_QUADS);
    glVertex2d(-100, 100);
    glVertex2d(100, 100);
    glVertex2d(100, -100);
    glVertex2d(-100, -100);
    glEnd();
}

void display(void)
{
    GLfloat matriz_transf[16] = {1*cos(rad), sin(rad), 0, 0,
                                 -1*sin(rad), 1*cos(rad)*cos(alpha), sin(alpha), 0,
                                 0, -1*sin(alpha), cos(alpha), 0,
                                 pos_x + width/2, pos_y + height/2, 0, 1};

    glClear(GL_COLOR_BUFFER_BIT); // Limpa para a cor do buffer
    

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    grid();

    glPushMatrix();
    glMultMatrixf(matriz_transf);
    square();
    glPopMatrix();

    // glFlush(); // Envia o desenho para o framebuffer
    printf("LOG:\n"
            "pos_x = %0.2f, pos_y = %0.2f, pos_z = %0.2f\n"
            "rad = %0.5f, degrees = %0.1f\n\n", pos_x, pos_y, pos_z, rad, rad*180/3.14);
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case '+':
        rad += 0.0174533;
        break;
    case '-':
        rad -= 0.0174533;
        break;

    case '8':
        pos_y += 10;
        break;
    case '2':
        pos_y -= 10;
        break;
    case '4':
        pos_x -= 10;
        break;
    case '6':
        pos_x += 10;
        break;
    case '9':
        pos_x += 10;
        pos_y += 10;
        break;
    case '7':
        pos_x -= 10;
        pos_y += 10;
        break;
    case '1':
        pos_x -= 10;
        pos_y -= 10;
        break;
    case '3':
        pos_x += 10;
        pos_y -= 10;
        break;

    case '/':
        alpha += 0.0174533;
        // scale11 -= 0.1;
        // scale22 -= 0.1;
        // scale33 -= 0.1;
        break;

    case '*':
        alpha -= 0.0174533;
        // scale11 += 0.1;
        // scale22 += 0.1;
        // scale33 += 0.1;
        break;

    case 'q':
    case 27:
        exit(0);
        break;
    }
    glutPostRedisplay();
}