template<class TL>
template<class TE>
lista::Lista<TL>::Elemento<TE>::Elemento():
	info{nullptr},
	proximo_elemento{nullptr},
	anterior_elemento{nullptr}
{
}

template<class TL>
template<class TE>
lista::Lista<TL>::Elemento<TE>::~Elemento()
{
	info = nullptr;
	proximo_elemento = nullptr;
	anterior_elemento = nullptr;
}

template<class TL>
template<class TE>
void lista::Lista<TL>::Elemento<TE>::set_info(TE* info_input)
{
	info = info_input;
}

template<class TL>
template<class TE>
TE* lista::Lista<TL>::Elemento<TE>::get_info() const
{
	return(info);
}

template<class TL>
template<class TE>
void lista::Lista<TL>::Elemento<TE>::set_proximo_elemento(Lista<TL>::Elemento<TE>* elemento_input)
{
	proximo_elemento = elemento_input;
}

template<class TL>
template<class TE>
lista::Lista<TL>::Elemento<TE>* lista::Lista<TL>::Elemento<TE>::get_proximo_elemento() const
{
	return(proximo_elemento);
}

template<class TL>
template<class TE>
void lista::Lista<TL>::Elemento<TE>::set_anterior_elemento(Lista<TL>::Elemento<TE>* elemento_input)
{
	anterior_elemento = elemento_input;
}

template<class TL>
template<class TE>
lista::Lista<TL>::Elemento<TE>* lista::Lista<TL>::Elemento<TE>::get_anterior_elemento() const
{
	return(anterior_elemento);
}
