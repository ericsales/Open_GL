//Defines
//#define GLM_ENABLE_EXPERIMENTAL

//Bibliotecas
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cassert>
//#include <gl/GL.h> Funções do openGL 1.1 

//constantes
const int Width = 800;
const int Height = 600;

int main(){
	
	//Inicializando a biblioteca GLFW
	assert(glfwInit() == GLFW_TRUE);

	//Criando Janela
	GLFWwindow *Window = glfwCreateWindow(Width, Height, "Blue Marble", nullptr, nullptr);
	assert(Window);

	//Ativa o contexto criado na janela Window
	glfwMakeContextCurrent(Window);
	
	//Iniciando a biblioteca GLEW
	assert(glewInit() == GLEW_OK);

	//Verificar a versão do openGL
	GLint GLmajorVersion = 0;
	GLint GLminorVersion = 0;
	glGetIntegerv(GL_MAJOR_VERSION, &GLmajorVersion);
	glGetIntegerv(GL_MINOR_VERSION, &GLminorVersion);
	std::cout << "OpenGL version	: " << GLmajorVersion << "." << GLminorVersion << std::endl;
	
	//Usar o glGetString() para obter informaçoes do driver que estamos usando
	std::cout << "OpenGL Vendor	: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "OpenGL renderer	: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "OpenGL version	: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL   version	: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

	//Definir a cor de fundo
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

	//Loop de eventos
	while(!glfwWindowShouldClose(Window)){
		// glClear vai limpar o flamebuffer. GL_COLOR_BUFFER_BIT diz para limpar o buffer de cor. Depois de limpar, ele vai preencher com a cor setada no glClearColor
		// Quado formos desenhar geometrias 3D, vamos voltar ao glClear por que temos que limpar o buffer de profundidade (depth buffer).
		glClear(GL_COLOR_BUFFER_BIT);

		//Processa todos os eventos na fila de eventos do GLFW
		//Esses eventos podem ser eventos do teclado, mouse ou gamepad
		glfwPollEvents();

		//Envia o conteúdo do flamebuffer da janela para ser desenhado na tela
		glfwSwapBuffers(Window);
	}

	//Encerra a biblioteca GLFW
	glfwTerminate();

	return 0;
}
