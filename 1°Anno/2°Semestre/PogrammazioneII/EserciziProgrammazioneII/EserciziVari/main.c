/**
 * @file main.c
 *
 * In questo file sono presenti tutte i metodi che ho testato e commentato per essere alla portata di tutti.
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

#include "main.h"

int main()
{
    // Dichiarazioni liste intere
    Node *head1 = NULL, *head2 = NULL, *head3 = NULL;

    // Dichiarazione lista in virgola mobile
    Nodef *headf = NULL;

    // DA SCOMMENTARE PER TESTARE METODI CON ARRAY
    /*
    Dichiarazione array di interi
    int arr[] = {5, 4, 2, -6, -8, 9};

    // Dichiarazione array in virgola mobile
    float arr_float[] = {2.4, 5.1, 0.2, 7.8, 10.0, 0.9};

    // Dichiarazione matrice di parole
    char *parole[] = {"Carlo", "Piergiovanni", "Luca", "Maurizio"};

    // Dimensione dell'array
    int size_arr = sizeof(arr_float) / sizeof(int);

    // Dimensione della parola
    int len_parola = sizeof(parole) / sizeof(parole[0]);
    */

    // Apertura file in lettura
    FILE *fp = fopen("valori_interi.txt", "r");

    // Creazioni liste
    crea_lista_da_file(&head1, fp);
    crea_lista_da_file(&head2, fp);

    // Chiusura del file
    fclose(fp);

    // Apertura file in lettura
    FILE *ffp = fopen("valori_virgola_mobile.txt", "r");

    // Creazione lista in virgola mobile
    crea_lista_file_float(&headf, ffp);

    // Chiusura del file
    fclose(ffp);

    // Stampa le liste popolate
    stampa_lista(head1);
    stampa_lista(head2);

    // Distruzione liste intere
    distruggi_lista(&head1);
    distruggi_lista(&head2);
    distruggi_lista(&head3);

    // Distruzione lista in virgola mobile
    distruggi_lista_float(&headf);

    return 0;
}

Node *crea_nodo()
{
    Node *temp = malloc(sizeof(Node));

    if (temp == NULL)
    {
        perror("Errore");
        return NULL;
    }

    return temp;
}

Nodef *crea_nodo_float()
{
    Nodef *temp = malloc(sizeof(Nodef));

    if (temp == NULL)
    {
        perror("Errore");
        return NULL;
    }

    return temp;
}

