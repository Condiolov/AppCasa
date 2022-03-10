#  AppCasa Automação
Esse pequeno projeto de automação tem por objetivo a simplicidade de subir um código ou binário via ip OTA, na realidade o ESP 8266 enviar notificações via bot telegram, e o controle remoto via internet sem bibliotecas, com isso você pode ampliar o leque de recursos e usabilidades que podemos falar, e ate mesmo mostrar em videos futuros..

# [1_pisca_pisca](https://github.com/Condiolov/AppCasa/tree/main/1_pisca_pisca "1_pisca_pisca")

Passo a passo de como fazer o upload do binário via IP OTA (atualização remota de software) usando o Kate Editor ou a IDE do proprio Arduino para ESP 8266, um pisca pisca apenas para saber se o ESP esta funcionando, se o Código esta subindo, se esta tudo ok.

video 1: https://youtu.be/TgQbt1ys-FA

video 2: https://youtu.be/9wk9-3_aoyo ( AppCasa 1 - Pisca Pisca via ip OTA usando Kate Editor)

```mermaid
graph LR
NOTA>Atualização do Esp via OTA]
A[Kate Editor ou IDE Arduino] --> B((WIFI -> 10.0.0.1))

B --> D{ESP 8266 pisca pisca}

```

# [2_uma_lampada](https://github.com/Condiolov/AppCasa/tree/main/2_uma_lampada "2_uma_lampada")

Criando um mine web servidor com ESP 8266 capaz de acionar um led e futuramente uma lampada ou algo bem superior. Ao acessar o ip do ESP (no meu caso o 10.0.0.101) você verá uma pagina web que é a inteface basica que pode ser modificada e criada de acordo com suas espectativas. Nesse video explico cada funcionalidade, uma delas é o coração função que faz o ESP ficar picando, para mostrar seu funcionamento, bem como servir de led sinalizador de atividade.

video 3: https://youtu.be/al7JYiOS6YU ( AppCasa 2 - Web servidor com ESP 8266 capaz de acionar um LED)


```mermaid
graph LR
NOTA>Um mine Servidor]
A[PAGINA WEB] --> B((WIFI -> 10.0.0.1))
B --> D[ESP]
D-->E(LED 1)
D-->F(LED 2)
D-->H(...)
```

# [3_entradas_saidas]
AppCasa 3 - Expansor de Entras e Saida para o ESP 8266 scanear endereço do ci PCF8574, conseguimos ampliar para mais dispositivos o controle do espectativas


```mermaid
graph LR
NOTA>Um mine Servidor]
A[PAGINA WEB] --> B((WIFI -> 10.0.0.1))
B --> D[ESP]
D --> E[PCF8574 1]
E-->F(ci_1 P0 SAIDA)
E-->G(ci_1 P1 ENTRADA)
E-->H(cada ci 8 portas<br/> configuraveis)
D --> E2[PCF8574 2 ]
E2-->F2(ci_2 P1 SAIDA)
E2-->G2(ci_2 P0 ENTRADA)
E2-->H2(cada ci 8 portas<br/> configuraveis)
D --> E3[Outros CI's ]
E3-->H3(cada ci 8 portas<br/> configuraveis)
```


## Em breve

 - [x] 1_pisca_pisca ( Kate -> OTA -> ESP (pisca pisca)
 - [x] 2_uma_lampada (Acionar via LED acessando ESP como servidor WEB)
 - [x] 3_entrada_saidas (Expansão)
 - [ ] 4_
 - [ ] 5_
 - [ ] 6_
 - [ ] 7_


> **Note:** Inscreve no canal muita coisa legal!!




```mermaid
sequenceDiagram
ESP ->> NET:  Tem novidade?
NET--x ESP: Não tem !!
CLIENTE -->> NET: como estão as coisas?
Note right of NET: AJAX

```

htps://stackedit.io/app
