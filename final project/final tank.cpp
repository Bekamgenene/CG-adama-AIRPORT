#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

float r = 10.0; //horznotal postion of airplan
float f = 70.0;//vertical postion of airplan
float t = 0.05;//vertical moving postion of airplan
float c = 70.0;//horznotal moving postion of cloud
float c2 = 90.0;//horznotal moving postion of cloud2
float mp = 830;//mini plan
float v = 880;//postion of vehicle
bool isDay = true;
int displayState = 0; // 0 for initial display, 1 for main drawing
float vehicle1_x = 0; // Vehicle moving from west to east
float vehicle2_x = 1400; // Vehicle moving from east to west
float vehicle3_x = 700; // Another vehicle moving from east to west

//text that desplay our name
void bitmap_output(int x, int y, char *string, void *font) {
    int len, i;
    glRasterPos2f(x, 600 - y); 
    len = (int)strlen(string);
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(font, string[i]);
    }
}

void displayInitial(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 1, 1);
    glVertex2f(30, 30);
    glVertex2f(870, 30);
    glVertex2f(870, 720);
    glVertex2f(30, 720);
    glEnd();

    glColor3f(1, 0, 0);
    bitmap_output(250, 140, "ADAMA INTERNATIONAL AIRPORT", GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3f(1, 1, 1);
    bitmap_output(138, 170, "          ADAMA SCIENCE AND TECHNOLOGY UNIVERSITY", GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(1, 1, 1);
    bitmap_output(138, 210, "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING", GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3f(102, 51, 0);
    bitmap_output(170, 250, "Submited To: ", GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(38, 38, 38);
    bitmap_output(170, 270, "Mr. Alemayehu Megersa", GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3f(38, 38, 38);
    bitmap_output(170, 290, "Course Name: COMPUTER GRAPHICS", GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3f(38, 38, 38);
    bitmap_output(170, 320, "Section: 2", GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3f(102, 51, 0);
    bitmap_output(170, 350, "Submited By:", GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(255, 102, 0);
    bitmap_output(210, 390, "NAME: ", GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(255, 102, 0);
    bitmap_output(450, 380, "ID: ", GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3f(38, 38, 38);
    bitmap_output(170, 420, "Bekam Genene", GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(38, 38, 38);
    bitmap_output(420, 420, "UGR/30253/15", GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3f(38, 38, 38);
    bitmap_output(170, 460, "Betelhem Yehuala", GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(38, 38, 38);
    bitmap_output(420, 460, "UGR/30284/15", GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3f(38, 38, 38);
    bitmap_output(170, 500, "Folikia Nigussie", GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(38, 38, 38);
    bitmap_output(420, 500, "UGR/30562/15", GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3f(38, 38, 38);
    bitmap_output(170, 540, "Yeabsira Goitom ", GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(38, 38, 38);
    bitmap_output(420, 540, "UGR/31390/15", GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3f(1, 0, 0);
    bitmap_output(650, 480, "Press `ENTER'", GLUT_BITMAP_TIMES_ROMAN_24);
    glEnd();
    glFlush();
    glutSwapBuffers();
}
 //day and night contorler
void keyboard(unsigned char key, int x, int y) {
    if (key == 13) { // Enter key
        displayState = 1; // Switch to main drawing
        glutPostRedisplay();
    }
    if (key == 't' || key == 'T') { 
        isDay = !isDay; // Toggle day/night
        glutPostRedisplay();
    }
}
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity();
    glOrtho(0.0, 1000.0, 0.0, 500.0, -1.0, 1.0); 
   
}

//ethiopian flag
void drawEthiopianFlag() {
    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.5f, 0.0f);  // Green stripe
    glVertex2f(200.0f, 220.0f);
    glVertex2f(375.0f, 220.0f);
    glVertex2f(375.0f, 250.0f);
    glVertex2f(200.0f, 250.0f);

    glColor3f(1.0f, 1.0f, 0.0f);  // Yellow stripe
    glVertex2f(200.0f, 190.0f);
    glVertex2f(375.0f, 190.0f);
    glVertex2f(375.0f, 220.0f);
    glVertex2f(200.0f, 220.0f);

    glColor3f(1.0f, 0.0f, 0.0f);  // Red stripe
    glVertex2f(200.0f, 160.0f);
    glVertex2f(375.0f, 160.0f);
    glVertex2f(375.0f, 190.0f);
    glVertex2f(200.0f, 190.0f);

    glEnd();
}

void drawFlagPole() {
    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);  // Pole color
    glVertex2f(195.0f, 0.0f);
    glVertex2f(200.0f, 0.0f);
    glVertex2f(200.0f, 250.0f);
    glVertex2f(195.0f, 250.0f);

    glEnd();
}

void drawStairBase() {
    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.5f, 0.5f);

    // Bottom step
    glVertex2f(185.0f, 0.0f);
    glVertex2f(225.0f, 0.0f);
    glVertex2f(225.0f, 10.0f);
    glVertex2f(185.0f, 10.0f);

    // Middle step
    glVertex2f(190.0f, 10.0f);
    glVertex2f(220.0f, 10.0f);
    glVertex2f(220.0f, 20.0f);
    glVertex2f(190.0f, 20.0f);

    // Top step
    glVertex2f(195.0f, 20.0f);
    glVertex2f(215.0f, 20.0f);
    glVertex2f(215.0f, 30.0f);
    glVertex2f(195.0f, 30.0f);

    glEnd();
}

void drawCircle(float cx, float cy, float radius, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++) {
        float theta = i * 3.14159 / 180.0f;
        float x = cx + radius * 0.8f * cos(theta);  
        float y = cy + radius * 0.8f * sin(theta);
        glVertex2f(x, y);
    }

    glEnd();
}

void drawStar() {
    glLineWidth(1.0);  
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_LINE_LOOP);

    glVertex2f(270.0f, 210.0f);  
    glVertex2f(305.0f, 210.0f);
    glVertex2f(275.0f, 186.0f);
    glVertex2f(287.5f, 225.0f);
    glVertex2f(300.0f, 186.0f);

    glEnd();
}

//text that written on the building...
void drawText(float x, float y, const char* text) {
    glColor3f(0.0f, 0.0f, 0.0f); 
    glRasterPos2f(x, y); 
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}
void drawText2(float x, float y, const char* text) {
    glColor3f(0.0f, 0.0f, 0.0f); 
    glRasterPos2f(x, y); 
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *c);
    }
}

//abstract color
float rgb(float rgb)
{
    float x = rgb / 255;
    return floorf(x * 100) / 100;
}

//oromia flag
void drawOromiaFlag() {
    // Red 
    glColor3f(1.0f, 0.0f, 0.0f); 
    glRecti(75, 200, 225, 225);

    // White 
    glColor3f(1.0f, 1.0f, 1.0f);
    glRecti(75, 175, 225, 200);

    // Black 
    glColor3f(0.0f, 0.0f, 0.0f); 
    glRecti(75, 150, 225, 175);
    
    // Draw wood of the odaa
    glColor3f(0.55f, 0.27f, 0.07f); 
    glRecti(144, 172, 146, 185); 
    
    // Triangle for the wood
    glColor3f(0.55f, 0.27f, 0.07f); 
    glBegin(GL_TRIANGLES); 
        glVertex2i(148, 186);  
        glVertex2i(148, 172);  
        glVertex2i(140, 172);  
    glEnd(); 
    
    glBegin(GL_TRIANGLES); 
        glVertex2i(142, 186);  
        glVertex2i(148, 172);  
        glVertex2i(152, 172);  
    glEnd(); 

    // Flagpole
    glColor3f(0.5f, 0.35f, 0.05f); 
    glRecti(70, 0, 75, 225);
}

//odaa oromia
void drawSmallSycamoreTree() {
    // Simple green circles for leaves
    glColor3f(0.0f, 0.8f, 0.0f); 
    for (int i = 0; i < 3; i++) { 
        int y = 188 + (i * 5); 
        glBegin(GL_POLYGON);
        for (int j = 0; j < 360; j++) {
            float theta = j * 3.14159 / 180.0f; 
            glVertex2f(145 + 7 * cos(theta), y + 7 * sin(theta)); 
        }
        glEnd();
    }
    
    glColor3f(0.0f, 0.8f, 0.0f); 
    for (int i = 0; i < 2; i++) { 
        int y = 188 + (i * 5); 
        glBegin(GL_POLYGON);
        for (int j = 0; j < 360; j++) {
            float theta = j * 3.14159 / 180.0f;
            glVertex2f(145 + 7 * cos(theta) + 7, y + 7 * sin(theta)); 
        }
        glEnd();
        
        glColor3f(0.0f, 0.8f, 0.0f); 
        for (int i = 0; i < 2; i++) { 
            int y = 188 + (i * 5); 
            glBegin(GL_POLYGON);
            for (int j = 0; j < 360; j++) {
                float theta = j * 3.14159 / 180.0f; 
                glVertex2f(145 + 7 * cos(theta) - 7, y + 7 * sin(theta));
            }
            glEnd();
        }
    }
}

//trees around the building
void drawSmallTree(float x, float y) {
    glColor3f(0.55f, 0.27f, 0.07f); 
    glBegin(GL_QUADS);
    glVertex2f(x - 2, y); 
    glVertex2f(x + 2, y); 
    glVertex2f(x + 2, y + 10); 
    glVertex2f(x - 2, y + 10); 
    glEnd();

    // Draw leaves (using circles)
    glColor3f(0.0f, 0.8f, 0.0f); 
    int numLeaves = 3; 
    for (int i = 0; i < numLeaves; i++) {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y + 15 + (i * 8)); 
        for (int j = 0; j <= 360; j++) {
            float theta = j * 3.14159 / 180.0f;
            glVertex2f(x + 10 * cos(theta), y + 15 + (i * 8) + 10 * sin(theta)); 
        }
        glEnd();
    }
    
    // Draw leaves (using circles)
    glColor3f(0.0f, 0.8f, 0.0f); 
    int numLeaves2 = 2; 
    for (int i = 0; i < numLeaves2; i++) {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y + 15 + (i * 8)); 
        for (int j = 0; j <= 360; j++) {
            float theta = j * 3.14159 / 180.0f;
            glVertex2f(x + 20 * cos(theta), y + 15 + (i * 8) + 10 * sin(theta)); 
        }
        glEnd();
    }
    // Draw leaves (using circles)
    glColor3f(0.0f, 0.8f, 0.0f); 
    int numLeaves3 = 2; 
    for (int i = 0; i < numLeaves3; i++) {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y + 15 + (i * 8)); 
        for (int j = 0; j <= 360; j++) {
            float theta = j * 3.14159 / 180.0f;
            glVertex2f(x + 0 * cos(theta), y + 15 + (i * 8) + 10 * sin(theta)); 
        }
        glEnd();
    }
}

//bus vehicles
void drawVehicle(float x, float y) {
    
    glColor3f(0.8f, 0.8f, 0.9f); 
    glBegin(GL_QUADS);
    glVertex2f(x, y); 
    glVertex2f(x + 60, y); 
    glVertex2f(x + 60, y + 30); 
    glVertex2f(x, y + 30); 
    glEnd();
    
    // Draw the windows
    glColor3f(0.0f, 0.0f, 1.0f); 

    // Window 1
    glBegin(GL_QUADS);
    glVertex2f(x + 5, y + 15); 
    glVertex2f(x + 20, y + 15); 
    glVertex2f(x + 20, y + 25); 
    glVertex2f(x + 5, y + 25); 
    glEnd();

    // Window 2
    glBegin(GL_QUADS);
    glVertex2f(x + 20, y + 15); 
    glVertex2f(x + 35, y + 15); 
    glVertex2f(x + 35, y + 25); 
    glVertex2f(x + 20, y + 25); 
    glEnd();

    // Window 3
    glBegin(GL_QUADS);
    glVertex2f(x + 35, y + 15); 
    glVertex2f(x + 55, y + 15); 
    glVertex2f(x + 55, y + 25); 
    glVertex2f(x + 35, y + 25); 
    glEnd();
    drawText2(x+22, y + 5, "BUS");
    
    
    // Draw the wheels
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x + 10, y); 
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        glVertex2f(x + 10 + 5 * cos(angle), y + 5 * sin(angle)); 
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x + 45, y); 
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        glVertex2f(x + 45 + 5 * cos(angle), y + 5 * sin(angle)); 
    }
    glEnd();
}

//sun
void drawSun(float x, float y, float radius) {
    // Draw the sun's body
    glColor3f(1.0f, 1.0f, 0.0f); 
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f( x - c, y); 
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180.0f;
        glVertex2f(x - c + radius * cos(angle), y + radius * sin(angle)); 
    }
    glEnd();

    // Draw sun rays
    glColor3f(1.0f, 0.8f, 0.0f); 
    for (int i = 0; i < 12; i++) { 
        float angle = i * 30 * 3.14159 / 180.0f; 
        float x1 = x - c+ radius * cos(angle);
        float y1 = y + radius * sin(angle);
        float x2 = x - c + (radius + 20) * cos(angle); 
        float y2 = y + (radius + 20) * sin(angle);
        
        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
    }
	}
//moon
void drawMoon(float x, float y, float radius) {
    glColor3f(1.0f, 1.0f, 1.0f); 
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); 
    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159 / 180.0f;
        glVertex2f(x + radius * cos(angle), y + radius * sin(angle)); 
    }
    glEnd();
}

