#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <string.h>
#include <GL/freeglut.h>


GLfloat right_bird_position = -0.4f;
GLfloat right_bird_speed = 0.0008f;


void *font;
#define PI 3.14159265358979323846
GLfloat i = 0.0f;
GLfloat position_cloud1x = 0.0f;
GLfloat position_cloud2x = 0.0f;
GLfloat position_cloud3x = 0.0f;

//Train Position & Speed
GLfloat train1_position = -1.3f;
GLfloat train1_speed = 0.0014f;
GLfloat train2_position = 1.5f;
GLfloat train2_speed = 0.0014f;
//cloud
GLfloat cloud1_position = 1.2f;
GLfloat cloud1_speed = 0.0003f;

GLfloat cloud2_position = 1.3f;
GLfloat cloud2_speed = 0.00032f;

GLfloat cloud3_position = 1.5f;
GLfloat cloud3_speed = 0.00035f;

void renderBitmapString(float x, float y, float z, void *font, const char *string)
{
    const char *c;
    glRasterPos3f(x, y, z);

    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}
/*
void renderBitmapString(float x, float y, float z, void *font, const std::string& string) {
    glRasterPos3f(x, y, z);
    for (char c : string) {
        glutBitmapCharacter(font, c);
    }
}

// Function to calculate and set responsive text position
void setResponsiveTextPosition(const std::string& text, float& x, float& y) {
    // Get window dimensions
    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);

    // Calculate text width (approximate)
    float textWidth = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)text.c_str());

    // Calculate center position for x (horizontally centered)
    x = (width / 2.0f) - (textWidth / 2.0f);

    // Calculate center position for y (vertically centered)
    y = (height / 2.0f) - (glutBitmapHeight(GLUT_BITMAP_HELVETICA_18) / 2.0f);
}

*/
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        // Increase train speeds on left mouse button press
        train1_speed += 0.0002f;
        train2_speed += 0.0002f;
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        // Decrease train speeds on right mouse button press
        train1_speed -= 0.0002f;
        train2_speed -= 0.0002f;

        // Ensure speeds don't become negative
        train1_speed = (train1_speed < 0.0f) ? 0.0f : train1_speed;
        train2_speed = (train2_speed < 0.0f) ? 0.0f : train2_speed;
    }
}



void train1_update(int value)
{
    if(train1_position >3.0)
        train1_position = -2.2f;
    train1_position += train1_speed;

    glutPostRedisplay();
    glutTimerFunc(1, train1_update, 0);
}
void train2_update(int value)
{
    if(train2_position <-3.0)
        train2_position = 1.5f;
    train2_position -= train2_speed;

    glutPostRedisplay();
    glutTimerFunc(1, train2_update, 0);
}
//cloud
void cloud1_update(int value)
{
    if(cloud1_position <-1.2)
        cloud1_position = 1.5f;
    cloud1_position -= cloud1_speed;

    glutPostRedisplay();
    glutTimerFunc(1, cloud1_update, 0);
}

void cloud2_update(int value)
{
    if(cloud2_position <-1.3)
        cloud2_position = 1.5f;
    cloud2_position -= cloud2_speed;

    glutPostRedisplay();
    glutTimerFunc(1, cloud2_update, 0);
}

void cloud3_update(int value)
{
    if(cloud3_position <-1.5)
        cloud3_position = 1.5f;
    cloud3_position -= cloud3_speed;

    glutPostRedisplay();
    glutTimerFunc(1, cloud3_update, 0);
}


void drawCircle(float x, float y, float radius);
//Birds
void circle_bird(float x1, float y1, float r)
{

    int i;

    GLfloat x=x1;
    GLfloat y=y1;
    GLfloat radius =r;
    int triangleAmount = 100; //# of lines used to draw circle

    // Get the aspect ratio of the window
    int width2 = glutGet(GLUT_WINDOW_WIDTH);
    int height2 = glutGet(GLUT_WINDOW_HEIGHT);
    GLfloat aspect2 = (GLfloat)height2 / (GLfloat)width2; // Aspect ratio (height/width)


    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glColor3ub(80, 80, 80);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)*aspect2),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
}


void circle(float x1,float y1, float r,char c)
{

    int i;
// Get the aspect ratio of the window
    int width2 = glutGet(GLUT_WINDOW_WIDTH);
    int height2 = glutGet(GLUT_WINDOW_HEIGHT);
    GLfloat aspect2 = (GLfloat)height2 / (GLfloat)width2; // Aspect ratio (height/width)

    GLfloat x=x1;
    GLfloat y=y1;
    GLfloat radius =r;
    int triangleAmount = 100; //# of lines used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;
    //glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {

        if(c=='s')
        {
            glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );

        }
        else
        {
            glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );

        }


    }
    glEnd();
}


//bird
void update_right_bird(int value)
{

    if (right_bird_position > 2.4f)
    {
        right_bird_position = -0.6f;
    }

    // Update the position
    right_bird_position += right_bird_speed;

    // Request display update
    glutPostRedisplay();

    // Register the timer callback again
    glutTimerFunc(3, update_right_bird, 0);
}

void bird_left1()
{
    float xAdjust=-0.06f;
    float yAdjust=0.05;

    glColor3ub(255, 140, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f + xAdjust, 0.508f + yAdjust);
    glVertex2f(-0.5f + xAdjust, 0.492f + yAdjust);
    glVertex2f(-0.48f + xAdjust, 0.50f + yAdjust);
    glEnd();

    glColor3ub(255,255, 0);

    glBegin(GL_QUADS);
    glVertex2f(-0.51f + xAdjust, 0.49f + yAdjust);
    glVertex2f(-0.53f + xAdjust, 0.55f + yAdjust);
    glVertex2f(-0.53f + xAdjust, 0.52f + yAdjust);
    glVertex2f(-0.52f + xAdjust, 0.47f + yAdjust);
    glEnd();


    glColor3ub(0, 0, 0);
    circle_bird(-0.5 + xAdjust, 0.5 + yAdjust, 0.01);
    glColor3ub(255,0,0);

    circle(-0.52 + xAdjust, 0.49 + yAdjust, 0.015, 'l');

    glColor3ub(255,255, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.52f + xAdjust, 0.49f + yAdjust);
    glVertex2f(-0.55f + xAdjust, 0.47f + yAdjust);
    glVertex2f(-0.535f + xAdjust, 0.465f + yAdjust);
    glVertex2f(-0.55f + xAdjust, 0.43f + yAdjust);
    glVertex2f(-0.515f + xAdjust, 0.485f + yAdjust);
    glEnd();
}
void bird_left2()
{
    float xAdjust=-0.06f;
    float yAdjust=0.09;

    glColor3ub(255, 140, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f + xAdjust, 0.508f + yAdjust);
    glVertex2f(-0.5f + xAdjust, 0.492f + yAdjust);
    glVertex2f(-0.48f + xAdjust, 0.50f + yAdjust);
    glEnd();



    glColor3ub(255,255, 0);

    glBegin(GL_QUADS);
    glVertex2f(-0.51f + xAdjust, 0.49f + yAdjust);
    glVertex2f(-0.53f + xAdjust, 0.55f + yAdjust);
    glVertex2f(-0.53f + xAdjust, 0.52f + yAdjust);
    glVertex2f(-0.52f + xAdjust, 0.47f + yAdjust);
    glEnd();


    glColor3ub(0, 0, 0);
    circle_bird(-0.5 + xAdjust, 0.5 + yAdjust, 0.01);
    glColor3ub(255,0,0);
    circle(-0.52 + xAdjust, 0.49 + yAdjust, 0.015, 'l');

    glColor3ub(255,255, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.52f + xAdjust, 0.49f + yAdjust);
    glVertex2f(-0.55f + xAdjust, 0.47f + yAdjust);
    glVertex2f(-0.535f + xAdjust, 0.465f + yAdjust);
    glVertex2f(-0.55f + xAdjust, 0.43f + yAdjust);
    glVertex2f(-0.515f + xAdjust, 0.485f + yAdjust);
    glEnd();
}

void bird_left3()
{
    float xAdjust=-0.12f;
    float yAdjust=0.03f;

    glColor3ub(255, 140, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f + xAdjust, 0.508f + yAdjust);
    glVertex2f(-0.5f + xAdjust, 0.492f + yAdjust);
    glVertex2f(-0.48f + xAdjust, 0.50f + yAdjust);
    glEnd();



    glColor3ub(255,255, 0);

    glBegin(GL_QUADS);
    glVertex2f(-0.51f + xAdjust, 0.49f + yAdjust);
    glVertex2f(-0.53f + xAdjust, 0.55f + yAdjust);
    glVertex2f(-0.53f + xAdjust, 0.52f + yAdjust);
    glVertex2f(-0.52f + xAdjust, 0.47f + yAdjust);
    glEnd();


    glColor3ub(0, 0, 0);
    circle_bird(-0.5 + xAdjust, 0.5 + yAdjust, 0.01);
    glColor3ub(255,0,0);
    circle(-0.52 + xAdjust, 0.49 + yAdjust, 0.015, 'l');

    glColor3ub(255,255, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.52f + xAdjust, 0.49f + yAdjust);
    glVertex2f(-0.55f + xAdjust, 0.47f + yAdjust);
    glVertex2f(-0.535f + xAdjust, 0.465f + yAdjust);
    glVertex2f(-0.55f + xAdjust, 0.43f + yAdjust);
    glVertex2f(-0.515f + xAdjust, 0.485f + yAdjust);
    glEnd();
}

void bird_left4()
{

    float xAdjust=-0.12f;
    float yAdjust=0.07;

    glColor3ub(255, 140, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f + xAdjust, 0.508f + yAdjust);
    glVertex2f(-0.5f + xAdjust, 0.492f + yAdjust);
    glVertex2f(-0.48f + xAdjust, 0.50f + yAdjust);
    glEnd();



    glColor3ub(255,255, 0);

    glBegin(GL_QUADS);
    glVertex2f(-0.51f + xAdjust, 0.49f + yAdjust);
    glVertex2f(-0.53f + xAdjust, 0.55f + yAdjust);
    glVertex2f(-0.53f + xAdjust, 0.52f + yAdjust);
    glVertex2f(-0.52f + xAdjust, 0.47f + yAdjust);
    glEnd();


    glColor3ub(0, 0, 0);
    circle_bird(-0.5 + xAdjust, 0.5 + yAdjust, 0.01);
    glColor3ub(255,0,0);
    circle(-0.52 + xAdjust, 0.49 + yAdjust, 0.015, 'l');

    glColor3ub(255,255, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.52f + xAdjust, 0.49f + yAdjust);
    glVertex2f(-0.55f + xAdjust, 0.47f + yAdjust);
    glVertex2f(-0.535f + xAdjust, 0.465f + yAdjust);
    glVertex2f(-0.55f + xAdjust, 0.43f + yAdjust);
    glVertex2f(-0.515f + xAdjust, 0.485f + yAdjust);
    glEnd();
}

void bird_left5()
{
    float xAdjust=-0.13f;
    float yAdjust=0.25f;

    glColor3ub(225, 140, 25);


    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f + xAdjust, 0.508f + yAdjust);
    glVertex2f(-0.5f + xAdjust, 0.492f + yAdjust);
    glVertex2f(-0.48f + xAdjust, 0.50f + yAdjust);
    glEnd();


    glColor3ub(0, 215, 0);


    glBegin(GL_QUADS);
    glVertex2f(-0.51f + xAdjust, 0.49f + yAdjust);
    glVertex2f(-0.53f + xAdjust, 0.55f + yAdjust);
    glVertex2f(-0.53f + xAdjust, 0.52f + yAdjust);
    glVertex2f(-0.52f + xAdjust, 0.47f + yAdjust);
    glEnd();


    glColor3ub(0, 0, 0);
    circle_bird(-0.5 + xAdjust, 0.5 + yAdjust, 0.01);
    glColor3ub(0,0,0);
    circle(-0.52 + xAdjust, 0.49 + yAdjust, 0.015, 'l');

    glColor3ub(0, 215, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.52f + xAdjust, 0.49f + yAdjust);
    glVertex2f(-0.55f + xAdjust, 0.47f + yAdjust);
    glVertex2f(-0.535f + xAdjust, 0.465f + yAdjust);
    glVertex2f(-0.55f + xAdjust, 0.43f + yAdjust);
    glVertex2f(-0.515f + xAdjust, 0.485f + yAdjust);
    glEnd();
}

void bird_left6()
{
    float xAdjust=-0.13f;
    float yAdjust=0.29f;

    glColor3ub(225, 140, 25);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f + xAdjust, 0.508f + yAdjust);
    glVertex2f(-0.5f + xAdjust, 0.492f + yAdjust);
    glVertex2f(-0.48f + xAdjust, 0.50f + yAdjust);
    glEnd();


    glColor3ub(0, 215, 0);

    glBegin(GL_QUADS);
    glVertex2f(-0.51f + xAdjust, 0.49f + yAdjust);
    glVertex2f(-0.53f + xAdjust, 0.55f + yAdjust);
    glVertex2f(-0.53f + xAdjust, 0.52f + yAdjust);
    glVertex2f(-0.52f + xAdjust, 0.47f + yAdjust);
    glEnd();


    glColor3ub(0, 0, 0);
    circle_bird(-0.5 + xAdjust, 0.5 + yAdjust, 0.01);
    glColor3ub(0,0,0);
    circle(-0.52 + xAdjust, 0.49 + yAdjust, 0.015, 'l');

    glColor3ub(0, 215, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.52f + xAdjust, 0.49f + yAdjust);
    glVertex2f(-0.55f + xAdjust, 0.47f + yAdjust);
    glVertex2f(-0.535f + xAdjust, 0.465f + yAdjust);
    glVertex2f(-0.55f + xAdjust, 0.43f + yAdjust);
    glVertex2f(-0.515f + xAdjust, 0.485f + yAdjust);
    glEnd();
}

