#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<string.h>
#define TEXTID      3
static GLfloat theta[]={0.0,0.0,0.0};
static GLfloat zeta[]={0.0,0.0,0.0};
static int value = 0;
static int window;
static int menu_id;
static int submenu_id;
static int stateofRotation = 1;
static int stateofDancing = 1;
static int color = 0;
static float scaling = 1;
GLfloat vertices[][3]={{-0.3,0.7,-0.1},
{0.3,0.7,-0.1},
{0.5,1.3,-0.2},
{-0.5,1.3,-0.2},
{-0.3,0.7,0.1},
{0.3,0.7,0.1},
{0.5,1.3,0.2},
{-0.5,1.3,0.2}};

GLfloat normals[][3]={{-0.3,0.7,-0.1},
{0.3,0.7,-0.1},
{0.5,1.3,-0.2},
{-0.5,1.3,-0.2},
{-0.3,0.7,0.1},
{0.3,0.7,0.1},
{0.5,1.3,0.2},
{-0.5,1.3,0.2}};

GLfloat verticesofBody[][3]={{-0.3,-0.5,-0.1},
{0.3,-0.5,-0.1},
{0.3,0.5,-0.1},
{-0.3,0.5,-0.1},
{-0.3,-0.5,0.1},
{0.3,-0.5,0.1},
{0.3,0.5,0.1},
{-0.3,0.5,0.1}};

GLfloat normalsofBody[][3]={{-0.3,-0.5,-0.1},
{0.3,-0.5,-0.1},
{0.3,0.5,-0.1},
{-0.3,0.5,-0.1},
{-0.3,-0.5,0.1},
{0.3,-0.5,0.1},
{0.3,0.5,0.1},
{-0.3,0.5,0.1}};

GLfloat verticesofLeftArm[][3]={{-0.6,0.0,-0.1},
{-0.4,0.0,-0.1},
{-0.4,0.5,-0.1},
{-0.6,0.5,-0.1},
{-0.6,0.0,0.1},
{-0.4,0.0,0.1},
{-0.4,0.5,0.1},
{-0.6,0.5,0.1}};

GLfloat normalsofLeftArm[][3]={{-0.6,0.0,-0.1},
{-0.4,0.0,-0.1},
{-0.4,0.5,-0.1},
{-0.6,0.5,-0.1},
{-0.6,0.0,0.1},
{-0.4,0.0,0.1},
{-0.4,0.5,0.1},
{-0.6,0.5,0.1}};

GLfloat verticesofRightArm[][3]={{0.4,0.0,-0.1},
{0.6,0.0,-0.1},
{0.6,0.5,-0.1},
{0.4,0.5,-0.1},
{0.4,0.0,0.1},
{0.6,0.0,0.1},
{0.6,0.5,0.1},
{0.4,0.5,0.1}};

GLfloat normalsofRightArm[][3]={{0.4,0.0,-0.1},
{0.6,0.0,-0.1},
{0.6,0.5,-0.1},
{0.4,0.5,-0.1},
{0.4,0.0,0.1},
{0.6,0.0,0.1},
{0.6,0.5,0.1},
{0.4,0.5,0.1}};

GLfloat verticesofLeftLeg[][3]={{-0.3,-1.3,-0.1},
{-0.1,-1.3,-0.1},
{-0.1,-0.7,-0.1},
{-0.3,-0.7,-0.1},
{-0.3,-1.3,0.1},
{-0.1,-1.3,0.1},
{-0.1,-0.7,0.1},
{-0.3,-0.7,0.1}};

GLfloat normalsofLeftLeg[][3]={{-0.3,-1.3,-0.1},
{-0.1,-1.3,-0.1},
{-0.1,-0.7,-0.1},
{-0.3,-0.7,-0.1},
{-0.3,-1.3,0.1},
{-0.1,-1.3,0.1},
{-0.1,-0.7,0.1},
{-0.3,-0.7,0.1}};

GLfloat verticesofRightLeg[][3]={{0.1,-1.3,-0.1},
{0.3,-1.3,-0.1},
{0.3,-0.7,-0.1},
{0.1,-0.7,-0.1},
{0.1,-1.3,0.1},
{0.3,-1.3,0.1},
{0.3,-0.7,0.1},
{0.1,-0.7,0.1}};

