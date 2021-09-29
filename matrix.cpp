#include <iostream>
#include <iomanip>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/matrix_transform.hpp>

/*
http://www.c-jump.com/bcc/common/Talk3/Math/GLM/index.html
*/


//Prototipos
void TranslationMatrix();

int main(){
	std::cout << std::endl;
	TranslationMatrix();

	return 0;
}

void PrintMatrix(const glm::mat4& M){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			std::cout 
					<< std::setw(10)
					<< std::setprecision(4)
					<< std::fixed
					<< M[j][i] << " ";
		}
		std::cout << std::endl;
	}
}

void TranslationMatrix(){
	std::cout << "===================" << std::endl;
	std::cout << " Tranlation Matrix " << std::endl;
	std::cout << "===================" << std::endl;

	glm::mat4 I(1.0f);	//Identidade
	glm::vec3 T{10, 10, 10};
	glm::mat4 Tranlation = glm::translate(I, T);

	PrintMatrix(Tranlation);

	glm::vec4 Position{ 10, 10, 10, 1};
	glm::vec4 Direction{ 10, 10, 10, 0};
	
	std::cout << std::endl;

	Position = Tranlation * Position;
	std::cout << glm::to_string(Position) << std::endl;

	//PrintMatrix();
}