void bird_left7()
{
    float xAdjust=-0.18f;
    float yAdjust=0.29f;

    glColor3ub(225, 140, 25);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f + xAdjust, 0.508f + yAdjust);
    glVertex2f(-0.5f + xAdjust, 0.492f + yAdjust);
    glVertex2f(-0.48f + xAdjust, 0.50f + yAdjust);
    glEnd();


    glColor3ub(0, 215, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.51f + xAdjust, 0.49f + yAdjust);
    glVertex2f(-0.53f + xAdjust, 0.55f + yAdjust);
    glVertex2f(-0.53f + xAdjust, 0.52f + yAdjust);
    glVertex2f(-0.52f + xAdjust, 0.47f + yAdjust);
    glEnd();


    glColor3ub(0, 0, 0);
    circle_bird(-0.5 + xAdjust, 0.5 + yAdjust, 0.01);
    glColor3ub(0,0,0);
    circle(-0.52 + xAdjust, 0.49 + yAdjust, 0.015, 'l');

    glColor3ub(0, 215, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.52f + xAdjust, 0.49f + yAdjust);
    glVertex2f(-0.55f + xAdjust, 0.47f + yAdjust);
    glVertex2f(-0.535f + xAdjust, 0.465f + yAdjust);
    glVertex2f(-0.55f + xAdjust, 0.43f + yAdjust);
    glVertex2f(-0.515f + xAdjust, 0.485f + yAdjust);
    glEnd();
}
void bird_left8()
{
    float xAdjust=-0.18f;
    float yAdjust=0.33f;

    glColor3ub(225, 140, 25);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f + xAdjust, 0.508f + yAdjust);
    glVertex2f(-0.5f + xAdjust, 0.492f + yAdjust);
    glVertex2f(-0.48f + xAdjust, 0.50f + yAdjust);
    glEnd();


    glColor3ub(0, 215, 0);

    glBegin(GL_QUADS);
    glVertex2f(-0.51f + xAdjust, 0.49f + yAdjust);
    glVertex2f(-0.53f + xAdjust, 0.55f + yAdjust);
    glVertex2f(-0.53f + xAdjust, 0.52f + yAdjust);
    glVertex2f(-0.52f + xAdjust, 0.47f + yAdjust);
    glEnd();


    glColor3ub(0, 0, 0);
    circle_bird(-0.5 + xAdjust, 0.5 + yAdjust, 0.01);
    glColor3ub(0,0,0);
    circle(-0.52 + xAdjust, 0.49 + yAdjust, 0.015, 'l');

    glColor3ub(0, 215, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.52f + xAdjust, 0.49f + yAdjust);
    glVertex2f(-0.55f + xAdjust, 0.47f + yAdjust);
    glVertex2f(-0.535f + xAdjust, 0.465f + yAdjust);
    glVertex2f(-0.55f + xAdjust, 0.43f + yAdjust);
    glVertex2f(-0.515f + xAdjust, 0.485f + yAdjust);
    glEnd();
}
/**.......................................Sun...........................................**/

void sun ()
{


    GLfloat x=0.7f;
    GLfloat y=0.85f;
    GLfloat radius =0.055f;
    int triangleAmount = 100; //# of lines used to draw circle
    GLfloat twicePi = 2.0f * PI;
    glColor3f(1.0f, 1.0f, 0.680f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {

        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

        glColor3f(1.0f, 1.0f, 0.0f);
    }
    glEnd();


}

void sun_shadow()
{
    glColor3f(1.0f, 1.0f, 0.680f);
    drawCircle(0.7,0.68,0.055);
}
/**...........................................Cloud....................................................**/

void cloud1()
{
    /**........................................Cloud Middle..........................................**/
    glPushMatrix();
    glTranslated(position_cloud1x,0.0f,0.0f);
    glPushMatrix();
    glTranslated(0.0f, 0.05f, 0.0f);
    GLfloat x=0.0f;
    GLfloat y=0.88f;
    GLfloat radius =.04f;
    int  triangleAmount = 100;
    GLfloat twicePi =2.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x, y); /// center of circle
    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    x=0.05f;
    y=0.88f;
    radius =.04f;
    twicePi =2.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=-0.05f;
    y=0.88f;
    radius =.04f;
    twicePi =2.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle
    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=-0.04f;
    y=0.92f;
    radius =.03f;
    twicePi =2.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=-0.013f;
    y=0.85f;
    radius =.03f;
    twicePi =2.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.053f;
    y=0.85f;
    radius =.036f;
    twicePi =2.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void cloud2()
{
    /**........................................Cloud Left...........................................**/
    glPushMatrix();
    glTranslated(position_cloud2x,0.0f,0.0f);
    GLfloat x=-0.5f;
    GLfloat y=0.85f;
    GLfloat radius =.058f;
    int  triangleAmount = 100;
    GLfloat twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=-0.57f;
    y=0.85f;
    radius =.037f;
    twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle
    for(float i = 0; i <= triangleAmount; i++)
    {

        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=-0.43f;
    y=0.85f;
    radius =.04f;
    twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=-0.55f;
    y=0.86f;
    radius =.03f;
    twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=-0.61f;
    y=0.85f;
    radius =.02f;
    twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=-0.39f;
    y=0.85f;
    radius =.02f;
    twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }

    glEnd();
    glPopMatrix();
}

void cloud3()
{
    /**........................................Cloud Right...........................................**/
    glPushMatrix();
    glTranslated(position_cloud3x,0.0f,0.0f);
    GLfloat x=0.45f;
    GLfloat y=0.85f;
    GLfloat radius =.035f;
    int  triangleAmount = 100;
    GLfloat twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount; i++)
    {

        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),

                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }

    glEnd();

    x=0.48f;
    y=0.85f;
    radius =.03f;
    twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle

    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.42f;
    y=0.85f;
    radius =.028f;
    twicePi =1.0f * PI;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y); /// center of circle
    for(float i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();
}



//TREE


void tree1()
{


    /**....................................... Small Tree (right) Stem ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.54f, 0.20f);
    glVertex2f(0.54f, 0.25f);
    glVertex2f(0.56f, 0.25f);
    glVertex2f(0.56f, 0.20f);
    glEnd();
    /**....................................... Small Tree (right) Leaf ..........................................**/
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0.235, 0.039);
    glVertex2f(0.47f, 0.25f);
    glVertex2f(0.63f, 0.25f);
    glVertex2f(0.55f, 0.34f);

    glColor3f(0.008, 0.357, 0.063);
    glVertex2f(0.48f, 0.30f);
    glVertex2f(0.62f, 0.30f);
    glVertex2f(0.55f, 0.38f);

    glColor3f(0.024, 0.451, 0.086);
    glVertex2f(0.50f, 0.35f);
    glVertex2f(0.6f, 0.35f);
    glVertex2f(0.55f, 0.42f);
    glEnd();
    /**....................................... Small Tree (Left) ..........................................**/
    glPushMatrix();
    glTranslated(-1.1f,0.0f,0.0f);
    /**....................................... Small Tree (Left) Stem ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.54f, 0.20f);
    glVertex2f(0.54f, 0.25f);
    glVertex2f(0.56f, 0.25f);
    glVertex2f(0.56f, 0.20f);
    glEnd();
    /**....................................... Small Tree (Left) Leaf ..........................................**/
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0.235, 0.039);
    glVertex2f(0.47f, 0.25f);
    glVertex2f(0.63f, 0.25f);
    glVertex2f(0.55f, 0.34f);

    glColor3f(0.008, 0.357, 0.063);
    glVertex2f(0.48f, 0.30f);
    glVertex2f(0.62f, 0.30f);
    glVertex2f(0.55f, 0.38f);

    glColor3f(0.024, 0.451, 0.086);
    glVertex2f(0.50f, 0.35f);
    glVertex2f(0.6f, 0.35f);
    glVertex2f(0.55f, 0.42f);
    glEnd();
    glPopMatrix();

}

void tree2()
{
    /**....................................... Big Tree (Right) ..........................................**/

    /**....................................... Big Tree (Right) Stem ..........................................**/

    glBegin(GL_QUADS);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.73f, 0.19f);
    glVertex2f(0.744f, 0.472f);
    glVertex2f(0.754f, 0.472f);
    glVertex2f(0.764f, 0.19f);

    glVertex2f(0.738f, 0.255f);
    glVertex2f(0.736f, 0.274f);
    glVertex2f(0.684f, 0.303f);
    glVertex2f(0.680f, 0.298f);

    glVertex2f(0.759f, 0.303f);
    glVertex2f(0.759f, 0.319f);
    glVertex2f(0.815f, 0.350f);
    glVertex2f(0.824f, 0.347f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.744f, 0.408f);
    glVertex2f(0.687f, 0.460f);
    glVertex2f(0.744f, 0.424f);

    glVertex2f(0.755f, 0.421f);
    glVertex2f(0.815f, 0.493f);
    glVertex2f(0.755f, 0.439f);
    glEnd();




    /**....................................... Big Tree (Left) ..........................................**/



    /**....................................... Big Tree (Left) Stem ..........................................**/

    glPushMatrix();
    glTranslated(-1.7f,-0.02f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.73f, 0.19f);
    glVertex2f(0.744f, 0.472f);
    glVertex2f(0.754f, 0.472f);
    glVertex2f(0.764f, 0.19f);

    glVertex2f(0.738f, 0.255f);
    glVertex2f(0.736f, 0.274f);
    glVertex2f(0.684f, 0.303f);
    glVertex2f(0.680f, 0.298f);

    glVertex2f(0.759f, 0.303f);
    glVertex2f(0.759f, 0.319f);
    glVertex2f(0.815f, 0.350f);
    glVertex2f(0.824f, 0.347f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.314, 0.184, 0.149);
    glVertex2f(0.744f, 0.408f);
    glVertex2f(0.687f, 0.460f);
    glVertex2f(0.744f, 0.424f);

    glVertex2f(0.755f, 0.421f);
    glVertex2f(0.815f, 0.493f);
    glVertex2f(0.755f, 0.439f);
    glEnd();
    glPopMatrix();



}

void tree_leaf1()
{
    /**....................................... Big Tree (Right) Top Leaf ..........................................**/

    glColor3f(0.549, 0.639, 0.153);
    drawCircle(0.644,0.532,0.06);

    drawCircle(0.644,0.477,0.05);

    glColor3f(0.647, 0.745, 0.184);
    drawCircle(0.691,0.568,0.07);

    glColor3f(0.647, 0.745, 0.184);
    drawCircle(0.771,0.563,0.06);

    glColor3f(0.694, 0.78, 0.294);
    drawCircle(0.814,0.562,0.045);

    glColor3f(0.694, 0.78, 0.294);
    drawCircle(0.835,0.543,0.05);

    glColor3f(0.694, 0.78, 0.294);
    drawCircle(0.839,0.508,0.05);

    glColor3f(0.647, 0.745, 0.184);
    drawCircle(0.749,0.457,0.06);

    glColor3f(0.694, 0.78, 0.294);
    drawCircle(0.796,0.485,0.05);

    glColor3f(0.647, 0.745, 0.184);
    drawCircle(0.709,0.442,0.05);

    glColor3f(0.647, 0.745, 0.184);
    drawCircle(0.695,0.457,0.055);

    /**....................................... Big Tree (Right) Right Leaf ..........................................**/

    glColor3f(0.549, 0.639, 0.153);
    drawCircle(0.865,0.376,0.035);

    glColor3f(0.647, 0.745, 0.184);
    drawCircle(0.896,0.390,0.025);

    glColor3f(0.694, 0.78, 0.294);
    drawCircle(0.835,0.406,0.03);

    glColor3f(0.694, 0.78, 0.294);
    drawCircle(0.802,0.384,0.03);

    glColor3f(0.549, 0.639, 0.153);
    drawCircle(0.836,0.366,0.035);

    glColor3f(0.647, 0.745, 0.184);
    drawCircle(0.881,0.408,0.03);

    glColor3f(0.687, 0.945, 0.234);
    drawCircle(0.938,0.52,0.05);

    glColor3f(0.687, 0.945, 0.234);
    drawCircle(0.957,0.52,0.05);

    glColor3f(0.687, 0.945, 0.234);
    drawCircle(0.957,0.57,0.05);


    /**....................................... Big Tree (Right) Left Leaf ..........................................**/

    glPushMatrix();
    glTranslated(-0.18f,-0.055f,0.0f);

    glColor3f(0.549, 0.639, 0.153);
    drawCircle(0.865,0.376,0.035);

    glColor3f(0.647, 0.745, 0.184);
    drawCircle(0.896,0.390,0.025);

    glColor3f(0.694, 0.78, 0.294);
    drawCircle(0.835,0.406,0.03);

    glColor3f(0.694, 0.78, 0.294);
    drawCircle(0.802,0.384,0.03);

    glColor3f(0.549, 0.639, 0.153);
    drawCircle(0.836,0.366,0.035);

    glColor3f(0.647, 0.745, 0.184);
    drawCircle(0.881,0.408,0.03);
    glPopMatrix();


}


void tree_leaf2()
{
    /**....................................... Big Tree (Left) Top Leaf ..........................................**/
    glPushMatrix();
    glTranslated(-1.7f,-0.02f,0.0f);

    drawCircle(0.644,0.532,0.06);

    glColor3f(0.549, 0.639, 0.153);
    drawCircle(0.644,0.477,0.05);

    glColor3f(0.647, 0.745, 0.184);
    drawCircle(0.691,0.568,0.07);

    glColor3f(0.647, 0.745, 0.184);
    drawCircle(0.771,0.563,0.06);

    glColor3f(0.694, 0.78, 0.294);
    drawCircle(0.814,0.562,0.045);

    glColor3f(0.694, 0.78, 0.294);
    drawCircle(0.835,0.543,0.05);

    glColor3f(0.694, 0.78, 0.294);
    drawCircle(0.839,0.508,0.05);

    glColor3f(0.647, 0.745, 0.184);
    drawCircle(0.749,0.457,0.06);

    glColor3f(0.694, 0.78, 0.294);
    drawCircle(0.796,0.485,0.05);

    glColor3f(0.647, 0.745, 0.184);
    drawCircle(0.709,0.442,0.05);

    glColor3f(0.647, 0.745, 0.184);
    drawCircle(0.695,0.457,0.055);

    /**....................................... Big Tree (Left) Right Leaf ..........................................**/

    glColor3f(0.549, 0.639, 0.153);
    drawCircle(0.865,0.376,0.035);

    glColor3f(0.647, 0.745, 0.184);
    drawCircle(0.896,0.390,0.025);

    glColor3f(0.694, 0.78, 0.294);
    drawCircle(0.835,0.406,0.03);

    glColor3f(0.694, 0.78, 0.294);
    drawCircle(0.802,0.384,0.03);

    glColor3f(0.549, 0.639, 0.153);
    drawCircle(0.836,0.366,0.035);

    glColor3f(0.647, 0.745, 0.184);
    drawCircle(0.881,0.408,0.03);


    /**....................................... Big Tree (Left) Left Leaf ..........................................**/

    glPushMatrix();
    glTranslated(-0.18f,-0.055f,0.0f);

    glColor3f(0.549, 0.639, 0.153);
    drawCircle(0.865,0.376,0.035);

    glColor3f(0.647, 0.745, 0.184);
    drawCircle(0.896,0.390,0.025);

    glColor3f(0.694, 0.78, 0.294);
    drawCircle(0.835,0.406,0.03);

    glColor3f(0.694, 0.78, 0.294);
    drawCircle(0.802,0.384,0.03);

    glColor3f(0.549, 0.639, 0.153);
    drawCircle(0.836,0.366,0.035);

    glColor3f(0.647, 0.745, 0.184);
    drawCircle(0.881,0.408,0.03);

    glPopMatrix();


    glPopMatrix();

}
// TRAIN