GLfloat normalsofRightLeg[][3]={{0.1,-1.3,-0.1},
{0.3,-1.3,-0.1},
{0.3,-0.7,-0.1},
{0.1,-0.7,-0.1},
{0.1,-1.3,0.1},
{0.3,-1.3,0.1},
{0.3,-0.7,0.1},
{0.1,-0.7,0.1}};



GLfloat colors[][3]={{0.0,0.0,0.0},
{1.0,0.0,0.0},
{1.0,1.0,0.0},
{0.0,1.0,0.0},
{0.0,0.0,1.0},
{1.0,0.0,1.0},
{1.0,1.0,1.0},
{0.0,1.0,1.0}};

void polygon(int a, int b, int c, int d)
{
    glPushMatrix();
    glRotatef(theta[2],0.0,1.0,1.0);

	glBegin(GL_POLYGON);
		glColor3fv(colors[a]);
		glNormal3fv(normals[a]);
		glVertex3fv(vertices[a]);

		glColor3fv(colors[b]);
		glNormal3fv(normals[b]);
		glVertex3fv(vertices[b]);

		glColor3fv(colors[c]);
		glNormal3fv(normals[c]);
		glVertex3fv(vertices[c]);

		glColor3fv(colors[d]);
		glNormal3fv(normals[d]);
		glVertex3fv(vertices[d]);

	glEnd();
    glPopMatrix();
}

void rightArm(int a, int b, int c, int d)
{     glPushMatrix();
    glRotatef(-theta[2],1.0,1.0,0.0);
	glBegin(GL_POLYGON);
		glColor3fv(colors[a]);
		glNormal3fv(normalsofRightArm[a]);
		glVertex3fv(verticesofRightArm[a]);

		glColor3fv(colors[b]);
		glNormal3fv(normalsofRightArm[b]);
		glVertex3fv(verticesofRightArm[b]);

		glColor3fv(colors[c]);
		glNormal3fv(normalsofRightArm[c]);
		glVertex3fv(verticesofRightArm[c]);

		glColor3fv(colors[d]);
		glNormal3fv(normalsofRightArm[d]);
		glVertex3fv(verticesofRightArm[d]);

	glEnd();
  glPopMatrix();
}


