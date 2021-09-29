//Defines
//#define GLM_ENABLE_EXPERIMENTAL

//Bibliotecas
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cassert>
#include <array>
#include <glm/glm.hpp>
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

	//Definir um triangulo em cooerdenadas normalizadas
	std::array<glm::vec3, 3> Triangle = {
		glm::vec3{ -1.0f, -1.0f, 0.0f },
		glm::vec3{  1.0f, -1.0f, 0.0f },
		glm::vec3{  0.0f,  1.0f, 0.0f },
	};

	//Agora, vamos copiar os vertices do triangulo para a memoria da GPU
	GLuint  VertexBuffer; /* Inteiro binário sem sinal */

	//Pedir para o OpenGL gerar o indentificador do VertexBuffer
	/* void glGenBuffers(GLsizei  	n, GLuint *  	buffers); -> gera nomes de objetos de buffer */
	//	- Parametros
	//		- n:       Especifica o número de nomes de objetos de buffer a serem gerados.
	//		- buffers: Especifica uma matriz na qual os nomes de objetos de buffer gerados são armazenados.
	glGenBuffers(1, &VertexBuffer);

	//Ativar o VertexBuffer como sendo o buffer para onde vamos copiar os dados do triangulo
	/* Especifica o destino ao qual o objeto buffer está vinculado. A constante simbólica deve ser GL_ARRAY_BUFFER ou GL_ELEMENT_ARRAY_BUFFER. */
	glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);
	
	//Copiar os dados para a memoria de video
	/* cria e inicializa o armazenamento de dados de um objeto buffer */
	/* 
	   void glBufferData(	GLenum			alvo,
	   						GLsizeiptr		tamanho,
	   						const GLvoid 	*dados,
	   						GLenum			uso) ;
	*/
	glBufferData(GL_ARRAY_BUFFER, sizeof(Triangle), Triangle.data(), GL_STATIC_DRAW);

	//Definir a cor de fundo
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

	//Loop de eventos
	while(!glfwWindowShouldClose(Window)){
		// glClear vai limpar o flamebuffer. GL_COLOR_BUFFER_BIT diz para limpar o buffer de cor. Depois de limpar, ele vai preencher com a cor setada no glClearColor
		// Quado formos desenhar geometrias 3D, vamos voltar ao glClear por que temos que limpar o buffer de profundidade (depth buffer).
		glClear(GL_COLOR_BUFFER_BIT);

		glEnableVertexAttribArray(0);

		//Diz para o openGL que o VertexBuffer vai ser o buffer ativo no momento
		glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);

		//Informa ao openGL onde, dentro do VertexBuffer, os vertices então no caso o array Triangle e contiguuo em memoria, logo basta dizer quantos vertices vamos usar para desenhar o triangulo
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

		//Diz para o openGl desenhar o triangulo com os dados armazenados no VertexBuffer
		glDrawArrays(GL_TRIANGLES, 0, 3);

		//Reverte o estado criado
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDisableVertexAttribArray(0);

		//Processa todos os eventos na fila de eventos do GLFW
		//Esses eventos podem ser eventos do teclado, mouse ou gamepad
		glfwPollEvents();

		//Envia o conteúdo do flamebuffer da janela para ser desenhado na tela
		glfwSwapBuffers(Window);
	}

	//Desalocar o VertexBuffer
	glDeleteBuffers(1, &VertexBuffer);

	//Encerra a biblioteca GLFW
	glfwTerminate();

	return 0;
}