/**....................................... Drawing train 1 Engine..........................................**/

void drawEngine(float startX, float yRail, float bogieWidth, float bogieHeight, float wheelRadius, float engineBodyColor[], float engineCabinColor[], float engineWheelColor[])
{
    // Engine body (Rectangle)
    glBegin(GL_QUADS);
    glColor3f(0.0078f, 0.3020f, 0.3529f);


    glVertex2f(startX, yRail);
    glVertex2f(startX + bogieWidth, yRail);
    glVertex2f(startX + bogieWidth, yRail + bogieHeight);
    glVertex2f(startX, yRail + bogieHeight);
    glEnd();

    // Cabin part of the engine
    float cabinWidth = bogieWidth / 2.0f;
    glBegin(GL_QUADS);
    glColor3f(0.7725f, 0.6549f, 0.5059f);
    glVertex2f(startX, yRail);
    glVertex2f(startX + cabinWidth, yRail);
    glVertex2f(startX + cabinWidth, yRail + bogieHeight * 1.3f);
    glVertex2f(startX, yRail + bogieHeight * 1.3f);
    glEnd();

    // Engine chimney
    float chimneyWidth = bogieWidth / 6.0f;
    float chimneyHeight = bogieHeight * 0.9f;
    float chimneyX = startX + cabinWidth + bogieWidth / 10.0f;
    float chimneyY = yRail + bogieHeight;

    glBegin(GL_QUADS);
    glColor3f(0.7725f, 0.6549f, 0.5059f);
    glVertex2f(chimneyX, chimneyY);
    glVertex2f(chimneyX + chimneyWidth, chimneyY);
    glVertex2f(chimneyX + chimneyWidth, chimneyY + chimneyHeight);
    glVertex2f(chimneyX, chimneyY + chimneyHeight);
    glEnd();

    // Engine roof (Deep-Blue rectangle on the cabin)
    float roofWidth = cabinWidth * 1.2f;
    float roofHeight = bogieHeight / 6.0f;
    glBegin(GL_QUADS);
    glColor3f(0.0078f, 0.3020f, 0.3529f);
    glVertex2f(startX - roofWidth / 10.0f, yRail + bogieHeight * 1.3f);
    glVertex2f(startX + cabinWidth + roofWidth / 10.0f, yRail + bogieHeight * 1.3f);
    glVertex2f(startX + cabinWidth + roofWidth / 10.0f, yRail + bogieHeight * 1.3f + roofHeight);
    glVertex2f(startX - roofWidth / 10.0f, yRail + bogieHeight * 1.3f + roofHeight);
    glEnd();

    // Engine wheels (Two wheels)
    float wheelX1 = startX + bogieWidth / 4.0f; // Left wheel position
    float wheelX2 = startX + bogieWidth - bogieWidth / 4.0f; // Right wheel position
    float wheelY = yRail - wheelRadius;

    glColor3f(0.0f, 0.0f, 0.0f); //black wheel
    drawCircle(wheelX1, wheelY, wheelRadius); // Left wheel
    drawCircle(wheelX2, wheelY, wheelRadius); // Right wheel
}



/**....................................... Drawing train 1 boogie..........................................**/


void drawTrain()
{
    // Colors for train parts

    float bodyColor[] = {0.0078f, 0.3020f, 0.3529f};
// Deep-Blue Body
    float windowColor[] = {0.7f, 0.9f, 1.0f}; // Light blue windows
    float wheelColor[] = {0.0f, 0.0f, 0.0f}; // Black wheels

    // Train bogie dimensions
    float bogieWidth = 0.25f;
    float bogieHeight = 0.15f;
    float wheelRadius = 0.03f;

    float startX = -.9f; // Starting x-position for the first bogie
    float yRail =0.07f; // Align train with the rail line

    for (int i = 0; i < 3; i++)
    {
        // Draw bogie body
        glBegin(GL_QUADS);
        glColor3f(bodyColor[0], bodyColor[1], bodyColor[2]);
        glVertex2f(startX, yRail);
        glVertex2f(startX + bogieWidth, yRail);
        glVertex2f(startX + bogieWidth, yRail + bogieHeight);
        glVertex2f(startX, yRail + bogieHeight);
        glEnd();

        // Draw windows
        float windowWidth = bogieWidth / 4.3f;
        float windowHeight = bogieHeight / 2.2f;
        float windowStartX = startX + 0.032f;
        float windowY = yRail + bogieHeight / 2.0f;
        for (int j = 0; j < 3; j++)
        {
            glBegin(GL_QUADS);
            glColor3f(windowColor[0], windowColor[1], windowColor[2]);
            glVertex2f(windowStartX, windowY);
            glVertex2f(windowStartX + windowWidth, windowY);
            glVertex2f(windowStartX + windowWidth, windowY + windowHeight);
            glVertex2f(windowStartX, windowY + windowHeight);
            glEnd();
            windowStartX += windowWidth + 0.02f; // Space between windows
        }
        int width2 = glutGet(GLUT_WINDOW_WIDTH);
        int height2 = glutGet(GLUT_WINDOW_HEIGHT);
        GLfloat aspect2 = (GLfloat)height2 / (GLfloat)width2; // Aspect ratio (height/width)

        // Draw wheels
        float wheelX1 = startX + 0.0425f;
        float wheelX2 = startX + bogieWidth - 0.0425f;
        float wheelY = yRail - wheelRadius;

        glColor3f(wheelColor[0], wheelColor[1], wheelColor[2]);
        drawCircle(wheelX1, wheelY, wheelRadius); // Left wheel
        drawCircle(wheelX2, wheelY, wheelRadius); // Right wheel

        startX += bogieWidth + 0.02f; // Move to the next bogie
    }

    //engine colour

    float engineBodyColor[] = {0.0078f, 0.3020f, 0.3529f};
// Deep-Blue Engine
    float engineCabinColor[] = {0.7725f, 0.6549f, 0.5059f};
    float engineWheelColor[] = {0.0f, 0.0f, 0.0f}; // Black wheels

    drawEngine(startX, yRail, bogieWidth, bogieHeight, wheelRadius, engineBodyColor, engineCabinColor, engineWheelColor);


}

void drawCircle(float x, float y, float radius)
{
    int numSegments = 100; // Smoothness of the circle
    float angle;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // Center of the circle
    for (int i = 0; i <= numSegments; i++)
    {
        angle = (i * 2.0f * PI )/ numSegments;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}


/**....................................... DRawing train  2 boogie/engine..........................................**/




void drawCircle2(float x, float y, float radius);
void drawEngine2(float startX, float yRail, float bogieWidth, float bogieHeight, float wheelRadius, float engineBodyColor[], float engineCabinColor[], float engineWheelColor[]);

void drawTrain2()
{
    // Colors for train parts
    float bodyColor[] = {0.0078f, 0.3020f, 0.3529f};
// Deep-Blue Body
    float windowColor[] = {0.7f, 0.9f, 1.0f}; // Light blue windows
    float wheelColor[] = {0.0f, 0.0f, 0.0f}; // Black wheels

    // Train bogie dimensions
    float bogieWidth = 0.25f;
    float bogieHeight = 0.15f;
    float wheelRadius = 0.03f;

    // Middle point for the wheels (calculated from given vertices)
    float middleX = 0.0f;
    float middleY = -0.27f;

    // Position the train so that wheels are centered on the middle point
    float startX = middleX - 1.0f; // Starting x-position for the first bogie
    float yRail = middleY; // Align the train with the midpoint of the rail line

    for (int i = 0; i < 3; i++)
    {
        // Draw bogie body
        glBegin(GL_QUADS);
        glColor3f(bodyColor[0], bodyColor[1], bodyColor[2]);
        glVertex2f(startX, yRail);
        glVertex2f(startX + bogieWidth, yRail);
        glVertex2f(startX + bogieWidth, yRail + bogieHeight);
        glVertex2f(startX, yRail + bogieHeight);
        glEnd();

        // Draw windows
        float windowWidth = bogieWidth / 4.3f;
        float windowHeight = bogieHeight / 2.2f;
        float windowStartX = startX + 0.032f;
        float windowY = yRail + bogieHeight / 2.0f;
        for (int j = 0; j < 3; j++)
        {
            glBegin(GL_QUADS);
            glColor3f(windowColor[0], windowColor[1], windowColor[2]);
            glVertex2f(windowStartX, windowY);
            glVertex2f(windowStartX + windowWidth, windowY);
            glVertex2f(windowStartX + windowWidth, windowY + windowHeight);
            glVertex2f(windowStartX, windowY + windowHeight);
            glEnd();
            windowStartX += windowWidth + 0.02f; // Space between windows
        }

        // Draw wheels (placed around the middle of the line)
        float wheelX1 = startX + 0.0425f;
        float wheelX2 = startX + bogieWidth - 0.0425f;
        float wheelY = middleY - wheelRadius;

        glColor3f(wheelColor[0], wheelColor[1], wheelColor[2]);
        drawCircle(wheelX1, wheelY, wheelRadius); // Left wheel
        drawCircle(wheelX2, wheelY, wheelRadius); // Right wheel

        startX += bogieWidth + 0.02f; // Move to the next bogie
    }

    // Engine color
    float engineBodyColor[] = {0.0078f, 0.3020f, 0.3529f};
// Deep-Blue Engine
    float engineCabinColor[] = {0.7725f, 0.6549f, 0.5059f};
    float engineWheelColor[] = {0.0f, 0.0f, 0.0f}; // Black wheels

    drawEngine2(startX, yRail, bogieWidth, bogieHeight, wheelRadius, engineBodyColor, engineCabinColor, engineWheelColor);
}

//Engine2

void drawEngine2(float startX, float yRail, float bogieWidth, float bogieHeight, float wheelRadius, float engineBodyColor[], float engineCabinColor[], float engineWheelColor[])
{
    // Engine body (Rectangle)
    glBegin(GL_QUADS);
    glColor3f(engineBodyColor[0], engineBodyColor[1], engineBodyColor[2]);
    glVertex2f(startX, yRail);
    glVertex2f(startX + bogieWidth, yRail);
    glVertex2f(startX + bogieWidth, yRail + bogieHeight);
    glVertex2f(startX, yRail + bogieHeight);
    glEnd();

    // Cabin part of the engine
    float cabinWidth = bogieWidth / 2.0f;
    glBegin(GL_QUADS);
    glColor3f(engineCabinColor[0], engineCabinColor[1], engineCabinColor[2]);
    glVertex2f(startX, yRail);
    glVertex2f(startX + cabinWidth, yRail);
    glVertex2f(startX + cabinWidth, yRail + bogieHeight * 1.3f);
    glVertex2f(startX, yRail + bogieHeight * 1.3f);
    glEnd();

    // Engine chimney
    float chimneyWidth = bogieWidth / 6.0f;
    float chimneyHeight = bogieHeight * 0.9f;
    float chimneyX = startX + cabinWidth + bogieWidth / 10.0f;
    float chimneyY = yRail + bogieHeight;

    glBegin(GL_QUADS);
    glColor3f(0.7725f, 0.6549f, 0.5059f);
    glVertex2f(chimneyX, chimneyY);
    glVertex2f(chimneyX + chimneyWidth, chimneyY);
    glVertex2f(chimneyX + chimneyWidth, chimneyY + chimneyHeight);
    glVertex2f(chimneyX, chimneyY + chimneyHeight);
    glEnd();

    // Engine roof
    float roofWidth = cabinWidth * 1.2f;
    float roofHeight = bogieHeight / 6.0f;
    glBegin(GL_QUADS);
    glColor3f(0.0078f, 0.3020f, 0.3529f);
    glVertex2f(startX - roofWidth / 10.0f, yRail + bogieHeight * 1.3f);
    glVertex2f(startX + cabinWidth + roofWidth / 10.0f, yRail + bogieHeight * 1.3f);
    glVertex2f(startX + cabinWidth + roofWidth / 10.0f, yRail + bogieHeight * 1.3f + roofHeight);
    glVertex2f(startX - roofWidth / 10.0f, yRail + bogieHeight * 1.3f + roofHeight);
    glEnd();

    // Engine wheels (Two wheels)
    float wheelX1 = startX + bogieWidth / 4.0f; // Left wheel position
    float wheelX2 = startX + bogieWidth - bogieWidth / 4.0f; // Right wheel position
    float wheelY = yRail - wheelRadius;

    glColor3f(engineWheelColor[0], engineWheelColor[1], engineWheelColor[2]);
    drawCircle(wheelX1, wheelY, wheelRadius); // Left wheel
    drawCircle(wheelX2, wheelY, wheelRadius); // Right wheel
}





void rail_Line()
{

    /**....................................... Rail Line Stone ..........................................**/
    glBegin(GL_QUADS);
    ///    Upper
    // glColor3f(0.537, 0.569, 0.592);
    //glColor3ub(84, 82, 96);

    glVertex2f(-1.0f, 0.03f);
    //glColor3f(0.553, 0.584, 0.635);
    glVertex2f(-1.0f, 0.09f);

    //glColor3f(0.235, 0.365, 0.459);
    glVertex2f(1.0f, 0.09f);
    // glColor3f(0.486, 0.388, 0.267);
    glVertex2f(1.0f, 0.03f);
    ///     lower
    //glColor3f(0.537, 0.569, 0.592);
    //glColor3ub(84, 82, 96);

    glVertex2f(-1.0f, 0.11f);
    //glColor3f(0.553, 0.584, 0.635);
    glVertex2f(-1.0f, 0.17f);
    //glColor3f(0.235, 0.365, 0.459);
    glVertex2f(1.0f, 0.17f);
    //glColor3f(0.486, 0.388, 0.267);
    glVertex2f(1.0f, 0.11f);
    glEnd();

    /**....................................... Rail Line Soil ..........................................**/

//glColor3ub(255,244,203);
    glBegin(GL_QUADS);

// Top edge (darker color)
    glColor3ub(178, 153, 131);
    glVertex2f(-1.0f, 0.26f);
    glVertex2f(1.0f, 0.26f);

// Bottom edge (lighter color)
    //glColor3ub(245, 214, 163);
    glVertex2f(1.0f, -0.02f);
    glVertex2f(-1.0f, -0.02f);

    glEnd();


    //soil between first rail line and platform
    glBegin(GL_QUADS);
    // glColor3ub(150, 150, 150);
    glColor3ub(64, 70, 84);

    glVertex2f(-1.0f,0.1);
    glVertex2f(1.0f,0.1);
    glVertex2f(1.0f,-0.08);
    glVertex2f(-1.0f,-0.08);
    glEnd();


//1st line soil
    glBegin(GL_QUADS);
    glColor3ub(150, 150, 150);
    //glColor3ub(181, 101, 29);

    glVertex2f(-1.0f,0.17);
    glVertex2f(1.0f,0.17);
    glVertex2f(1.0f,0.1);
    glVertex2f(-1.0f,0.1);
    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(150, 150, 150);
    glVertex2f(-1.0f,0.055);
    glVertex2f(1.0f,0.055);
    glVertex2f(1.0f,-0.02);
    glVertex2f(-1.0f,-0.02);
    glEnd();

    //3rd rail line soil
    glBegin(GL_QUADS);
    glColor3ub(150, 150, 150);
    glVertex2f(-1.0f,0);
    glVertex2f(1.0f,0);
    glVertex2f(1.0f,-0.55);
    glVertex2f(-1.0f,-0.550);
    glEnd();


    //3rd rail line soil
    glBegin(GL_QUADS);
    glColor3ub(64, 70, 84);
    glVertex2f(-1.0f,-0.25);
    glVertex2f(1.0f,-0.250);
    glVertex2f(1.0f,-0.40);
    glVertex2f(-1.0f,-0.40);
    glEnd();


    //3rd rail line
    glBegin(GL_QUADS);
    glColor3ub(150, 150, 150);
    glVertex2f(-1.0f,-0.29);
    glVertex2f(1.0f,-0.290);
    glVertex2f(1.0f,-0.36);
    glVertex2f(-1.0f,-0.36);
    glEnd();


    //middle soil without rail lines
    glBegin(GL_QUADS);
    glColor3ub(64, 70, 84);
    glVertex2f(-1.0f,-0.16);
    glVertex2f(1.0f,-0.160);
    glVertex2f(1.0f,-0.09);
    glVertex2f(-1.0f,-0.09);
    glEnd();





    /**....................................... Rail Line ..........................................**/
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    ///     Lower Line
    glVertex2f(-1.0f, 0.01f);
    glVertex2f(1.0f, 0.01f);
    glVertex2f(-1.0f, 0.04f);
    glVertex2f(1.0f, 0.04f);
    ///     Upper Line
    glVertex2f(-1.0f, 0.13f);
    glVertex2f(1.0f, 0.13f);
    glVertex2f(-1.0f, 0.16f);
    glVertex2f(1.0f, 0.16f);


    //3rd line
    ///      Line

    glVertex2f(-1.0f, -0.3f);
    glVertex2f(1.0f, - 0.3f);
    glVertex2f(-1.0f, -0.33f);
    glVertex2f(1.0f, -0.33f);
    glEnd();

    /**...............
    /**....................................... Lower Line Joiner ..........................................**/
    glColor3f(0.114f, 0.106f, 0.125f);

    float x_start = -1.01f; // Starting X-coordinate
    float y_start = 0.00f;  // Starting Y-coordinate for the bottom point
    float y_end = 0.04f;    // Y-coordinate for the top point
    float x_increment = 0.04f; // Increment for X-coordinate

// Loop to draw the repeated lines
    for (int i = 0; i < 50; ++i)
    {
        glBegin(GL_LINES);
        glVertex2f(x_start, y_start);
        glVertex2f(x_start + 0.03f, y_end); // Top point
        glEnd();
        x_start += x_increment; // Shift the X-coordinate for the next line
    }
    /**....................................... 3rd Line Joiner ..........................................**/
    glColor3f(0.114f, 0.106f, 0.125f);

    float x_start3 = -1.01f; // Starting X-coordinate
    float y_start3 = -0.34f;  // Starting Y-coordinate for the bottom point
    float y_end3 = -0.30f;    // Y-coordinate for the top point
    float x_increment3 = 0.04f; // Increment for X-coordinate

// Loop to draw the repeated lines
    for (int i = 0; i < 50; ++i)
    {
        glBegin(GL_LINES);
        glVertex2f(x_start3, y_start3);
        glVertex2f(x_start3 + 0.03f, y_end3); // Top point
        glEnd();
        x_start3 += x_increment3; // Shift the X-coordinate for the next line
    }


    /**....................................... Upper Line Joiner ..........................................**/
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-1.01f, 0.12f);
    glVertex2f(-0.98f, 0.16f);

    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);

    glEnd();
    glPushMatrix();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);

    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();
    glTranslated(0.04f,0.0f,0.0f);
    glBegin(GL_LINES);
    glColor3f(0.114f, 0.106f, 0.125f);
    glVertex2f(-0.97f, 0.12f);
    glVertex2f(-0.94f, 0.16f);
    glEnd();

    glPopMatrix();

}