void leftArm(int a, int b, int c, int d)
{ glPushMatrix();
    glRotatef(theta[2],1.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glColor3fv(colors[a]);
		glNormal3fv(normalsofLeftArm[a]);
		glVertex3fv(verticesofLeftArm[a]);

		glColor3fv(colors[b]);
		glNormal3fv(normalsofLeftArm[b]);
		glVertex3fv(verticesofLeftArm[b]);

		glColor3fv(colors[c]);
		glNormal3fv(normalsofLeftArm[c]);
		glVertex3fv(verticesofLeftArm[c]);

		glColor3fv(colors[d]);
		glNormal3fv(normalsofLeftArm[d]);
		glVertex3fv(verticesofLeftArm[d]);

	glEnd();
  glPopMatrix();
}



void body(int a, int b, int c, int d) {
  glPushMatrix();
     glRotatef(-theta[2]/2.0,1.0,1.0,0.0);
  glBegin(GL_POLYGON);
    glColor3fv(colors[a]);
    glNormal3fv(normalsofBody[a]);
    glVertex3fv(verticesofBody[a]);

    glColor3fv(colors[b]);
    glNormal3fv(normalsofBody[b]);
    glVertex3fv(verticesofBody[b]);

    glColor3fv(colors[c]);
    glNormal3fv(normalsofBody[c]);
    glVertex3fv(verticesofBody[c]);

    glColor3fv(colors[d]);
    glNormal3fv(normalsofBody[d]);
    glVertex3fv(verticesofBody[d]);

  glEnd();
  glPopMatrix();
}

void leftLeg(int a, int b, int c, int d) {
  glPushMatrix();
     glTranslatef(0.0,-theta[2]/180.0,0.0);
  glBegin(GL_POLYGON);
    glColor3fv(colors[a]);
    glNormal3fv(normalsofLeftLeg[a]);
    glVertex3fv(verticesofLeftLeg[a]);

    glColor3fv(colors[b]);
    glNormal3fv(normalsofLeftLeg[b]);
    glVertex3fv(verticesofLeftLeg[b]);

    glColor3fv(colors[c]);
    glNormal3fv(normalsofLeftLeg[c]);
    glVertex3fv(verticesofLeftLeg[c]);

    glColor3fv(colors[d]);
    glNormal3fv(normalsofLeftLeg[d]);
    glVertex3fv(verticesofLeftLeg[d]);

  glEnd();
  glPopMatrix();
}
void rightLeg(int a, int b, int c, int d)
{  glPushMatrix();
     glTranslatef(0.0,-theta[2]/180.0,0.0);
     glRotatef(theta[2],1.0,0.0,1.0);
	glBegin(GL_POLYGON);
		glColor3fv(colors[a]);
		glNormal3fv(normalsofRightLeg[a]);
		glVertex3fv(verticesofRightLeg[a]);

		glColor3fv(colors[b]);
		glNormal3fv(normalsofRightLeg[b]);
		glVertex3fv(verticesofRightLeg[b]);

		glColor3fv(colors[c]);
		glNormal3fv(normalsofRightLeg[c]);
		glVertex3fv(verticesofRightLeg[c]);

		glColor3fv(colors[d]);
		glNormal3fv(normalsofRightLeg[d]);
		glVertex3fv(verticesofRightLeg[d]);

	glEnd();
  glPopMatrix();
}
void colorcube(void)
{
	polygon(0,3,2,1);
	polygon(2,3,7,6);
	polygon(0,4,7,3);
	polygon(1,2,6,5);
	polygon(4,5,6,7);
	polygon(0,1,5,4);
}
void colorbody(void)
{
	body(0,3,2,1);
	body(2,3,7,6);
	body(0,4,7,3);
	body(1,2,6,5);
	body(4,5,6,7);
	body(0,1,5,4);
}
void colorLeg(void) {
  leftLeg(0,3,2,1);
  leftLeg(2,3,7,6);
  leftLeg(0,4,7,3);
  leftLeg(1,2,6,5);
  leftLeg(4,5,6,7);
  leftLeg(0,1,5,4);
}
void colorRightLeg(void) {
  rightLeg(0,3,2,1);
  rightLeg(2,3,7,6);
  rightLeg(0,4,7,3);
  rightLeg(1,2,6,5);
  rightLeg(4,5,6,7);
  rightLeg(0,1,5,4);
}
void colorLeftArm(void) {
  leftArm(0,3,2,1);
  leftArm(2,3,7,6);
  leftArm(0,4,7,3);
  leftArm(1,2,6,5);
  leftArm(4,5,6,7);
  leftArm(0,1,5,4);
}

void colorRightArm(void) {
  rightArm(0,3,2,1);
  rightArm(2,3,7,6);
  rightArm(0,4,7,3);
  rightArm(1,2,6,5);
  rightArm(4,5,6,7);
  rightArm(0,1,5,4);
}

static GLint axis=4;
void DrawTextXY(double x,double y,double z,double scale,char *s)
{
   int i;

   glPushMatrix();
   glTranslatef(x,y,z);
   glScalef(scale,scale,scale);
   for (i=0;i < strlen(s);i++)
      glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,s[i]);
   glPopMatrix();
}

