template<class TL>
lista::Lista<TL>::Iterador::Iterador():
	elemento(nullptr)
{
}

template<class TL>
lista::Lista<TL>::Iterador::~Iterador()
{
	elemento = nullptr;
}

template<class TL>
void lista::Lista<TL>::Iterador::operator++()
{
	elemento = elemento->get_proximo_elemento();
}

template<class TL>
void lista::Lista<TL>::Iterador::operator--()
{
	elemento = elemento->get_anterior_elemento();
}

template<class TL>
void lista::Lista<TL>::Iterador::operator=(lista::Lista<TL>::Elemento<TL>* elemento_input)
{
	elemento = elemento_input;
}

template<class TL>
bool lista::Lista<TL>::Iterador::operator!=(lista::Lista<TL>::Elemento<TL>* elemento_input) const
{
	if (elemento != elemento_input)
		return(true);

	else
		return(false);
}

template<class TL>
bool lista::Lista<TL>::Iterador::operator==(lista::Lista<TL>::Elemento<TL>* elemento_input) const
{
	if (elemento == elemento_input)
		return(true);

	else
		return(false);
}

template<class TL>
TL* lista::Lista<TL>::Iterador::operator*() const
{
	return(elemento->get_info());
}