void station()
{



    /**....................................... Upper Half Circle Roof ..........................................**/
    GLfloat x=0.0f;
    GLfloat y=0.3f;
    GLfloat  radius =.4f;
    int  triangleAmount = 100; ///# of lines used to draw circle

    GLfloat twicePi =.892f * PI;
    glColor3ub(191,153,88);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); /// center of circle
    for(float i = 12.6; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
        glColor3ub(81,66,62);


    }
    glEnd();



    /**....................................... Upper Roof Stand 1 ..........................................**/
    glLineWidth(4);
    x=0.0f;
    y=0.3f;
    radius =0.36f;
    float i;
    int lineAmount = 100; //# of triangles used to draw circle

    twicePi = .891f * PI;

    // glColor3f(0.663, 0.482, 0.91);
    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    for(i = 12.7; i <= lineAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / lineAmount)),
            y + (radius* sin(i * twicePi / lineAmount))
        );
    }
    glEnd();
    /**....................................... Upper Roof Stand 2 ..........................................**/
    x=0.0f;
    y=0.3f;
    radius =0.4f;

    lineAmount = 100; //# of triangles used to draw circle


    twicePi = 1.05f * PI;

    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    for(i = -4; i <= lineAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / lineAmount)),
            y + (radius* sin(i * twicePi / lineAmount))
        );
    }
    glEnd();


    /**....................................... Upper Roof Stand 3  ..........................................**/
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.375f, 0.437f);
    glVertex2f(-0.27f, 0.2f);

    glVertex2f(0.375f, 0.437f);
    glVertex2f(0.27f, 0.2f);
    glEnd();

    /**....................................... Upper Roof Stand 4 ..........................................**/
    glLineWidth(2);
    x=0.0f;
    y=0.11f;
    radius =0.4f;

    lineAmount = 100; //# of triangles used to draw circle


    twicePi = 1.0f * PI;

    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    for(i = 1; i <= lineAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / lineAmount)),
            y + (radius* sin(i * twicePi / lineAmount))
        );
    }
    glEnd();
    /**....................................... Upper Roof Stand 5 ..........................................**/
    glLineWidth(2);
    x=0.0f;
    y=0.099f;
    radius =0.4f;

    lineAmount = 100; //# of triangles used to draw circle


    twicePi = 1.0f * PI;

    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    for(i = 1; i <= lineAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / lineAmount)),
            y + (radius* sin(i * twicePi / lineAmount))
        );
    }
    glEnd();

    /**....................................... Upper Roof Stand 6 ..........................................**/
    glLineWidth(2);
    x=0.0f;
    y=0.089f;
    radius =0.4f;

    lineAmount = 100; //# of triangles used to draw circle


    twicePi = 1.0f * PI;

    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    for(i = 1; i <= lineAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / lineAmount)),
            y + (radius* sin(i * twicePi / lineAmount))
        );
    }
    glEnd();

    /**....................................... Upper Roof Stand 7 ..........................................**/
    glLineWidth(2);
    x=0.0f;
    y=0.079f;
    radius =0.4f;

    lineAmount = 100; //# of triangles used to draw circle


    twicePi = 1.0f * PI;

    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    for(i = 1; i <= lineAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / lineAmount)),
            y + (radius* sin(i * twicePi / lineAmount))
        );
    }
    glEnd();

    /**....................................... Upper Roof Stand 8 ..........................................**/
    glLineWidth(2);
    x=0.0f;
    y=0.069f;
    radius =0.4f;

    lineAmount = 100; //# of triangles used to draw circle


    twicePi = 1.0f * PI;

    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    for(i = 1; i <= lineAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / lineAmount)),
            y + (radius* sin(i * twicePi / lineAmount))
        );
    }
    glEnd();
    /**....................................... Upper Roof Stand 9 ..........................................**/
    glLineWidth(2);
    x=0.0f;
    y=0.059f;
    radius =0.4f;

    lineAmount = 100; //# of triangles used to draw circle


    twicePi = 1.0f * PI;

    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    for(i = 1; i <= lineAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / lineAmount)),
            y + (radius* sin(i * twicePi / lineAmount))
        );
    }
    glEnd();
    /**....................................... Upper Roof Stand 10 ..........................................**/
    glLineWidth(2);
    x=0.0f;
    y=0.049f;
    radius =0.4f;

    lineAmount = 100; //# of triangles used to draw circle


    twicePi = 1.0f * PI;

    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    for(i = 1; i <= lineAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / lineAmount)),
            y + (radius* sin(i * twicePi / lineAmount))
        );
    }
    glEnd();
    /**....................................... Upper Roof stand ..........................................**/
    glLineWidth(2.25);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.36f, 0.47f);
    glVertex2f(-0.3f, 0.41f);

    glVertex2f(-0.35f, 0.5f);
    glVertex2f(-0.25f, 0.4f);

    glVertex2f(-0.333f, 0.53f);
    glVertex2f(-0.20f, 0.4f);

    glVertex2f(-0.31f, 0.56f);
    glVertex2f(-0.15f, 0.4f);

    glVertex2f(-0.285f, 0.585f);
    glVertex2f(-0.10f, 0.4f);

    glVertex2f(-0.255f, 0.61f);
    glVertex2f(-0.05f, 0.405f);

    glVertex2f(-0.225f, 0.635f);
    glVertex2f(-0.0f, 0.41f);

    glVertex2f(-0.19f, 0.655f);
    glVertex2f(0.05f, 0.41f);

    glVertex2f(-0.15f, 0.675f);
    glVertex2f(0.10f, 0.41f);

    glVertex2f(-0.105f, 0.69f);
    glVertex2f(0.15f, 0.41f);

    glVertex2f(-0.057f, 0.7f);
    glVertex2f(0.20f, 0.41f);

    glVertex2f(0.36f, 0.47f);
    glVertex2f(0.3f, 0.41f);

    glVertex2f(0.35f, 0.5f);
    glVertex2f(0.25f, 0.4f);

    glVertex2f(0.333f, 0.53f);
    glVertex2f(0.20f, 0.4f);

    glVertex2f(0.31f, 0.56f);
    glVertex2f(0.15f, 0.4f);

    glVertex2f(0.285f, 0.585f);
    glVertex2f(0.10f, 0.4f);

    glVertex2f(0.255f, 0.61f);
    glVertex2f(0.05f, 0.405f);

    glVertex2f(0.225f, 0.635f);
    glVertex2f(0.0f, 0.41f);

    glVertex2f(0.19f, 0.655f);
    glVertex2f(-0.05f, 0.41f);

    glVertex2f(0.15f, 0.675f);
    glVertex2f(-0.10f, 0.41f);

    glVertex2f(0.105f, 0.69f);
    glVertex2f(-0.15f, 0.41f);

    glVertex2f(0.057f, 0.7f);
    glVertex2f(-0.20f, 0.41f);

    glVertex2f(0.00f, 0.7f);
    glVertex2f(0.00f, 0.4f);


    glEnd();


    /**....................................... Side Glass Wall Left ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.627, 0.792, 0.816);
    glColor3ub(75, 82, 137);
    glVertex2f(-0.27f, 0.4f);
    glColor3f(0.561, 0.89, 0.941);
    glVertex2f(-0.17f, 0.4f);
    glColor3f(0.306, 0.518, 0.549);
    glVertex2f(-0.17f, 0.26f);
    glColor3f(0.478, 0.686, 0.722);
    glVertex2f(-0.23f, 0.26f);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(-0.19f, 0.26f);
    glVertex2f(-0.19f, 0.4f);
    glVertex2f(-0.21f, 0.26f);
    glVertex2f(-0.21f, 0.4f);
    glVertex2f(-0.23f, 0.26f);
    glVertex2f(-0.23f, 0.4f);
    glVertex2f(-0.25f, 0.335f);
    glVertex2f(-0.25f, 0.4f);
    glVertex2f(-0.17f, 0.27f);
    glVertex2f(-0.23f, 0.27f);
    glVertex2f(-0.17f, 0.28f);
    glVertex2f(-0.24f, 0.28f);
    glVertex2f(-0.17f, 0.29f);
    glVertex2f(-0.24f, 0.29f);
    glVertex2f(-0.17f, 0.30f);
    glVertex2f(-0.24f, 0.30f);
    glVertex2f(-0.17f, 0.31f);
    glVertex2f(-0.24f, 0.31f);
    glVertex2f(-0.17f, 0.32f);
    glVertex2f(-0.24f, 0.32f);
    glVertex2f(-0.17f, 0.33f);
    glVertex2f(-0.251f, 0.33f);
    glVertex2f(-0.17f, 0.34f);
    glVertex2f(-0.254f, 0.34f);
    glVertex2f(-0.17f, 0.35f);
    glVertex2f(-0.257f, 0.35f);
    glVertex2f(-0.17f, 0.36f);
    glVertex2f(-0.259f, 0.36f);
    glVertex2f(-0.17f, 0.37f);
    glVertex2f(-0.262f, 0.37f);
    glVertex2f(-0.17f, 0.38f);
    glVertex2f(-0.265f, 0.38f);
    glVertex2f(-0.17f, 0.39f);
    glVertex2f(-0.267f, 0.39f);
    glEnd();


    /**....................................... Side Glass Wall Left ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.627, 0.792, 0.816);
    glVertex2f(0.27f, 0.4f);
    glColor3f(0.478, 0.686, 0.722);
    glVertex2f(0.17f, 0.4f);
    glColor3f(0.306, 0.518, 0.549);
    glVertex2f(0.17f, 0.26f);
    glColor3f(0.561, 0.89, 0.941);
    glVertex2f(0.23f, 0.26f);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(0.19f, 0.26f);
    glVertex2f(0.19f, 0.4f);
    glVertex2f(0.21f, 0.26f);
    glVertex2f(0.21f, 0.4f);
    glVertex2f(0.23f, 0.26f);
    glVertex2f(0.23f, 0.4f);
    glVertex2f(0.25f, 0.335f);
    glVertex2f(0.25f, 0.4f);
    glVertex2f(0.17f, 0.27f);
    glVertex2f(0.234f, 0.27f);
    glVertex2f(0.17f, 0.28f);
    glVertex2f(0.237f, 0.28f);
    glVertex2f(0.17f, 0.29f);
    glVertex2f(0.24f, 0.29f);
    glVertex2f(0.17f, 0.30f);
    glVertex2f(0.24f, 0.30f);
    glVertex2f(0.17f, 0.31f);
    glVertex2f(0.24f, 0.31f);
    glVertex2f(0.17f, 0.32f);
    glVertex2f(0.24f, 0.32f);
    glVertex2f(0.17f, 0.33f);
    glVertex2f(0.251f, 0.33f);
    glVertex2f(0.17f, 0.34f);
    glVertex2f(0.254f, 0.34f);
    glVertex2f(0.17f, 0.35f);
    glVertex2f(0.257f, 0.35f);
    glVertex2f(0.17f, 0.36f);
    glVertex2f(0.259f, 0.36f);
    glVertex2f(0.17f, 0.37f);
    glVertex2f(0.262f, 0.37f);
    glVertex2f(0.17f, 0.38f);
    glVertex2f(0.265f, 0.38f);
    glVertex2f(0.17f, 0.39f);
    glVertex2f(0.267f, 0.39f);
    glEnd();


    /**....................................... Top Glass roof ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.627, 0.792, 0.816);
    glVertex2f(-0.19f, 0.38f);
    glColor3f(0.478, 0.686, 0.722);
    glVertex2f(-0.19f, 0.5f);
    glColor3f(0.561, 0.89, 0.941);
    glVertex2f(0.19f, 0.5f);
    glColor3f(0.306, 0.518, 0.549);
    glVertex2f(0.19f, 0.38f);
    glEnd();
    /**....................................... Top Glass Roof Joining Aluminium frame..........................................**/
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(-0.19f, 0.39f);
    glVertex2f(0.19f, 0.39f);
    glVertex2f(-0.19f, 0.41f);
    glVertex2f(0.19f, 0.41f);
    glVertex2f(-0.19f, 0.43f);
    glVertex2f(0.19f, 0.43f);
    glVertex2f(-0.19f, 0.45f);
    glVertex2f(0.19f, 0.45f);
    glVertex2f(-0.19f, 0.47f);
    glVertex2f(0.19f, 0.47f);
    glVertex2f(-0.19f, 0.49f);
    glVertex2f(0.19f, 0.49f);
    glVertex2f(-0.15f, 0.50f);
    glVertex2f(-0.15f, 0.38f);
    glVertex2f(-0.11f, 0.5f);
    glVertex2f(-0.11f, 0.38f);
    glVertex2f(-0.07f, 0.5f);
    glVertex2f(-0.07f, 0.38f);
    glVertex2f(-0.03f, 0.5f);
    glVertex2f(-0.03f, 0.38f);
    glVertex2f(0.01f, 0.50f);
    glVertex2f(0.01f, 0.38f);
    glVertex2f(0.05f, 0.5f);
    glVertex2f(0.05f, 0.38f);
    glVertex2f(0.09f, 0.5f);
    glVertex2f(0.09f, 0.38f);

    glVertex2f(0.13f, 0.50f);
    glVertex2f(0.13f, 0.38f);

    glVertex2f(0.17f, 0.5f);
    glVertex2f(0.17f, 0.38f);

    glEnd();



    /**....................................... Terminal ..........................................**/

    ///  2 side wall
    glBegin(GL_QUADS);
    glColor3f(0.698, 0.596, 0.592);
    glVertex2f(-0.17f, 0.26f);
    glVertex2f(-0.17f, 0.38f);
    glVertex2f(0.17f, 0.38f);
    glVertex2f(0.17f, 0.26f);
    glEnd();
    ///  Terminal Glass
    glBegin(GL_QUADS);
    glColor3f(0.824, 0.847, 0.839);
    glVertex2f(-0.1f, 0.26f);
    glColor3f(0.702, 0.812, 0.776);
    glVertex2f(-0.1f, 0.38f);
    glColor3f(0.937, 0.937, 0.937);
    glVertex2f(0.1f, 0.38f);
    glColor3f(0.863, 0.902, 0.898);
    glVertex2f(0.1f, 0.26f);
    glEnd();
    /**....................................... Terminal Glass Joining Aluminium frame..........................................**/
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.643, 0.663, 0.675);
    glVertex2f(-0.1f, 0.27f);
    glVertex2f(0.1f, 0.27f);
    glVertex2f(-0.1f, 0.28f);
    glVertex2f(0.1f, 0.28f);
    glVertex2f(-0.1f, 0.29f);
    glVertex2f(0.1f, 0.29f);
    glVertex2f(-0.1f, 0.30f);
    glVertex2f(0.1f, 0.30f);
    glVertex2f(-0.1f, 0.31f);
    glVertex2f(0.1f, 0.31f);
    glVertex2f(-0.1f, 0.32f);
    glVertex2f(0.1f, 0.32f);
    glVertex2f(-0.1f, 0.33f);
    glVertex2f(0.1f, 0.33f);
    glVertex2f(-0.1f, 0.34f);
    glVertex2f(0.1f, 0.34f);
    glVertex2f(-0.1f, 0.35f);
    glVertex2f(0.1f, 0.35f);
    glVertex2f(-0.1f, 0.36f);
    glVertex2f(0.1f, 0.36f);
    glVertex2f(-0.1f, 0.37f);
    glVertex2f(0.1f, 0.37f);
    glVertex2f(-0.09f, 0.26f);
    glVertex2f(-0.09f, 0.38f);
    glVertex2f(-0.08f, 0.26f);
    glVertex2f(-0.08f, 0.38f);
    glVertex2f(-0.07f, 0.26f);
    glVertex2f(-0.07f, 0.38f);
    glVertex2f(-0.06f, 0.26f);
    glVertex2f(-0.06f, 0.38f);
    glVertex2f(-0.05f, 0.26f);
    glVertex2f(-0.05f, 0.38f);
    glVertex2f(-0.04f, 0.26f);
    glVertex2f(-0.04f, 0.38f);
    glVertex2f(-0.03f, 0.26f);
    glVertex2f(-0.03f, 0.38f);
    glVertex2f(-0.02f, 0.26f);
    glVertex2f(-0.02f, 0.38f);
    glVertex2f(-0.01f, 0.26f);
    glVertex2f(-0.01f, 0.38f);
    glVertex2f(0.0f, 0.26f);
    glVertex2f(0.0f, 0.38f);
    glVertex2f(0.01f, 0.26f);
    glVertex2f(0.01f, 0.38f);
    glVertex2f(0.02f, 0.26f);
    glVertex2f(0.02f, 0.38f);
    glVertex2f(0.03f, 0.26f);
    glVertex2f(0.03f, 0.38f);
    glVertex2f(0.04f, 0.26f);
    glVertex2f(0.04f, 0.38f);
    glVertex2f(0.05f, 0.26f);
    glVertex2f(0.05f, 0.38f);
    glVertex2f(0.06f, 0.26f);
    glVertex2f(0.06f, 0.38f);
    glVertex2f(0.07f, 0.26f);
    glVertex2f(0.07f, 0.38f);
    glVertex2f(0.08f, 0.26f);
    glVertex2f(0.08f, 0.38f);
    glVertex2f(0.09f, 0.26f);
    glVertex2f(0.09f, 0.38f);
    glEnd(); /**....................................... Terminal Glass Joining Aluminium frame..........................................**/
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(-0.1f, 0.27f);
    glVertex2f(0.1f, 0.27f);
    glVertex2f(-0.1f, 0.28f);
    glVertex2f(0.1f, 0.28f);
    glVertex2f(-0.1f, 0.29f);
    glVertex2f(0.1f, 0.29f);
    glVertex2f(-0.1f, 0.30f);
    glVertex2f(0.1f, 0.30f);
    glVertex2f(-0.1f, 0.31f);
    glVertex2f(0.1f, 0.31f);
    glVertex2f(-0.1f, 0.32f);
    glVertex2f(0.1f, 0.32f);
    glVertex2f(-0.1f, 0.33f);
    glVertex2f(0.1f, 0.33f);
    glVertex2f(-0.1f, 0.34f);
    glVertex2f(0.1f, 0.34f);
    glVertex2f(-0.1f, 0.35f);
    glVertex2f(0.1f, 0.35f);
    glVertex2f(-0.1f, 0.36f);
    glVertex2f(0.1f, 0.36f);
    glVertex2f(-0.1f, 0.37f);
    glVertex2f(0.1f, 0.37f);
    glVertex2f(-0.09f, 0.26f);
    glVertex2f(-0.09f, 0.38f);
    glVertex2f(-0.08f, 0.26f);
    glVertex2f(-0.08f, 0.38f);
    glVertex2f(-0.07f, 0.26f);
    glVertex2f(-0.07f, 0.38f);
    glVertex2f(-0.06f, 0.26f);
    glVertex2f(-0.06f, 0.38f);
    glVertex2f(-0.05f, 0.26f);
    glVertex2f(-0.05f, 0.38f);
    glVertex2f(-0.04f, 0.26f);
    glVertex2f(-0.04f, 0.38f);
    glVertex2f(-0.03f, 0.26f);
    glVertex2f(-0.03f, 0.38f);
    glVertex2f(-0.02f, 0.26f);
    glVertex2f(-0.02f, 0.38f);
    glVertex2f(-0.01f, 0.26f);
    glVertex2f(-0.01f, 0.38f);
    glVertex2f(0.0f, 0.26f);
    glVertex2f(0.0f, 0.38f);
    glVertex2f(0.01f, 0.26f);
    glVertex2f(0.01f, 0.38f);
    glVertex2f(0.02f, 0.26f);
    glVertex2f(0.02f, 0.38f);
    glVertex2f(0.03f, 0.26f);
    glVertex2f(0.03f, 0.38f);
    glVertex2f(0.04f, 0.26f);
    glVertex2f(0.04f, 0.38f);
    glVertex2f(0.05f, 0.26f);
    glVertex2f(0.05f, 0.38f);
    glVertex2f(0.06f, 0.26f);
    glVertex2f(0.06f, 0.38f);
    glVertex2f(0.07f, 0.26f);
    glVertex2f(0.07f, 0.38f);
    glVertex2f(0.08f, 0.26f);
    glVertex2f(0.08f, 0.38f);
    glVertex2f(0.09f, 0.26f);
    glVertex2f(0.09f, 0.38f);
    glEnd();
    /**....................................... Gate ..........................................**/
    glBegin(GL_QUADS);
    glColor3f(0.98, 0.98, 0.98);
    glVertex2f(-0.02f, 0.26f);
    glVertex2f(-0.02f, 0.35f);
    glVertex2f(0.04f, 0.35f);
    glVertex2f(0.04f, 0.26f);
    glEnd();

    ///  Gate Joining Aluminium frame
    glLineWidth(2);
    glBegin(GL_LINES);
    // glColor3f(0.643, 0.663, 0.675);
    glColor3f(0.0, 0.0, 0.0);

    glVertex2f(0.01f, 0.26f);
    glVertex2f(0.01f, 0.35f);
    glVertex2f(-0.02f, 0.29f);
    glVertex2f(0.04f, 0.29f);
    glEnd();

    /**....................................... Roof Supporting Stand ..........................................**/
    glLineWidth(4);
    glBegin(GL_LINES);
    //glColor3f(0.478, 0.478, 0.463);
    glColor3f(0.0, 0.0, 0.0);
    //glColor3ub(203, 197, 212);

    glVertex2f(-0.32f, 0.47f);
    glVertex2f(-0.29f, 0.33f);
    glVertex2f(-0.32f, 0.47f);
    glVertex2f(-0.32f, 0.33f);


    glVertex2f(-0.28f, 0.53f);
    glVertex2f(-0.25f, 0.33f);
    glVertex2f(-0.28f, 0.53f);
    glVertex2f(-0.22f, 0.33f);



    glVertex2f(-0.225f, 0.583f);
    glVertex2f(-0.185f, 0.33f);
    glVertex2f(-0.225f, 0.583f);
    glVertex2f(-0.155f, 0.33f);


    glVertex2f(-0.16f, 0.623f);
    glVertex2f(-0.11f, 0.33f);
    glVertex2f(-0.16f, 0.623f);
    glVertex2f(-0.07f, 0.33f);



    glVertex2f(-0.075f, 0.655f);
    glVertex2f(0.01f, 0.33f);
    glVertex2f(-0.075f, 0.655f);
    glVertex2f(0.04f, 0.33f);


    glVertex2f(0.035f, 0.655f);
    glVertex2f(0.12f, 0.33f);
    glVertex2f(0.035f, 0.655f);
    glVertex2f(0.09f, 0.33f);


    glVertex2f(0.12f, 0.623f);
    glVertex2f(0.19f, 0.33f);
    glVertex2f(0.12f, 0.623f);
    glVertex2f(0.16f, 0.33f);


    glVertex2f(0.205f, 0.583f);
    glVertex2f(0.26f, 0.33f);
    glVertex2f(0.205f, 0.583f);
    glVertex2f(0.23f, 0.33f);



    glVertex2f(0.29f, 0.53f);
    glVertex2f(0.33f, 0.33f);
    glVertex2f(0.29f, 0.53f);
    glVertex2f(0.30f, 0.33f);

    glEnd();


    glColor3f(0.973, 0.988, 0.42);
    renderBitmapString(-0.16f, 0.505f, 0.0f, GLUT_BITMAP_HELVETICA_18, "COX'S BAZAR RAILWAY STATION");


    rail_Line();

}


