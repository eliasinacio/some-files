### HTML 

#### estrutura comum

###### cabeçalho: 
`<header>`
###### navegação (menu): 
`<nav>`
###### conteúdo principal: 
`<main>`
###### conteúdo "paralelo" que tem relação ao main ≠ sidebar: 
`<aside>` 
###### artigo, como uma seção sem ligação com o conteúdo principal da página: 
`<article>`
###### seção de conteúdo, geralmente com um título: 
`<section>`
###### rodapé: 
`<footer>`

#### meta (básicos)

###### Codificação de caracteres especiais:
`<meta charset="UTF-8">`

###### Portabilidade para dispositivos móveis:
`<meta name="viewport" content="width=device-width, initial-scale=1.0">`


#### meta avançados (SEO)
são dados relacionados à buscas no navegador

###### Nome do autor:
`<meta name="author" content="Elias Inácio">`

###### Descrição do site: 
`<meta name="description" content="Um website e tals e tals...">`


#### fiveicon
`<link rel="icon" href="link/ou/diretório/do/icone">`


#### Tags genéricas
##### div
`<div> Elemento genérico que se comporta como um bloco. </div>`
##### span
`<span> Elemento genérico que se mantém em linha. </span>`


#### Aninhamento de tags

Uma tag que emgloba outra(s) é **pai(parent)** destas e estas são suas **filhas(child)**.
Existem tags que quebram linhas e outras que são em linha.

#### Tabelas

##### Tabela simples
~~~html
<table>
  <caption> <!-- Descrição ou Sumário --> </caption>
  <thead> <!-- cabeçalho -->
    <tr> <!-- linha -->
      <th> <!-- data head (elemento cabeçalho) --> </th>
      <th> <!-- data head (elemento cabeçalho) --> </th>
      <th> <!-- data head (elemento cabeçalho) --> </th>
    </tr>    
  </thead> 

  <tbody> <!-- corpo -->
    <tr> <!-- linha -->
      <td> <!-- data cell (elemento simples) --> </td>
      <td> <!-- data cell (elemento simples) --> </td>
      <td> <!-- data cell (elemento simples) --> </td>
    </tr>
  </tbody>
  
  <tfoot> <!-- rodapé -->
    <tr> <!-- linha -->
      <td> ... </td>
      <td> ... </td>
      <td> ... </td>
    </tr>
  </tfoot> 
</table>
~~~

##### Tabela Complexa
~~~html
<table>
  <caption>Produzidos vs Vendidos por Loja</caption>

  <colgroup>
    <col>     <!-- span/rowspan/colspan espandem -->
    <col span="2" style="background-color: red;">      
    <col span="2" style="background-color: blue;">
  </colgroup>
  
  <thead>
    <tr>
      <th rowspan="2"></th>
      <th colspan="2" scope="colgroup">Loja 1</th>
      <th colspan="2" scope="colgroup">Loja 2</th>
    </tr>

    <!-- scope indica se o cabeçalho é de linha ou de coluna -->
    
    <tr>
      <th scope="col">Produzidos</th>
      <th scope="col">Vendidos</th>
      <th scope="col">Produzidos</th>
      <th scope="col">Vendidos</th>
    </tr>
  </thead>

  <tbody>
    <tr>
      <th scope="row">Vassouras</th>
      <td>50</td>
      <td>30</td>
      <td>20</td>
      <td>20</td>
    </tr>

    <tr>
      <th scope="row">Baldes</th> 
      <td>10</td>
      <td>10</td>
      <td>30</td>
      <td>25</td>
    </tr>
  </tbody>
</table>
~~~

#### Citações
###### blockquote:
`<blockquote cite="link/da/fonte"> <p>Citação</p> </blockquote>`

###### cite:
`<p> De acordo com <a href="link/da/fonte"> Nome da Fonte</a>: Citação...</p>`

###### quote:
`<p><q cite="link/da/fonte"> Citação...</q> </p>`
    
#### Abreviações
~~~html
<p> 
  Usamos 
  <abbr title="Hypertext markup Language">HTML</abbr> 
  para estruturar documentos web.
</p>
~~~

#### Códigos
~~~html
<pre>
  <code>
    function selectTitle() {
      const title = document.getElementById("title")
      console.log(title.value)
    }
  </code>
</pre>
~~~

#### tag âncora(link)
Atributos importantes:
**href** é o link ou fragmento
**download** faz download de algo
**target** define se abre o link na mesma aba (**_self** ou **_blank**)

~~~html
<a href="link">
  Link Normal</a>
<a href="mailto:email@mail.com">
  Enviar email</a>
<a href="tel:+5588988001122">
  Fazer ligação</a>
<a href="#fragmento">
  Direciona a página  para o elemento com id igual ao "fragmento"</a>
~~~

#### mídias 
Normalmente não é recomendado ter videos e audios na própria página e sim hospedar e outras plataformas (youtube, soundcloud) e "embutir" na página [iframe].

###### video
~~~html
<video 
  constrols autoplay loop muted
  preload="auto ou metadata ou none"
  poster="caminho/imagem/de/tumb">

  <source src="./caminho/do/video.mp4" type="video/mp4"> <!-- "o(s) vídeo(s)" -->
  <source src="./caminho/do/video.mp3" type="video/mp3"> <!-- procura o melhor -->
  <source src="./caminho/do/video.mkv" type="video/mkv"> <!-- para reproduzir -->
</video>
~~~

###### audio
~~~html
<audio 
  constrols autoplay loop muted
  preload="auto ou metadata ou none"

  <source src="./caminho/para/audio.mp4" type="audio/wav"> <!-- "o(s) vídeo(s)" -->
  <source src="./caminho/para/audio.mp3" type="audio/mp3"> <!-- procura o melhor -->
</audio>
~~~

###### iframe
audios, videos, maps, etc.

~~~html
<iframe src"link/para/o/video-ou-audio"
  frameborder="0px"
  allow="permissões; como; autoplay; accelerometer; gyroscope;" 
  allowfullscreen
  title="Título da mídia para leitores">

</iframe>
~~~

###### img
"https://source.unsplash.com/random" coloca uma imagem aleatória

~~~html
<img src="local/ou/link/da/imagem"
  alt="texto que aparecerá se a imagem não carregar"
  title="titulo que aparece quando o cursor descansa sobre a imagem">
~~~
***ou*** adicionando *background-image* em qualquer tag, estilizando ela com CSS

***figure/figcaption:*** é semanticamente melhor colocar uma imagem em um container figure e paralela a uma figcaption para criar um título ou descrição à imagem.

~~~html
<figure>
  <img src="" alt"">
  <figcaption> Título ou descrição </figcaption>
</figure>
~~~
