# Teoria Java

Possibili domande che la Docente potrebbe proporre all'esame.

## 1. Modificatori di visibilità

*Modificatori di visibilità per variabili e metodi di una classe.*

*Se una variabile/metodo è dichiarato: public, private, protected oppure non ha modificatori di visibilità dov'è visibile. Fare un esempio di una porzione di codice corretto e scorretto.*

I tipi di modificatori sono:

- **public**: variabili/metodi visibili ovunque: sia all’interno della classe che al di fuori di essa;
- **private**: variabili/metodi visibili sono all’interno della propria classe;
- **protected**: variabili/metodi visibili all’interno della stessa classe e nelle sue classi derivate (sottoclassi) nello stesso package;
- **senza modificatori** di visibilità: variabili/metodi visibili all’interno della stessa classe e nelle classe dello stesso package.

Esempio corretto:

```java
public class MyClass {
    public int publicVariable;
    private int privateVariable;
    protected int protectedVariable;
    int packagePrivateVariable; // senza modificatori
}

public class AnotherClass {
    public void someMethod() {
        MyClass m = new MyClass();
        int x = m.publicVariable; // accesso consentito
        int y = m.packagePrivateVariable; // accesso consentito
    }
}
```

Esempio scorretto:

```java
public class MyClass {
    private int privateVariable;
}

public class AnotherClass {
    public void someMethod() {
        MyClass m = new MyClass();
        int x = m.privateVariable; // accesso non consentito
    }
}
```

## 2. Differenza tra variabile statica e istanza

*Differenza tra variabili/metodi statici e di istanza. Fare un esempio.*

Differenza:

- variabili/metodi **statici** appartengono alla stessa classe, non ad una specifica istanza e possono essere chiamati direttamente sulla classe senza creare un oggetto;
- variabili/metodi di **istanza** appartengono ad un’istanza specifica di una classe e richiedono un oggetto per essere accessibili.

```java
public class MyClass {
    public static int staticVariable; // variabile statica
    public int instanceVariable; // variabile di istanza

    public static void staticMethod() { // metodo statico
        System.out.println("Metodo statico");
    }

    public void instanceMethod() { // metodo di istanza
        System.out.println("Metodo di istanza");
    }
}

public class Main {
    public static void main(String[] args) {
        MyClass m = new MyClass();
        m.staticMethod(); // chiamata metodo statico
        int x = m.staticVariable; // accesso variabile statica

        m.instanceMethod(); // chiamata metodo di istanza
        int y = m.instanceVariable; // accesso variabile di istanza
    }
}
```

## 3. Differenza tra classe astratta e interfaccia

*Differenza tra una classe astratta ed un’interfaccia. Quante interfacce può implementare una classe?*

*Fare un esempio di classe astratta e di un’interfaccia.*

La differenza è:

- una classe **astratta** è una classe che **non** può essere **istanziata direttamente** e può contenere implementazioni di metodi, mentre può anche avere dei metodi astratti che le sottoclassi devono implementare;

    ```java
    public abstract class Shape {
        public abstract double area(); // metodo astratto
    }
    
    public class Circle extends Shape {
        private double radius;
    
        public Circle(double radius) {
            this.radius = radius;
        }
    
        @Override
        public double area() {
            return Math.PI * radius * radius;
        }
    }
    ```

- un’**interfaccia** è una **collezione di metodi astratti** che una classe può implementare. Una classe può implementare **più di un’interfaccia**,  mentre può estendere una sola classe astratta.

    ```java
    public interface Drawable {
        void draw(); // metodo astratto
    }
    
    public class Circle implements Drawable {
        private double radius;
    
        public Circle(double radius) {
            this.radius = radius;
        }
    
        @Override
        public void draw() {
            // implementazione del metodo draw per Circle
        }
    }
    ```

## 4. Possibili usi interface

*Dare alcuni possibili usi delle interfacce. Fare un esempio interfaccia e di una classe che la implementa.*

- Le **interfacce** consentono di definire contratti che le classi devono seguire**.**

Alcuni possibili **usi** includono la creazione di interfacce per **definire comportamenti comuni** che **diverse classi** possono **implementare** in modo **diverso**, il raggruppamento di classi in base alle funzionalità comuni o la creazione di callback per eventi.

```java
public interface Printable {
    void print();
}

public class Printer implements Printable {
    @Override
    public void print() {
        // implementazione del metodo
    }
}
```

## 5. Differenza tra classe e oggetto

*Differenza tra una classe ed un oggetto. Cos’è la metaclasse di una classe?*

Differenza:

- una **classe** è un modello o prototipo che definisce la struttura e il comportamento di un oggetto;
- un **oggetto** è un’istanza di una classe. Esso è un’entità concrea che ha attributi (variabili di istanza) e comportamenti (metodi) basati sulla definizione fornita dalla classe.

Una **metaclasse** è una classe le cui istanze sono a loro volta classi.

## 6. Cos’è un costruttore

*Cos’è un costruttore. Esempio di una classe con più di un costruttore. Come avviene la creazione di un oggetto e quando viene eseguito il costruttore.*

