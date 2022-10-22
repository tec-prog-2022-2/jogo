#pragma once

template<class TIPO>
class Lista
{
private:
	template<class TIPO_>
	class Elemento
	{
	private:
		TIPO_* info;
		Elemento<TIPO_>* proximo_elemento;
		Elemento<TIPO_>* anterior_elemento;

	public:
		Elemento()
		{
			info = nullptr;
			proximo_elemento = nullptr;
			anterior_elemento = nullptr;
		}

		~Elemento()
		{
			info = nullptr;
			proximo_elemento = nullptr;
			anterior_elemento = nullptr;
		}

		void set_info(TIPO_* info_input)
		{
			info = info_input;
		}

		TIPO_* get_info()
		{
			return(info);
		}

		void set_proximo_elemento(Elemento<TIPO_>* elemento_input)
		{
			proximo_elemento = elemento_input;
		}

		Elemento<TIPO_>* get_proximo_elemento()
		{
			return(proximo_elemento);
		}

		void set_anterior_elemento(Elemento<TIPO_>* elemento_input)
		{
			anterior_elemento = elemento_input;
		}

		Elemento<TIPO_>* get_anterior_elemento()
		{
			return(anterior_elemento);
		}
	};

private:
	Elemento<TIPO>* primeiro_elemento;
	Elemento<TIPO>* ultimo_elemento;

public:
	Lista()
	{
		primeiro_elemento = nullptr;
		ultimo_elemento = nullptr;
		atual_elemento = nullptr;
	}

	~Lista()
	{
		primeiro_elemento = nullptr;
		ultimo_elemento = nullptr;
		atual_elemento = nullptr;
	}

	void set_primeiro_elemento(Elemento<TIPO>* elemento_input)
	{
		primeiro_elemento = elemento_input;
	}

	Elemento<TIPO>* get_primeiro_elemento()
	{
		return(primeiro_elemento);
	}

	void set_ultimo_elemento(Elemento<TIPO>* elemento_input)
	{
		ultimo_elemento = elemento_input;
	}

	Elemento<TIPO>* get_ultimo_elemento()
	{
		return(ultimo_elemento);
	}

	void set_atual_elemento(Elemento<TIPO>* elemento_input)
	{
		atual_elemento = elemento_input;
	}

	Elemento<TIPO>* get_atual_elemento()
	{
		return(atual_elemento);
	}

	void add_info(TIPO* info_input)
	{
		if (info_input != nullptr)
		{
			Elemento<TIPO>* novo_elemento = new Elemento<TIPO>();
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
			cout << "Nao foi possivel adicionar!" << endl;
	}

	void limpar_lista()
	{
		if (primeiro_elemento == nullptr)
			cout << "Nao ha informacao cadastrada!" << endl;

		else
		{
			Elemento<TIPO>* elemento = primeiro_elemento;

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
};
