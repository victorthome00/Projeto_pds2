# Projeto_pds2

## Site de e-commerce
 
 ### INTRODUÇÃO

  * O grande avanço da internet nas últimas décadas reformulou por completo as relações interpessoais, incrementando a globalização e intensificando o acesso à informação. Seguindo nessa logica, as relações comerciais foram inovadas, com o surgimento de sites, propagandas pop-ups, pagamentos PIX e muito mais. Consequentemente, nos dias atuais, é cada vez mais importante manter uma relação próxima e eficiente entre o vendedor e o público alvo. A partir desse pretexto, nosso grupo optou por desenvolver um site de e-commerce, que estreita a relação cliente e lojista, beneficiando ambos os usuários.

  ### FUNCIONAMENTO GERAL

  * No site teremos dois tipos de usuários, o cliente e o lojista. Aquele faz o seu cadastro e login e a partir disso escolhe entre os produtos disponíveis adicionando-os ao carrinho. Ao concluir suas compras é calculado o valor total a ser pago, efetuando o pagamento escolhendo o modo de pagamento e, caso credito ou debito validando cartão e, caso PIX, confirmando o código gerado. Esse por sua vez, cadastra sua loja no site adicionando seus produtos, podendo também modificá-los conforme vontade.
  * Na interface do gerente, quando for adicionar o produto, atente-se para colocar o valor do produto com duas casas decimais (ex: 10.99) e que o número do código do produto difere-se do número de quantidade do mesmo.

  ### OBSERVAÇÕES / DESAFIOS

  - A implementação de testes utilizando o doctest foi um grande desafio, primeiro porque o própio file doctest apresentava erros nos computadores da maioria dos integrantes do grupo. No caso, no computador do Arthur conseguimos trabalhá-lo. Em segundo lugar, algumas classes já tratavam os erros com do-whiles e os testes de erros ficavam ineficazes. Além disso tudo, classes que recebiam os dados com cin, ou seja, tinham a entrada efetuada pelo usuário, e classes que retornavam void também apresentaram um alto grau de dificuldade para nós.
  - Outra dificuldade enfrentada pelo grupo foi a implementação de um banco de dados que facilitaria a implementação do código. A falta de conhecimento sobre do grupo, e a dificuldade de tirar um tempo específico para o estudo disso, impossibilitou a implementação. Com isso, partimos para o uso de arquivos de txt, como definidos pelo integrante Aurélio, como uma "gambiarra", pelo Maarten, como "rataria" e pelo Arthur...
  - A configuração do github e do vscode foi outra dificuldade enfrentada pelo grupo.
  - O arquivo usuario.cpp foi o de maior desafio também ao grupo, apresentando ao longo da elaboração do trabalho, inúmeros erros de compilação que atrasaram o desenvolvimento do projeto e requisitaram uma grande doação do grupo como um todo. 
  - A manipulação de arquivos em txt também gerou muita dor de cabeça. Primeiro com a dificuldade de lê-los, depois com a adição involuntária de elementos no arquivo e também na dificuldade de adicioná-los posteriormente.
  - Eventuais conflitos no github conjuntamente com branches atualizadas e também desatualizadas em comparação com a main(ao mesmo tempo).
  - O tratamento de entrada também foi outra dificuldade, uma vez que são inúmeras entradas possíveis que poderiam ocasionar inúmeros erros e, mesmo tratando várias entradas, sempre surgem novas que ocasionam o erro.
  - Durante o trabalho final desse semestre, uma das dificuldades foi os testes de software sob o DocTest, devido ao passo que a maioria das novas função são alto retroativas visto que os while, durante nossa implementação, já pede para o cliente(usuario) botar um comando válido e repete a execução até que a saída esteja válida. Ademais, as funções sem retorno(void) e que não exigem parâmetros, exigem complexidade a mais para ter consecução nos testes.

  ### MAKE FILE

  - Para rodar o make file é necessario o compilador de c++ GNU: g++.
  - O make file foi criado para funcionar no sistema operacional Linux.
  - Para rodar o make test, basta digitar "make test" na pasta do projeto.
  - Para criar o make run, basta digitar "make run" na pasta do projeto.
