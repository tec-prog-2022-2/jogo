template<class TL>
Listas::Lista<TL>::Lista() :
	primeiro_elemento{ nullptr },
	ultimo_elemento{ nullptr }
{
}

template<class TL>
Listas::Lista<TL>::~Lista()
{
	limpar_lista();
	primeiro_elemento = nullptr;
	ultimo_elemento = nullptr;
}

template<class TL>
Listas::Lista<TL>::Elemento<TL>* Listas::Lista<TL>::comeco() const
{
	return(get_primeiro_elemento());
}

template<class TL>
Listas::Lista<TL>::Elemento<TL>* Listas::Lista<TL>::fim() const
{
	return(get_ultimo_elemento()->get_proximo_elemento());
}

template<class TL>
Listas::Lista<TL>::Elemento<TL>* Listas::Lista<TL>::rcomeco() const
{
	return(get_ultimo_elemento());
}

template<class TL>
Listas::Lista<TL>::Elemento<TL>* Listas::Lista<TL>::rfim() const
{
	return(get_primeiro_elemento()->get_anterior_elemento());
}

template<class TL>
void Listas::Lista<TL>::set_primeiro_elemento(Listas::Lista<TL>::Elemento<TL>* elemento_input)
{
	primeiro_elemento = elemento_input;
}

template<class TL>
Listas::Lista<TL>::Elemento<TL>* Listas::Lista<TL>::get_primeiro_elemento() const
{
	return(primeiro_elemento);
}

template<class TL>
void Listas::Lista<TL>::set_ultimo_elemento(Listas::Lista<TL>::Elemento<TL>* elemento_input)
{
	ultimo_elemento = elemento_input;
}

template<class TL>
Listas::Lista<TL>::Elemento<TL>* Listas::Lista<TL>::get_ultimo_elemento() const
{
	return(ultimo_elemento);
}

template<class TL>
void Listas::Lista<TL>::add_info(TL* info_input)
{
	if (info_input != nullptr)
	{
		Elemento<TL>* novo_elemento = new Elemento<TL>();
		novo_elemento->set_info(info_input);

		if (primeiro_elemento == nullptr && info_input != nullptr)
		{
			primeiro_elemento = novo_elemento;
			ultimo_elemento = novo_elemento;
		}

		else
		{
			novo_elemento->set_anterior_elemento(ultimo_elemento);
			ultimo_elemento->set_proximo_elemento(novo_elemento);
			ultimo_elemento = novo_elemento;
		}
	}

	else
		std::cout << "Nao foi possivel adicionar!" << std::endl;
}

template<class TL>
void Listas::Lista<TL>::limpar_lista()
{
	if (primeiro_elemento == nullptr)
		std::cout << "Nao ha informacao cadastrada!" << std::endl;

	else
	{
		Elemento<TL>* elemento = primeiro_elemento;

		while (primeiro_elemento != ultimo_elemento)
		{
			primeiro_elemento = elemento->get_proximo_elemento();
			primeiro_elemento->set_anterior_elemento(nullptr);
			elemento->set_proximo_elemento(nullptr);
			elemento = nullptr;
			delete elemento;
			elemento = primeiro_elemento;
		}

		elemento = nullptr;
		delete elemento;

		primeiro_elemento = nullptr;
		ultimo_elemento = nullptr;
	}
}
