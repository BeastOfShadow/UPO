# 1 Logica matematica

> [!NOTE] Logica
>
> Studio dei linguaggi formali usati in matematica, nel <b style="color: #fc8c03">calcolo</b> e nelle loro <b style="color: #fc8c03">interpretazioni</b>.

## 1.1 Calcolo proposizionale

> [!NOTE] Variabili
>
> Enunciati che possono essere veri o falsi.

### 1.1.1 Pre-requisiti:

Variabili proposizionali: $p,\ q,\ r,\ \dots$

Una variabile proposizionale è anche detta proposizione <b style="color: #fc8c03">atomica</b>.

Connettivi logici: $\wedge,\ \vee,\ \neg,\ \Rightarrow$.

### 1.1.2 Linguaggio
> [!NOTE] Sintassi
>
> Insieme delle formule ben formate del calcolo proposizionale $\text{Prop}$ è il minimo fra gli insiemi $X$ che godono delle seguenti proprietà:
> 
> - ogni variabile proposizionale appartiene a $X$ ($\text{VarProp} \sube \text{Prop}$);
> - se $P, \ Q$ appartengono a $X$, allora anche $P\wedge Q,\ P\vee Q,\ P\Rightarrow Q$ appartengono a $X$.

> [!NOTE] Semantica
>
> Interpretazione di un enunciato corrisponde al suo valore di verità.
> 
> Assegnazione: $v: \text{VarProp} → \{0, 1\}$.

Estendiamo la funzione $v$ al dominio più ampio $\text{Prop}$ con la funzione

$v^*,v^*: \text{Prop} → \{0,1\}$, definita come segue, nei vari casi. 

