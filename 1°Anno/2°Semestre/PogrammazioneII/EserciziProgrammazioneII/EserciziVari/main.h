/**
 * @file main.h
 *
 * In questo file sono presenti tutte le definizioni dei metodi che ho testato e commentato per essere alla portata di tutti.
 *
 * Ogni qual volta dovesse servire una mano per ricevere delucidazioni o per inserire dei metodi, contattatemi o create una pull request sulla repository.
 *
 * @author Simone Negro, Simone Gattini
 *
 * @copyright 2015 University of Piemonte Orientale, Computer Science Institute
 *
 * I file sono stati creati per poter dare un'occhiata su come vanno eseguiti i metodi per passare l'esame di Programmazione II.
 *
 * Il mio obiettivo è quello di rendere questo esame bello da studiare e comprendere, soprattutto per le persone che, come me, fanno fatica a programmare.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Struttura con dati interi.
 */
struct node
{
    int data;
    struct node *next;
};

/**
 * Struttura con dati in virgola mobile.
 */
struct nodef
{
    float data;
    struct nodef *next;
};

/**
 * Alias della struttura con dati interi.
 */
typedef struct node Node;

/**
 * Alias della struttura con dati in virgola mobile
 */
typedef struct nodef Nodef;

/**
 * Alloca l'area di memoria della dimensione della struttura dati.
 *
 * @return L'allocazione dello spazio in memoria della dimensione della struttura.
 */
Node *crea_nodo();

/**
 * Alloca l'area di memoria della dimensione della struttura dati.
 *
 * @return L'allocazione dello spazio in memoria della dimensione della struttura.
 */
Nodef *crea_nodo_float();

/**
 * Crea una lista i cui valori sono presi dal file passato per parametro.
 *
 * @param head Lista che si vuole popolare.
 * @param fp File da cui leggere i dati.
 */
void crea_lista_da_file(Node **head, FILE *fp);

/**
 * Distrugge la lista, anando a disallocare ogni nodo della lista.
 *
 * @param head Lista che si vuole distruggere.
 */
void distruggi_lista(Node **head);

/**
 * Distrugge la lista, anando a disallocare ogni nodo della lista.
 *
 * @param head Lista che si vuole distruggere.
 */
void distruggi_lista_float(Nodef **head);

/**
 * Stampa ogni nodo della lista.
 *
 * @param head Lista che si vuole visualizzare.
 */
void stampa_lista(Node *head);

/**
 * Ritorna il numero massimo di nodi consecutivi con lo stesso valore.
 *
 * @param head Lista su cui eseguire l'operazione.
 *
 * @return Numero massimo dei nodi consecutivi.
 */
int sequenza_piu_lunga(Node *head);

/**
 * Cancella un nodo in una determinata posizione della lista.
 *
 * @param head Lista su cui cancellare il nodo.
 * @param pos Posizione del nodo da cancellare.
 */
void cancella_nodo_pos(Node **head, int pos);

/**
 * Crea una lista dalle eccedenze delle due liste passate per parametro.
 *
 * @param head1 Prima lista.
 * @param head2 Seconda lista.
 *
 * @return Se le liste sono uguali verrà ritoranto NULL, altrimenti ritorna l'eccedenza della lista più lunga.
 */
Node *crea_lista_da_eccedenze_liste(Node *head1, Node *head2);

/**
 * Cancella tutti i nodi della lista con un determinato valore passato per parametro.
 *
 * @param head Lista su cui cancellare i nodi.
 * @param val Valore del nodo da cancellare.
 */
void cancella_nodo_val_ricorsivo(Node **head, int val);

/**
 * Somma tutti i nodi delle due liste e ritorna la somma con il valore più grande.
 *
 * @param head1 Prima lista.
 * @param head2 Seconda lista.
 * @param somma1 Contiene la somma dei nodi della prima lista. Valore di default: 0.
 * @param somma2 Contiene la somma dei nodi della seconda lista. Valore di default: 0.
 *
 * @return Ritorna la somma maggiore dei nodi della lista.
 */
