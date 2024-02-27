# 1 Logica matematica

> [!NOTE] Logica
>
> Studio dei linguaggi formali usati in matematica, **<font color="#fc8c03">calcolo</font>** e nelle loro <b style="color: #fc8c03">interpretazioni</b>.

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
> - ogni variabile proposizionale appartiene a $X$ ($\text{VarProp} \subseteq \text{Prop}$);
> - se $P, \ Q$ appartengono a $X$, allora anche $P\wedge Q,\ P\vee Q,\ P\Rightarrow Q$ appartengono a $X$.

> [!NOTE] Semantica
>
> Interpretazione di un enunciato corrisponde al suo valore di verità.
> 
> Assegnazione: $v: \text{VarProp} → \{0, 1\}$.

Estendiamo la funzione $v$ al dominio più ampio $\text{Prop}$ con la funzione

$v ^ *, v ^ *: \text{Prop} \rightarrow \{0,1\}$, definita come segue, nei vari casi.

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

$v ^ * ( \neg P) = 1 - v ^ * (P)$

<b>AND</b>

| $P$| $Q$|$P\wedge Q$|
|:--:|:---:|:---:|
|0|0|0|
|0|1|0|
|1|0|0|
|1|1|1|

$v^*(P \wedge Q)=v^*(P)v^*(Q)=min(v^*(P);\ v^*(Q))$

<b>OR</b>

| $P$| $Q$|$P\vee Q$|
|:--:|:---:|:---:|
|0|0|0|
|0|1|1|
|1|0|1|
|1|1|1|

$v^*(P\vee Q)=v^*(P)+v^*(Q)-v^*(P)v^*(Q)=max(v^*(P);\ v^*(Q))$

<b>SE ... ALLORA ...</b>

| $P$| $Q$|$P\Rightarrow Q$|
|:--:|:---:|:---:|
|0|0|1|
|0|1|1|
|1|0|0|
|1|1|1|

$v^*(P\Rightarrow Q)=1-v^*(P)+v^*(Q)-(1-v^*(P))v^*(Q)=max(v^*(\neg P);\ v^*(Q))$

<b>$\Leftrightarrow$</b>

| $P$| $Q$|$P\Leftrightarrow Q$|
|:--:|:---:|:---:|
|0|0|1|
|0|1|1|
|1|0|0|
|1|1|1|

$v^*(P\Leftrightarrow Q)=v^*(P)v^*(Q)+(1-v^*(P)(1-v^*(Q)))$

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

# 2 Ragionamenti

## 2.1 Ragionamento per assurdo

Per dimostrare che da $\Gamma$ segue $P$ è sufficiente verificare che $\Gamma\cup\{\neg P\}$ è insoddisfacibile. Questo equivale a trovare una contraddizione che sia conseguenza logica di $\Gamma\cup\{\neg P\}$.

### 2.1.1 Primo esempio
Dimostrare l'irrazionalità di $\sqrt 2$.

- $\Gamma$ = proprietà numeri irrazionali;
- $P$: *$\sqrt 2$ è irrazionale*;
- $\neg P$: $\sqrt 2$ *è razionale.*

Si trova una contraddizione che è conseguenza logica di $\Gamma\cup\{\neg P\}$.

*Come possiamo dimostrarlo?*

Non possiamo dimostrare direttamente che la sua rappresentazione decimale è illimitata non periodica. **<font color="#fc8c03">Dimostriamo per assurdo</font>**.

**Hp**:

Supponiamo, per assurdo, che $\sqrt 2$ sia razionale. Allora esistono due numeri interi $m,n$ tali che: $\sqrt 2=\frac m n$.

Possiamo supporre che $m,n$  non abbiano fattori comuni. Per definizione vale:

$(\frac m n)^2 = \frac{m^2}{n^2}=2$, e quindi $m^2=2n^2$.

Allora $m^2$ deve essere pari, quindi $m$  deve essere pari. Esiste un $k\in\Z$  tale che $m=2k$. Se $m=2k$, allora $m^2=4k^2=2n^2$.

Se $4k^2=2n^2$, allora $2k^2=n^2$. Quindi $n^2$ deve essere pari.

Questo contraddice l’ipotesi secondo cui $m,n$ non hanno fattori comuni!

### 2.1.2 Secondo esempio

$(0,\ 1]$

Dato un insieme $A$ di numeri reali, un numero reale $m$ è un minimo per $A$ se valgono entrambe le condizioni:

- $m\in A$;
- $\forall x\in A,\ m\leq x$.

---

- $\Gamma$ = proprietà numeri reali;
- $P$: *$(0,\ 1]$ non ha un minimo*;
- $\neg P$: $(0,\ 1]$ *ha un minimo.*

Si trova una contraddizione che sia conseguenza logica di $\Gamma\cup\{\neg P\}$.

Supponiamo valga $\neg P$. Allora esiste $m$ tale che:

1. $m\in A$
2. $\forall x\in A,\ m \leq x$.

$m \in A$ implica $0 < m \leq 1$. In particolare $m>0$. Allora dalle proprietà dei numeri reali discende: $0 < \frac{m}{2} < m \leq 1$.

Quindi vale: $\frac{m}{2} \in (0,\ 1]$ e anche: $\frac{m}{2} < m$.

Questo contraddice la definizione di $m$. Quindi l’ipotesi che esista un minimo è falsa, quindi tale minimo non esiste.

## 2.2 Ragionamento per induzione

**Premesse**

Sia $X$ l’insieme dei numeri naturali che godono di una certa proprietà. Provare che tutti i numeri naturali godono di quella proprietà equivale a provare che $X=\N$. Per provare questo si può usare il principio di induzione, del quale esistono diverse forme.

La forma più nota di induzione è la seguente (dato $X\sube \N$):
Se valgono:

1. $0$ (oppure $1$) appartiene a $X$;
2. Per ogni $n$, se n appartiene a $X$ allora $n+1$ appartiene a $X$.

Allora $X = \N$.

### 2.1.1 Primo esempio

$1+2+3+...+n=\frac{n(n+1)}{2}$

![schema induzione.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/abeb71f5-7dbe-4d94-9609-01325c661229/schema_induzione.png)

Proviamo per induzione che vale: $\sum^n_{i=1}i=\frac{n(n+1)}2$.

$X$ è il sottoinsieme di $\N$ in cui la formula è verificata.

1. $1$ appartiene a $X$: vero, sostituendo $1$ a $n$ nella formula si ottiene $1$: $\frac{1(1+1)}2=1$ 
   
   La somma dei numeri da $1$ a $1$ è $\sum^1_{i=1}i=1$
2. Per ogni $n$, se $n$ appartiene a $X$ allora $n+1$ appartiene a $X$.

Supponiamo che $n\in X$. Mostriamo che: $\sum^{n+1}_{i=1}i=\frac{n+1(n+1+1)}2$