#include <GLFW/glfw3.h>

class Player {
	void IsKeyPressed()
	{
		glPointSize(10);
		glBegin(GL_POINTS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-0.7f, 0.3f);
	}
	void IsKeyUnpressed() {
		glPointSize(10);
		glBegin(GL_POINTS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-0.7f, 0.0f);
	}
};