int somma_nodi_liste_ritorna_somma_max_ricorsiva(Node *head1, Node *head2, int somma1, int somma2);

/**
 * Cancella tutti i nodi della lista con valore multiplo del valore passato per parametro.
 *
 * @param head Lista su cui cancellare i nodi.
 * @param val Divisore del valore dei nodi da cancellare.
 *
 * @return Ritorna il numero di nodi cancellati.
 */
int cancella_nodi_multipli_di_val(Node **head, int val);

/**
 * Controlla se i valori dei nodi delle liste dopo la posizione pos sono uguali.
 *
 * Se le liste sono di dimensione diversa, ritorna 1 se la lista più corta, dal valore pos, è uguale alla lista più lunga.
 *
 * @param head1 Prima lista.
 * @param head2 Seconda lista.
 * @param pos Posizione dopo il quale controllare se i valori dei nodi sono uguali.
 * @param posizione_corrente Posizione che controlla in che posizione della lista mi trovo. Valore di default: 0.
 *
 * @return Ritorna 1 se le liste dopo pos sono uguali, altrimenti ritorna 0.
 */
int liste_uguali_dopo_pos_ricorsiva(Node *head1, Node *head2, int pos, int posizione_corrente);

/**
 * Crea una lista i cui nodi sono la somma dei nodi di due liste.
 *
 * @param head1 Prima lista.
 * @param head2 Seconda lista.
 *
 * @return Se le liste sono vuote, il valore di ritorno sarà NULL; se la prima lista è vuota, ritorno la seconda lista; se la seconda lista è vuota, ritorno la prima lista.
 */
Node *crea_lista_somma_valori_liste(Node *head1, Node *head2);

/**
 * Ritorna la media dei valori dei nodi di una lista.
 *
 * @param head Lista da cui effettuare la media.
 * @param num_nodi Numero di nodi. Valore di default: 0.
 * @param somma Somma dei valori dei nodi.
 *
 * @return Ritorna la media dei valori dei nodi della lista.
 */
double media_valori_nodi_lista_ricorsiva(Node *head, int num_nodi, int somma);

/**
 * Somma pesata del valore dei nodi della lista con valori multipli di val.
 *
 * @param head Lista da cui effettuare la somma pesata.
 * @param val Divisore del valore dei nodi da sommare.
 *
 * @return Ritorna la somma pesata; se la lista è vuota ritorna 0.
 */
int somma_pesata_nodi_multipli_di_val(Node *head, int val);

/**
 * Somma il valore dei nodi di una lista fino alla pos_fine_somma, poi esegure la differenza da pos_fine_somma fino a pos_fine_differenza. pos_fine_somma dev'essere un valore maggiore di pos_fine_differenza.
 *
 * @param head Lista da cui effettuare la somma.
 * @param pos_fine_somma Posizione finale in cui viene eseguita la somma dei valori dei nodi della lista.
 * @param pos_fine_differenza Posizione finale in cui viene eseguita la differenza dei valori dei nodi della lista.
 *
 * @return Ritorna la somma/differenza dei valori dei nodi della lista; se l'intervallo non è valido o la lista è vuota ritorna 0.
 */
int somma_differenza_nodi_in_un_intervallo(Node *head, int pos_fine_somma, int pos_fine_differenza);

/**
 * Conta il numero di volte in cui un numero si presenta tre volte consecutivamente all'interno di una lista.
 *
 * @param head Lista su cui effettuare l'operazione.
 * @param val Valore da cui contare il numero di occorrenze.
 *
 * @return Ritorna il numero di volte in cui i valori dei nodi di una lista si presenta tre volte consecutivamente; altrimento ritorna 0.
 */
int numero_volte_tre_valori_ripetuti_di_fila(Node *head, int val);

/**
 * Duplica tutti i nodi della lista in posizione multipla di pos con valore val.
 *
 * @param head Lista su cui eseguire la duplicazione.
 * @param pos Posizione da controllare se è divisiore.
 * @param val Valore da controllare per l'uguaglianza.
 */
void duplica_nodo_posizione_multipla_valore_uguale(Node **head, int pos, int val);