void platform()
{

//platform color
    glBegin(GL_QUADS);
// Top edge (darker color)
    glColor3ub(79, 22, 33); // Darker color
    glVertex2f(-1.0f, 0.38f);
    glVertex2f(1.0f, 0.38f);

// Bottom edge (lighter color)
    glColor3ub(150, 90, 110); // Lighter color
    glVertex2f(1.0f, 0.3f);
    glVertex2f(-1.0f, 0.3f);
    glEnd();


    glLineWidth(2);
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(1.0f, 0.3f);
    glVertex2f(-1.0f, 0.3f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(87,87,97);
    glVertex2f(-1.0f,0.32f);
    glVertex2f(-1.0f,0.3f);
    glVertex2f(1.0f,0.3f);
    glVertex2f(1.0f,0.32f);
    glEnd();


//piller

//inner piller
    float flag2 = 0.0f; // Initialize the flag outside the loop
    for (int i = 0; i < 10; i++)
    {
        glBegin(GL_QUADS);
        glColor3ub(205-50, 167-50, 96-50);
        glVertex2f(-0.85f + flag2, 0.3f);
        glVertex2f(-0.855f + flag2, 0.23f);
        glVertex2f(-0.81f + flag2, 0.23f);
        glVertex2f(-0.82f + flag2, 0.3f);
        glEnd();
        flag2 += 0.25f; // Increment flag to shift the next pillar
    }
// Pillar outer
    float flag = 0.0f; // Initialize the flag outside the loop
    for (int i = 0; i < 10; i++)
    {
        glBegin(GL_QUADS);
        glColor3ub(205-30, 167-30, 96-30);
        glVertex2f(-0.89f + flag, 0.3f);
        glVertex2f(-0.9f + flag, 0.18f);
        glVertex2f(-0.85f + flag, 0.18f);
        glVertex2f(-0.86f + flag, 0.3f);
        glEnd();
        flag += 0.25f; // Increment flag to shift the next pillar
    }

//under piller black line
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-1.0f, 0.175f);
    glVertex2f(1.0f, 0.175f);

    glEnd();



    glLineWidth(2);
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(1.0f, 0.3f);
    glVertex2f(-1.0f, 0.3f);
    glEnd();

}