//main desplay function 
void Draw()

{
	 if (displayState == 0) {
        displayInitial();
        return;
    }
      glClear(GL_COLOR_BUFFER_BIT);

    // moving objects-----------------
    if (r <= 1000)
    {
        r = r + 0.7;
        f = f + t;
        t = t + 0.0003;

        // r = r + 0.5;
        // f = f + t;
        // t = t + 0.0001;
        // p = p + 0.001;
    }
    else {
        r = -20;
        f = 70;
        t = 0.5;


    }
    if (c <= 1000)
    {
       
        c = c + 0.1;
    }
    else {
        c = -50;
    }
    if (c2 <= 1000)
    {
        // c2 = c2 + 0.1;
        c2 = c2 + 0.1;
    }
    else {
        c2 = -500;
    }
    if (mp >= -100)
    {
        // c2 = c2 + 0.1;
        mp = mp - 0.1;
    }
    else {
        mp = 2000;
    }
    if (v >= -100)
    {
        // c2 = c2 + 0.1;
        v = v - 0.1;
    }
    else {
        v = 2000;
    }
    glutPostRedisplay();
    
    
    
    vehicle1_x += 0.2; // Move vehicle 1 to the right
    vehicle2_x -= 0.2; // Move vehicle 2 to the left
    vehicle3_x -= 0.2; // Move vehicle 3 to the left

    // Reset vehicle positions if they go off screen
    if (vehicle1_x > 1400) vehicle1_x = 0; // Reset vehicle 1
    if (vehicle2_x < -5) vehicle2_x = 1400; // Reset vehicle 2
    if (vehicle3_x < -5) vehicle3_x = 1400; 
    // ===================================

    // drawing sky==================================================
        if (isDay) {
        // Daytime
        glBegin(GL_POLYGON);
    glColor3f(rgb(228), rgb(247), rgb(254));
    glVertex2i(0, 100);
    glVertex2i(1000, 100);

    glColor3f(rgb(47), rgb(199), rgb(236));
    glVertex2i(1000, 500);
    glVertex2i(0, 500);
    glEnd();
     // Draw the sun
        drawSun(850, 450, 30); 
    // =========================================
     // Drawing cloud-----------------------------------------
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(c, 400);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 20 * cosf(angle);
        float y = 20 * sinf(angle);
        glVertex2f(x + c, y + 400);
    }
    glEnd();


    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(c + 30, 410);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 20 * cosf(angle);
        float y = 20 * sinf(angle);
        glVertex2f(x + c + 30, y + 410);
    }
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(c + 60, 400);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 20 * cosf(angle);
        float y = 20 * sinf(angle);
        glVertex2f(x + c + 60, y + 400);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2i(c, 380);
    glVertex2i(c + 60, 380);
    glVertex2i(c + 60, 400);
    glVertex2i(c, 400);
    glEnd();

    // mini cloud-----------------------------------
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(c2 + 530, 470);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 15 * cosf(angle);
        float y = 15 * sinf(angle);
        glVertex2f(x + c2 + 530, y + 470);
    }
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(c2 + 550, 470);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 15 * cosf(angle);
        float y = 15 * sinf(angle);
        glVertex2f(x + c2 + 550, y + 470);
    }
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(c2 + 540, 480);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 15 * cosf(angle);
        float y = 15 * sinf(angle);
        glVertex2f(x + c2 + 540, y + 480);
    }
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(c2 + 570, 470);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 15 * cosf(angle);
        float y = 15 * sinf(angle);
        glVertex2f(x + c2 + 570, y + 470);
    }
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(c2 + 560, 480);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 15 * cosf(angle);
        float y = 15 * sinf(angle);
        glVertex2f(x + c2 + 560, y + 480);
    }
    glEnd();


       
    } else {
        // Nighttime
        glBegin(GL_POLYGON);
        glColor3f(0.1f, 0.1f, 0.3f); 
        glVertex2i(0, 100);
        glVertex2i(1000, 100);
        glVertex2i(1000, 500);
        glVertex2i(0, 500);
        glEnd();
        
        // Draw the moon
         glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(c + 60, 400);
        for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 20 * cosf(angle);
        float y = 20 * sinf(angle);
        glVertex2f(x + c + 60, y + 400);
    }
    glEnd();
    }
    
    // drawing building
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(0), rgb(0));
    glVertex2i(800, 250);
    glVertex2i(850, 250);
    glVertex2i(850, 270);
    glVertex2i(800, 270);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(0), rgb(0), rgb(0));
    glVertex2i(800, 270);
    glVertex2i(850, 270);
    glVertex2i(850, 280);
    glVertex2i(800, 280);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(550, 250);
    glVertex2i(870, 230);
    glVertex2i(870, 250);
    glVertex2i(550, 270);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(rgb(0), rgb(0), rgb(0));
    glVertex2i(650, 180);
    glVertex2i(850, 230);
    glVertex2i(550, 250);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(0), rgb(0));
    glVertex2i(650, 220);
    glVertex2i(850, 220);
    glVertex2i(850, 230);
    glVertex2i(650, 230);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(650, 100);
    glVertex2i(850, 100);
    glVertex2i(850, 220);
    glVertex2i(650, 220);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(rgb(0), rgb(0), rgb(0));
    glVertex2i(670, 110);
    glVertex2i(740, 110);
    glVertex2i(740, 200);
    glVertex2i(670, 200);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(rgb(0), rgb(0), rgb(0));
    glVertex2i(760, 110);
    glVertex2i(830, 110);
    glVertex2i(830, 200);
    glVertex2i(760, 200);
    glEnd();

    // glass window---------------------------------------
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(680, 120);
    glVertex2i(700, 120);
    glVertex2i(700, 130);
    glVertex2i(680, 130);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(680, 140);
    glVertex2i(700, 140);
    glVertex2i(700, 150);
    glVertex2i(680, 150);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(680, 160);
    glVertex2i(700, 160);
    glVertex2i(700, 170);
    glVertex2i(680, 170);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(680, 180);
    glVertex2i(700, 180);
    glVertex2i(700, 190);
    glVertex2i(680, 190);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(710, 120);
    glVertex2i(730, 120);
    glVertex2i(730, 130);
    glVertex2i(710, 130);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(710, 140);
    glVertex2i(730, 140);
    glVertex2i(730, 150);
    glVertex2i(710, 150);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(710, 160);
    glVertex2i(730, 160);
    glVertex2i(730, 170);
    glVertex2i(710, 170);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(710, 180);
    glVertex2i(730, 180);
    glVertex2i(730, 190);
    glVertex2i(710, 190);
    glEnd();

    // 2nd part glass window
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(770, 120);
    glVertex2i(790, 120);
    glVertex2i(790, 130);
    glVertex2i(770, 130);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(770, 140);
    glVertex2i(790, 140);
    glVertex2i(790, 150);
    glVertex2i(770, 150);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(770, 160);
    glVertex2i(790, 160);
    glVertex2i(790, 170);
    glVertex2i(770, 170);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(770, 180);
    glVertex2i(790, 180);
    glVertex2i(790, 190);
    glVertex2i(770, 190);
    glEnd();
    // --------------
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(800, 120);
    glVertex2i(820, 120);
    glVertex2i(820, 130);
    glVertex2i(800, 130);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(800, 140);
    glVertex2i(820, 140);
    glVertex2i(820, 150);
    glVertex2i(800, 150);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(800, 160);
    glVertex2i(820, 160);
    glVertex2i(820, 170);
    glVertex2i(800, 170);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(800, 180);
    glVertex2i(820, 180);
    glVertex2i(820, 190);
    glVertex2i(800, 190);
    glEnd();
     drawSmallSycamoreTree();
    drawSmallTree(980, 100); 
    drawSmallTree(920, 100); 
    drawSmallTree(360, 100); 
    drawSmallTree(300, 100);
	drawSmallTree(240, 100);
	drawSmallTree(180, 100);  
	drawSmallTree(120, 100);
	drawSmallTree(60, 100);
    drawText(655.0f, 205.0f, "BAGA NAGAN DHUFTAN");
    // signbord
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(570, 290);
    glVertex2i(680, 290);
    glVertex2i(680, 320);
    glVertex2i(570, 320);
    glEnd();
    // line
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(580, 290);
    glVertex2f(580, 270);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(670, 260);
    glVertex2f(670, 290);
    glEnd();
    // ------------
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(600, 100);
    glVertex2i(650, 100);
    glVertex2i(650, 110);
    glVertex2i(600, 110);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(0), rgb(0));
    glVertex2i(610, 110);
    glVertex2i(620, 110);
    glColor3f(rgb(255), rgb(0), rgb(0));
    glVertex2i(600, 240);
    glVertex2i(580, 240);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(0), rgb(0));
    glVertex2i(630, 110);
    glVertex2i(640, 110);
    glColor3f(rgb(255), rgb(0), rgb(0));
    glVertex2i(640, 230);
    glVertex2i(620, 230);
    glEnd();
    drawText(575.0f, 305.0f, "Ethiopian Airline");
    
    // ==============mini signbord
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(510, 120);
    glVertex2i(550, 120);
    glVertex2i(550, 140);
    glVertex2i(510, 140);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(520, 100);
    glVertex2f(520, 120);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(540, 100);
    glVertex2f(540, 120);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(rgb(238), rgb(154), rgb(32));
    glVertex2i(560, 140);
    glVertex2i(570, 140);
    glVertex2i(570, 170);
    glVertex2i(560, 170);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(570, 100);
    glVertex2f(570, 170);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(rgb(238), rgb(154), rgb(32));
    glVertex2i(860, 110);
    glVertex2i(870, 110);
    glVertex2i(870, 130);
    glVertex2i(860, 130);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(860, 130);
    glVertex2f(860, 100);
    glEnd();
    drawText2(510.0f, 130.0f, "Adama port");
    
    
    
    // ======================================
    // || mini Plane ||
    // ======================================
    // tail
    glBegin(GL_POLYGON);
    glColor3f(rgb(0), rgb(255), rgb(0));
    glVertex2i(mp + 70, 440);
    glVertex2i(mp + 100, 440);
    glVertex2i(mp + 100, 460);
    glVertex2i(mp + 90, 450);
    glVertex2i(mp + 80, 450);
    glVertex2i(mp + 80, 450);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(0));
    glVertex2i(mp + 70, 436);
    glVertex2i(mp + 100, 436);
    glVertex2i(mp + 100, 456);
    glVertex2i(mp + 90, 446);
    glVertex2i(mp + 80, 446);
    glVertex2i(mp + 80, 446);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(0), rgb(0));
    glVertex2i(mp + 70, 432);
    glVertex2i(mp + 100, 432);
    glVertex2i(mp + 100, 452);
    glVertex2i(mp + 90, 442);
    glVertex2i(mp + 80, 442);
    glVertex2i(mp + 80, 442);
    glEnd();
    // body
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(mp, 420);
    glVertex2i(mp + 80, 420);
    glVertex2i(mp + 100, 440);
    glVertex2i(mp + 30, 440);
    glVertex2i(mp + 30, 430);
    glVertex2i(mp + 10, 430);
    glEnd();
    // cokepit
    glBegin(GL_POLYGON);
    glColor3f(rgb(200), rgb(200), rgb(200));
    glVertex2i(mp + 20, 430);
    glVertex2i(mp + 30, 430);
    glVertex2i(mp + 30, 440);
    glEnd();
    // backline
    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3f(rgb(0), rgb(0), rgb(0));
    glVertex2f(mp + 80, 440);
    glVertex2f(mp + 110, 440);
    glEnd();
    // fan
    glBegin(GL_POLYGON);
    glColor3f(rgb(200), rgb(200), rgb(200));
    glVertex2i(mp + 40, 410);
    glVertex2i(mp + 60, 410);
    glVertex2i(mp + 70, 420);
    glVertex2i(mp + 60, 430);
    glVertex2i(mp + 40, 430);
    glEnd();






    // =====================================
    // drawing tower
    // =====================================
    
    glBegin(GL_POLYGON);
    glColor3f(rgb(0), rgb(0), rgb(0));
    glVertex2i(450, 100);
    glVertex2i(480, 100);
    glVertex2i(480, 240);
    glVertex2i(450, 240);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(0), rgb(0));
    glVertex2i(440, 240);
    glVertex2i(490, 240);
    glVertex2i(490, 250);
    glVertex2i(440, 250);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(450, 250);
    glVertex2i(480, 250);
    glVertex2i(500, 290);
    glVertex2i(430, 290);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(0), rgb(0), rgb(0));
    glVertex2i(430, 290);
    glVertex2i(500, 290);
    glVertex2i(500, 310);
    glVertex2i(430, 310);
    glEnd();
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(rgb(255), rgb(0), rgb(0));
    glVertex2f(440, 300);
    glVertex2f(490, 300);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(430, 310);
    glVertex2i(500, 310);
    glVertex2i(480, 320);
    glVertex2i(450, 320);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(0), rgb(0));
    glVertex2i(450, 320);
    glVertex2i(480, 320);
    glVertex2i(480, 330);
    glVertex2i(450, 330);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(0), rgb(0), rgb(0));
    glVertex2f(460, 380);
    glVertex2f(460, 410);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(255), rgb(0), rgb(0));
    glVertex2f(470, 380);
    glVertex2f(470, 430);
    glEnd();
    // circle
    glColor3f(rgb(255), rgb(255), rgb(255));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(465, 360); 
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 20 * cosf(angle); 
        float y = 20 * sinf(angle); 
        glVertex2f(x + 465, y + 360); 
    }
    glEnd();
    // mini circle
    glColor3f(rgb(255), rgb(255), rgb(255));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(470, 430); 
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 5 * cosf(angle); 
        float y = 5 * sinf(angle);  
        glVertex2f(x + 470, y + 430); 
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(0), rgb(0), rgb(0));
    glVertex2i(450, 330);
    glVertex2i(480, 330);
    glVertex2i(490, 350);
    glVertex2i(440, 350);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(0), rgb(0));
    glVertex2i(440, 350);
    glVertex2i(490, 350);
    glVertex2i(490, 360);
    glVertex2i(440, 360);
    glEnd();

    // ================================
    // drawing runway
    // ================================
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(0, 50);
    glVertex2f(50, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(100, 50);
    glVertex2f(150, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(200, 50);
    glVertex2f(250, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(300, 50);
    glVertex2f(350, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(400, 50);
    glVertex2f(450, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(500, 50);
    glVertex2f(550, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(600, 50);
    glVertex2f(650, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(700, 50);
    glVertex2f(750, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(800, 50);
    glVertex2f(850, 50);
    glEnd();
    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(900, 50);
    glVertex2f(950, 50);
    glEnd();

    // ================================
    // drawing runway light
    // ================================
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(236), rgb(255));
    glVertex2i(70, 100);
    glVertex2i(90, 100);
    glVertex2i(90, 110);
    glVertex2i(70, 110);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(236), rgb(255));
    glVertex2i(170, 100);
    glVertex2i(190, 100);
    glVertex2i(190, 110);
    glVertex2i(170, 110);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(236), rgb(255));
    glVertex2i(270, 100);
    glVertex2i(290, 100);
    glVertex2i(290, 110);
    glVertex2i(270, 110);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(236), rgb(255));
    glVertex2i(370, 100);
    glVertex2i(390, 100);
    glVertex2i(390, 110);
    glVertex2i(370, 110);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(236), rgb(255));
    glVertex2i(890, 100);
    glVertex2i(910, 100);
    glVertex2i(910, 110);
    glVertex2i(890, 110);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(236), rgb(255));
    glVertex2i(950, 100);
    glVertex2i(970, 100);
    glVertex2i(970, 110);
    glVertex2i(950, 110);
    glEnd();
    // cargo car-----------------------------
    // ====================================
    // driver
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(0), rgb(0));
    glVertex2i(v, 110);
    glVertex2i(v + 20, 110);
    glVertex2i(v + 20, 130);
    glEnd();
    // carback
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(0), rgb(0));
    glVertex2i(v + 20, 110);
    glVertex2i(v + 40, 110);
    glVertex2i(v + 40, 120);
    glVertex2i(v + 20, 120);
    glEnd();
    // driver seat up
    glBegin(GL_POLYGON);
    glColor3f(rgb(213), rgb(158), rgb(61));
    glVertex2i(v, 130);
    glVertex2i(v + 20, 130);
    glVertex2i(v + 20, 140);
    glVertex2i(v, 140);
    glEnd();
    // car stear
    glBegin(GL_POLYGON);
    glColor3f(rgb(213), rgb(158), rgb(61));
    glVertex2i(v + 50, 110);
    glVertex2i(v + 60, 110);
    glVertex2i(v + 60, 120);
    glVertex2i(v + 50, 120);
    glVertex2i(v + 20, 140);
    glVertex2i(v + 20, 130);
    glEnd();
    // car wheel 1
    glColor3f(rgb(92), rgb(141), rgb(148));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(v + 10, 100); 
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 5 * cosf(angle);
        float y = 5 * sinf(angle);  
        glVertex2f(x + v + 10, y + 100); 
    }
    glEnd();
    // car wheel 2
    glColor3f(rgb(92), rgb(141), rgb(148));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(v + 40, 100); 
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 5 * cosf(angle); 
        float y = 5 * sinf(angle);  
        glVertex2f(x + v + 40, y + 100); 
    }
    glEnd();

    //drawVehicle(vehicle1_x, 100); 
    drawVehicle(vehicle2_x, 100); 
    drawVehicle(vehicle3_x, 100); 

    // =========================================
    // || drawing airplane                    ||
    // =========================================

        // tail
    glBegin(GL_POLYGON);
    glColor3f(rgb(0), rgb(255), rgb(0));
    glVertex2i(r + 25, f + 50);
    glVertex2i(r + 40, f + 50);
    glVertex2i(r + 40, f + 60);
    glVertex2i(r + 20, f + 80);
    glVertex2i(r + 00, f + 80);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(0));
    glVertex2i(r + 20, f + 450);
    glVertex2i(r + 40, f + 450);
    glVertex2i(r + 40, f + 550);
    glVertex2i(r + 20, f + 750);
    glVertex2i(r + 00, f + 750);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(0), rgb(0));
    glVertex2i(r + 20, f + 40);
    glVertex2i(r + 40, f + 40);
    glVertex2i(r + 40, f + 50);
    glVertex2i(r + 20, f + 70);
    glVertex2i(r + 00, f + 70);
    glEnd();
    // body
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(r + 20, f + 30);
    glVertex2i(r + 210, f + 30);
    glVertex2i(r + 210, f + 40);
    glVertex2i(r + 200, f + 50);
    glVertex2i(r + 160, f + 50);
    glVertex2i(r + 160, f + 60);
    glVertex2i(r + 30, f + 60);
    glVertex2i(r, f + 50);
    glVertex2i(r, f + 40);
    glEnd();
    // cockepit
    glBegin(GL_POLYGON);
    glColor3f(rgb(200), rgb(200), rgb(200));
    glVertex2i(r + 160, f + 50);
    glVertex2i(r + 180, f + 50);
    glVertex2i(r + 170, f + 60);
    glVertex2i(r + 160, f + 60);
    glEnd();
    // window
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.7, 0.7, 0.7);
    glVertex2f(r + 40, f + 50);
    glVertex2f(r + 50, f + 50);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.7, 0.7, 0.7);
    glVertex2f(r + 60, f + 50);
    glVertex2f(r + 70, f + 50);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.7, 0.7, 0.7);
    glVertex2f(r + 80, f + 50);
    glVertex2f(r + 90, f + 50);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.7, 0.7, 0.7);
    glVertex2f(r + 100, f + 50);
    glVertex2f(r + 110, f + 50);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.7, 0.7, 0.7);
    glVertex2f(r + 120, f + 50);
    glVertex2f(r + 130, f + 50);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.7, 0.7, 0.7);
    glVertex2f(r + 140, f + 50);
    glVertex2f(r + 150, f + 50);
    glEnd();
    // wing
    glBegin(GL_POLYGON);
    glColor3f(rgb(200), rgb(200), rgb(200));
    glVertex2i(r + 30, f + 20);
    glVertex2i(r + 120, f + 20);
    glVertex2i(r + 140, f + 40);
    glVertex2i(r + 40, f + 40);
    glVertex2i(r, f + 30);
    glEnd();
    // fan
    glBegin(GL_POLYGON);
    glColor3f(rgb(180), rgb(180), rgb(180));
    glVertex2i(r + 50, f + 10);
    glVertex2i(r + 70, f + 10);
    glVertex2i(r + 70, f + 30);
    glVertex2i(r + 50, f + 30);
    glVertex2i(r + 40, f + 20);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(180), rgb(180), rgb(180));
    glVertex2i(r + 90, f + 10);
    glVertex2i(r + 110, f + 10);
    glVertex2i(r + 110, f + 30);
    glVertex2i(r + 90, f + 30);
    glVertex2i(r + 80, f + 20);
    glEnd();
    // wheel 1
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(r + 40, f + 20);
    glVertex2f(r + 40, f);
    glEnd();
    // mini circle
    glColor3f(rgb(236), rgb(154), rgb(32));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(r + 40, f); // circle er center position
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 5 * cosf(angle); 
        float y = 5 * sinf(angle);  
        glVertex2f(x + r + 40, y + f); 
    }
    glEnd();
    // wheel 2
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(r + 140, f + 30);
    glVertex2f(r + 140, f);
    glEnd();
    // mini circle
    glColor3f(rgb(236), rgb(154), rgb(32));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(r + 140, f); 
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 5 * cosf(angle); 
        float y = 5 * sinf(angle);  
        glVertex2f(x + r + 140, y + f); 
    }
    glEnd();
    // wheel 3
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(180 + r, f + 30);
    glVertex2f(180 + r, f);
    glEnd();
    // mini circle
    glColor3f(rgb(236), rgb(154), rgb(32));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(180 + r, f); 
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 5 * cosf(angle); 
        float y = 5 * sinf(angle);  
        glVertex2f(x + r + 180, y + f); 
    }
    glEnd();
    
    // =========================================
    // || drawing airplane 2                    ||
    // =========================================
    
         // tail
    glBegin(GL_POLYGON);
    glColor3f(rgb(0), rgb(255), rgb(0));
    glVertex2i(380, 50);
    glVertex2i(400, 50);
    glVertex2i(400, 60);
    glVertex2i(380, 80);
    glVertex2i(360, 80);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(0));
    glVertex2i(380, 45);
    glVertex2i(400, 45);
    glVertex2i(400, 55);
    glVertex2i(380, 75);
    glVertex2i(360, 75);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(0), rgb(0));
    glVertex2i(380, 40);
    glVertex2i(400, 40);
    glVertex2i(400, 50);
    glVertex2i(380, 70);
    glVertex2i(360, 70);
    glEnd();
    // body
    glBegin(GL_POLYGON);
    glColor3f(rgb(255), rgb(255), rgb(255));
    glVertex2i(380, 30);
    glVertex2i(570, 30);
    glVertex2i(570, 40);
    glVertex2i(560, 50);
    glVertex2i(520, 50);
    glVertex2i(520, 60);
    glVertex2i(390, 60);
    glVertex2i(360, 50);
    glVertex2i(360, 40);
    glEnd();
    // cockepit
    glBegin(GL_POLYGON);
    glColor3f(rgb(200), rgb(200), rgb(200));
    glVertex2i(520, 50);
    glVertex2i(540, 50);
    glVertex2i(530, 60);
    glVertex2i(520, 60);
    glEnd();
    // window
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.7, 0.7, 0.7);
    glVertex2f(400, 50);
    glVertex2f(410, 50);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.7, 0.7, 0.7);
    glVertex2f(420, 50);
    glVertex2f(430, 50);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.7, 0.7, 0.7);
    glVertex2f(440, 50);
    glVertex2f(450, 50);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.7, 0.7, 0.7);
    glVertex2f(460, 50);
    glVertex2f(470, 50);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.7, 0.7, 0.7);
    glVertex2f(480, 50);
    glVertex2f(490, 50);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.7, 0.7, 0.7);
    glVertex2f(500, 50);
    glVertex2f(510, 50);
    glEnd();
    // wing
    glBegin(GL_POLYGON);
    glColor3f(rgb(200), rgb(200), rgb(200));
    glVertex2i(390, 20);
    glVertex2i(480, 20);
    glVertex2i(500, 40);
    glVertex2i(400, 40);
    glVertex2i(360, 30);
    glEnd();
    // fan
    glBegin(GL_POLYGON);
    glColor3f(rgb(180), rgb(180), rgb(180));
    glVertex2i(410, 10);
    glVertex2i(420, 10);
    glVertex2i(430, 30);
    glVertex2i(440, 30);
    glVertex2i(400, 20);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(rgb(180), rgb(180), rgb(180));
    glVertex2i(450, 10);
    glVertex2i(470, 10);
    glVertex2i(470, 30);
    glVertex2i(450, 30);
    glVertex2i(440, 20);
    glEnd();
    // wheel 1
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(400, 20);
    glVertex2f(400, 0);
    glEnd();
    // mini circle
    glColor3f(rgb(236), rgb(154), rgb(32));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(r + 40, f); // circle er center position
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 5 * cosf(angle); 
        float y = 5 * sinf(angle);  
        glVertex2f(400, 0); 
    }
    glEnd();
    // wheel 2
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(500, 30);
    glVertex2f(500, 0);
    glEnd();
    // mini circle
    glColor3f(rgb(236), rgb(154), rgb(32));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(140, 0); // circle er center position
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 5 * cosf(angle); 
        float y = 5 * sinf(angle);  
        glVertex2f(500, 0); 
    }
    glEnd();
    // wheel 3
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(rgb(43), rgb(43), rgb(48));
    glVertex2f(540 , 30);
    glVertex2f(540 ,0);
    glEnd();
    // mini circle
    glColor3f(rgb(236), rgb(154), rgb(32));
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(180, f); 
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float x = 5 * cosf(angle); 
        float y = 5 * sinf(angle);  
        glVertex2f(540, 0); 
    }
    glEnd();
    
    drawFlagPole();
    drawStairBase();
    drawEthiopianFlag();
    drawCircle(287.5f, 205.0f, 25.0f, 0.0f, 0.0f, 1.0f);  
    drawStar();
    drawOromiaFlag(); 
    drawSmallSycamoreTree();
    glutSwapBuffers();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1400, 680);
    glutCreateWindow("Computer Graphics Project");
    init();
    glutDisplayFunc(Draw);
    glutIdleFunc(Draw);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