Un **costruttore** è un metodo speciale di una classe che viene chiamato quando si crea un **nuovo oggetto della classe**. Ha lo stesso nome della classe e può essere usato per inizializzare gli attributi dell’oggetto.

Quando si crea un oggetto, la **new** invoca un costruttore su di esso. I costruttori completano l’inizializzazione di un oggetto, ad esempio inizializzano le variabili d’istanza. Hanno una sintassi simile ai metodi, ma id = id classe e non hanno il tipo del risultato.

```java
public class Person {
    private String name;
    private int age

    public Person() { // costruttore senza argomenti
        name = "Jhon Doe";
        age = 30;
    }

    public Person(String name, int age) { // costruttore con argomenti 
        this.name = name;
        this.age = age;
    }
}

Person p1 = new Person();
Person p2 = new Persona("Jhon Doe", 30);
```

## 7. Metavariabili this e super

*Che significato hanno le metavariabili this e super in un metodo.*

- **this** si riferisce all’oggetto corrente all’interno di una classe e può essere utilizzato per accedere agli attributi e ai metodi dell’oggetto stesso;
- **super** si riferisce alla superclasse dell’oggetto corrente e può essere utilizzato per accedere agli attributi e ai metodi ereditati dalla superclasse.

## 8. Metavariabili nel costruttore

*Che significato hanno this(...) e super(...) in un costruttore.*

- **this(…)** chiama un altro costruttore della stessa classe;
- **super(…)** chiama il costruttore della superclasse.

Sono utilizzati per inizializzare un oggetto in modo appropriato in base ai diversi scenari di creazione.

## 9. Tipi primitivi

*Quali sono i tipi primitivi del linguaggio Java (elencarne 4)? Le stringhe sono tipi primitivi? Gli array sono primitivi? Quale è la differenza i fra tipi primitivi e gli altri tipi.*

Tipi primitivi in Java (4 esempi): **int**, **double**, **boolean**, **char**.

Le **stringhe** **non** sono **tipi primitivi**; sono oggetti della classe String.

Gli **array non** sono **primitivi**; sono oggetti che contengono elementi di un determinato tipo.

La **differenza** principale tra tipi primitivi e altri tipi è che i tipi primitivi sono **dati direttamente memorizzati nella memoria**, mentre gli altri tipi sono **oggetti** che contengono dati e metodi.

## 10. Classe interna

*Cos'è una classe interna? Quali tipi di classe interna si possono avere. Fare un esempio.*

Una classe interna è una **classe** definita all'**interno di un'altra classe**.

Ci sono quattro tipi di classi interne in Java:

- interna **non statica** (inner class);
- interna **statica** (static nested class);
- **locale** (local class);
- **anonima** (anonymous class).

```java
public class Outer {
    private int x;

    public class Inner {
        public void printX() {
            System.out.println(x);
        }
    }
}
```

## 11. Override e overloading

*Che cos’è l'override di metodi. Esiste override di costruttori.*

*Che cos’è l'overloading di metodi. Esiste overloading di costruttori.*

- l'**override** di un metodo consente a una classe derivata di fornire una nuova implementazione per un metodo ereditato dalla sua superclasse. I costruttori **non** possono essere sovrascritti;
- l'**overloading** di metodi consente di definire più metodi con lo stesso nome in una classe, ma con firme diverse (parametri diversi). I costruttori **possono** essere sovraccaricati.

## 12. Parametri di tipo

*A cosa servono i parametri di tipo e quali costrutti Java possono avere parametri di tipo. Fare un esempio.*

I **parametri di tipo** (generici) consentono di creare classi, interfacce e metodi che **operano** **su tipi** specifici **senza specificare il tipo** effettivo in anticipo. Sono ampiamente utilizzati nelle collezioni Java come ArrayList, HashMap, ecc.

```java
public class GenericClass<T> {
    private T data;

    public GenericClass(T data) {
        this.data = data;
    }

    public T getData() {
        return data;
    }
}
```

## 13. Polimorfismo

*A cosa ci si riferisce quando si parla di polimorfismo di un metodo?
Quali forme di polimorfismo si possono avere in Java.*

Il **polimorfismo** consente agli **oggetti** di **classi diverse** di **rispondere allo stesso metodo** in modo diverso. In Java, il polimorfismo può essere raggiunto attraverso l'**override** dei metodi.

Forme di polimorfismo:

- di **sottotipo** (subtyping) attraverso l'ereditarietà;
- di **parametri** attraverso l'uso di argomenti polimorfici.

## 14. Try/catch

*A cosa serve il costrutto try/catch? Fare un esempio.*

Il costrutto **try/catch** viene **utilizzato per gestire eccezioni** in Java.

Il **codice all'interno** del blocco **try** è **monitorato** per eccezioni, e **se** viene **generata** un'**eccezione**, il codice all'interno del blocco **catch** associato a quella eccezione viene eseguito per gestirla.

```java
try {
    int result = 10 / 0; // codice che potrebbe generare un eccezione
} catch (ArithmeticException e) {
    System.out.println("Errore");
}
```

## 15. Eccezione

*Cos’è un’eccezione? come si dichiara? come si solleva. Fare un esempio.*