void draw_newspaper_store(float x, float y);
void draw_human(float x, float y, int r, int g, int b);




void platform_down()
{
    // Platform color with gradient
    glBegin(GL_QUADS);
    // Top edge ()
    glColor3ub(178, 153, 131);
    glVertex2f(-1.0f, -0.55f);
    glVertex2f(1.0f, -0.55f);
    // Bottom edge
    //glColor3ub(); // shade
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    // Platform border bottom
    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-1.0f, -0.55f);
    glVertex2f(1.0f, -0.55f);
    glEnd();

    draw_newspaper_store(0.8f, -0.73f);
}


// HUMAN
void human1()
{

    /**..........................................Human...............................................**/
    ///..........Head..........
    glPushMatrix();
    glTranslatef(0.0f,0.02f,0.0f);
    glScalef(0.9f,0.9f,0.0f);
    GLfloat x=0.3f;
    GLfloat y=0.28f;
    GLfloat radius =0.01f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.3f;
    y=0.28f;
    radius =0.01f;

    triangleAmount = 100;
    twicePi = -1.0f * PI;

    glColor3f(0.702f, 0.447f, 0.240f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }
    glEnd();

/// Hair bun for the head
    x=0.284f;
    y=0.278f;
    radius =0.0087f;

    triangleAmount = 100;
    twicePi = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }

    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.296f, 0.278f);
    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.306f, 0.278f);
    glEnd();

    glPointSize(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.298f, 0.275f);
    glVertex2f(0.304f, 0.275f);
    glEnd();

    ///.........................Body.....................
    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.0f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    ///.........................Shari.....................
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glVertex2f(0.31f, 0.26f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.248f);
    glVertex2f(0.29f, 0.232f);
    glVertex2f(0.296f, 0.232f);
    glVertex2f(0.304f, 0.232f);
    glVertex2f(0.31f, 0.232f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    ///....................Hand Right....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.254f);
    glVertex2f(0.318f, 0.25f);
    glVertex2f(0.31f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.252f);
    glVertex2f(0.318f, 0.254f);
    glVertex2f(0.31f, 0.265f);
    glEnd();



    ///....................Hand left....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.254f);
    glVertex2f(0.282f, 0.25f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.252f);
    glVertex2f(0.282f, 0.254f);
    glVertex2f(0.29f, 0.265f);
    glEnd();
    glPopMatrix();
}


void human2()
{
    ///..........Head..........
    glPushMatrix();
    glTranslatef(-0.02f,0.02f,0.0f);
    glScalef(0.9f,0.9f,0.0f);
    GLfloat x=0.3f;
    GLfloat y=0.28f;
    GLfloat radius =0.01f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.3f;
    y=0.28f;
    radius =0.01f;

    triangleAmount = 100;
    twicePi = -1.0f * PI;

    glColor3f(0.702f, 0.447f, 0.240f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }

    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.296f, 0.278f);
    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.306f, 0.278f);
    glEnd();

    glPointSize(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.298f, 0.275f);
    glVertex2f(0.304f, 0.275f);
    glEnd();

    ///.........................Body.....................
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.7f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glLineWidth(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.3f, 0.273f);
    glVertex2f(0.3f, 0.25f);

    glEnd();

    ///....................Hand Right....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.254f);
    glVertex2f(0.318f, 0.25f);
    glVertex2f(0.31f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.252f);
    glVertex2f(0.318f, 0.254f);
    glVertex2f(0.31f, 0.265f);
    glEnd();



    ///....................Hand left....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.254f);
    glVertex2f(0.282f, 0.25f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.252f);
    glVertex2f(0.282f, 0.254f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    ///................................Legs............................

    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.29f, 0.23f);
    glVertex2f(0.296f, 0.23f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.304f, 0.23f);
    glVertex2f(0.31f, 0.23f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.745f, 0.710f);
    glVertex2f(0.29f, 0.248f);
    glVertex2f(0.29f, 0.232f);
    glVertex2f(0.296f, 0.232f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.304f, 0.232f);
    glVertex2f(0.31f, 0.232f);
    glVertex2f(0.31f, 0.25f);
    glEnd();
    glPopMatrix();
}

void human3()
{

    /**..........................................Human...............................................**/
    ///..........Head..........
    glPushMatrix();
    glTranslatef(-0.2f,0.02f,0.0f);
    glScalef(0.9f,0.9f,0.0f);
    GLfloat x=0.3f;
    GLfloat y=0.28f;
    GLfloat radius =0.01f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.3f;
    y=0.28f;
    radius =0.01f;

    triangleAmount = 100;
    twicePi = -1.0f * PI;

    glColor3f(0.702f, 0.447f, 0.240f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }
    glEnd();

/// Hair bun for the head
    x=0.284f;
    y=0.278f;
    radius =0.0087f;

    triangleAmount = 100;
    twicePi = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }

    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.296f, 0.278f);
    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.306f, 0.278f);
    glEnd();

    glPointSize(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.298f, 0.275f);
    glVertex2f(0.304f, 0.275f);
    glEnd();

    ///.........................Body.....................
    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.0f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    ///.........................Shari.....................
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glVertex2f(0.31f, 0.26f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.248f);
    glVertex2f(0.29f, 0.232f);
    glVertex2f(0.296f, 0.232f);
    glVertex2f(0.304f, 0.232f);
    glVertex2f(0.31f, 0.232f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    ///....................Hand Right....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.254f);
    glVertex2f(0.318f, 0.25f);
    glVertex2f(0.31f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.252f);
    glVertex2f(0.318f, 0.254f);
    glVertex2f(0.31f, 0.265f);
    glEnd();



    ///....................Hand left....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.254f);
    glVertex2f(0.282f, 0.25f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.252f);
    glVertex2f(0.282f, 0.254f);
    glVertex2f(0.29f, 0.265f);
    glEnd();
    glPopMatrix();
}
void human4()
{

    /**..........................................Human...............................................**/
    ///..........Head..........
    glPushMatrix();
    glTranslatef(0.02f,0.02f,0.0f);
    glScalef(0.9f,0.9f,0.0f);
    GLfloat x=0.3f;
    GLfloat y=0.28f;
    GLfloat radius =0.01f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.3f;
    y=0.28f;
    radius =0.01f;

    triangleAmount = 100;
    twicePi = -1.0f * PI;

    glColor3f(0.702f, 0.447f, 0.240f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }
    glEnd();

/// Hair bun for the head
    x=0.284f;
    y=0.278f;
    radius =0.0087f;

    triangleAmount = 100;
    twicePi = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }

    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.296f, 0.278f);
    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.306f, 0.278f);
    glEnd();

    glPointSize(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.298f, 0.275f);
    glVertex2f(0.304f, 0.275f);
    glEnd();

    ///.........................Body.....................
    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.0f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    ///.........................Shari.....................
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glVertex2f(0.31f, 0.26f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.248f);
    glVertex2f(0.29f, 0.232f);
    glVertex2f(0.296f, 0.232f);
    glVertex2f(0.304f, 0.232f);
    glVertex2f(0.31f, 0.232f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    ///....................Hand Right....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.254f);
    glVertex2f(0.318f, 0.25f);
    glVertex2f(0.31f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.252f);
    glVertex2f(0.318f, 0.254f);
    glVertex2f(0.31f, 0.265f);
    glEnd();



    ///....................Hand left....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.254f);
    glVertex2f(0.282f, 0.25f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.252f);
    glVertex2f(0.282f, 0.254f);
    glVertex2f(0.29f, 0.265f);
    glEnd();
    glPopMatrix();
}
void human5()
{

    /**..........................................Human...............................................**/
    ///..........Head..........
    glPushMatrix();
    glTranslatef(-0.5f,0.02f,0.0f);
    glScalef(0.9f,0.9f,0.0f);
    GLfloat x=0.3f;
    GLfloat y=0.28f;
    GLfloat radius =0.01f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.3f;
    y=0.28f;
    radius =0.01f;

    triangleAmount = 100;
    twicePi = -1.0f * PI;

    glColor3f(0.702f, 0.447f, 0.240f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }
    glEnd();

/// Hair bun for the head
    x=0.284f;
    y=0.278f;
    radius =0.0087f;

    triangleAmount = 100;
    twicePi = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }

    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.296f, 0.278f);
    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.306f, 0.278f);
    glEnd();

    glPointSize(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.298f, 0.275f);
    glVertex2f(0.304f, 0.275f);
    glEnd();

    ///.........................Body.....................
    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.0f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    ///.........................Shari.....................
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glVertex2f(0.31f, 0.26f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.248f);
    glVertex2f(0.29f, 0.232f);
    glVertex2f(0.296f, 0.232f);
    glVertex2f(0.304f, 0.232f);
    glVertex2f(0.31f, 0.232f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    ///....................Hand Right....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.254f);
    glVertex2f(0.318f, 0.25f);
    glVertex2f(0.31f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.252f);
    glVertex2f(0.318f, 0.254f);
    glVertex2f(0.31f, 0.265f);
    glEnd();



    ///....................Hand left....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.254f);
    glVertex2f(0.282f, 0.25f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.252f);
    glVertex2f(0.282f, 0.254f);
    glVertex2f(0.29f, 0.265f);
    glEnd();
    glPopMatrix();
}
void human6()
{
    ///..........Head..........
    glPushMatrix();
    glTranslatef(0.05f,0.02f,0.0f);
    glScalef(0.9f,0.9f,0.0f);
    GLfloat x=0.3f;
    GLfloat y=0.28f;
    GLfloat radius =0.01f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.3f;
    y=0.28f;
    radius =0.01f;

    triangleAmount = 100;
    twicePi = -1.0f * PI;

    glColor3f(0.702f, 0.447f, 0.240f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }

    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.296f, 0.278f);
    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.306f, 0.278f);
    glEnd();

    glPointSize(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.298f, 0.275f);
    glVertex2f(0.304f, 0.275f);
    glEnd();

    ///.........................Body.....................
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.7f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glLineWidth(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.3f, 0.273f);
    glVertex2f(0.3f, 0.25f);

    glEnd();

    ///....................Hand Right....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.254f);
    glVertex2f(0.318f, 0.25f);
    glVertex2f(0.31f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.252f);
    glVertex2f(0.318f, 0.254f);
    glVertex2f(0.31f, 0.265f);
    glEnd();



    ///....................Hand left....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.254f);
    glVertex2f(0.282f, 0.25f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.252f);
    glVertex2f(0.282f, 0.254f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    ///................................Legs............................

    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.29f, 0.23f);
    glVertex2f(0.296f, 0.23f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.304f, 0.23f);
    glVertex2f(0.31f, 0.23f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.745f, 0.710f);
    glVertex2f(0.29f, 0.248f);
    glVertex2f(0.29f, 0.232f);
    glVertex2f(0.296f, 0.232f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.304f, 0.232f);
    glVertex2f(0.31f, 0.232f);
    glVertex2f(0.31f, 0.25f);
    glEnd();
    glPopMatrix();
}

void human7()
{

    /**..........................................Human...............................................**/
    ///..........Head..........
    glPushMatrix();
    glTranslatef(-0.57f,0.02f,0.0f);
    glScalef(0.9f,0.9f,0.0f);
    GLfloat x=0.3f;
    GLfloat y=0.28f;
    GLfloat radius =0.01f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.3f;
    y=0.28f;
    radius =0.01f;

    triangleAmount = 100;
    twicePi = -1.0f * PI;

    glColor3f(0.702f, 0.447f, 0.240f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }
    glEnd();

/// Hair bun for the head
    x=0.284f;
    y=0.278f;
    radius =0.0087f;

    triangleAmount = 100;
    twicePi = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }

    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.296f, 0.278f);
    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.306f, 0.278f);
    glEnd();

    glPointSize(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.298f, 0.275f);
    glVertex2f(0.304f, 0.275f);
    glEnd();

    ///.........................Body.....................
    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.0f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    ///.........................Shari.....................
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glVertex2f(0.31f, 0.26f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.248f);
    glVertex2f(0.29f, 0.232f);
    glVertex2f(0.296f, 0.232f);
    glVertex2f(0.304f, 0.232f);
    glVertex2f(0.31f, 0.232f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    ///....................Hand Right....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.254f);
    glVertex2f(0.318f, 0.25f);
    glVertex2f(0.31f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.252f);
    glVertex2f(0.318f, 0.254f);
    glVertex2f(0.31f, 0.265f);
    glEnd();



    ///....................Hand left....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.254f);
    glVertex2f(0.282f, 0.25f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.252f);
    glVertex2f(0.282f, 0.254f);
    glVertex2f(0.29f, 0.265f);
    glEnd();
    glPopMatrix();
}


