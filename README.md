#  AppCasa Automação
Esse pequeno projeto de automação tem por objetivo a simplicidade de subir um código ou binário via ip OTA, na realidade o ESP 8266 enviar notificações via bot telegram, e o controle remoto via internet sem bibliotecas, com isso você pode ampliar o leque de recursos e usabilidades que podemos falar, e ate mesmo mostrar em videos futuros..

# [1_pisca_pisca](https://github.com/Condiolov/AppCasa/tree/main/1_pisca_pisca "1_pisca_pisca")

Passo a passo de como fazer o upload do binário via IP OTA usando o Kate Editor ou a IDE do proprio Arduino para ESP 8266, um pisca pisca apenas para saber se o ESP esta funcionando, se o Código esta subindo, se esta tudo ok.

video 1: https://youtu.be/TgQbt1ys-FA

video 2:

```mermaid
graph LR
A[Kate Editor ou IDE Arduino] -- 10.0.0.1 --> B((WIFI))

B --> D{ESP 8266}

```

## Em breve

 - [x] 1_pisca_pisca ( Kate -> OTA -> ESP (pisca pisca)
 - [ ] 2_
 - [ ] 3_
 - [ ] 4_
 - [ ] 5_
 - [ ] 6_
 - [ ] 7_

<<<<<<< HEAD
> **Note:** Inscreve no canal muita coisa legal!!
=======
> **Note:** Inscreve no canal muita coisa legal!! 
>>>>>>> 8337385c85a9ae17c23d4b50f97bc462dddfaa9d


```mermaid
sequenceDiagram
ESP ->> NET:  Tem novidade?
NET--x ESP: Não tem !!
CLIENTE -->> NET: como estão as coisas?
Note right of NET: AJAX

```

htps://stackedit.io/app
