### HTTP
HyperText Transfer Protocol
Permite troca de insformações e dados na internet

	*__request__* é uma *__message__* Browser -> Servidor.
	*__response__* é uma *__message__* Servidor -> Browser.

#### request
	###### Methods
	_GET_: Pegar um recurso
	_POST_: Criar um recurso

	###### Protocol version
	2 ou 1.1

	###### URI

#### response
	###### Protocol version 
	HTTP/2 por exemplo

	###### status codeR
	esposta do Servidor a respeito do pedido/resposta

	_200_: OK
	_301_: Redirecionamento
	_404_: Página não encontrada 
	_500_: Erro no servidor

	###### headers
	cabeçalho com informações

	###### Status message
	o "corpo" da resposta

#### Client 
Entidade que dá início à comunicação

#### Server
Recebe pedidos e manda respostas

#### Proxies
Representantes, ficam entre o cliente e o servidor e ajudam no transporte de dados. Além de _distribuição de carga_, cache, autenticações, autorizações.

#### URI
Uniform Resource Identifier. Identifica o recurso pelo nome ou localização.

	##### Resource
	O alvo do pedido: um Recurso. Pode ser uma Entidade digital, abstrata e física.

	##### Locator 
	URL - Uniform Resource Locator.
	Componentes obrigatórios: Protocolo (http) e Domínio(nome.com) 
	Componentes opcionais: Subdomínio(www.), path(~/blog), parâmetros(?key=), porta(:3000) e âncora(#parte)


#### HTTP Methods
	##### OPTIONS
	Checa a disponibilidade dos methods do Servidor

	##### GET
	Pega um recurso no Servidor. É o padrão das requisições.

	##### HEAD
	É um GET porém só recebe o cabeçalho.

	##### POST
	Publica ou Cadastra um recurso.

	##### PUT
	Cria ou Atualiza dados em um recurso.

	##### PATCH
	Atualiza parcialmente um recurso.

	##### DELETE
	Deleta um recurso ou parte.

	#### Headers
	São cabeçalhos, informações adicionais para o request ou response.