//down platform
//female
void human8()
{

    /**..........................................Human...............................................**/
    ///..........Head..........
    glPushMatrix();
    glTranslatef(-0.55f,-0.88f,0.0f);
    glScalef(1.0f,1.0f,0.0f);
    GLfloat x=0.3f;
    GLfloat y=0.28f;
    GLfloat radius =0.01f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.3f;
    y=0.28f;
    radius =0.01f;

    triangleAmount = 100;
    twicePi = -1.0f * PI;

    glColor3f(0.702f, 0.447f, 0.240f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }
    glEnd();

/// Hair bun for the head
    x=0.284f;
    y=0.278f;
    radius =0.0087f;

    triangleAmount = 100;
    twicePi = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }

    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.296f, 0.278f);
    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.306f, 0.278f);
    glEnd();

    glPointSize(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.298f, 0.275f);
    glVertex2f(0.304f, 0.275f);
    glEnd();

    ///.........................Body.....................
    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.0f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    ///.........................Shari.....................
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glVertex2f(0.31f, 0.26f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.248f);
    glVertex2f(0.29f, 0.232f);
    glVertex2f(0.296f, 0.232f);
    glVertex2f(0.304f, 0.232f);
    glVertex2f(0.31f, 0.232f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    ///....................Hand Right....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.254f);
    glVertex2f(0.318f, 0.25f);
    glVertex2f(0.31f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.252f);
    glVertex2f(0.318f, 0.254f);
    glVertex2f(0.31f, 0.265f);
    glEnd();



    ///....................Hand left....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.254f);
    glVertex2f(0.282f, 0.25f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.252f);
    glVertex2f(0.282f, 0.254f);
    glVertex2f(0.29f, 0.265f);
    glEnd();
    glPopMatrix();
}

void human9()
{
    ///..........Head..........
    glPushMatrix();
    glTranslatef(0.09f,-0.88f,0.0f);
    glScalef(1.0f,1.0f,0.0f);
    GLfloat x=0.3f;
    GLfloat y=0.28f;
    GLfloat radius =0.01f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.3f;
    y=0.28f;
    radius =0.01f;

    triangleAmount = 100;
    twicePi = -1.0f * PI;

    glColor3f(0.702f, 0.447f, 0.240f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }

    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.296f, 0.278f);
    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.306f, 0.278f);

    glEnd();

    glPointSize(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.298f, 0.275f);
    glVertex2f(0.304f, 0.275f);
    glEnd();

    ///.........................Body.....................
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.7f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glLineWidth(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.3f, 0.273f);
    glVertex2f(0.3f, 0.25f);

    glEnd();

    ///....................Hand Right....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.254f);
    glVertex2f(0.318f, 0.25f);
    glVertex2f(0.31f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.252f);
    glVertex2f(0.318f, 0.254f);
    glVertex2f(0.31f, 0.265f);
    glEnd();



    ///....................Hand left....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.254f);
    glVertex2f(0.282f, 0.25f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.252f);
    glVertex2f(0.282f, 0.254f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    ///................................Legs............................

    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.29f, 0.23f);
    glVertex2f(0.296f, 0.23f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.304f, 0.23f);
    glVertex2f(0.31f, 0.23f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.745f, 0.710f);
    glVertex2f(0.29f, 0.248f);
    glVertex2f(0.29f, 0.232f);
    glVertex2f(0.296f, 0.232f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.304f, 0.232f);
    glVertex2f(0.31f, 0.232f);
    glVertex2f(0.31f, 0.25f);
    glEnd();
    glPopMatrix();
}
void human10()
{
    ///..........Head..........
    glPushMatrix();
    glTranslatef(0.13f,-0.88f,0.0f);
    glScalef(1.0f,1.0f,0.0f);
    GLfloat x=0.3f;
    GLfloat y=0.28f;
    GLfloat radius =0.01f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.3f;
    y=0.28f;
    radius =0.01f;

    triangleAmount = 100;
    twicePi = -1.0f * PI;

    glColor3f(0.702f, 0.447f, 0.240f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }

    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.296f, 0.278f);
    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.306f, 0.278f);
    glEnd();

    glPointSize(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.298f, 0.275f);
    glVertex2f(0.304f, 0.275f);
    glEnd();

    ///.........................Body.....................
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.7f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glLineWidth(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.3f, 0.273f);
    glVertex2f(0.3f, 0.25f);

    glEnd();

    ///....................Hand Right....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.254f);
    glVertex2f(0.318f, 0.25f);
    glVertex2f(0.31f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.252f);
    glVertex2f(0.318f, 0.254f);
    glVertex2f(0.31f, 0.265f);
    glEnd();



    ///....................Hand left....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.254f);
    glVertex2f(0.282f, 0.25f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.252f);
    glVertex2f(0.282f, 0.254f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    ///................................Legs............................

    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.29f, 0.23f);
    glVertex2f(0.296f, 0.23f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.304f, 0.23f);
    glVertex2f(0.31f, 0.23f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.745f, 0.710f);
    glVertex2f(0.29f, 0.248f);
    glVertex2f(0.29f, 0.232f);
    glVertex2f(0.296f, 0.232f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.304f, 0.232f);
    glVertex2f(0.31f, 0.232f);
    glVertex2f(0.31f, 0.25f);
    glEnd();
    glPopMatrix();
}

void human11()
{
    ///..........Head..........
    glPushMatrix();
    glTranslatef(0.17f,-0.88f,0.0f);
    glScalef(1.0f,1.0f,0.0f);
    GLfloat x=0.3f;
    GLfloat y=0.28f;
    GLfloat radius =0.01f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.3f;
    y=0.28f;
    radius =0.01f;

    triangleAmount = 100;
    twicePi = -1.0f * PI;

    glColor3f(0.702f, 0.447f, 0.240f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }

    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.296f, 0.278f);
    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.306f, 0.278f);
    glEnd();

    glPointSize(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.298f, 0.275f);
    glVertex2f(0.304f, 0.275f);
    glEnd();

    ///.........................Body.....................
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.7f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glLineWidth(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.3f, 0.273f);
    glVertex2f(0.3f, 0.25f);

    glEnd();

    ///....................Hand Right....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.254f);
    glVertex2f(0.318f, 0.25f);
    glVertex2f(0.31f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.252f);
    glVertex2f(0.318f, 0.254f);
    glVertex2f(0.31f, 0.265f);
    glEnd();



    ///....................Hand left....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.254f);
    glVertex2f(0.282f, 0.25f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.252f);
    glVertex2f(0.282f, 0.254f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    ///................................Legs............................

    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.29f, 0.23f);
    glVertex2f(0.296f, 0.23f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.304f, 0.23f);
    glVertex2f(0.31f, 0.23f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.745f, 0.710f);
    glVertex2f(0.29f, 0.248f);
    glVertex2f(0.29f, 0.232f);
    glVertex2f(0.296f, 0.232f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.304f, 0.232f);
    glVertex2f(0.31f, 0.232f);
    glVertex2f(0.31f, 0.25f);
    glEnd();
    glPopMatrix();
}



void human4_down()
{

    /**..........................................Human...............................................**/
    ///..........Head..........
    glPushMatrix();
    glTranslatef(-0.88f,-0.88f,0.0f);
    glScalef(1.0f,1.0f,0.0f);
    GLfloat x=0.3f;
    GLfloat y=0.28f;
    GLfloat radius =0.01f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.3f;
    y=0.28f;
    radius =0.01f;

    triangleAmount = 100;
    twicePi = -1.0f * PI;

    glColor3f(0.702f, 0.447f, 0.240f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }
    glEnd();

/// Hair bun for the head
    x=0.284f;
    y=0.278f;
    radius =0.0087f;

    triangleAmount = 100;
    twicePi = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }

    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.296f, 0.278f);
    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.306f, 0.278f);
    glEnd();

    glPointSize(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.298f, 0.275f);
    glVertex2f(0.304f, 0.275f);
    glEnd();

    ///.........................Body.....................
    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.0f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    ///.........................Shari.....................
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glVertex2f(0.31f, 0.26f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.248f);
    glVertex2f(0.29f, 0.232f);
    glVertex2f(0.296f, 0.232f);
    glVertex2f(0.304f, 0.232f);
    glVertex2f(0.31f, 0.232f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    ///....................Hand Right....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.254f);
    glVertex2f(0.318f, 0.25f);
    glVertex2f(0.31f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.252f);
    glVertex2f(0.318f, 0.254f);
    glVertex2f(0.31f, 0.265f);
    glEnd();



    ///....................Hand left....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.254f);
    glVertex2f(0.282f, 0.25f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.252f);
    glVertex2f(0.282f, 0.254f);
    glVertex2f(0.29f, 0.265f);
    glEnd();
    glPopMatrix();
}
void human5_down()
{

    /**..........................................Human...............................................**/
    ///..........Head..........
    glPushMatrix();
    glTranslatef(-0.92f,-0.88f,0.0f);
    //glTranslatef(0.17f,-0.88f,0.0f);
    glScalef(1.0f,1.0f,0.0f);
    GLfloat x=0.3f;
    GLfloat y=0.28f;
    GLfloat radius =0.01f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.3f;
    y=0.28f;
    radius =0.01f;

    triangleAmount = 100;
    twicePi = -1.0f * PI;

    glColor3f(0.702f, 0.447f, 0.240f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }
    glEnd();

/// Hair bun for the head
    x=0.284f;
    y=0.278f;
    radius =0.0087f;

    triangleAmount = 100;
    twicePi = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }

    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.296f, 0.278f);
    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.306f, 0.278f);
    glEnd();

    glPointSize(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.298f, 0.275f);
    glVertex2f(0.304f, 0.275f);
    glEnd();

    ///.........................Body.....................
    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.0f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    ///.........................Shari.....................
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glVertex2f(0.31f, 0.26f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.248f);
    glVertex2f(0.29f, 0.232f);
    glVertex2f(0.296f, 0.232f);
    glVertex2f(0.304f, 0.232f);
    glVertex2f(0.31f, 0.232f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    ///....................Hand Right....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.254f);
    glVertex2f(0.318f, 0.25f);
    glVertex2f(0.31f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.252f);
    glVertex2f(0.318f, 0.254f);
    glVertex2f(0.31f, 0.265f);
    glEnd();



    ///....................Hand left....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.254f);
    glVertex2f(0.282f, 0.25f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.252f);
    glVertex2f(0.282f, 0.254f);
    glVertex2f(0.29f, 0.265f);
    glEnd();
    glPopMatrix();
}
void human6_down()
{
    ///..........Head..........
    glPushMatrix();
    glTranslatef(0.05f,0.02f,0.0f);
    glScalef(0.9f,0.9f,0.0f);
    GLfloat x=0.3f;
    GLfloat y=0.28f;
    GLfloat radius =0.01f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.3f;
    y=0.28f;
    radius =0.01f;

    triangleAmount = 100;
    twicePi = -1.0f * PI;

    glColor3f(0.702f, 0.447f, 0.240f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }

    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.296f, 0.278f);
    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.306f, 0.278f);
    glEnd();

    glPointSize(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.298f, 0.275f);
    glVertex2f(0.304f, 0.275f);
    glEnd();

    ///.........................Body.....................
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.7f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glLineWidth(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.3f, 0.273f);
    glVertex2f(0.3f, 0.25f);

    glEnd();

    ///....................Hand Right....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.254f);
    glVertex2f(0.318f, 0.25f);
    glVertex2f(0.31f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.252f);
    glVertex2f(0.318f, 0.254f);
    glVertex2f(0.31f, 0.265f);
    glEnd();



    ///....................Hand left....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.254f);
    glVertex2f(0.282f, 0.25f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.252f);
    glVertex2f(0.282f, 0.254f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    ///................................Legs............................

    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.29f, 0.23f);
    glVertex2f(0.296f, 0.23f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.304f, 0.23f);
    glVertex2f(0.31f, 0.23f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.745f, 0.710f);
    glVertex2f(0.29f, 0.248f);
    glVertex2f(0.29f, 0.232f);
    glVertex2f(0.296f, 0.232f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.304f, 0.232f);
    glVertex2f(0.31f, 0.232f);
    glVertex2f(0.31f, 0.25f);
    glEnd();
    glPopMatrix();
}

void human7_down()
{

    /**..........................................Human...............................................**/
    ///..........Head..........
    glPushMatrix();
    glTranslatef(-0.55f,0.02f,0.0f);
    glScalef(0.9f,0.9f,0.0f);
    GLfloat x=0.3f;
    GLfloat y=0.28f;
    GLfloat radius =0.01f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.3f;
    y=0.28f;
    radius =0.01f;

    triangleAmount = 100;
    twicePi = -1.0f * PI;

    glColor3f(0.702f, 0.447f, 0.240f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }
    glEnd();

/// Hair bun for the head
    x=0.284f;
    y=0.278f;
    radius =0.0087f;

    triangleAmount = 100;
    twicePi = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }

    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.296f, 0.278f);
    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.306f, 0.278f);
    glEnd();

    glPointSize(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.298f, 0.275f);
    glVertex2f(0.304f, 0.275f);
    glEnd();

    ///.........................Body.....................
    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.0f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    ///.........................Shari.....................
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glVertex2f(0.31f, 0.26f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.248f);
    glVertex2f(0.29f, 0.232f);
    glVertex2f(0.296f, 0.232f);
    glVertex2f(0.304f, 0.232f);
    glVertex2f(0.31f, 0.232f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    ///....................Hand Right....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.254f);
    glVertex2f(0.318f, 0.25f);
    glVertex2f(0.31f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.252f);
    glVertex2f(0.318f, 0.254f);
    glVertex2f(0.31f, 0.265f);
    glEnd();



    ///....................Hand left....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.254f);
    glVertex2f(0.282f, 0.25f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.252f);
    glVertex2f(0.282f, 0.254f);
    glVertex2f(0.29f, 0.265f);
    glEnd();
    glPopMatrix();
}
void human8_down()
{
    ///..........Head..........
    glPushMatrix();
    glTranslatef(-0.4f,-0.85f,0.0f);
    glScalef(0.9f,0.9f,0.0f);
    GLfloat x=0.3f;
    GLfloat y=0.28f;
    GLfloat radius =0.01f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.3f;
    y=0.28f;
    radius =0.01f;

    triangleAmount = 100;
    twicePi = -1.0f * PI;

    glColor3f(0.702f, 0.447f, 0.240f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }

    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.296f, 0.278f);
    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.306f, 0.278f);
    glEnd();

    glPointSize(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.298f, 0.275f);
    glVertex2f(0.304f, 0.275f);
    glEnd();

    ///.........................Body.....................
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.7f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glLineWidth(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.3f, 0.273f);
    glVertex2f(0.3f, 0.25f);

    glEnd();

    ///....................Hand Right....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.254f);
    glVertex2f(0.318f, 0.25f);
    glVertex2f(0.31f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.252f);
    glVertex2f(0.318f, 0.254f);
    glVertex2f(0.31f, 0.265f);
    glEnd();



    ///....................Hand left....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.254f);
    glVertex2f(0.282f, 0.25f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.252f);
    glVertex2f(0.282f, 0.254f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    ///................................Legs............................

    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.29f, 0.23f);
    glVertex2f(0.296f, 0.23f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.304f, 0.23f);
    glVertex2f(0.31f, 0.23f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.745f, 0.710f);
    glVertex2f(0.29f, 0.248f);
    glVertex2f(0.29f, 0.232f);
    glVertex2f(0.296f, 0.232f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.304f, 0.232f);
    glVertex2f(0.31f, 0.232f);
    glVertex2f(0.31f, 0.25f);
    glEnd();
    glPopMatrix();
}