Un'**eccezione** è un **oggetto** che **rappresenta** un **errore** o una situazione eccezionale durante l'esecuzione di un programma. In Java, le eccezioni possono essere dichiarate, lanciate e catturate.

```java
public void myMethod() throws MyException {
    // ...
    if(/* condizione di errore */) {
        throw new MyException("Messaggio di errore");
    }
    // ...
}
```

## 16. Super-classe

*I metodi e gli attributi di una super-classe sono sempre disponibili alle sue classi derivate? (motivare la risposta)*.

I **metodi** e gli **attributi** di una **superclasse non** sono **sempre disponibili** alle sue classi derivate. La **visibilità** (pubblico, privato, protetto) e l'**overriding** dei metodi determinano se i metodi della superclasse sono accessibili o meno nelle sottoclassi.

## 17. Ereditarietà

*Che cos’è l'ereditarietà. Che vantaggi porta l’utilizzo del meccanismo dell’ereditarietà nella definizione delle classi?*

L'**ereditarietà** è un meccanismo in programmazione orientata agli oggetti che consente a una classe di ereditare attributi e metodi da una classe madre o superclasse. Vantaggi:

- **riuso del codice**: evita la duplicazione di codice.
- **estendibilità**: permette di aggiungere nuove funzionalità alle classi esistenti.

## 18. Cast

*Differenza fra il cast dei tipi primitivi e quello dei tipi riferimento.*

Differenza dei cast dei tipi:

- **primitivi** è la conversione di un tipo primitivo in un altro tipo primitivo compatibile. Ad esempio, da int a double;
- **di riferimento** è la conversione di un tipo di riferimento in un altro tipo di riferimento compatibile o tra una classe e una sua superclasse o sottoclasse.

## 19. Wrapper

*Cosa sono le classi wrapper (involucro) e a cosa servono.*

Le classi **wrapper** (o classi di involucro) in Java sono classi che forniscono un oggetto wrapper per i tipi primitivi. Consentono di **trattare i tipi primitivi come oggetti**. Alcune classi wrapper includono Integer, Double, Boolean, Character, ecc. Sono utili quando è necessario lavorare con collezioni o API che richiedono oggetti anziché tipi primitivi.

## 20. Differenze tra Array e ArrayList

*Quali sono le differenze fra arrays e oggetti di tipi ArrayList? Considera ad esempio le seguenti 2 dichiarazioni:*

- *int array[];*
- *ArrayList\<Integer> arrayList.*

Gli **array** in Java sono strutture di dati fisse con una **lunghezza predefinita**, mentre gli oggetti di tipo **ArrayList** sono **dinamici** e possono essere ridimensionati in modo automatico;

Gli **array** possono **contenere** **tipi primitivi** o **oggetti**, mentre gli **ArrayList** possono contenere **solo oggetti**;

Gli **ArrayList** forniscono metodi convenienti per l'aggiunta, la rimozione e la gestione degli elementi, mentre gli array richiedono più lavoro manuale per queste operazioni.

```java
int[] array = new int[10]; // array con lunghezza fissa
ArrayList<Integer> arrayList = new ArrayList<>(); // ArrayList dinamico
```

## 21. Thread

*Che cos’è un thread in Java. Come si crea un nuovo thread in Java, e come gli si assegnano delle operazioni da eseguire?*

Un **thread** è un **processo leggero** che esegue operazioni in modo concorrente all'interno di un programma Java. Si possono creare nuovi thread per eseguire operazioni parallele o asincrone.

Il thread è il modello di esecuzione del programma con un unico flusso. Esiste una **classe** di **sistema** chiama **Thread** che serve per gestire i thread in java. Un nuovo thread viene creato tramite un’espressione **new**. Per attivare un thread è necessario il metodo start().

```java
Thread myThread = new Thread(new Runnable() {
    public void run() {
        // codice da eseguire nel thread
    }
});

myThread.start(); // avvia il thread
```

## 22. Sincronizzazione

*Quali sono i meccanismi di sincronizzazione fra thread.*

Java fornisce meccanismi di sincronizzazione come il blocco **synchronized**, i monitor e i metodi sincronizzati per gestire la concorrenza tra thread. Questi meccanismi impediscono l'accesso
simultaneo a risorse condivise.

## 23. Oggetto condiviso

*Come possono 2 thread accedere ad un oggetto condiviso senza interferire fra loro?*

Per consentire a due **thread** di accedere a un oggetto condiviso senza interferire tra loro, è necessario utilizzare il blocco **synchronized** o altri meccanismi di sincronizzazione per proteggere l'accesso simultaneo.

```java
public synchronized void metodoCondiviso() {
    // codice sincronizzato
}
```

## 24. Wait e notify

*Cosa fanno i metodi "wait" e "notify" e in quale classe sono definiti?*

I metodi wait e notify sono utilizzati per la sincronizzazione tra thread. Sono definiti nella classe Object.

- **wait** viene utilizzato da un thread per rilasciare il blocco e aspettare fino a quando un altro thread chiama notify o notifyAll sull'oggetto;
- **notify** viene utilizzato per svegliare uno dei thread in attesa che l'oggetto chiami wait.