void crea_lista_da_file(Node **head, FILE *fp)
{
    int aus = 0;
    Node *tail = NULL;

    while (fscanf(fp, "%d", &aus) != EOF && aus != -1)
    {
        Node *temp = crea_nodo();

        temp->data = aus;
        temp->next = NULL;

        if (*head == NULL)
        {
            *head = temp;
            tail = *head;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
}

void distruggi_lista(Node **head)
{
    while (*head != NULL)
    {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    *head = NULL;
}

void distruggi_lista_float(Nodef **head)
{
    while (*head != NULL)
    {
        Nodef *temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    *head = NULL;
}

void stampa_lista(Node *head)
{
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int sequenza_piu_lunga(Node *head)
{
    if (head == NULL)
        return 0;

    int len = 0, cont = 1, aus = head->data;

    head = head->next;

    while (head != NULL)
    {
        if (head->data == aus)
            cont++;

        else
        {
            if (cont > len)
                len = cont;

            aus = head->data;
            cont = 1;
        }

        head = head->next;
    }

    if (cont > len)
        len = cont;

    return len;
}

void cancella_nodo_pos(Node **head, int pos)
{
    if (*head == NULL)
        return;

    int index = 1;
    Node *temp = *head, *prec = NULL;

    while (temp != NULL && index != pos)
    {
        prec = temp;
        temp = temp->next;
        index++;
    }

    if (index == pos)
    {
        if (prec == NULL)
            *head = (*head)->next;
        else
            prec->next = temp->next;

        free(temp);
    }
}

Node *crea_lista_da_eccedenze_liste(Node *head1, Node *head2)
{
    if (head1 == NULL && head2 == NULL)
        return NULL;

    Node *head3 = NULL, *tail = NULL;

    while (head1 != NULL || head2 != NULL)
    {
        Node *temp = crea_nodo();

        if (head1 == NULL)
        {
            temp->data = head2->data;
            temp->next = NULL;

            if (head3 == NULL)
            {
                head3 = temp;
                tail = head3;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }

            head2 = head2->next;
        }
        else if (head2 == NULL)
        {
            temp->data = head1->data;
            temp->next = NULL;

            if (head3 == NULL)
            {
                head3 = temp;
                tail = head3;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }

            head1 = head1->next;
        }
        else
        {
            head1 = head1->next;
            head2 = head2->next;
        }
    }

    return head3;
}

void cancella_nodo_val_ricorsivo(Node **head, int val)
{
    if (*head != NULL)
    {
        if ((*head)->data == val)
        {
            Node *temp = *head;
            *head = (*head)->next;
            free(temp);
            cancella_nodo_val_ricorsivo(head, val);
        }
        cancella_nodo_val_ricorsivo(&(*head)->next, val);
    }
}

int somma_nodi_liste_ritorna_somma_max_ricorsiva(Node *head1, Node *head2, int somma1, int somma2)
{
    if (head1 == NULL && head2 == NULL)
    {
        if (somma1 > somma2)
            return somma1;

        return somma2;
    }
    if (head1 != NULL)
    {
        somma1 += head1->data;
        return somma_nodi_liste_ritorna_somma_max_ricorsiva(head1->next, head2, somma1, somma2);
    }
    if (head2 != NULL)
    {
        somma2 += head2->data;
        return somma_nodi_liste_ritorna_somma_max_ricorsiva(head1, head2->next, somma1, somma2);
    }

    return 0;
}

int cancella_nodi_multipli_di_val(Node **head, int val)
{
    if (*head == NULL)
        return 0;

    Node *aus = *head, *prec = NULL;
    int cont = 0;

    while (aus != NULL)
    {
        if (aus->data % val == 0)
        {
            if (prec == NULL)
            {
                *head = (*head)->next;
                free(aus);
                aus = *head;
                prec = NULL;
            }
            else
            {
                Node *temp = aus;
                prec->next = aus->next;
                aus = aus->next;
                free(temp);
            }
            cont++;
        }
        else
        {
            prec = aus;
            aus = aus->next;
        }
    }

    return cont;
}

int liste_uguali_dopo_pos_ricorsiva(Node *head1, Node *head2, int pos, int posizione_corrente)
{
    if (head1 == NULL || head2 == NULL)
        return 1;

    if (posizione_corrente < pos || head1->data == head2->data)
        return liste_uguali_dopo_pos_ricorsiva(head1->next, head2->next, pos, ++posizione_corrente);

    return 0;
}

Node *crea_lista_somma_valori_liste(Node *head1, Node *head2)
{
    if (head1 == NULL && head2 == NULL)
        return NULL;
    else if (head1 == NULL)
        return head2;
    else if (head2 == NULL)
        return head1;

    Node *head3 = NULL, *aus = NULL;

    while (head1 != NULL || head2 != NULL)
    {
        if (head1 != NULL && head2 != NULL)
        {
            Node *temp = crea_nodo();

            temp->data = head1->data + head2->data;
            temp->next = NULL;

            if (head3 == NULL)
            {
                head3 = temp;
                aus = head3;
            }
            else
            {
                aus->next = temp;
                aus = temp;
            }

            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1 == NULL)
        {
            aus->next = head2;
            aus = head2;
            head2 = head2->next;
        }
        else if (head2 == NULL)
        {
            aus->next = head1;
            aus = head1;
            head1 = head1->next;
        }
    }

    return head3;
}

double media_valori_nodi_lista_ricorsiva(Node *head, int num_nodi, int somma)
{
    if (head == NULL)
        return (double)somma / num_nodi;

    somma += head->data;
    return media_valori_nodi_lista_ricorsiva(head->next, ++num_nodi, somma);
}

int somma_pesata_nodi_multipli_di_val(Node *head, int val)
{
    if (head == NULL)
        return 0;

    int somma = 0, pos = 1;

    while (head != NULL)
    {
        if (pos % val == 0)
            somma += head->data * pos;

        pos++;
        head = head->next;
    }

    return somma;
}

int somma_differenza_nodi_in_un_intervallo(Node *head, int pos_fine_somma, int pos_fine_differenza)
{
    if (pos_fine_differenza < pos_fine_somma || head == NULL)
        return 0;

    int somma = 0, pos = 1;

    while (head != NULL)
    {
        if (pos <= pos_fine_somma)
            somma += head->data;
        else if (pos > pos_fine_somma && pos <= pos_fine_differenza)
            somma -= head->data;

        pos++;
        head = head->next;
    }

    return somma;
}

int numero_volte_tre_valori_ripetuti_di_fila(Node *head, int val)
{
    if (head == NULL)
        return 0;

    int cont = 0, aus = 0;

    while (head != NULL)
    {
        if (head->data == val)
        {
            aus++;
            if (aus > 3)
            {
                cont++;
                aus--;
            }
        }
        else
        {
            if (aus == 3)
            {
                cont++;
                aus = 0;
            }

            aus = 0;
        }

        head = head->next;
    }

    if (aus == 3)
    {
        cont++;
        aus = 0;
    }

    return cont;
}

void duplica_nodo_posizione_multipla_valore_uguale(Node **head, int pos, int val)
{
    if (*head == NULL)
        return;

    Node *tail = *head;
    int index = 1;

    while (tail != NULL)
    {
        if (index % pos == 0 && tail->data == val)
        {
            Node *temp = crea_nodo();

            temp->data = tail->data;
            temp->next = tail->next;
            tail->next = temp;
            tail = temp;
        }

        index++;
        tail = tail->next;
    }
}

Node *crea_lista_somma_nodi_precedenti_uguale_nodo_corrente(Node *head)
{
    if (head == NULL)
        return NULL;
    else if (head->next == NULL)
        return NULL;
    else if (head->next->next == NULL)
        return NULL;

    Node *prec = head, *prec1 = head->next, *head1 = NULL, *tail = NULL;
    head = head->next->next;

    while (head != NULL)
    {
        if (prec->data + prec1->data == head->data)
        {
            Node *temp = crea_nodo();
            temp->data = head->data;
            temp->next = NULL;

            if (head1 == NULL)
            {
                head1 = temp;
                tail = head1;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
        }
        prec = prec1;
        prec1 = head;
        head = head->next;
    }

    return head1;
}
/* DA CONTROLLARE
Node *duplicaListaSomma(Node *head1, Node *head2, int n, int m)
{
    if (head1 == NULL && head2 == NULL)
        return NULL;
    else if (head1 == NULL)
        return head2;
    else if (head2 == NULL)
        return head1;

    Node *head3 = NULL, *aus = NULL;
    int pos = 1;

    while (head1 != NULL || head2 != NULL)
    {
        Node *temp = crea_nodo();
        if (pos <= n && head1 != NULL)
        {
            temp->data = head1->data;
            temp->next = NULL;

            if (head3 == NULL)
            {
                head3 = temp;
                aus = head3;
            }
            else
            {
                aus->next = temp;
                aus = temp;
            }
        }
        else if (pos > n && pos < m)
        {
            if (head1 == NULL)
            {
                temp->data = head2->data;
            }
            else
            {
                temp->data = head1->data + head2->data;
            }
            temp->next = NULL;

            if (head3 == NULL)
            {
                head3 = temp;
                aus = head3;
            }
            else
            {
                aus->next = temp;
                aus = temp;
            }
        }
        else
        {
            temp->data = head2->data;
            temp->next = NULL;

            if (head3 == NULL)
            {
                head3 = temp;
                aus = head3;
            }
            else
            {
                aus->next = temp;
                aus = temp;
            }
        }
        if (head1 != NULL)
        {
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            head2 = head2->next;
        }
        pos++;
    }

    return head3;
}*/

void elimina_nodi_somma_nodi_multipli_val(Node **head1, Node *head2, int val)
{
    if (*head1 == NULL && head2 == NULL)
        return;

    Node *temp = *head1, *prec = NULL;

    while (temp != NULL)
    {
        if ((head2 != NULL && (temp->data + head2->data) % val == 0) || (head2 == NULL && temp->data % val == 0))
        {
            if (prec == NULL)
            {
                *head1 = (*head1)->next;
                free(temp);
                temp = *head1;
            }
            else
            {
                prec->next = temp->next;
                free(temp);
                temp = prec->next;
            }
        }
        else
        {
            prec = temp;
            temp = temp->next;
        }

        if (head2 != NULL)
            head2 = head2->next;
    }
}

int numero_massimo_occorrenze_consecutive_maggiori_di_val(Node *head, int val)
{
    if (head == NULL)
        return 0;

    int len = 0, cont = 0, aus = -1;

    while (head != NULL)
    {
        if (aus == -1 && head->data > val)
        {
            aus = head->data;
            cont++;
        }
        else if (head->data == aus && aus != -1)
            cont++;
        else if (head->data != aus && head->data > val)
        {
            if (cont > len)
                len = cont;

            cont = 0;
            aus = head->data;
            cont++;
        }
        else
        {
            if (cont > len)
            {
                len = cont;
                cont = 0;
                aus = -1;
            }
        }

        head = head->next;
    }

    if (cont > len)
        len = cont;

    return len;
}

/* DA CONTROLLARE
int occorrenze_val_max_ricorsiva(Node *head, int max)
{
    if (head == NULL)
        return 0;

    if (head->data > max)
    {
        max = head->data;
        return 1 + occorrenze_val_max_ricorsiva(head->next, max);
    }

    return 1 - occorrenze_val_max_ricorsiva(head->next, max);
}*/

int lista_strettamente_crescente_ricorsiva(Node *head)
{
    if (head == NULL || head->next == NULL)
        return 1;

    if (head->data > head->next->data)
        return 0;

    return lista_strettamente_crescente_ricorsiva(head->next);
}

int conta_nodi_duplicati_liste_ricorsiva(Node *head1, Node *head2)
{
    if (head1 == NULL || head2 == NULL)
        return 0;

    if (head1->data == head2->data)
        return 1 + conta_nodi_duplicati_liste_ricorsiva(head1->next, head2->next);

    return 0 + conta_nodi_duplicati_liste_ricorsiva(head1->next, head2->next);
}

Node *crea_lista_pos_multiple_di_differenza_nodi_ricorsiva(Node *head1, Node *head2, int pos)
{
    if (head1 == NULL || head2 == NULL)
        return NULL;

    Node *temp = crea_nodo();
    int aus = head1->data - head2->data;

    if (aus % pos == 0)
    {
        temp->data = aus;
        temp->next = crea_lista_pos_multiple_di_differenza_nodi_ricorsiva(head1->next, head2->next, ++pos);
        return temp;
    }

    return crea_lista_pos_multiple_di_differenza_nodi_ricorsiva(head1->next, head2->next, ++pos);
}

int prodotto_massimo_due_valori_array(int arr[], int size)
{
    if (size == 0)
        return 0;

    int maxProd = 0, prec = arr[0], aus = 0;

    for (int i = 1; i < size; i++)
    {
        aus = prec * arr[i];

        if (aus > maxProd)
        {
            maxProd = aus;
        }
        prec = arr[i];
    }

    return maxProd;
}

float ema_array_ricorsiva(float arr[], float alpha, int pos)
{
    if (pos == 0)
        return arr[0];

    pos--;
    float ema = alpha * arr[pos] + (1.0 - alpha) * ema_array_ricorsiva(arr, alpha, pos);
    printf("EMA(%d): %f\n", pos, ema);
    return ema;
}

int sequenza_max_due_liste(Node *head1, Node *head2)
{
    if (head1 == NULL && head2 == NULL)
        return 0;

    int len = 0, cont = 0;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data == head2->data)
            cont++;
        else if (cont > len)
        {
            len = cont;
            cont = 0;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    if (cont > len)
        return cont;

    return len;
}

Node *cancella_nodi_pos_multipli_val_divisibile_ricorsiva(Node *head, int pos, int val, int index)
{
    if (head == NULL)
        return NULL;

    if (index % pos == 0 && head->data % val == 0)
    {
        Node *aus = head;
        head = head->next;
        free(aus);
        head = cancella_nodi_pos_multipli_val_divisibile_ricorsiva(head, pos, val, ++index);
    }
    else
        head->next = cancella_nodi_pos_multipli_val_divisibile_ricorsiva(head->next, pos, val, ++index);

    return head;
}

Node *cancella_nodi_val_ricorsiva(Node *head, int val)
{
    if (head == NULL)
        return head;

    if (head->data == val)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        head = cancella_nodi_val_ricorsiva(head, val);
    }
    else
        head->next = cancella_nodi_val_ricorsiva(head->next, val);

    return head;
}

Node *cancella_nodi_divisibili_val_ricorsiva(Node *head, int val)
{
    if (head == NULL)
        return head;

    if (head->data % val == 0)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        head = cancella_nodi_divisibili_val_ricorsiva(head, val);
    }
    else
        head->next = cancella_nodi_divisibili_val_ricorsiva(head->next, val);

    return head;
}

char *max_occorrenze_car_parole(char **parole, char car, int caratteri)
{
    int aus = 0, indexParola = 0;

    for (int i = 0; i < caratteri; i++)
    {
        char *parola = parole[i];
        int cont = 0;

        while (*parola != '\0')
        {
            if (*parola++ == car)
                cont++;
        }

        if (cont > aus)
        {
            indexParola = i;
            aus = cont;
        }
    }

    return parole[indexParola];
}

void elimina_moltiplicatore_se_prodotto_multiplo_val(Node **head, int val)
{
    if (head == NULL)
        return;
    else if ((*head)->next == NULL)
        return;

    Node *a = *head, *b = a->next;

    while (b->next != NULL)
    {
        if ((a->data * b->data) % val == 0)
        {
            Node *aus = b;

            a->next = aus->next;
            free(b);
            a = a->next;
            b = a->next;
        }
        else
        {
            a = b;
            b = b->next;
        }
    }
}

void inverti_lista(Node **head)
{
    Node *curr = *head, *prev = NULL;

    while (curr != NULL)
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    *head = prev;
}

char *parola_piu_lunga(char **parole, int size)
{
    int pos = 0, max = 0;

    for (int i = 0; i < size; i++)
    {
        int len = strlen(parole[i]);

        if (len > max)
        {
            max = len;
            pos = i;
        }
    }

    return parole[pos];
}

int somma_dispari_val_ricorsiva(int val)
{
    if (val == 0)
        return 0;

    return somma_dispari_val_ricorsiva(val - 1) + (2 * val - 1);
}

Node *unisci_liste_pos_multiple(Node *head1, Node *head2, int pos)
{
    if (head1 == NULL && head2 == NULL)
        return NULL;

    Node *head3 = NULL, *tail = NULL;
    int index = 1;

    while (head1 != NULL || head2 != NULL)
    {
        if (index % pos == 0)
        {
            Node *aus = crea_nodo(), *aus1 = crea_nodo();

            if (head1 != NULL && head2 != NULL)
            {
                aus->data = head1->data;
                aus->next = aus1;

                aus1->data = head2->data;
                aus1->next = NULL;

                if (head3 == NULL)
                    head3 = aus;
                else
                    tail->next = aus;
            }
            else if (head2 == NULL && head1 != NULL)
            {
                aus->data = head1->data;
                aus->next = aus1;

                aus1->data = 0;
                aus1->next = NULL;

                if (head3 == NULL)
                    head3 = aus;
                else
                    tail->next = aus;
            }
            else if (head1 == NULL && head2 != NULL)
            {
                aus->data = 0;
                aus->next = aus1;

                aus1->data = head2->data;
                aus1->next = NULL;

                if (head3 == NULL)
                    head3 = aus;
                else
                    tail->next = aus;
            }

            tail = aus1;
        }

        if (head1 != NULL)
            head1 = head1->next;

        if (head2 != NULL)
            head2 = head2->next;

        index++;
    }

    return head3;
}

void crea_lista_file_float(Nodef **head, FILE *fp)
{
    Nodef *tail = NULL;
    float aus = 0;

    while (fscanf(fp, "%f", &aus) != EOF && aus != -1.0)
    {
        Nodef *nodo = crea_nodo_float();
        if (nodo == NULL)

            nodo->data = aus;
        nodo->next = NULL;
        if (*head == NULL)
        {
            *head = nodo;
            tail = *head;
        }
        else
        {
            tail->next = nodo;
            tail = nodo;
        }
    }
}

void stampa_lista_float(Nodef *head)
{
    while (head != NULL)
    {
        printf("%f->", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

Nodef *riempi_lista_media_float_ricorsiva(Nodef *head)
{
    if (head == NULL)
        return NULL;

    Nodef *curr = riempi_lista_media_float_ricorsiva(head->next);

    if (curr != NULL)
    {
        Nodef *temp = crea_nodo_float();

        temp->data = (head->data + curr->data) / 2;
        temp->next = curr;
        head->next = temp;
    }

    return head;
}

int modi_salita_scala_ricorsiva(int gradini)
{
    if (gradini <= 1)
        return 1;

    return modi_salita_scala_ricorsiva(gradini - 1) + modi_salita_scala_ricorsiva(gradini - 2);
}