/**
 * Crea una nuova lista i cui nodi hanno il valore del nodo attuale solo se la somma dei due nodi precedenti è uaugale a quello corrente.
 *
 * @param head Lista su cui eseguire le operazioni.
 *
 * @return Ritorna la lista con i nodi che sono la somma dei due precedenti della lista vecchia; altrimenti ritorna NULL.
 */
Node *crea_lista_somma_nodi_precedenti_uguale_nodo_corrente(Node *head);

/**
 * DA REVISIONARE
 */
// Node *duplicaListaSomma(Node *head1, Node *head2, int n, int m);

/**
 * Elimina tutti i nodi della prima lista solo se la somma dei nodi tra la prima e la seconda lista è multipla di un valore.
 *
 * @param head1 Lista da cui vanno eliminati i nodi.
 * @param head2 Lista con cui effettuare la somma.
 * @param val Valore di verifica per vedere se la somma dei due nodi è multipla di quest'ultimo.
 */
void elimina_nodi_somma_nodi_multipli_val(Node **head1, Node *head2, int val);

/**
 * Controlla il numero massimo di occorrenze consecutive con numeri maggiori di val all'interno di un valore.
 *
 * @param head Lista su cui effettuare il controllo.
 * @param val Valore di controllo per verificare se un numero è maggiore di val.
 *
 * @return Ritorna il numero massimo di occorrenze consecutive con numeri maggiori di val; altrimenti restituisce 0.
 */
int numero_massimo_occorrenze_consecutive_maggiori_di_val(Node *head, int val);

/**
 * DA REVISIONARE
 */
// int occorrenze_val_max_ricorsiva(Node *head, int max);

/**
 * Controlla se una lista è strettamente crescente.
 *
 * @param head Lista su cui effettuare l'operazione.
 *
 * @return Ritorna 1 se la lista è strettamente crescente; altrimenti ritorna 0.
 */
int lista_strettamente_crescente_ricorsiva(Node *head);

/**
 * Conta il numero di nodi con lo stesso valore nella stessa posizione di due liste.
 *
 * @param head1 Prima lista.
 * @param head2 Seconda lista.
 *
 * @return Ritorna il numero di nodi con lo stesso valore nella stessa posizione; altrimenti ritorna 0.
 */
int conta_nodi_duplicati_liste_ricorsiva(Node *head1, Node *head2);

/**
 * Crea una lista con i valori che sono la differenza tra i nodi della lista che sono nella stessa posizione e sono divisibili per pos.
 *
 * @param head1 Prima lista.
 * @param head2 Seconda lista.
 * @param pos Posizione della lista. Valore di default: 1.
 *
 * @return Ritorna la nuova lista; se le liste sono vuote ritorna NULL.
 */
Node *crea_lista_pos_multiple_di_differenza_nodi_ricorsiva(Node *head1, Node *head2, int pos);

/**
 * Ritorna il prodotto massimo tra due valori all'interno di un array.
 *
 * @param arr Array su cui eseguire l'operazione.
 * @param size Dimensione dell'array.
 *
 * @return Ritorna il prodotto massimo.
 */
int prodotto_massimo_due_valori_array(int arr[], int size);

/**
 * Media EMA con un array.
 *
 * @param arr Array con cui calcolare la media EMA.
 * @param alpha Valore compreso tra 0.1 e 0.9
 * @param pos Posizione dell'array.
 *
 * @return Ritorna il primo valore dell'array.
 */
float ema_array_ricorsiva(float arr[], float alpha, int pos);

/**
 * Ritorna la sequenza massima di un valore di un nodo all'interno di due liste.
 *
 * @param head1 Prima lista.
 * @param head2 Seconda lista.
 *
 * @return Ritorna la sequenza massima.
 */
int sequenza_max_due_liste(Node *head1, Node *head2);

/**
 * Cancella i nodi della lista che hanno il valore divisibile per val e la posizione è divisibile per pos.
 *
 * @param head Lista su cui eseguire la cancellazione.
 * @param pos Posizione di controllo per verificare se la posizione del nodo è multiplo di pos.
 * @param val Valore di controllo per verificare se il valore di un nodo è multiplo di val.
 * @param index Posizione attuale. Valore di default: 1.
 *
 * @return Ritorna la lista con i nodi cancellati.
 */