La definizione per induzione (#TO-DO: aggiungere il link del ragionamento per induzione) sulla complessità dell’enunciato: il suo valore di verità è determinato in funzione di quello degli enunciati che lo compongono.

> [!WARNING] Ordine connettivi logici
>
>$\neg,\ \vee,\ \wedge,\ \Rightarrow$

## 1.2 Tavole di verità dei connettivi logici

<b>NOT</b>

| $P$| $\neg P$|
|:--:|:---:    |
|1   |0        |
|0   |1        |

<font size="1">$v^*(\neg P)=1-v^*(P)$</font> 

<b>AND</b>

| $P$| $Q$|$P\wedge Q$|
|:--:|:---:|:---:|
|0|0|0|
|0|1|0|
|1|0|0|
|1|1|1|

<font size="1">$v^*(P\wedge Q)=v^*(P)v^*(Q)=min(v^*(P);\ v^*(Q))$</font>

<b>OR</b>

| $P$| $Q$|$P\vee Q$|
|:--:|:---:|:---:|
|0|0|0|
|0|1|1|
|1|0|1|
|1|1|1|

<font size="1">$v^*(P\vee Q)=v^*(P)+v^*(Q)-v^*(P)v^*(Q)=max(v^*(P);\ v^*(Q))$</font>

<b>SE ... ALLORA ...</b>

| $P$| $Q$|$P\Rightarrow Q$|
|:--:|:---:|:---:|
|0|0|1|
|0|1|1|
|1|0|0|
|1|1|1|

<font size="1">$v^*(P\Rightarrow Q)=1-v^*(P)+v^*(Q)-(1-v^*(P))v^*(Q)=max(v^*(\neg P);\ v^*(Q))$</font>

<b>$\Leftrightarrow$</b>

| $P$| $Q$|$P\Leftrightarrow Q$|
|:--:|:---:|:---:|
|0|0|1|
|0|1|1|
|1|0|0|
|1|1|1|

<font size="1">$v^*(P\Leftrightarrow Q)=v^*(P)v^*(Q)+(1-v^*(P)(1-v^*(Q))$</font>

<b>Connettivi binari</b>

I connettivi binari corrispondono alle funzioni $f:\{0,1\}*\{0,1\}$ → $\{0,1\}$ che sono $2^4$. Quindi ci sono esattamente 16 connettivi binari. Non è necessario usarli tutti e 16.

| $P$| $Q$|$P * Q$|
|:--:|:---:|:---:|
|0|0|0-1|
|0|1|0-1|
|1|0|0-1|
|1|1|0-1|

## 1.3 Enunciati

Ci sono tre tipi di enunciati:

- soddisfacibili: un enunciato $P$ è soddisfacibile se esiste almeno un’assegnazione $v$ tale che $v^*(P)=1$;
- insoddisfacibili: un enunciato $P$ è insoddisfacibile se esiste un’assegnazione $v$ tale che $v^*(P)=0$;
- tatutologie: un enunciato $P$ è una tautologia se per ogni assegnazione $v,\ v^*(P)=1$. Evidentemente, tutte le tautologie sono soddisfacibili.

> [!NOTE] Modello
> 
> Un’assegnazione $v$ è un modello di un insieme di enunciati $\Gamma$ se e solo se $v^*$ soddisfa tutti gli elementi di $\Gamma$.

Sia $\Gamma$ un insieme di enunciati, e sia $P$ un enunciato. Si dice che $P$ è conseguenza logica di $\Gamma$ ($\Gamma\models P$) se e solo se ogni assegnazione $v$ che è un modello di $\Gamma$ soddisfa anche $P$.

Più formalmente:
$\Gamma\models P$ se e solo se per ogni assegnazione $v$, se per ogni $Q\in \Gamma v^*(Q)=1$, allora $v^*(P)=1$.

In altre parole, se e solo se ogni assegnazione $v$ che è un modello $\Gamma$ soddisfa anche $P$.

Ad esempio: $\Gamma = \{P\Rightarrow Q;\ Q\Rightarrow\neg R;\ R\}$ , se soddisfa, allora $\Gamma\models\neg P$.
|$P$|$Q$|$R$|$P\Rightarrow Q$|$Q\Rightarrow \neg R$|
|:-:|:-:|:-:|:-:|:-:|
|0|0|0|1|1|
|<b style="color: #fc8c03">0</b>|<b style="color: #fc8c03">0</b>|<b style="color: #fc8c03">1</b>|<b style="color: #fc8c03">1</b>|<b style="color: #fc8c03">1</b>|
|0|1|0|1|1|
|0|1|1|1|0|
|1|0|0|0|1|
|1|0|1|0|1|
|1|1|0|1|1|
|1|1|1|1|0|

Solo la <b style="color: #fc8c03">riga</b> soddisfa tutte le assegnazione in $\Gamma$, quindi soddisfa $\Gamma\models\neg P$.

<b>Teorema</b>

$\Gamma\models P$ se e solo se $\Gamma\cup\{\neg P\}$ è insoddisfacibile.

Esempio: sia $\Gamma =\{P\Rightarrow Q;\ Q\Rightarrow R;\ P\vee\neg Q\}$. 

È vero che $\Gamma\models R$? Per rispondere è sufficiente controllare se $\Gamma\cup\{\neg R\}$ è soddisfacibile.

$\Gamma =\{P\Rightarrow Q;\ Q\Rightarrow R;\ P\vee\neg Q;\ \neg R \}$

|$P$|$Q$|$R$|$P\Rightarrow Q$|$Q\Rightarrow R$|$P \vee \neg Q$|$\neg R$|
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|0|0|0|<b style="color: #fc8c03">1</b>|<b style="color: #fc8c03">1</b>|<b style="color: #fc8c03">1</b>|<b style="color: #fc8c03">1</b>|
|0|0|1|1|1|1|0|
|0|1|0|1|0|0|1|
|0|1|1|1|1|0|0|
|1|0|0|0|1|1|1|
|1|0|1|0|1|1|0|
|1|1|0|1|0|1|1|
|1|1|1|1|1|1|0|

$\Gamma\cup\{\neg R\}$ è soddisfacibile. Quindi $\Gamma\nvDash R$
