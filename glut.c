#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int width = 500, height = 500;

float rad = 0.0174533;
double pos_x, pos_y, pos_z;

GLfloat matriz_transf[16] = {1, 0, 0, 0,
							 0, 1, 0, 0,
							 0, 0, 1, 0,
							 0, 0, 0, 1};

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void grid();

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;
}

void init(void)
{
	glClearColor(0, 0, 0, 0); // Cor do buffer
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1000, 1000); // Projeção ortogonal
}

void display(void)
{
	double rot11, rot12, rot21, rot22;
	rot11 = cos(rad);
	rot12 = sin(rad);
	rot21 = sin(-rad);
	rot22 = cos(rad);


	GLfloat matriz_rot[16] = {rot11, rot12, 0, 0,
							  rot21, rot22, 0, 0,
							  0, 0, 1, 0,
							  pos_x, pos_y, pos_z, 1};

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// glMultMatrixf(matriz_transf);
	// glMultMatrixf(matriz_rot);
	glMultMatrixf(matriz_rot);

	// glTranslated(250, 10, 0);
	// glScalef(2.5, 2.5, 1);
	// glTranslatef(-250, -10, 0);

	// glBegin(GL_TRIANGLES);
	// 	glColor3f(1.0, 1.0, 0.8);
	// 	glVertex2f(250, 100);
	// 	glVertex2f(350, 250);
	// 	glVertex2f(150, 250);
	// glEnd();

	glutWireTeapot(150);

	glFlush(); // Envia o desenho para o framebuffer
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

	case 'q':
	case 27:
		exit(0);
		break;
	}
	glutPostRedisplay();
}