Node *cancella_nodi_pos_multipli_val_divisibile_ricorsiva(Node *head, int pos, int val, int index);

/**
 * Cancella tutti i nodi della lista con un valore passato per parametro.
 *
 * @param head Lista su cui eseguire la cancellazione.
 * @param val Valore dei nodi da cancellare.
 *
 * @return Ritorna la lista con i nodi cancellati.
 */
Node *cancella_nodi_val_ricorsiva(Node *head, int val);

/**
 * Cancella tutti i nodi della lista con un valore divisibile per il valore passato per parametro.
 *
 * @param head Lista su cui eseguire la cancellazione.
 * @param val Valore dei nodi divisibili da cancellare.
 *
 * @return Ritorna la lista con i nodi cancellati.
 */
Node *cancella_nodi_divisibili_val_ricorsiva(Node *head, int val);

/**
 * Controlla qual è la parola che presenta più volte un carattere, ritornando quella parola.
 *
 * @param parole Array di parole.
 * @param car Carattere di controllo.
 * @param caratteri Lunghezza massima delle parole.
 *
 * @return Ritorna la parola con il massimo numero di occorrenze di un carattere.
 */
char *max_occorrenze_car_parole(char **parole, char car, int caratteri);

/**
 * Elimina i nodi che sono moltiplicatori il cui risultato del prodotto è multiplo del valore passato per parametro.
 *
 * @param head Lista su cui eseguire la cancellazione.
 * @param val Valore di controllo per vedere se il prodotto è multiplo di esso.
 */
void elimina_moltiplicatore_se_prodotto_multiplo_val(Node **head, int val);

/**
 * Inverte l'ordine della lista.
 * 
 * @param head Lista da invertire.
*/
void inverti_lista(Node **head);

/**
 * Controlla qual è la parola che contiene più caratteri.
 * 
 * @param parole Array di parole.
 * @param size Dimensione massima della parola.
 * 
 * @return Ritorna la parola più lunga.
*/
char *parola_piu_lunga(char **parole, int size);

/**
 * Somma tutti i numeri dispari.
 * 
 * @param val Numero da sommare, in caso sia dispari.
 * 
 * @return Ritorna la somma di tutti i valori dispari; altrimenti ritorna 0.
*/
int somma_dispari_val_ricorsiva(int val);

/**
 * Unisce due liste in una terza lista solo dei nodi che sono in posizione multipla di un valore passato per parametro. In caso una lista finisca, si presuma che il valore sia dei nodi mancanti sia 0.
 * 
 * @param head1 Prima lista.
 * @param head2 Seconda lista.
 * @param pos Posizione su cui verificare se la posizione è multipla di quest'ultima.
 * 
 * @return Ritorna una lista che ha i nodi delle altre due in posizione multipla.
*/
Node *unisci_liste_pos_multiple(Node *head1, Node *head2, int pos);

/**
 * Crea una lista i cui valori sono presi dal file passato per parametro.
 *
 * @param head Lista che si vuole popolare.
 * @param fp File da cui leggere i dati.
 */
void crea_lista_file_float(Nodef **head, FILE *fp);

/**
 * Stampa ogni nodo della lista.
 *
 * @param head Lista che si vuole visualizzare.
 */
void stampa_lista_float(Nodef *head);

/**
 * Aggiunge un nodo tra ogni coppia di nodi della lista contente la medie dei due nodi precedenti.
 * 
 * @param head Lista da andare a modificare.
 * 
 * @return Ritorna la lista modificata.
*/
Nodef *riempi_lista__media_float_ricorsiva(Nodef *head);

/**
 * Conta il numero di modi in cui è possibile salire una scala con tot gradidini, facendo un passo o due passi alla volta per gradino.
 * 
 * @param gradini Numero di gradini.
 * 
 * @return Ritorna il numero di modi possibili su cui salire la scala.
*/
int modi_salita_scala_ricorsiva(int gradini);