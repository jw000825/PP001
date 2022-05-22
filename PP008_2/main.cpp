#include <GLFW/glfw3.h> // 그래픽 라이브러리 프레임워크
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>

#pragma comment(lib, "OpenGL32")

static void error_callback(int error, const char* description) {
	fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

int main(void) {
	GLFWwindow* window;
	float bpX01 = 0.5f;			//box point X 01
	float bpX02 = 0.0f;			//box point X 02
	float bpY01 = -0.5f;		//box point Y 01
	float bpY02 = 0.0f;			//box point Y 02

	float mbpX01 = 0.8f;		//move box point X 01
	float mbpX02 = 0.6f;		//move box point X 02
	float mbpY01 = 0.15f;		//move box point Y 01
	float mbpY02 = 0.0f;		//move box point Y 02

	glfwSetErrorCallback(error_callback);

	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);

	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);		//Context를 장악, GPU 정리, Context = 클래스 묶음, s(스레드) = 동시에 여러개를 돌린다
	glfwSetKeyCallback(window, key_callback);

	float ratio;
	int width, height;

	glfwGetFramebufferSize(window, &width, &height);	//FrameBuffer = 화면에 담겨질 메모리 공간

	ratio = width / (float)height;

	while (!glfwWindowShouldClose(window)) {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);		//화면은 한가지 색으로 체운다(Clear)
		glClear(GL_COLOR_BUFFER_BIT);

		// LEFT
		if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8001) {
			mbpX01 -= 0.02;
			mbpX01 -= 0.02;
		}
		// RIGHT
		if (GetAsyncKeyState(VK_RIGHT & 0x8000) || GetAsyncKeyState(VK_RIGHT) & 0x8001) {
			mbpX01 += 0.02;
			mbpX02 += 0.02;
		}
		// UP
		if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8001) {
			mbpY01 += 0.02;
			mbpY02 += 0.02;
		}
		// DOWN
		if (GetAsyncKeyState(VK_DOWN) & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8001) {
			mbpY01 -= 0.02;
			mbpY02 -= 0.02;
		}

		glPointSize(10);
		glBegin(GL_TRIANGLES);

		glColor4f(1.0f, 1.0f, 0.0f, 1.0f);		//RGB + Alpha
		glVertex2f(bpX01, bpY01);
		glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
		glVertex2f(bpX01, bpY02);
		glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
		glVertex2f(bpX02, bpY02);
		glEnd();


		glPointSize(10);
		glBegin(GL_TRIANGLES);

		glColor4f(1.0f, 1.0f, 0.0f, 1.0f);		
		glVertex2f(bpX01, bpY01);
		glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
		glVertex2f(bpX02, bpY01);
		glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
		glVertex2f(bpX02, bpY02);
		glEnd();
		

		glPointSize(5);
		glBegin(GL_TRIANGLES);
		
		glColor4f(1.0f, 0.0f, 1.0f, 1.0f);		
		glVertex2f(mbpX02, mbpY02);
		glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
		glVertex2f(mbpX01, mbpY02);
		glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
		glVertex2f(mbpX01, mbpY01);
		glEnd();

		
		glPointSize(5);
		glBegin(GL_TRIANGLES);

		glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
		glVertex2f(mbpX02, mbpY01);
		glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
		glVertex2f(mbpX01, mbpY01);
		glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
		glVertex2f(mbpX02, mbpY02);
		glEnd();


		glfwSwapBuffers(window); 
		glfwPollEvents();

		if (mbpX02 < bpX02 && mbpX02 > bpX01 && mbpY02 > bpY02 && mbpY02 < bpY01) {
			std::cout << "touch!";
		}
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}













