#include <iostream>

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

void constructors();
void components();
void operation();

int main(){
	constructors();
	components();
	operation();
	
	return 0;
}

void operation(){
	std::cout << std::endl;
	std::cout << "*** OPERATIONS ***" << std::endl;
	
	glm::vec3 P0{ 10.0f, 10.0f, 0.0f };
	glm::vec3 P1{ 10.0f, 10.0f, 10.0f };
	std::cout << "Point_P0: " << glm::to_string(P0) << std::endl;
	std::cout << "Point_P1: " << glm::to_string(P1) << std::endl;
	glm::vec3 R;
	
	//Soma
	R = P0 + P1;
	std::cout << std::endl;
	std::cout << "*** SOMA ***" << std::endl;
	std::cout << "P0 + P1: " << glm::to_string(R) << std::endl;

	//Subtração
	R = P0 - P1;
	std::cout << std::endl;
	std::cout << "*** SUBTRAÇÃO ***" << std::endl;
	std::cout << "P0 - P1: " << glm::to_string(R) << std::endl;
	
	//Multiplicação
	R = P0 * P1;
	std::cout << std::endl;
	std::cout << "*** MULTIPLICAÇÃO ***" << std::endl;
	std::cout << "P0 * P1: " << glm::to_string(R) << std::endl;

	//Divição
	R = P0 / P1;
	std::cout << std::endl;
	std::cout << "*** DIVIÇÃO ***" << std::endl;
	std::cout << "P0 / P1: " << glm::to_string(R) << std::endl;
	
	//Scale
	R = P0 * 5.0f;
	std::cout << std::endl;
	std::cout << "*** SCALE ***" << std::endl;
	std::cout << "P0 * 10: " << glm::to_string(R) << std::endl;

	//Tamanho de um vetor
	float L = glm::length(P0);
	std::cout << std::endl;
	std::cout << "*** TAMANHO DE UM VETOR ***" << std::endl;
	std::cout << "P0: " << L << std::endl;

	//Normalizar um vetor
	glm::vec3 norm = glm::normalize(P0);
	L = glm::length(norm);
	std::cout << std::endl;
	std::cout << "*** NORMALIZAR UM VETOR ***" << std::endl;
	std::cout << "P0: " << glm::to_string(norm) << std::endl;
	std::cout << "P0(TAMANHO): " << L << std::endl;

	//Produto Escalar (Dot Product)
	L = glm::dot(P0, P1);
	std::cout << std::endl;
	std::cout << "*** PRODUTO ESCALAR (DOT PRODUCT) ***" << std::endl;
	std::cout << "P0 . P1: " << L << std::endl;

	//Produto Vetorial (Cross Product)
	glm::vec3 cross = glm::cross(P0, P1);
	std::cout << std::endl;
	std::cout << "*** PRODUTO VETORIAL ***" << std::endl;
	std::cout << "P0 ^ P1: " << glm::to_string(cross) << std::endl;

	//Distancia entre pontos
	L = glm::distance(P0, P1);
	std::cout << std::endl;
	std::cout << "*** DISTANCIA ENTRE PONTOS ***" << std::endl;
	std::cout << "DISTANCIA(P0, P1): " << L << std::endl;

	//Reflação
	glm::vec3 refract = glm::refract(P0, norm, 1.0f);
	std::cout << std::endl;
	std::cout << "*** REFRAÇÃO ***" << std::endl;
	std::cout << "(P0, NORM, 1): " << glm::to_string(refract) << std::endl;

	//Reflecção
	glm::vec3 reflect = glm::reflect(P0, norm);
	std::cout << std::endl;
	std::cout << "*** REFLECÇÃO ***" << std::endl;
	std::cout << "(P0, NORM): " << glm::to_string(reflect) << std::endl;

}

void components(){
	std::cout << std::endl;
	
	glm::vec3 P{ 10.0f, 0.0f, 0.0f };
	
	std::cout << "*** COMPONENTES ***" << std::endl;
	std::cout << "point: " << glm::to_string(P) << std::endl;
	std::cout << "X: " << P.x << " Y: " << P.y << " Z: " << P.z << std::endl;
	std::cout << "R: " << P.r << " G: " << P.g << " B: " << P.b << std::endl;
	
}

void constructors(){
	std::cout << std::endl;

	glm::vec2 Point0{ 10.0f, 10.0f };
	glm::vec3 Point1{ 10.0f, 0.0f, 0.0f };
	glm::vec4 Point2{ 10.0f, 0.0f, 0.0f, 10.0f };
	
	glm::ivec2 int_Point0{ 10, 1 };
	glm::ivec3 int_Point1{ 10, 0, 0 };
	glm::ivec4 int_Point2{ 10, 0, 0, 1 };
	
	glm::bvec2 bool_Point0{ true, false };
	glm::bvec3 bool_Point1{ true, true, false };
	glm::bvec4 bool_Point2{ true, false, false, false };
	
	glm::vec2 double_Point0{ 10.0, 10.0 };
	glm::vec3 double_Point1{ 10.0, 0.0, 0.0 };
	glm::vec4 double_Point2{ 10.0, 0.0, 0.0, 10.0 };
	
	//Vetor de ponto flutuante
	std::cout << "*** VETOR DE FLOATS ***" << std::endl;
	std::cout << "point0: " << glm::to_string(Point0) << std::endl;
	std::cout << "point1: " << glm::to_string(Point1) << std::endl;
	std::cout << "point2: " << glm::to_string(Point2) << std::endl << std::endl;

	std::cout << "*** VETOR DE INTEIROS ***" << std::endl;
	std::cout << "point: " << glm::to_string(int_Point0) << std::endl;
	std::cout << "point: " << glm::to_string(int_Point1) << std::endl;
	std::cout << "point: " << glm::to_string(int_Point2) << std::endl << std::endl;
	
	std::cout << "*** VETOR DE BOOLEANOS ***" << std::endl;
	std::cout << "point: " << glm::to_string(bool_Point0) << std::endl;
	std::cout << "point: " << glm::to_string(bool_Point1) << std::endl;
	std::cout << "point: " << glm::to_string(bool_Point2) << std::endl << std::endl;
	
	std::cout << "*** VETOR DE DOUBLES ***" << std::endl;
	std::cout << "point: " << glm::to_string(double_Point0) << std::endl;
	std::cout << "point: " << glm::to_string(double_Point1) << std::endl;
	std::cout << "point: " << glm::to_string(double_Point2) << std::endl << std::endl;
}
