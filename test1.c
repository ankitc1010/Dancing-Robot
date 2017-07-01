#include<stdio.h>
#include<GL/glut.h>
float i,j;
GLfloat x=6.0,y=37.0,z=10.0;
GLfloat body[][2]={{2,2},{4,2},{5,2.5},{6,3},{9,6},{9.5,7},{10,8},{10.5,8.5},{11,9},{11.5,9.5},{12,10},{11,10.5},{10,11},{9,11.5},{8,11},{7,10.8},{6,10.5},{5,10},{4,9.9},{3,9.3},{2.5,9},{1.5,8},{1,7},{0.5,6},{0.5,4},{1,3}};
GLfloat arm[][2]={{6,4},{7,3.5},{8,3},{8.5,3},{9.5,2.5},{9,3},{10,3.5},{9,3.5},{9.5,4.5},{8.5,3.5},{7.5,4.5},{8,5},{8,6},{7,7},{6,6}};
GLfloat leg[][2]={{2,0},{5.5,0},{5,0.5},{5.5,1},{4.5,1},{5,1.5},{4,1},{3.5,1.5},{3.5,2},{3,2.5},{1.5,4},{0,4},{0,2}};
GLfloat eye[][2]={{8.25,10},{8.5,9.7},{9.1,9.7},{9.6,10},{9.1,10.25},{8.5,10.25}};
static float scale = 1.0;
static float rotateAngle = 0.0;
void frog()
{
	int i;
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glColor3f(1.0,0.0,0.0);//body
	glBegin(GL_POLYGON);
	for(i=0;i<26;i++)
	glVertex3f(body[i][0],body[i][1],-1.0);
	glEnd();
	glColor3f(1.0,0.85,0.0);//leg
	glBegin(GL_POLYGON);
	for(i=0;i<13;i++)
	glVertex2f(leg[i][0],leg[i][1]);
	glEnd();
	glColor3f(0.0,0.0,0.0);//eye
	glBegin(GL_POLYGON);
	for(i=0;i<6;i++)
	glVertex2f(eye[i][0],eye[i][1]);
	glEnd();
	//glFlush();
}
void frogArm()
{
	int i;
	glColor3f(1.0,0.80,0.0);//arm
	glBegin(GL_POLYGON);
	for(i=0;i<15;i++)
	glVertex2f(arm[i][0],arm[i][1]);
	glEnd();
}
void grass()
{
	glBegin(GL_POLYGON);
	glColor3f(0.0,1.0,0.0);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glVertex3f(2.0,0.0,0.0);
	glVertex3f(2.0,0.0,3.0);
	glVertex3f(0.0,3.0,0.0);
	glVertex3f(0.0,3.0,3.0);
	glVertex3f(2.5,1.0,0.0);
	glVertex3f(2.5,1.0,3.0);
	glVertex3f(4.0,4.0,0.0);
	glVertex3f(4.0,4.0,3.0);
	glVertex3f(5.0,1.5,0.0);
	glVertex3f(5.0,1.5,3.0);
	glVertex3f(7.5,3.0,0.0);
	glVertex3f(7.5,3.0,3.0);
	glVertex3f(6.0,0.0,0.0);
	glVertex3f(6.0,0.0,3.0);
	glEnd();
}
void leaf()
{	glPushMatrix();
		glRotatef(rotateAngle,0.0,0.0,1.0);
	glutSolidSphere(8,10,10);
	glPopMatrix();


}

void idleFunction()
{ rotateAngle+=0.5;
  if(rotateAngle>360.0)rotateAngle-=360.0;
	glutPostRedisplay();
}
void grassland()
{
	glColor3f(0.0,1.0,0.0);
	for(i=0.0;i<100;i+=8.0){
	for(j=0.0;j<25;j+=5.0){
	glPushMatrix();
 	glTranslatef(i,j,0.0);
 	grass();
   	glPopMatrix();
   	glutPostRedisplay();
   	}}
   	for(i=0.0;i<100;i+=8.0){
	for(j=75.0;j<100;j+=5.0){
	glPushMatrix();
 	glTranslatef(i,j,0.0);
 	grass();
   	glPopMatrix();
   	glutPostRedisplay();
   	}}
   	glColor3f(0.0,0.30,0.0);
   	for(i=10;i<100;i+=50){
   	glPushMatrix();
	glTranslatef(i,40,0.0);
	leaf();
	glPopMatrix();
	glutPostRedisplay();
	}
	for(i=35;i<100;i+=50){
   	glPushMatrix();
	glTranslatef(i,60,0.0);
	leaf();
	glPopMatrix();
	glutPostRedisplay();
	}

}
void moveFrog()
{
	glPushMatrix();
	glTranslatef(scale+5,y,z);//6,37,10//56,37,10//32,57,10
	//  glScalef(scale,scale,0.0);
	frog();
	frogArm();
	glPopMatrix();
	glutPostRedisplay();
}
void Redisplay()
{
	moveFrog();
}
void display()
{
	GLfloat i[]={2.0,3.0,-2.0,-3.0,7.0};
	int j;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	grassland();//grass();
	moveFrog();
	glFlush();
}
void keys(unsigned char key,int x,int y)
{
	switch(key)
	{
		case 'd':glutIdleFunc(NULL);
			 break;
		case 'm':scale=scale+1.0;
			 break;
		case 'n':glutIdleFunc(idleFunction);
			 break;
		case ' ':x=50;
			 Redisplay();
			 break;
	}
	glutPostRedisplay();//display();
}
void init()
{
	glClearColor(0.0,0.0,0.4,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,100.0,0.0,100.0,-10.0,90.0);
	glMatrixMode(GL_MODELVIEW);
}
void myReshape(int w,int h)
{
	glViewport(0,0,w,h);
}
static int window;
static int menu_id;
static int submenu_id;
static int value = 0;
void menu(int num){
  if(num == 0){
    glutDestroyWindow(window);
    exit(0);
  }else{
    value = num;
  }
  glutPostRedisplay();
}
void createMenu(void){     submenu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Sphere", 2);
    glutAddMenuEntry("Cone", 3);
    glutAddMenuEntry("Torus", 4);
    glutAddMenuEntry("Teapot", 5);     menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Clear", 1);
    glutAddSubMenu("Draw", submenu_id);
    glutAddMenuEntry("Quit", 0);     glutAttachMenu(GLUT_RIGHT_BUTTON);
}
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1280,720);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Structure of frog");
	glutDisplayFunc(display);
	glutKeyboardFunc(keys);
	glutReshapeFunc(myReshape);
	init();
	  createMenu();
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}
