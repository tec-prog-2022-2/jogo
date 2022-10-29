#pragma once

template<class TV>
class Vetor2D
{
private:
	TV x;
	TV y;

public:
	Vetor2D(const TV x_input=0, const TV y_input=0);
	~Vetor2D();
	Vetor2D<TV> operator+(Vetor2D<TV> vetor_input); //soma vetorial
	Vetor2D<TV> operator-(Vetor2D<TV> vetor_input); //subtra��o vetorial
	void operator+=(Vetor2D<TV> vetor_input); 
	void operator-=(Vetor2D<TV> vetor_input);
	Vetor2D<TV> operator*(int fator); //produto por escalar
	Vetor2D<TV> operator*(float fator); //produto por escalar
	Vetor2D<TV> operator*(double fator); //produto por escalar
	Vetor2D<TV> operator/(int fator); //divis�o por escalar
	Vetor2D<TV> operator/(float fator); //divis�o por escalar
	Vetor2D<TV> operator/(double fator); //divis�o por escalar
	TV operator*(Vetor2D<TV> vetor_input); //produto interno
	double get_module();
	Vetor2D<TV> get_versor();
	TV get_x() const;
	TV get_y() const;
};

#include"Vetor2DImplementacao.h"
