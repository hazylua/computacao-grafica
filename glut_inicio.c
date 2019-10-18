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

int main(int argc, char** argv) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE  | GLUT_RGB);  // Especifica o buffer a ser utilizado
        glutInitWindowSize(width,height);  // Dimensoes da Janela em pixels
        glutInitWindowPosition(100,100); // Especifica coordenada superior esquerda
        glutCreateWindow("Janela Inicial"); // Cria a janela mas só exibe após mainLoop
        init();
        glutDisplayFunc(display);
        glutKeyboardFunc(keyboard);
        glutMainLoop();

return 0;
}

void init(void){
        glClearColor(0.0,0.0,0.0,1.0); // Cor do buffer
        glOrtho(0, width, 0, height, -1, 1); // Projeção ortogonal
}
void display(void){

        glClear(GL_COLOR_BUFFER_BIT);   // Limpa para a cor do buffer
        glLineWidth(1.0f);
		int i;

        glColor3f(1, 1, 1);

        glBegin(GL_TRIANGLE_FAN);
                glVertex2f(250, 250);
                glVertex2f(150, 200); // 1
				glVertex2f(260, 100); // 2
				glVertex2f(380, 100); // 3
				glVertex2f(410, 200); // 4
				glVertex2f(360, 360); // 6
				glVertex2f(220, 380); // 7
				glVertex2f(170, 360); // 8
				glVertex2f(150, 200); // 1
        glEnd();

		glColor3f(1, 0, 0);
		glPointSize(10.0f);
		glBegin(GL_POINTS);
			glVertex2f(250, 250);
			glVertex2f(150, 200); // 1
			glVertex2f(260, 100); // 2
			glVertex2f(380, 100); // 3
			glVertex2f(410, 200); // 4
			glVertex2f(360, 360); // 6
			glVertex2f(220, 380); // 7
			glVertex2f(170, 360); // 8
			glVertex2f(150, 200); // 1
		glEnd();

		glBegin(GL_LINES);
			glVertex2f(250, 250);
			glVertex2f(150, 200); // 1
			glVertex2f(250, 250);
			glVertex2f(260, 100); // 2
			glVertex2f(250, 250);
			glVertex2f(380, 100); // 3
			glVertex2f(250, 250);
			glVertex2f(410, 200); // 4
			glVertex2f(250, 250);
			glVertex2f(360, 360); // 6
			glVertex2f(250, 250);
			glVertex2f(220, 380); // 7
			glVertex2f(250, 250);
			glVertex2f(170, 360); // 8
			glVertex2f(250, 250);
			glVertex2f(150, 200); // 1
		glEnd();

        glFlush(); // Envia o desenho para o framebuffer
}

void keyboard(unsigned  char key, int x, int y){
        switch (key) {
                case 'q':
                case 27:
                        exit(0);
                        break;
        }
        glutPostRedisplay();
}

//gcc glut.c -o glut -lGL -lglut
//./glut
//RED BOOK OPENGL

//  glBegin(GL_LINE_STRIP);
//                 glVertex2f(0,0);
//                 glVertex2f(100,100);ransformadaordenadas dos pontos inicial e final
//                 glVertex2f(100,100);ransformada
//                 glVertex2f(200,120);ransformada
//                 glVertex2f(200,120);
//                 glVertex2f(0,0);
//         glEnd();

// glBegin(GL_TRIANGLES);
//         glColor3f(0.8, 0.4, 0.2);
//                 glVertex2f(0,0);
//                 glVertex2f(100,100);  // Coordenadas dos pontos inicial e final
//                 glVertex2f(200,120);

//                 glColor3f(0.2, 0.8, 1.0);
//                 glVertex2f(200,120);
//                 glVertex2f(240,60);
//                 glVertex2f(0.0,0.0);

//         glEnd();

// glBegin(GL_TRIANGLE_STRIP);
//         glColor3f(0.8, 0.3, 0.9);
//                 glVertex2f(100,100);
//                 glVertex2f(0,0); // Coordenadas dos pontos inicial e final
//                 glVertex2f(200,120);

//                 glColor3f(0.2, 0.8, 1.0);
//                 glVertex2f(240,60);

//         glEnd();

// glTranslatef(50,50,00);   TRANSLAÇÃO glTranslatef para float e glTranslated para int
//         glBegin(GL_TRIANGLES);
//         glColor3f(0.8, 0.4, 0.2);
//                 glVertex2f(0,0);
//                 glVertex2f(100,100);  // Coordenadas dos pontos inicial e final
//                 glVertex2f(200,0);

//         glEnd();

// glScaled(2,2,1);  ESCALA  ///se for inteiro glScaled e se for float glScalef
//         glBegin(GL_TRIANGLES);
//         glColor3f(0.8, 0.4, 0.2);
//                 glVertex2f(0,0);
//                 glVertex2f(100,100);  // Coordenadas dos pontos inicial e final
//                 glVertex2f(200,0);
//         glEnd();

//GRID