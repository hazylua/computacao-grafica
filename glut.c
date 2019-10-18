#include <GL/glut.h>
#include <stdlib.h>
#include <unistd.h>

int width = 500, height = 500;

int rot = 0;
int y_pos = 0;
int x_pos = 0;

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
	glClearColor(0.0, 1.0, 0.0, 1.0);		// Cor do buffer
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1000, 1000);	// Projeção ortogonal
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 2.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslated(x_pos, y_pos, 0);

	glTranslated(250, 100, 0);
	glRotatef(rot, 0, 0, 1);
	glTranslated(-250, -100, 0);

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

	glFlush();	// Envia o desenho para o framebuffer
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '+':
		rot += 5;
		break;
	case '-':
		rot -= 5;
		break;

	case '8':
		y_pos += 10;
		break;
	case '2':
		y_pos -= 10;
		break;
	case '4':
		x_pos -= 10;
		break;
	case '6':
		x_pos += 10;
		break;

	case 'q':
	case 27:
		exit(0);
		break;
	}
	glutPostRedisplay();
}