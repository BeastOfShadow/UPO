# 1 Realizzazione database

Realizzazione di un database per immagazzinare i dati. Si usa un **DB** per:

- conservare una grande quantità di dati;
- modellarli;
- proteggerli;
- condividerli.

> [!IMPORTANT] Base di dati
>
> Insieme di **dati atomici**, **strutturati** e permanenti, raggruppati in **insiemi omogenei** in relazione tra loro, organizzati con la **minima ridondanza** per essere utilizzati da **applicazioni diverse** in modo controllato.

- Atomici: dati semplici (string, int…);
- Strutturati: dati legati tra loro;
- Insiemi omogenei;
- Minima ridondanza: dati non duplicati;
- Utilizzo applicazioni diverse: grazie al DBMS.

Il **DBMS** è un software usato per gestire i dati. Garantisce le caratteristiche del DB, multi-utenza, riservatezza dei dati, manipolazione dati.

Architettura a livelli: schema esterno (persone), logico, interno e DB.

## 1.1 ANALISI FUNZIONALE

Ciclo **sistema informativo**:

- studio fattibilità;
- raccolta e analisi requisiti;
- progettazione;
- implementazione;
- validazione/collaudo;
- funzionamento.

Le variabili fondamentali sono: costo, tempo, qualità, funzionalità.

Analisi dati:

- **schema**: invariato nel tempo (aspetto intensionale);
- **istanza**: valore effettivo (aspetto estensionale).

> [!IMPORTANT] Modello Concettuale
>
> Analisi rigorosa della realtà.

Dopo il modello concettuale, si struttura il modello logico

> [!IMPORTANT] Modello Logico
>
> Struttura di un modello dati.

Si può effettuare il **reverse engineering** da modello logico a modello concettuale.

Il DBMS permette di manipolare i dati:

- **DDL**: descrizione dello schema.

- **DML**: manipolazione istanze.

Il DBMS divide i dati:

- indipendenza **fisica**: utenti interagiscono senza considerare la struttura dati;
- indipendenza **logica**: utenti interagiscono senza preoccuparsi del livello sottostante.

 Gli accessi avvengono solo attraverso il livello esterno.

L’**amministratore** DB: si occupa della progettazione e controllo.

Il **progettista/programmatore**: sviluppano i programmi per accedere al DB.

Gli **utenti** utilizzano i DB per le proprie attività.

Vantaggi/svantaggi:

- considerare i dati come una risorsa comune di un’organizzazione a disposizione delle sue componenti;
- il DB fornisce un modello precisone del mondo reale di interesse;
- rende possibile il controllo centralizzato dei dati;
- la condivisione riduce le ridondanze e inconsistenze;
- l’indipendenza dei dati favorisce lo sviluppo di applicazioni flessibili.

## 1.2 Progettazione concettuale

- **Raccolta** e **analisi** dei **requisiti** (tramite utenti, documentazione e DB preesistenti);
  - requisiti vanno riscritti (ristrutturazione frasi, frasi corte, eliminazione omonimi/sinonimi);
- Costruzione **glossario**;
- Costruzione **schema** **concettuale**;
- **Identificazione** **operazioni**.

Ci sono dei passi da seguire per la realizzazione di uno schema concettuale E-R.

### 1.2.1 **Generalizzazioni**

Possono essere:

- **totali/parziali**: si riferisce ai figli del genitore, se presi tutti in considerazione o meno (**esistenza figli o meno**). Ad esempio: veicolo (p), macchina/camion (f). Esiste veicolo senza figli?
- **esclusive/sovrapposte**: si riferisce a quanti figli può avere il padre (**esclusivo** al massimo un figlio, **sovrapposto** esistono più entità figlie).

Le generalizzazioni possono essere: totali esclusive o sovrapposte oppure parziali esclusive o sovrapposte.

Business rules:

- vincolo di **integrità**: (RV) \<concetto> deve/non deve \<espressione>
- **derivazione**: (RD) \<concetto> si ottiene \<operazione>

Progettazione concettuale:

- entità (proprietà significative), attributo, associazione, generalizzazione.

Lo schema dev’essere:

- **corretto**: solo errori sintattici o semantici;
- **leggibile**: facilmente comprensibile;

- **completo**: modella tutte specifiche;
- **minimalista**.

Nello schema devono comparire solo cose che sono presenti nei requisiti rivisti.

### 1.2.2 Pattern di progettazione

- reificazione **da attributo ad entità**: se un attributo è importante, diventa un entità;
- **part-of**: un catalogo esiste solo quando esiste un’opera al suo interno, una scuola ha più aule;
- **instance-of**: creo una sotto entità che specifica la precedente (video, video premium);
- reificazione di un’**associazione binaria**: una relazione diventa un’entità;
- reificazione di un’**associazione ricorsiva**: una relazione diventa un’entità e creo due relazioni che le collegano;
- Reificazione **da attributo di associazione**: un attributo di una relazione diventa entità.
- caso particolare di entità: un figlio esegue azioni specifiche;
- **storicizzazione** di un’**entità**: come la validità di un documento;
- **storicizzazione** di un **associazione**: come inizio/fine impiego;
- **evoluzione di concetto**: aggiungo attributi;
- reificazione di **associazione ternaria**: da associazione ad entità collegate da relazioni.

