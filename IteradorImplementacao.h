template<class TL>
Listas::Lista<TL>::Iterador::Iterador():
	elemento{ nullptr }
{
}

template<class TL>
Listas::Lista<TL>::Iterador::~Iterador()
{
	elemento = nullptr;
}

template<class TL>
void Listas::Lista<TL>::Iterador::operator++()
{
	elemento = elemento->get_proximo_elemento();
}

template<class TL>
void Listas::Lista<TL>::Iterador::operator--()
{
	elemento = elemento->get_anterior_elemento();
}

template<class TL>
void Listas::Lista<TL>::Iterador::operator=(Listas::Lista<TL>::Elemento<TL>* elemento_input)
{
	elemento = elemento_input;
}

template<class TL>
bool Listas::Lista<TL>::Iterador::operator!=(Listas::Lista<TL>::Elemento<TL>* elemento_input) const
{
	if (elemento != elemento_input)
		return(true);

	else
		return(false);
}

template<class TL>
bool Listas::Lista<TL>::Iterador::operator==(Listas::Lista<TL>::Elemento<TL>* elemento_input) const
{
	if (elemento == elemento_input)
		return(true);

	else
		return(false);
}

template<class TL>
TL* Listas::Lista<TL>::Iterador::operator*() const
{
	return(elemento->get_info());
}
