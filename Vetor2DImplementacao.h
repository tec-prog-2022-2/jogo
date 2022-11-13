template<class TV>
Vetor2D<TV>::Vetor2D(const TV x_input, const TV y_input):
	x{x_input},
	y{y_input}
{
}

template<class TV>
Vetor2D<TV>::~Vetor2D()
{
}

template<class TV>
Vetor2D<TV> Vetor2D<TV>::operator+(Vetor2D<TV> vetor_input)
{
	return(Vetor2D<TV>(x + vetor_input.get_x(), y + vetor_input.get_y()));
}

template<class TV>
Vetor2D<TV> Vetor2D<TV>::operator-(Vetor2D<TV> vetor_input)
{
	return(Vetor2D<TV>(x - vetor_input.get_x(), y - vetor_input.get_y()));
}

template<class TV>
void Vetor2D<TV>::operator+=(Vetor2D<TV> vetor_input)
{
	x += vetor_input.get_x();
	y += vetor_input.get_y();
}

template<class TV>
void Vetor2D<TV>::operator-=(Vetor2D<TV> vetor_input)
{
	x -= vetor_input.get_x();
	y -= vetor_input.get_y();
}

template<class TV>
Vetor2D<TV> Vetor2D<TV>::operator*(int fator)
{
	return(Vetor2D<TV>(x * fator, y * fator));
}

template<class TV>
Vetor2D<TV> Vetor2D<TV>::operator*(float fator)
{
	return(Vetor2D<TV>(x * fator, y * fator));
}

template<class TV>
Vetor2D<TV> Vetor2D<TV>::operator*(double fator)
{
	return(Vetor2D<TV>(x * fator, y * fator));
}

template<class TV>
Vetor2D<TV> Vetor2D<TV>::operator/(int fator)
{
	return(Vetor2D<TV>(x / fator, y / fator));
}

template<class TV>
Vetor2D<TV> Vetor2D<TV>::operator/(float fator)
{
	return(Vetor2D(x / fator, y / fator));
}

template<class TV>
Vetor2D<TV> Vetor2D<TV>::operator/(double fator)
{
	return(Vetor2D<TV>(x / fator, y / fator));
}

template<class TV>
TV Vetor2D<TV>::operator*(Vetor2D<TV> vetor_input)
{
	return(x * vetor_input.get_x() + y * vetor_input.get_y());
}

template<class TV>
double Vetor2D<TV>::get_module()
{
	return(std::sqrt(x * x + y * y));
}

template<class TV>
Vetor2D<TV> Vetor2D<TV>::get_versor()
{
	return(operator/(get_module()));
}

template<class TV>
void Vetor2D<TV>::set_x(const TV x_input) 
{
	x = x_input;
}

template<class TV>
void Vetor2D<TV>::set_y(const TV y_input) 
{
	y = y_input;
}

template<class TV>
TV Vetor2D<TV>::get_x() const
{
	return(x);
}

template<class TV>
TV Vetor2D<TV>::get_y() const
{
	return(y);
}