### 1.2.3 Strategie di progetto

**Top-down**:

Parto **da problemi grandi** fino **a** scinderli in **problemi piccoli**:

1. creo una singola tabella;
2. metto attributi;
3. faccio le relazioni;
4. generalizzazioni.

Pro: trascuro alcuni aspetti da rivedere.

Contro: posso solo se ho la visione globale dei componenti.

**Bottom-up**:

Parto dalle cose meno importanti per arrivare ai problemi più grandi.

Pro: adatta a progettazione di gruppo.

Contro: l’integrazione di schemi concettuali diversi causano difficoltà.

**Inside-out**:

Variante **bottom-up**: parto dai concetti cardine e li lego ai problemi più piccoli. Inizio a collegare le entità finite, senza aspettare di averle completate tutte.

Pro: non richiede integrazione.

Contro: devo sempre riesaminare specifiche.

**Strategia mista**:

Individuo i concetti principali e realizzo lo scheletro dello schema. Dopo lo decompongo e lo raffino.

## 1.3 Progettazione logica

Da schema concettuale (E-R) a schema logico.

> [!NOTE]
>
> Tradurre schema concettuale in logico che rappresenti dati in modo intelligente.

Serve a **ottimizzare** la **base** di **dati**. Come analizzare le prestazioni:

- **tempo**: numero visite operazione sul DB;
- **spazio**: spazio in memoria necessario a rappresentare dati;
- **tavola dei volumi**: dimensione degli attributi;
- **tavola delle operazioni**.

### 1.3.1 Ristrutturazione E-R

- **analisi ridondanze**. Ci sono diverse forme:
  - attributi derivabili da altri attributi della stessa/altre entità, dalla partecipazione ad un’associazione (numero di like,).
  - associazioni derivabili dalla composizione di altre associazioni.
- **eliminazione generalizzazioni**:
  - accorpamento dei figli nel genitore: porto attributi figli nei genitori (con un tipo), quando le **operazioni non fanno troppa distinzione tra le istanze delle varie entità**;
  - accorpamento genitore nei figli: porto attributi del genitore in figlio, solo se a **partecipazione totale** e quando effettuo **poche operazioni alle istanze di quelle entità**;
  - sostituzione con associazioni: unisco le entità figlie al padre con un’associazione, se la generalizzazione è **esclusiva** aggiungo un vincolo di occorrenza che i figli non possono partecipare entrambi, se è **totale** aggiungo un vincolo che devono partecipare
- **partizionamento/accorpamento di entità e associazioni**:

    serva a partizionare/accorpare delle entità:

  - **partizionamento verticale** di entità: partiziona un’entità in una relazione con due entità (impiegato ha dati anagrafici e dati lavorativi);
  - **partizionamento orizzontale** di entità: introduco una generalizzazione che partiziona un’entità in modo che un’entità possa fare determinate azioni rispetto all’altra (utente con premium);
  - **accorpamento** di entità: accorpo due entità in una;
  - **eliminazione attributi multi-valore** (social);
- **scelta degli id**:
  - si predilige scegliere un attributo univoco. Se troppo complesso introduco un surrogato.

### 1.3.2 **Cardinalità**

- molti a molti: creo un’entità;
- uno a molti: da molti va a uno;
- uno a uno: sposto chiave a entità forte;
- ricorsivo: stessa chiave primaria con nomi diversi;
- n-arie: creo un’entità;
- identificazione esterna: la chiave primaria dell’entità associata va nell’entità con identificatore esterno.

## 1.4 DDL

Quindi query di: **create**, **alter**, **drop table**.

Possono esserci valori di default.

Abbiamo i **domini**, come: varchar(), char(), integer, deciamal(), double, date, timestamp(), blob.

Il comando **extract** mi fa estrarre solo un tipo dalla data. 

Si possono creare **domini personalizzati** (create domain *nome* as *tipo_dato*) solo di domini semplici.

### 1.4.1 **Vincoli**

Esistono vincoli **intrarelazionale** (una tabella) e **interrelazionali** (più tabelle).

Vincoli: 

- NOT NULL
- UNIQUE
- PRIMARY KEY
- FOREIGN KEY … REFERENCES (nome attributo dominio REFERENCES tabellaEsterna(attributoEsterno))

> [!IMPORTANT] Vincolo di Integrità Referenziale
>
> Ogni valore in una colonna di una tabella figlia ha un corrispondente valore nella colonna di una tabella padre.

### 1.4.2 ON UPDATE/DELETE

