# SSEs

Server-Side Extensions (SSEs) são extensões do servidor Node.js do OCC. Usando Express pra criar endpoints REST que ficam acessíveis ao site para serem acessadas por Webhooks, chamadas do Front ou chamadas externas ao site utilizando sempre a api de 

**Express**: Framework Node.js para web que facilita a criação de APIs REST.
**REST**: Representational State Transfer. Conjunto de fundamentos utilizados na criação de APIs que simplificam e facilitam o uso e torna mais eficiente a comunicação entre os sistemas.

## Download 

Existem duas formas de fazer download de SSEs: via **oracle-commerce-cli** e via API.

### Download via oracle-commerce-cli

Essa maneira é mais simples para projetos Classic. Para configurar o ambiente utilizando a cli do OCC veja esta [documentação](https://dev.azure.com/jbqconsultoria/Qualidoc/_wiki/wikis/Qualidoc.wiki/204/Configurando-o-ambiente-de-desenvolvimento).

Execute:

```bash
$ occ -x download
```

Escolha a SSE e será feito o download dela. Pode ser necessário rodar o comando duas vezes pois na primeira o cli vai criar a pasta `sse` caso não exista.

### Download via API

Para consultar as SSEs de um projeto/ambiente:

**GET**
 `/ccadmin/v1/serverExtensions`

Para fazer o download de uma SSE:

**GET**  (Send and Download)
`/ccadmin/v1/serverExtensions/nome_da_sse.zip`

## Trabalhando com SSEs

Pontos importantes sobre desenvolvimento de SSEs.

### Package.json

Existem alguns dados fundamentais que não podem faltar no package.json de uma SSE:

#### main

Identifica o caminho para o arquivo principal, que inicializa a SSE.

#### publicUrls

Especifica todas as rotas da SSE que não necessitam de authenticação.

#### authenticatedUrls

Especifica as rotas da SSE que apenas usuários logados podem acessar.

#### allowedUrls

Especifica os domínios externos que a SSE acessa. 

### Variáveis de ambiente

São 