void display(void)
{
  if(value == 0){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glClearColor(0.0,0,0,0.0);

	glTranslatef(0.0,0.0,-6.0);
	glTranslatef(0.0,-1.3,0.0);

		glColor3f(1.00,0.20,0.10);
	glLoadName(TEXTID);


	DrawTextXY(-1.7,3.5,0.0,0.001,"   GRAPHICAL IMPLEMENTATION OF  ");

	glColor3f(0.6,0.8,0.7);
	DrawTextXY(-1.75,3,0.0,0.0014,"    DANCING ROBOT ");

	glColor3f(0.7,0.6,0.1);
	DrawTextXY(-3.25,1.5,0.0,0.0007,"     Submitted by :- ");

	glColor3f(1.0,0.5,0.0);
	DrawTextXY(-2.5,1.2,0.0,0.001,"     Ankit Chauhan");
	glColor3f(0.7,0.8,0.6);
	DrawTextXY(-2.5,0.95,0.0,0.001,"    1BI14CS024  ");

	glColor3f(0.7,0.6,0.1);
	DrawTextXY(-1.25,0,0.0,0.0007,"     Under the guidance of : ");
	glColor3f(1.0,0.8,0.4);
	DrawTextXY(-1.25,-.2,0.0,0.001,"     Name of Guide");
	DrawTextXY(-1,-.5,0.0,0.0007,"     Designation ");
	DrawTextXY(-1,-.7,0.0,0.001,"       College Name");
	glColor3f(0.3,0.3,0.3);
	DrawTextXY(-1,-1,0.0,0.0008,"     Press any key... ");
  glFlush();
	glutSwapBuffers();
} else {
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  if(color == 0){
    glClearColor(0.0,0,0,0.0);
  } else {
    glClearColor(1.0,1,1.0,1.0);
  }
  glScalef(scaling,scaling,scaling);
  glRotatef(zeta[0],1.0,0.0,0.0);
  glRotatef(zeta[1],0.0,1.0,0.0);
  glRotatef(zeta[2],0.0,0.0,1.0);
  colorcube();
  colorbody();
  colorLeg();
  colorRightLeg();
  colorLeftArm();
  colorRightArm();
  glFlush();
  glutSwapBuffers();
}
}
int state = 0;
void increase() {
  theta[2]+=1.0;
}
void decrease() {
  theta[2]-=1.0;
}
void doCoolStuff()
{
  if(stateofRotation == 0 && stateofDancing == 0){
  zeta[axis]+=0.5;
  if(zeta[axis]>360.0)zeta[axis]-=360.0;
  if(state == 0){
    increase();
    if(theta[2]>25.0){
      state=1;
    }
  } else {
    decrease();
    if(theta[2]<-25.0){
      state=0;
    }
  }
} else if(stateofRotation == 0 && stateofDancing == 1){
  zeta[axis]+=0.5;
  if(zeta[axis]>360.0)zeta[axis]-=360.0;
} else if(stateofRotation == 1 && stateofDancing == 0){
  if(state == 0){
    increase();
    if(theta[2]>25.0){
      state=1;
    }
  } else {
    decrease();
    if(theta[2]<-25.0){
      state=0;
    }
  }
} else {
  //do nothing
}

	glutPostRedisplay();
}
void mouse(int btn, int state, int x, int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)axis=4;
	if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)axis=1;
	if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)axis=1;
}
void reshape(int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
	glOrtho(-2.0,2.0,-2.0*((GLfloat)h/(GLfloat)w),2.0*((GLfloat)h/(GLfloat)w),-10.0,10.0);
	else
	glOrtho(-2.0*((GLfloat)w/(GLfloat)h),2.0*((GLfloat)w/(GLfloat)h),-2.0,2.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
}
void menu(int num){
  if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
    switch(value)
		{
		case 9:color=0;
			 break;
       case 10:color=1;
   			 break;
		case 8:
			 break;
		case 7:axis=4;
    stateofRotation = 1;
			 break;
		case 6:axis=1;
    stateofRotation = 0;
			 break;
		case 11:
		scaling=scaling+0.2;
			break;
		case 12:
		scaling=scaling-0.2;
    break;
    case 4:
    	stateofDancing = 0;
    break;
    case 5:
    	stateofDancing = 1;
    break;
			break;
		}
  }
  glutPostRedisplay();
}
void createMenu(void)
{
	int sub_menu=glutCreateMenu(menu);
	//glutAddMenuEntry("RANDOM",3);
        glutAddMenuEntry("START",4);
        glutAddMenuEntry("STOP",5);

	int sub_menu1=glutCreateMenu(menu);//ZOOM
	glutAddMenuEntry("START",6);
        glutAddMenuEntry("STOP",7);
        int sub_menu2=glutCreateMenu(menu);//JUMP
	glutAddMenuEntry("Black",9);
        glutAddMenuEntry("White",10);
        int sub_menu3=glutCreateMenu(menu);//ROTATE
	glutAddMenuEntry("ScaleUp",11);
        glutAddMenuEntry("ScaleDown",12);

	glutCreateMenu(menu);
	glutAddSubMenu("Dance",sub_menu);
	glutAddSubMenu("Rotate",sub_menu1);
	glutAddSubMenu("Color",sub_menu2);
	glutAddSubMenu("Scale",sub_menu3);
	glutAddMenuEntry("Quit", 0);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void keys(unsigned char key,int x,int y)
{
	switch(key)
	{
		default: value = 1;
	}
}
void main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("Dancing Robot");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	// glutMouseFunc(mouse);
      glutIdleFunc(doCoolStuff);
  	glutKeyboardFunc(keys);
    createMenu();
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}