Update:

- cascade: nuovo valore dell’attributo della tabella esterna viene riportato in tutte le corrispondenti righe della tabella interna;
- set null: l’attributo referente sarà null;
- set default: l’attributo referente sarà un valore di default;
- no action: modifica non consentita.

Delete:

- cascade: cancella la chiave esterna della tabella corrispondente;
- set null: la chiave esterna sarà null;
- set default: la chiave esterna sarà un valore di default;
- no action: modifica non consentita.

on update/delete reazione.

Si può assegnare nomi ai vincoli con **constraint**.

**Alter table** modifica la struttura di una tabella.

La clausola **CHECK** serve per verificare che una riga non abbia quel valore.

### 1.4.3 Viste

create view nomeVista as (query)

Serve per **creare** una **query da poter riusare**.

Solo in alcuni casi è possibile andare a modificare i dati presenti in una tabella.

Devo verificare i vincoli, posso usare anche le **CHECK**.

### 1.4.4 **Sequence**

Serve per incrementare un valore di un tot.

Serial parte da zero e incrementa.

**Coalesce** ammette una sequenza di espressioni, e restituisce il primo risultato non nullo.

**Nullif** ammette un’espressione ed un valore costante, se il risultato dell’operazione è uguale alla costante, restituisce null.

## 1.5 DML

Estrazione dati con l’algebra relazionale, grazie all’uso di **select** (DQL), **insert into .., values()**, **update *nome_tabella* set *attributo* = …**, **delete from**, **drop table**.

Si possono fare delle query dentro per inserire valori.

Forma base: select * from tabella;

Abbiamo gli operatori algebrici ($+,\ -,\ *,\ /,\ !,\ @,\ **,\ \%$).

Ci sono diverse funzioni matematiche(abs(x), ceil(x), exp(x), ln(x), pi(), random(), round(x), trunc(x)).

Abbiamo la clausola **WHERE** che ammette espressioni booleane come =, <>, >, <, ≥, ≤.

Esistono anche le clausole **BETWEEN** e **NOT BETWEEN**.

Abbiamo il **LIKE** per confrontare due stringhe (abbiamo % che ci dice che non ci interessa quello che viene dopo/prima).

Esistono gli alias (**AS**) per dare un nome.

La clausola **FROM** ci dice da che tabella iniziamo a estrarre i dati.

La clausola **distinct** prima di un attributo elimina i duplicati.

Abbiamo **is null**/**is not null**.

Abbiamo la clausola **ORDER BY asc/desc**.

### 1.5.1 Join

Esegue un **prodotto cartesiano** in cui vengono mostrati solo i dati che soddisfano le richieste della where.

Tipi:

- **inner join**: join di default, restituisce le righe che soddisfano le condizioni;

    ![InnerJoin](https://prod-files-secure.s3.us-west-2.amazonaws.com/486a026b-e9e0-46cd-a99c-17f428c1a18f/ba1f6847-7300-4e11-a4f6-157a8f5bc264/Untitled.png)

- **natural join**: come la inner join, solo che può essere eseguita solo se gli attributi su cui si applica la condizione hanno lo stesso nome;
- **outer join**:
  - **right join**:

        ![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/486a026b-e9e0-46cd-a99c-17f428c1a18f/119e693d-ffd2-445f-ab24-32aae2b50a55/Untitled.png)

  - **left join**:

        ![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/486a026b-e9e0-46cd-a99c-17f428c1a18f/fd67cec2-a5f2-4a5d-89a8-e6186a318631/Untitled.png)

  - **full join**:

        ![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/486a026b-e9e0-46cd-a99c-17f428c1a18f/7122e976-1bd9-486d-9fae-9dc079495e80/Untitled.png)

- **self join**: eseguo una join sulla stessa tabella.

### 1.5.2 Operatori aggregati

- COUNT(*): conta il numero di righe che restituisce la query, possono usarne anche più di una;
- SUM(attributo): somma il valore contenuto nelle righe della tabella;
- MIN(attributo): restituisce il valore minimo presente nelle righe della tabella;
- GROUP BY: raggruppa le righe secondo delle condizioni, eliminando i duplicati;
- having: come una where ma sui risultati degli operatori aggregati.

### 1.5.3 Operatori insiemistici

Di solito rimuovono i duplicati:

- **union**: query a UNION query b (tutte le righe delle due query senza duplicati, a meno che non metta **ALL**);
- **intersect**: query a INTERSECT query b (righe comuni);
- **except**: query a EXCEPT query b (righe che appartengono ad a ma non in b).

### 1.5.4 Query nidificata

Una query nella condizione del where con dentro un’altra query.

Si usa: where attributo < any (query).

- **any**: predicato soddisfatto almeno in una riga;
- **all**: tutte le righe devono rispettare il predicato
- **in/not in**: se valore presente in un insieme o meno;

Si possono creare anche nella **from** e nella **select**.
