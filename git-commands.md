# Comandos Git

**Iniciar um repositório no diretório atual:** 

`$ git init`

**Adiciona arquivos para o Git monitorar:**

`$ git add <arquivo>`

`$ git add .` *(Adiciona todos da pasta atual)*


**Commit:**

`$ git commit -m "comentário para o commit"`

**Apontar o repositório local para o repositório remoto:**

`$ git remote add <nome> <url> `

**Enviar commits para o repositório remoto:**

`$ git push`
ou 
`$ git push <nome> master`

**Clonar repositório:**

`$ git clone <url>`

**Atualizar repositório local com o remoto:**

`$ git pull`
ou 
`$ git pull <nome> master`

**Status do Repositório (arquivos não adicionados e outras informações):**

`$ git status`

**Histórico de commits:**

`$ git log `
  
`$ git log --oneline` *(resumido)*
  
`$ git log --stat` *(mais informações)*
  
`$ git log --parents` *(mostra os "pais" dos commits)*
  
`$ git log --decorate` *(mostra para qual commit a branch está apontando)*

**Verificar diferenças entre a forma atual e a "monitorada" dos arquivos:**
  
`$ git diff` *(não adicionados)*

`$ git diff --staged` *(já adicionados mas não comitados)*

`$ git diff <cod. commit>..<cod. commit>` *(modif. entre os dois commits)*

**Remover arquivos:**

`$ git rm <arquivo>`

**Renomear arquivos:**

`$ git mv <nome-antigo> <nome-novo>`

**Mover arquivos:**

`$ git mv <arquivo> <novo-diretório>` *(o diretório já deve existir antes)*

**Remover alterações ainda não rastreadas (stage):**

`$ git checkout -- <arquivo>`

**Remover alterações do stage (rastreamento):**

`$ git reset -- <arquivo>`

**Remover alterações do stage e apagar alterações:**

`$ git reset --hard` *(Reseta para o último commit)*

**Remover alterações já comitadas:**

`$ git revert --no-edit <cod.commit>` *(cria um novo commit que reverte para o anterior)*

**Resetar para um commit anterior específico:**

`$ git reset --hard <cod.commit>` *(REESCREVE O HISTÓRICO ATÉ O COMMIT CITADO)*


## Repositórios

**Iniciar um repositório:**

`$ git init --bare <nome.git>`

**Adicionar um repositório remoto:**

`$ git remote add <nome> <url>`

**Listar repositórios remotos:**

`$ git remote` *(lista os nomes)*

`$ git remote -v` *(exibe as urls)*

**Renomear repositório remoto:**

`$ git remote rename <nome> <novo-nome>`

**Alterar a url do repositório remoto:**

`$ git remote set-url <nome> <url>`


## Branchs
É uma linha independente de desenvolvimento, uma "versão" paralela. Dentre as branchs HEAD é o apontador da branch atual.

**Listar branchs:**

`$ git branch`

**Criar nova branch:**

`$ git branch <nome>` *(cria mas não a torna "principal")*

**Trocando de branch:**

`$ git checkout <branch>`

**Criando e já trocando para a branch nova:**

`$ git checkout -b <nome>`

**Apagar branch:**

`$ git branch -d <nome>` *(se ainda não tiver commits mesclados a master)*

`$ git branch -D <nome>` *(apaga com seus commits)*

**Verificar branchs mescladas e não mescladas:**

`$ git branch --no-merged` *(lista branchs não mescladas)*

`$ git branch --merged` *(lista branchs mescladas)*

**Mesclar branch à master:**

`$ git merge <nome> -m "comentário"` *(bifurcação no histórico)*

`$ git rebase <nome>` *(mescla ao commit de criação da branch - histórico linear porém com perdas de histórico da master)*

**Listar branchs remotas:**

`$ git branch -r`

`$ git branch -a` *(lista também as locais)*

`$ git branch -r -v` *(quais commits as branchs remotas estão apontando)*

**Publicar branchs:**

`$ git push <nome-repo> <branch>`

**Clonar branchs remotas:**

`$ git checkout -b <branch> <branch-remota>`

`$ git checkout -t <branch-remota>`

**Buscar os commit e refs de uma branch remota:**

`$ git fetch <nome-repo>` *(só atualiza)*

`$ git pull` *(atualiza e faz merge na master) (com histórico detalhado)*

`$ git pull --rebase` *(atualiza e faz rebase na master) (reescreve histórico)*

**Deletar branch do servidor:**

`$ git branch -D <branch>` *(apaga localmente)*

`$ git push <repo> :<branch>` *(deleção no repositório remoto)*


## Tags 
São as "fotos" das versões, marcações temporais

**Criar uma tag:**

`$ git tag <tag>`
ou
`$ git tag -a <tag> -m "mensagem"`

**Criar tag para um commit específico passado:**

`$ git tag <tag> <cód.commit>`

**Listar tags:**

`$ git tag`

**Mostrar info de tags anotadas:**

`$ git show -s <tag>`

**Apagar tag:**

`$ git tag -d <tag>`

**Enviando tags para o repositório remoto:**

`$ git push <repo> <tag>` *(uma específica)*

`$ git push <repo> --tags` *(todas)*

## GitHub e projetos Open Source 

#### Fork 
Criar uma cópia do repositório no "meu" GitHub. A partir daí podem ser criadas novas branchs e ser feitas alterações nos arquivos DESTA CÓPIA.

#### Pull Request
Quando são feitas alterações porém o seu git não é "dono" do repositório. É a tentativa de devolver as alterações da versão do projeto que está no nosso repositório para o repositório original "dono".
