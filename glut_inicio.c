#include <GL/glut.h>
#include <stdlib.h>
#include <stdbool.h>

int width = 500,
	height = 500;

// Declarações
void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void grid();

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Especifica o buffer a ser utilizado
	glutInitWindowSize(width, height);			 // Dimensoes da Janela em pixels
	glutInitWindowPosition(100, 100);			 // Especifica coordenada superior esquerda
	glutCreateWindow("Janela Inicial");			 // Cria a janela mas só exibe após mainLoop
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;
}

void init(void)
{
	glClearColor(1, 1, 1, 1);	// Cor do buffer
	glOrtho(0, width, 0, height, -1, 1); // Projeção ortogonal
}
void display(void)
{

	glClear(GL_COLOR_BUFFER_BIT); // Limpa para a cor do buffer
	glLineWidth(1.0f);
	glPointSize(5.0f);

	int i;
	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_LINES);
	for(i = 0; i <= 500; i += 10)
	{
		glVertex2d(0, i);
		glVertex2d(width, i);

		glVertex2d(i, 0);
		glVertex2d(i, height);
	}
	
	// Eixo X
	glColor3f(1, 0, 0);
	glVertex2d(0, height/2);
	glVertex2d(width, height/2);

	// Eixo Y
	glColor3f(0, 0, 1);
	glVertex2d(width/2, 0);
	glVertex2d(width/2, height);

	glEnd();

	glFlush(); // Envia o desenho para o framebuffer
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
	case 27:
		exit(0);
		break;
	}
	glutPostRedisplay();
}