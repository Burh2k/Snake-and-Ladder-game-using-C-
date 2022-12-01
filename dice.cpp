// This code example is created for educational purpose
// by Thorsten Thormaehlen (contact: www.thormae.de).
// It is distributed without any warranty.

#include <GL/freeglut.h> // we use glut here as window manager

#define _USE_MATH_DEFINES
#include <math.h>

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

class Renderer {

public:
  float t;
private:
  GLuint texID;

public:
  // constructor
  Renderer() : t(0.0), texID(0) {}

  // destructor
  ~Renderer() {
    if(texID !=0) glDeleteTextures( 1, &texID);
  }

public:
  void init() {
    glEnable(GL_DEPTH_TEST);
    std::string fileName("dice_texture.ppm");
    texID = loadTexture(fileName);
  }

  void resize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (30.0, (float)w/(float)h, 0.1, 50.0);
  }

  void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // set camera
    gluLookAt(8.0, -2.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    // draw scene
    glRotatef(t, 0.0f, 0.0f, 1.0f);
    drawTexturedCube();
  }

private:
  // returns a valid textureID on success, otherwise 0
  GLuint loadTexture(std::string &filename) {

    unsigned width;
    unsigned height;
    int level = 0;
    int border = 0;
    std::vector<unsigned char> imgData;

    // load image data
    if(!loadPPMImageFlipped(filename, width, height, imgData)) return 0;

    // data is aligned in byte order
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    //request textureID
    GLuint textureID;
    glGenTextures( 1, &textureID);

    // bind texture
    glBindTexture( GL_TEXTURE_2D, textureID);

    //define how to filter the texture (important but ignore for now)
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    //texture colors should replace the original color values
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); //GL_MODULATE

    // specify the 2D texture map
    glTexImage2D(GL_TEXTURE_2D, level, GL_RGB, width, height, border, GL_RGB, GL_UNSIGNED_BYTE, &imgData[0]);

    // return unique texture identifier
    return textureID;
  }

  void drawTexturedCube() {
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texID);
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_POLYGON); // three
    glTexCoord2f(0.25f,0.50f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.25f,0.25f); glVertex3f(-1.0f,-1.0f, 1.0f);
    glTexCoord2f(0.50f,0.25f); glVertex3f( 1.0f,-1.0f, 1.0f);
    glTexCoord2f(0.50f,0.50f); glVertex3f( 1.0f, 1.0f, 1.0f);
    glEnd();
    glColor3f(1.0f,1.0f,0.0f);
    glBegin(GL_POLYGON); // five
    glTexCoord2f(0.00f,0.50f); glVertex3f(-1.0f, 1.0f,-1.0f);
    glTexCoord2f(0.00f,0.25f); glVertex3f(-1.0f,-1.0f,-1.0f);
    glTexCoord2f(0.25f,0.25f); glVertex3f(-1.0f,-1.0f, 1.0f);
    glTexCoord2f(0.25f,0.50f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glEnd();
    glColor3f(0.0f,0.0f,1.0f);
    glBegin(GL_POLYGON); // two
    glTexCoord2f(0.50f,0.50f); glVertex3f( 1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.50f,0.25f); glVertex3f( 1.0f,-1.0f, 1.0f);
    glTexCoord2f(0.75f,0.25f); glVertex3f( 1.0f,-1.0f,-1.0f);
    glTexCoord2f(0.75f,0.50f); glVertex3f( 1.0f, 1.0f,-1.0f);
    glEnd();
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_POLYGON); // six
    glTexCoord2f(0.25f,0.75f); glVertex3f(-1.0f, 1.0f,-1.0f);
    glTexCoord2f(0.25f,0.50f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.50f,0.50f); glVertex3f( 1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.50f,0.75f); glVertex3f( 1.0f, 1.0f,-1.0f);
    glEnd();
    glColor3f(0.0f,1.0f,1.0f);
    glBegin(GL_POLYGON); // one
    glTexCoord2f(0.25f,0.25f); glVertex3f(-1.0f, -1.0f, 1.0f);
    glTexCoord2f(0.25f,0.00f); glVertex3f(-1.0f, -1.0f,-1.0f);
    glTexCoord2f(0.50f,0.00f); glVertex3f( 1.0f, -1.0f,-1.0f);
    glTexCoord2f(0.50f,0.25f); glVertex3f( 1.0f, -1.0f, 1.0f);
    glEnd();
    glColor3f(0.0f,1.0f,0.0f);
    glBegin(GL_POLYGON); //four
    glTexCoord2f(0.75f,0.50f); glVertex3f( 1.0f, 1.0f,-1.0f);
    glTexCoord2f(0.75f,0.25f); glVertex3f( 1.0f,-1.0f,-1.0f);
    glTexCoord2f(1.00f,0.25f); glVertex3f(-1.0f,-1.0f,-1.0f);
    glTexCoord2f(1.00f,0.50f); glVertex3f(-1.0f, 1.0f,-1.0f);
    glEnd();
    glDisable(GL_TEXTURE_2D);
  }

  bool loadPPMImageFlipped(std::string &filename, unsigned &width, unsigned &height, std::vector<unsigned char> &imgData) {

    ifstream input(filename.c_str(), ifstream::in | ifstream::binary);
    if(!input) { // cast istream to bool to see if something went wrong
      cerr << "Can not find texture data file " << filename.c_str() << endl;
      return false;
    } 
    input.unsetf(std::ios_base::skipws);

    string line;
    input >> line >> std::ws;
    if (line != "P6") {
      cerr << "File is not PPM P6 raw format" << endl;
      return false;
    }

    width = 0;
    height = 0;
    unsigned depth = 0;
    unsigned readItems = 0;
    unsigned char lastCharBeforeBinary;

    while (readItems < 3) {
      input >> std::ws;
      if(input.peek() != '#') {
        if (readItems == 0) input >> width;
        if (readItems == 1) input >> height;
        if (readItems == 2) input >> depth >> lastCharBeforeBinary;
        readItems++;
      }else{ // skip comments
        std::getline(input, line);
      }
    }

    if(depth >= 256) {
	    cerr << "Only 8-bit PPM format is supported" << endl;
      return false;
    }

    unsigned byteCount = width * height * 3;
    imgData.resize(byteCount);
    input.read((char*)&imgData[0], byteCount*sizeof(unsigned char));

    // vertically flip the image because the image origin
    // in OpenGL is the lower-left corner
    unsigned char tmpData;
    for(unsigned y=0; y < height / 2; y++) {
      int sourceIndex = y * width * 3;
      int targetIndex = (height-1-y) * width *3;
      for(unsigned x=0; x < width*3; x++) {
          tmpData = imgData[targetIndex];
          imgData[targetIndex] = imgData[sourceIndex];
          imgData[sourceIndex] = tmpData;
          sourceIndex++;
          targetIndex++;
      }
    }

    return true;
  }
};

//this is a static pointer to a Renderer used in the glut callback functions
static Renderer *renderer;

//glut static callbacks start
static void glutResize(int w, int h) 
{
  renderer->resize(w,h);
}

static void glutDisplay() 
{
  renderer->display();
  glutSwapBuffers();
  glutReportErrors();
}

static void timer(int v) 
{
  float offset = 1.0f;
  renderer->t += offset;
  glutDisplay();
  glutTimerFunc(unsigned(20), timer, ++v);
}


int main(int argc, char **argv) 
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(320, 320);

  glutCreateWindow("Texture Demo");

  glutDisplayFunc(glutDisplay);
  //glutIdleFunc(glutDisplay);
  glutReshapeFunc(glutResize);

  renderer = new Renderer;
  renderer->init();

  glutTimerFunc(unsigned(20), timer, 0);

  glutMainLoop();
}
