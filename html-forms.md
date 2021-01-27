## forms
Elemento container para o formulário

*__action__* define para onde vão os dados. Quando não definido os dados são enviados para a própria página.
*__method__* define o verbo para o tráfego de dados.

#### fieldset
Agrupamento de campos semânticos.

*__disaled__* desabilita o envio de dados desse fieldset, form ou input.
*__form__* o id do form a qual esse fieldset pertence. Com ele o fieldset não precisa estar dentro do form.
*__name__* nome do grupo. Não aparece.

#### legend 
Nome do agrupamento, primeiro elemento dentro do fieldset. 


<form id="contato">
  <button>Enviar</button>
</form>

  <fieldset form="contato" name="inputs-contact">
    <legend>Contato</legend>
    <label for="">Name</label>
    <input type="text">
  </fieldset>


###### código: 
~~~html
<form id="contato">
  <button>Enviar</button>
</form>

  <fieldset form="contato" name="inputs-contact">
    <legend>Contato</legend>
    <label for="">Name</label>
    <input type="text">
  </fieldset>
~~~


#### label 
Associar e identificar uma ou mais entrada de dados.

*__for__* serve para conectar o label com o input que ele representa. Utiliza-se o id do input.

#### button
Representa um botão. Usado para enviar formulários.

*__autofocus__*: define como foco da página. Enter.
*__disable__*: botão não é clicável.
*__name__*: associa o botão a outro elemento, usa-se a id.
*__value__*: valor que será enviado para algum elemento que será associado em *__name__*.
*__type__*: define tipo do botão dentro do formulário. 
*__type="submit"__*: Submeter e enviar formulário.
*__type="reset"__*: Reseta para o value padrão.
*__form__*: associa o botão a um form.

#### datalist
lista de dados, como sugestões para um input.

###### código:

```html
<input type="text" list="fruitsdata" placeholder="Escolha uma fruta">
<datalist id="fruitsdata"> <!-- lista de dados/opções -->
  <option>apple</option> <!-- opção -->
  <option>banana</option>
  <option>orange</option>
  <option>mango</option>
  <option>cherry</option>
<datalist>
```

###### resultado:

<input type="text" list="fruitsdata" placeholder="Escolha uma fruta">
<datalist id="fruitsdata">
  <option>apple</option>
  <option>banana</option>
  <option>orange</option>
  <option>mango</option>
  <option>cherry</option>
</datalist>

#### Input
Recebe dados variados

###### Atributos comuns:
*__autocomplete__* usa os dados do navegador para autocompletar um input. No caso de input do tipo password, com 'new-password' ocorre a sugestão de senha.
*__disabled__* o value desse input fica inalterável.
*__value__* valor padrão desse input.
*__readonly__* apenas para leitura, inalterável.
*__form__* associa o input a um formulário caso não esteja dentro dele.
*__name__* identificador do input.
*__for__* utilizado geralmente em label para relacionar a um elemento oela id.
*__title__* um título ou ajuda para o campo.
*__required__* input obrigatório.
*__placeholder__* texto de fundo dentro do campo de digitação.
*__list__* associa o input a uma datalist

###### Outros atributos (não necessário para todos):
*__minlength__* mínimo de caracteres.
*__maxlength__* máximo de caracteres.
*__size__* meio que muda o tamanho do campo.
*__pattern__* expressão regular para validar o campo. 
*__inputmode__* define a forma de entrada de dados. "numeric" abriria o teclado numérico no smartphone.
*__multiple__* permite mais de um valor separado por vírgulas. No input do tipo *__file__*, ele pode ficar sozinho.
*__spellcheck__* verificação hortográfica.
*__accept__* no input do tipo *__file__*, indica o tipo de arquivo aceito.
*__checked__* simboliza que um campo está marcado.
*__rows__* e *__cols__* definem o tamanho de um *__textarea__*.
*__wrap__* define a quebra de linha numa *__textarea__*.
*__step__* pesso, usado em inputs do tipo number e range.


##### type
Define o tipo de dado que o input receberá

###### Principais tipos:
*__password__* esconde o que está sendo digitado no campo.
*__email__* valida se o valor digitado é um email.
*__url__* valida se o valor digitado é uma url.
*__file__* recebe arquivos do usuário. É necessário o form estar com *enctype="multipart/form-data"*.
*__color__* seleção de cor.
*__checkbox__* são "caixinhas" marcáveis. Se não marcadas, o back end recebe como vazio. Podem ser colocados vários, com o mesmo 'name'.
*__hidden__* input escondido para enviar algum valor ao back end sem necessitar do usuário, como hora ou data de submissão.
*__radio__* campos marcáveis, opções. Nesse caso, diferente do checkbox, é "obrigatório" marcar uma das opções.
*__search__* campo para pesquisa. Suporta list/datalist. Não suporta label, portanto é usado o atributo *'aria-label'*.
*__number__* permite a entrada de números. No lugar de min/maxlength usa-se _min_ e _max_.
*__range__* slider ou dial control, controle para selecionar números sem precisão.
*__date__* recebe datas. "yyyy-mm-dd".
*__datetime-local__* recebe data e hora. "yyyy-mm-dd hh-mm".
*__month__* recebe meses.
*__time__* recebe hora.
*__week__* recebe semana.

#### textarea
Área para textos grandes.

 
#### Select
Container para elementos *__option__* e/ou *__optgroup__*, menu de opções.

###### Código:
~~~html
<label for="carselect">Modelo do carro</label>
<select name="carmodel" id="carselect"> 
  <option>opção 1</option>
  <option>opção 2</option>
</select>
~~~

###### Resultado:
<label for="carselect">Modelo do carro</label>
<select name="carmodel" id="carselect"> 
  <option>Selecione um modelo</option>
  <option>opção 1</option>
  <option>opção 2</option>
  <option>opção 3</option>
</select>


###### Dicas

Desenhar o formulário antes de programá-lo. Para ajudar a definir as necessidades, organização.
 
###### Exemplo de um formulário simples

<form id="contato" action="" method="POST">
  <fieldset form="contato">
    <legend>Contato</legend>
  
  <label for="name">Nome</label>
  <input type="text" required name="name" id="name"> <br> 
  
  <label for="email">Email</label>
  <input type="email" required name="email" id="email"> <br> 
  
  <label for="message">Mensagem</label> 
  <textarea name="message" required id="message" cols="30" rows="10"></textarea> <br> 

  <button>Enviar</button>

  </fieldset>
</form>

###### Código

~~~html
<form id="contato" action="" method="POST">
  <fieldset form="contato">
    <legend>Contato</legend>
  
    <label for="name">Nome</label>
    <input type="text" required name="name" id="name"> <br> 
    
    <label for="email">Email</label>
    <input type="email" required name="email" id="email"> <br> 
    
    <label for="message">Mensagem</label> 
    <textarea name="message" required id="message" cols="30" rows="10"></textarea> <br> 

    <button>Enviar</button>

  </fieldset>
</form>
~~~