void human9_down()
{
    ///..........Head..........
    glPushMatrix();
    glTranslatef(-0.45f,-0.85f,0.0f);
    glScalef(0.9f,0.9f,0.0f);
    GLfloat x=0.3f;
    GLfloat y=0.28f;
    GLfloat radius =0.01f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.3f;
    y=0.28f;
    radius =0.01f;

    triangleAmount = 100;
    twicePi = -1.0f * PI;

    glColor3f(0.702f, 0.447f, 0.240f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }

    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.296f, 0.278f);
    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.306f, 0.278f);
    glEnd();

    glPointSize(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.298f, 0.275f);
    glVertex2f(0.304f, 0.275f);
    glEnd();

    ///.........................Body.....................
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.7f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glLineWidth(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.3f, 0.273f);
    glVertex2f(0.3f, 0.25f);

    glEnd();

    ///....................Hand Right....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.254f);
    glVertex2f(0.318f, 0.25f);
    glVertex2f(0.31f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.252f);
    glVertex2f(0.318f, 0.254f);
    glVertex2f(0.31f, 0.265f);
    glEnd();



    ///....................Hand left....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.254f);
    glVertex2f(0.282f, 0.25f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.252f);
    glVertex2f(0.282f, 0.254f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    ///................................Legs............................

    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.29f, 0.23f);
    glVertex2f(0.296f, 0.23f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.304f, 0.23f);
    glVertex2f(0.31f, 0.23f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.745f, 0.710f);
    glVertex2f(0.29f, 0.248f);
    glVertex2f(0.29f, 0.232f);
    glVertex2f(0.296f, 0.232f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.304f, 0.232f);
    glVertex2f(0.31f, 0.232f);
    glVertex2f(0.31f, 0.25f);
    glEnd();
    glPopMatrix();

}

void human10_down()
{
    ///..........Head..........
    glPushMatrix();
    glTranslatef(-0.48f,-0.85f,0.0f);
    glScalef(0.9f,0.9f,0.0f);
    GLfloat x=0.3f;
    GLfloat y=0.28f;
    GLfloat radius =0.01f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.3f;
    y=0.28f;
    radius =0.01f;

    triangleAmount = 100;
    twicePi = -1.0f * PI;

    glColor3f(0.702f, 0.447f, 0.240f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }

    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.296f, 0.278f);
    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.306f, 0.278f);
    glEnd();

    glPointSize(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.298f, 0.275f);
    glVertex2f(0.304f, 0.275f);
    glEnd();

    ///.........................Body.....................
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.7f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glLineWidth(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.3f, 0.273f);
    glVertex2f(0.3f, 0.25f);

    glEnd();

    ///....................Hand Right....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.254f);
    glVertex2f(0.318f, 0.25f);
    glVertex2f(0.31f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.252f);
    glVertex2f(0.318f, 0.254f);
    glVertex2f(0.31f, 0.265f);
    glEnd();



    ///....................Hand left....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.254f);
    glVertex2f(0.282f, 0.25f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.252f);
    glVertex2f(0.282f, 0.254f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    ///................................Legs............................

    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.29f, 0.23f);
    glVertex2f(0.296f, 0.23f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.304f, 0.23f);
    glVertex2f(0.31f, 0.23f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.745f, 0.710f);
    glVertex2f(0.29f, 0.248f);
    glVertex2f(0.29f, 0.232f);
    glVertex2f(0.296f, 0.232f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.304f, 0.232f);
    glVertex2f(0.31f, 0.232f);
    glVertex2f(0.31f, 0.25f);
    glEnd();
    glPopMatrix();

}

void human11_down()
{
    ///..........Head..........
    glPushMatrix();
    glTranslatef(-0.60f,-0.85f,0.0f);
    glScalef(0.9f,0.9f,0.0f);
    GLfloat x=0.3f;
    GLfloat y=0.28f;
    GLfloat radius =0.01f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.3f;
    y=0.28f;
    radius =0.01f;

    triangleAmount = 100;
    twicePi = -1.0f * PI;

    glColor3f(0.702f, 0.447f, 0.240f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }

    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.296f, 0.278f);
    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.306f, 0.278f);
    glEnd();

    glPointSize(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.298f, 0.275f);
    glVertex2f(0.304f, 0.275f);
    glEnd();

    ///.........................Body.....................
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.7f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glLineWidth(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.3f, 0.273f);
    glVertex2f(0.3f, 0.25f);

    glEnd();

    ///....................Hand Right....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.254f);
    glVertex2f(0.318f, 0.25f);
    glVertex2f(0.31f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.252f);
    glVertex2f(0.318f, 0.254f);
    glVertex2f(0.31f, 0.265f);
    glEnd();



    ///....................Hand left....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.254f);
    glVertex2f(0.282f, 0.25f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.252f);
    glVertex2f(0.282f, 0.254f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    ///................................Legs............................

    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.29f, 0.23f);
    glVertex2f(0.296f, 0.23f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.304f, 0.23f);
    glVertex2f(0.31f, 0.23f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.745f, 0.710f);
    glVertex2f(0.29f, 0.248f);
    glVertex2f(0.29f, 0.232f);
    glVertex2f(0.296f, 0.232f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.304f, 0.232f);
    glVertex2f(0.31f, 0.232f);
    glVertex2f(0.31f, 0.25f);
    glEnd();
    glPopMatrix();

}

void human12_down()
{
    ///..........Head..........
    glPushMatrix();
    glTranslatef(-1.2f,-0.85f,0.0f);
    glScalef(0.9f,0.9f,0.0f);
    GLfloat x=0.3f;
    GLfloat y=0.28f;
    GLfloat radius =0.01f;
    int triangleAmount = 100;
    GLfloat twicePi = 1.0f * PI;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    x=0.3f;
    y=0.28f;
    radius =0.01f;

    triangleAmount = 100;
    twicePi = -1.0f * PI;

    glColor3f(0.702f, 0.447f, 0.240f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );

    }

    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.296f, 0.278f);
    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.306f, 0.278f);
    glEnd();

    glPointSize(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f, 0.0f);
    glVertex2f(0.298f, 0.275f);
    glVertex2f(0.304f, 0.275f);
    glEnd();

    ///.........................Body.....................
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.7f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glLineWidth(0.1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.3f, 0.273f);
    glVertex2f(0.3f, 0.25f);

    glEnd();

    ///....................Hand Right....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.254f);
    glVertex2f(0.318f, 0.25f);
    glVertex2f(0.31f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.31f, 0.273f);
    glVertex2f(0.32f, 0.252f);
    glVertex2f(0.318f, 0.254f);
    glVertex2f(0.31f, 0.265f);
    glEnd();



    ///....................Hand left....................
    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.254f);
    glVertex2f(0.282f, 0.25f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.540f, 0.510f);
    glVertex2f(0.29f, 0.273f);
    glVertex2f(0.28f, 0.252f);
    glVertex2f(0.282f, 0.254f);
    glVertex2f(0.29f, 0.265f);
    glEnd();

    ///................................Legs............................

    glBegin(GL_QUADS);
    glColor3f(0.702f, 0.447f, 0.240f);
    glVertex2f(0.29f, 0.25f);
    glVertex2f(0.29f, 0.23f);
    glVertex2f(0.296f, 0.23f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.304f, 0.23f);
    glVertex2f(0.31f, 0.23f);
    glVertex2f(0.31f, 0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.745f, 0.710f);
    glVertex2f(0.29f, 0.248f);
    glVertex2f(0.29f, 0.232f);
    glVertex2f(0.296f, 0.232f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.304f, 0.232f);
    glVertex2f(0.31f, 0.232f);
    glVertex2f(0.31f, 0.25f);
    glEnd();
    glPopMatrix();

}






void draw_newspaper_store(float x, float y)
{
    // Store base (rectangle)
    glColor3ub(139, 69, 19); // Brown color for the store
    glBegin(GL_QUADS);
    glVertex2f(x - 0.15f, y);       // Bottom-left
    glVertex2f(x + 0.15f, y);       // Bottom-right
    glVertex2f(x + 0.15f, y + 0.2f); // Top-right
    glVertex2f(x - 0.15f, y + 0.2f); // Top-left
    glEnd();

    // Roof (triangle)
    glColor3ub(165, 42, 42); // Darker brown for the roof
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 0.18f, y + 0.2f); // Left point
    glVertex2f(x + 0.18f, y + 0.2f); // Right point
    glVertex2f(x, y + 0.3f);         // Top point
    glEnd();

    // Door (rectangle)
    glColor3ub(0, 0, 0); // Black door
    glBegin(GL_QUADS);
    glVertex2f(x - 0.05f, y);       // Bottom-left
    glVertex2f(x + 0.05f, y);       // Bottom-right
    glVertex2f(x + 0.05f, y + 0.1f); // Top-right
    glVertex2f(x - 0.05f, y + 0.1f); // Top-left
    glEnd();

    // Signboard
    glColor3ub(255, 255, 0); // Yellow signboard
    glBegin(GL_QUADS);
    glVertex2f(x - 0.1f, y + 0.22f); // Bottom-left
    glVertex2f(x + 0.1f, y + 0.22f); // Bottom-right
    glVertex2f(x + 0.1f, y + 0.25f); // Top-right
    glVertex2f(x - 0.1f, y + 0.25f); // Top-left
    glEnd();

    // Text on signboard (e.g., "NEWS")
    glColor3ub(0, 0, 0); // Black text
    glRasterPos2f(x - 0.04f, y + 0.22f); // Adjust position
    const unsigned char text[] = "STORE";
    for (int i = 0; i < 5; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}
bool soundOn = false; // Flag to track sound status
void sound()
{
    if (soundOn)
    {
        PlaySound("a.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    }
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == ' ')   // Toggle sound on/off
    {
        soundOn = !soundOn;
        if (soundOn)
        {
            sound();
        }
        else
        {
            PlaySound(NULL, 0, 0);
        }
    }
}






void display()
{
    // Set background color to dark blue for night sky
    //glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
    glClearColor(0.5294f, 0.8078f, 0.9216f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glLoadIdentity();


    glPushMatrix();                 // Save the current matrix state
    glTranslatef(0.2f, 0.05f, 0.0f); // Move up along the Y-axis
    tree2();
    tree_leaf2();
    // Draw the tree in the transformed position
    glPopMatrix();


    glPushMatrix();                 // Save the current matrix state
    glTranslatef(0.0f, 0.05f, 0.0f); // Move up along the Y-axis
    tree1();
    tree2();
    tree_leaf1();
    tree_leaf2();
    // Draw the tree in the transformed position
    glPopMatrix();

    /*
        // Calculate and set responsive text position
        float x, y;
        setResponsiveTextPosition("COX'S BAZAR RAILWAY STATION", x, y);

        glColor3f(0.973, 0.988, 0.42);
        renderBitmapString(x, y, 0.0f, GLUT_BITMAP_HELVETICA_18, "COX'S BAZAR RAILWAY STATION");
    */


    station();
    platform();


    human1();
    //human2();
    human3();
    // human4();
    human5();
    human6();
    //human7();
    human6_down();
    human7_down();
    sun();

    glPushMatrix();
    glTranslatef(cloud1_position,0.0f, 0.0f);

    cloud1();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloud2_position,0.0f, 0.0f);

    cloud2();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(cloud3_position,0.0f, 0.0f);
    cloud3();
    glPopMatrix();






    //bird_left9();
    //circle();
    //circle_bird();
    // sun_shadow();



    glPushMatrix();
    glTranslatef(train1_position,0.0f, 0.0f);

    drawTrain();

    glPopMatrix();




    glPushMatrix();
    glTranslatef(train2_position, 0.0f, 0.0f);
    glRotated(-90, 1.0, 0.0, 0.0);
    drawTrain2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(train2_position, 0.0f, 0.0f);
    glRotated(-90, 1.0, 0.0, 0.0);
    glScalef(1.0, -1.0, 1.0);
    drawTrain2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(train2_position, 0.0f, 0.0f);  // Position the train
    glScalef(-1.0f, 1.0f, 1.0f);               // Flip the train along Y-axis
    drawTrain2();                              // Draw the train
    glPopMatrix();



    platform_down();


    // human8();
    human9();
    human10();
    human11();

    human4_down();
    human5_down();

    human8_down();
    human9_down();
    human10_down();
    human11_down();
    human12_down();


    //birds
    glPushMatrix();
    glTranslatef(right_bird_position, right_bird_position, 0.0f);

    // Apply scaling transformation to dynamically change size
    GLfloat bird_scale = 0.3f + 0.3f * (1.0f + fabs(right_bird_position)); // Dynamic scaling
    glScalef(bird_scale, bird_scale, 1.0f);

    // Apply rotation transformation (rotating by 45 degrees)
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f); // Rotate around Z-axis

    // Draw birds (replace with your actual bird functions)
    // Draw the bird
    bird_left1();
    bird_left2();
    bird_left3();
    bird_left4();
    bird_left5();
    bird_left6();
    bird_left7();
    bird_left8();

    //keyboard();

    //  keybd_event();

    glPopMatrix();




    glutSwapBuffers();
    glFlush();
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("Railway Station");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
//    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    font = GLUT_BITMAP_HELVETICA_18;

    glutTimerFunc(100, train1_update, 0);
    glutTimerFunc(100, train2_update, 0);
    glutTimerFunc(100, cloud1_update, 0);

    glutTimerFunc(100, cloud2_update, 0);
    glutTimerFunc(100, cloud3_update, 0);
    sound();

    glutTimerFunc(500, update_right_bird, 0);

    glutMainLoop();
    return 0;
}




