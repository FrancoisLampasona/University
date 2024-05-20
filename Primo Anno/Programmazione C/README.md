# Introduzione alla programmazione e al linguaggio "C"

> # Architettura di Von Neumann

Ogni compilatore di programmazione ha le sue radici nell'architettura di Von Neumann, un modello fondamentale che guida il funzionamento dei moderni sistemi di elaborazione. Questa architettura fornisce il fondamento su cui si basano i linguaggi di programmazione e l'intero ecosistema informatico.

![Architettura di Von Neumann](https://drive.google.com/uc?id=12TOtRIOM02bEEWaLNgb2asirQ_gwFdxZ)

L'architettura di Von Neumann, che ha rivoluzionato il mondo dell'informatica, è composta da diversi componenti chiave, ognuno dei quali svolge un ruolo fondamentale nel funzionamento complessivo del sistema.

## Unità di Elaborazione Centrale (CPU)

La CPU è il cuore dell'architettura di Von Neumann, responsabile dell'elaborazione dei dati e delle istruzioni. È composta da due sottounità principali:

- **Unità di Controllo (CU)**: Gestisce l'esecuzione delle istruzioni, controlla il flusso di dati all'interno del sistema e coordina le operazioni degli altri componenti.
- **Unità di Logica Aritmetica (ALU)**: Esegue operazioni aritmetiche (come l'addizione e la sottrazione) e operazioni logiche (come AND, OR, NOT) sui dati.
- **Registri interni**: I registri sono piccole aree di memoria all'interno della CPU che vengono utilizzate per immagazzinare temporaneamente dati e istruzioni durante l'esecuzione dei programmi. Alcuni esempi comuni di registri includono:

  - **Program Counter (PC)**: Contiene l'indirizzo della prossima istruzione da eseguire.
  - **Memory Address Register (MAR)**: Contiene l'indirizzo di memoria dell'istruzione o dei dati che devono essere letti o scritti.
  - **Memory Data Register (MDR)**: Contiene i dati letti dalla memoria o i dati da scrivere nella memoria.
  - **Instruction Register (IR)**: Contiene l'istruzione corrente che viene eseguita dalla CPU.

Bus interni: I bus interni della CPU consentono il trasferimento di dati e istruzioni tra i vari componenti della CPU, come i registri e l'ALU.

## Memoria

La memoria è dove vengono memorizzati dati e istruzioni per l'elaborazione da parte della CPU. Nell'architettura di Von Neumann, la memoria è organizzata come segue:

- **Memoria Principale**: Composta da celle di memoria, ognuna delle quali può contenere un certo numero di bit. Questa è la memoria accessibile direttamente dalla CPU.
  - Ampiezza della memoria: il numero massimo di bit necessari per memorizzare un valore in una cella di memoria.
  - Ampiezza dell'indirizzo: il numero massimo di bit necessari per rappresentare un indirizzo di memoria.
  - Spazio di indirizzamento: il numero totale di celle di memoria che possono essere identificate univocamente tramite un indirizzo, dove il numero totale N di celle è dato da N=2^i (dove i è l'ampiezza dell'indirizzo).
- **Memoria Secondaria**: Fornisce uno spazio di archiviazione permanente per dati e istruzioni che non sono attualmente in uso dalla CPU. Esempi includono dischi rigidi e unità USB.

## Unità di Input/Output (I/O)

Le unità di input/output consentono al sistema di comunicare con il mondo esterno. Queste includono dispositivi come tastiere, mouse, monitor, stampanti, schede di rete e altro ancora. Il loro ruolo è quello di trasmettere dati tra il sistema e gli utenti o altri dispositivi.

## Bus di Sistema

Il bus di sistema è un canale di comunicazione che collega tutti i componenti del sistema, consentendo loro di scambiare dati e istruzioni. Esistono diversi tipi di bus, tra cui:

- **Bus dati**: Trasporta dati tra la CPU, la memoria e le periferiche di I/O.
- **Bus di indirizzi**: Trasporta gli indirizzi delle celle di memoria o delle periferiche di I/O.
- **Bus di controllo**: Trasporta segnali di controllo che coordinano le operazioni dei vari componenti del sistema.

## Funzionamento Generale

Il funzionamento dell'architettura di Von Neumann è caratterizzato da un ciclo di esecuzione fondamentale:

Quando un'istruzione deve essere eseguita, il suo indirizzo di memoria viene caricato nel registro MAR (Memory Address Register) della CPU. Questo processo avviene tipicamente in due modi:

- **Program Counter (Contatore di Programma)**: Il Program Counter (PC) è un registro interno della CPU che contiene l'indirizzo di memoria dell'istruzione successiva da eseguire. Durante l'esecuzione del programma, il PC viene incrementato di solito di una quantità fissa per puntare alla prossima istruzione. Quando arriva il momento di eseguire un'istruzione, il valore corrente del PC viene caricato nel registro MAR per accedere alla memoria principale e recuperare l'istruzione.

- **Indirizzamento Diretto**: In alcuni casi, potrebbe essere necessario un indirizzamento diretto per accedere a istruzioni o dati specifici in memoria. In questo caso, l'indirizzo di memoria dell'istruzione è noto a priori o viene calcolato durante l'esecuzione del programma e quindi caricato direttamente nel registro MAR.

Quindi, indipendentemente dal metodo utilizzato per ottenere l'indirizzo di memoria dell'istruzione, questo viene alla fine caricato nel registro MAR per permettere alla CPU di accedere alla memoria principale e recuperare l'istruzione da eseguire.

Dopo aver caricato l'indirizzo di memoria dell'istruzione nel registro MAR (Memory Address Register), la CPU comunica con la memoria principale per recuperare l'istruzione stessa. Durante questo processo, il contenuto della cella di memoria corrispondente all'indirizzo specificato viene letto dalla memoria e quindi caricato nel registro MDR (Memory Data Register).

Il registro MDR funge da "buffer" temporaneo per i dati che vengono letti o scritti dalla memoria principale. Una volta che l'istruzione è stata caricata nel registro MDR, può essere decodificata e quindi eseguita dalla CPU.

## Ciclo di Esecuzione

1. **Fetch (Prelevamento)**: La CPU preleva l'istruzione dalla memoria utilizzando l'indirizzo contenuto nel registro MAR. Il valore dell'istruzione viene memorizzato nel registro MDR.
2. **Decode (Decodifica)**: L'unità di controllo decodifica l'istruzione presente nel registro MDR, determinando quale operazione deve essere eseguita e come ottenere gli operandi.
3. **Execute (Esecuzione)**: Viene eseguita la computazione desiderata utilizzando i dati presenti nei registri della CPU e/o nella memoria principale. In questo passaggio, l'indirizzo dell'istruzione da eseguire può essere incrementato, se necessario, in base al tipo di istruzione eseguita.
4. **Write Back (Scrittura dei Risultati)**: Se necessario, i risultati dell'esecuzione vengono scritti nella memoria o in altri registri.

### Spiegazione Dettagliata :

#### Fetch (Prelevamento)

Il fetch è il primo passo nell'esecuzione di un'istruzione all'interno dell'architettura di Von Neumann. In questo passaggio, la CPU preleva l'istruzione dalla memoria principale utilizzando l'indirizzo contenuto nel registro MAR (Memory Address Register). Il contenuto dell'indirizzo viene inviato alla memoria come richiesta di accesso all'istruzione desiderata.

Una volta ricevuto il comando di accesso all'indirizzo specificato, la memoria principale fornisce l'istruzione corrispondente e la invia alla CPU. Questa istruzione viene quindi memorizzata nel registro MDR (Memory Data Register) per essere successivamente elaborata.

#### Decode (Decodifica)

Dopo che l'istruzione è stata prelevata dalla memoria e memorizzata nel registro MDR, passiamo al passaggio di decodifica. In questa fase, l'unità di controllo della CPU interpreta l'istruzione memorizzata nel registro MDR per determinare quale operazione deve essere eseguita e quali dati devono essere utilizzati.

L'unità di controllo analizza l'istruzione e determina l'operazione specifica da eseguire, come ad esempio l'addizione, la sottrazione, il trasferimento di dati o qualsiasi altra operazione supportata dall'architettura del processore. Inoltre, l'unità di controllo identifica gli operandi necessari per l'esecuzione dell'istruzione, come ad esempio i valori da prelevare dalla memoria o dai registri interni della CPU.

#### Execute (Esecuzione)

Una volta che l'istruzione è stata prelevata dalla memoria, memorizzata nel registro MDR e decodificata dall'unità di controllo, passiamo all'esecuzione effettiva dell'istruzione. Durante l'esecuzione, la CPU utilizza l'ALU (Arithmetic Logic Unit) per eseguire l'operazione specificata dall'istruzione.

L'ALU manipola i dati secondo le specifiche dell'istruzione, eseguendo operazioni aritmetiche, logiche o altre operazioni richieste. Una volta completata l'operazione, il risultato può essere memorizzato nuovamente nella memoria, nei registri della CPU o altrove a seconda delle esigenze dell'istruzione.

#### Conclusione:

Questi tre passaggi, fetch, decode ed execute, rappresentano il ciclo fondamentale di esecuzione all'interno di un sistema basato sull'architettura di Von Neumann. Ogni istruzione viene prelevata dalla memoria, decodificata per determinare l'operazione da eseguire e quindi eseguita dall'ALU. Questo ciclo si ripete continuamente fino a quando il programma in esecuzione non termina o viene interrotto.

> # Rappresentazione dell'Informazione nei calcolatori :

La rappresentazione dell'informazione nei calcolatori è fondamentale perché tutto ciò che un computer elabora, memorizza o comunica deve essere convertito in una forma che la macchina possa comprendere e manipolare. Ci sono diversi aspetti cruciali da considerare:

---

### Bit e Byte

Il **bit** è l'unità più piccola di informazione in un computer ed è rappresentato da uno zero o un uno. I **byte**, d'altra parte, sono gruppi di 8 bit e sono comunemente utilizzati come unità di misura per la memoria e lo storage dei dati.

Panoramica delle unità di misura comuni utilizzate nella rappresentazione dell'informazione nei calcolatori :

- Bit: La più piccola unità di dati in un calcolatore, può essere 0 o 1, rappresentando lo stato di un singolo elemento di dati.

- Nibble: Un nibble consiste di 4 bit. Sebbene meno comune di byte e word, può essere utile in alcune operazioni di manipolazione dei dati.

- Byte: Un byte è composto da 8 bit ed è l'unità di base utilizzata per memorizzare i dati nei calcolatori. È spesso utilizzato per rappresentare caratteri e piccoli numeri.

- Word: Una word è generalmente composta da 16 bit (su architetture a 16 bit) o 32 bit (su architetture a 32 bit). È l'unità di dati più grande che il processore di una determinata architettura può elaborare in un'unica istruzione.

- Double Word: Una double word è composta da 32 bit o 4 byte. È comunemente utilizzata in informatica per rappresentare interi più grandi o numeri in virgola mobile.

- Quad Word: Una quad word è composta da 64 bit o 8 byte. È utilizzata in applicazioni che richiedono numeri a precisione doppia o per memorizzare indirizzi di memoria su architetture a 64 bit.

## Sistemi di Numerazione

I calcolatori utilizzano principalmente due sistemi di numerazione:

- **Sistema Binario**: È il sistema di numerazione fondamentale per i calcolatori, dove ogni cifra può essere 0 o 1. È il sistema più adatto all'elettronica digitale.
- **Sistema Esadecimale**: Questo sistema è utilizzato per semplificare la rappresentazione binaria, raggruppando i bit in gruppi di quattro e rappresentandoli con cifre esadecimali (da 0 a 9 e da A a F).

### Rappresentazione dei Caratteri

I caratteri sono rappresentati nei calcolatori utilizzando codifiche come ASCII (American Standard Code for Information Interchange) o Unicode. Queste codifiche assegnano numeri a caratteri e simboli per consentire al computer di interpretarli e manipolarli.

### Rappresentazione dei Numeri

I numeri possono essere rappresentati in diversi formati nei calcolatori, tra cui:

- **Integer (Interi)**: I numeri interi vengono memorizzati senza parte decimale utilizzando la rappresentazione binaria.
- **Float (Virgola Mobile)**: I numeri floating point rappresentano numeri con parte decimale e vengono memorizzati utilizzando un formato specifico, come IEEE 754, che comprende bit per il segno, l'esponente e la mantissa.

### Memoria

La memoria nei calcolatori è organizzata in celle di memoria, ognuna delle quali può contenere un certo numero di bit (solitamente multipli di 8). Questa memoria può essere di diversi tipi, come RAM (Random Access Memory), ROM (Read-Only Memory), e memorie di massa come dischi rigidi o SSD (Solid State Drive).

### Rappresentazione dei Dati Multimediali

I dati multimediali come immagini, suoni e video vengono rappresentati utilizzando formati specifici che codificano informazioni visive e uditive in modo che i calcolatori possano memorizzarli e riprodurli fedelmente.

In breve, la rappresentazione dell'informazione nei calcolatori è una parte essenziale dell'informatica che coinvolge la conversione di dati in formati comprensibili e manipolabili dalla macchina, consentendo così il funzionamento di tutte le operazioni computazionali.

## Conteggi:

### Quanti sono tutti i numeri binari che si possono formare con k bit?

Quando parliamo di numeri binari con k bit, intendiamo sequenze di bit di lunghezza k, dove ogni bit può essere 0 o 1. Ad esempio, per k = 3, avremmo sequenze come 000, 001, 010, 011, 100, 101, 110, 111.

Per calcolare quanti di questi numeri binari possiamo formare con k bit, possiamo utilizzare il principio combinatorio, in particolare la formula per le disposizioni con ripetizione. Questa formula ci dice che se abbiamo n oggetti distinti e vogliamo sceglierne k con la possibilità di ripetizione, ci sono n<sup>k</sup> modi per farlo.

Nel nostro caso, abbiamo due scelte per ogni bit (0 o 1) e abbiamo k bit totali. Quindi, il numero totale di numeri binari che possiamo formare con k bit è 2<sup>k</sup>.

Ad esempio, se k = 3, abbiamo 2<sup>3</sup> = 8 numeri binari possibili (000, 001, 010, 011, 100, 101, 110, 111).

La nota aggiunta menziona che questi numeri binari corrispondono ai numeri decimali nell'intervallo da 0 a 2<sup>k</sup> - 1. Questo perché possiamo interpretare una sequenza di bit come un numero in base 2. Ad esempio, il numero binario 101 corrisponde al numero decimale 5 (1\*2<sup>2</sup> + 0\*2<sup>1</sup> + 1\*2<sup>0</sup>).

---

### Calcolo del numero di bit necessari per la rappresentazione binaria di un numero decimale:

Per determinare quanti bit sono necessari per rappresentare un numero decimale \( n \) in binario, possiamo utilizzare il seguente approccio:

1. Troviamo il numero di bit necessari per rappresentare il numero più grande possibile inferiore a \( n \). Questo sarà il numero binario più lungo che può rappresentare \( n \) senza superarlo.
2. Aggiungiamo uno a questo numero di bit per assicurarci di coprire anche \( n \).

La formula per calcolare il numero di bit necessari per rappresentare un numero decimale \( n \) in binario è:

Bit necessari = log<sub>2</sub>(n + 1)

Ad esempio, per rappresentare il numero decimale 10 in binario, possiamo fare quanto segue:

Bit necessari = log<sub>2</sub>(10 + 1) = log<sub>2</sub>(11) = 3.459 = 4

Quindi, sono necessari 4 bit per rappresentare il numero decimale 10 in binario.

Esempio:
Per rappresentare 57 informazioni diverse: <br>
5 bit non bastano , poiché : 2<sup>5</sup> = 32 < 57 <br>
6 bit invece bastano : 2<sup>6</sup> = 64 > 57 <br>

# Operazioni Logiche in Informatica

Le operazioni logiche, note anche come operazioni booleane, sono fondamentali nell'informatica e nella logica digitale. Queste operazioni lavorano su valori booleani (vero/falso, 1/0) e sono essenziali per la costruzione di circuiti logici e per la programmazione.

## Tipi di Operazioni Logiche

### 1. AND (E)

### 2. OR (O)

### 3. NOT (NON)

### 4. NAND (NOT AND)

### 5. NOR (NOT OR)

### 6. XOR (OR esclusivo)

### 7. XNOR (OR esclusivo negativo)

| A   | B   | A AND B | A OR B | NOT A | A NAND B | A NOR B | A XOR B | A XNOR B |
| --- | --- | ------- | ------ | ----- | -------- | ------- | ------- | -------- |
| 0   | 0   | 0       | 0      | 1     | 1        | 1       | 0       | 1        |
| 0   | 1   | 0       | 1      | 1     | 1        | 0       | 1       | 0        |
| 1   | 0   | 0       | 1      | 0     | 1        | 0       | 1       | 0        |
| 1   | 1   | 1       | 1      | 0     | 0        | 0       | 0       | 1        |

## Utilizzo delle Operazioni Logiche

Le operazioni logiche sono ampiamente utilizzate nei seguenti contesti:

- **Circuiti Digitali**: Implementazione di circuiti combinatori e sequenziali.
- **Programmazione**: Condizioni nei costrutti di controllo come `if`, `while`, e `for`.
- **Algoritmi**: Manipolazione di bit e operazioni bitwise.
- **Database**: Filtri di ricerca con operatori logici.

## Conversioni di Base:

## Conversione da Base 10 a Base \( b \)

Per convertire un numero decimale (base 10) a un numero in un'altra base \( b \), si utilizza il metodo della divisione ripetuta. Questo metodo comporta la divisione del numero decimale per la base \( b \) e l'annotazione dei resti. Ecco i passaggi:

1. **Dividere il numero per la base \( b \)** e annotare il quoziente e il resto.
2. **Prendere il quoziente ottenuto e dividerlo nuovamente per la base \( b \)**, annotando ancora una volta il quoziente e il resto.
3. **Ripetere il processo** fino a quando il quoziente diventa 0.
4. **Leggere i resti dal basso verso l'alto** per ottenere il numero nella base \( b \).

### Esempio: Convertire 45 in base 10 a base 2

1. \( 45 \div 2 = 22 \) con resto 1
2. \( 22 \div 2 = 11 \) con resto 0
3. \( 11 \div 2 = 5 \) con resto 1
4. \( 5 \div 2 = 2 \) con resto 1
5. \( 2 \div 2 = 1 \) con resto 0
6. \( 1 \div 2 = 0 \) con resto 1

Leggendo i resti dal basso verso l'alto, otteniamo: 101101. Quindi, 45 in base 10 è 101101 in base 2.

## Conversione da Base \( b \) a Base 10

Per convertire un numero da una base \( b \) a base 10, si utilizza la rappresentazione polinomiale del numero. Ogni cifra del numero in base \( b \) è moltiplicata per la base \( b \) elevata alla potenza corrispondente alla posizione della cifra, partendo da destra (con la posizione 0).

### Esempio: Convertire 101101 in base 2 a base 10

1. Identificare le posizioni delle cifre da destra a sinistra:
   - <code>1 &times; 2<sup>5</sup> + 0 &times; 2<sup>4</sup> + 1 &times; 2<sup>3</sup> + 1 &times; 2<sup>2</sup> + 0 &times; 2<sup>1</sup> + 1 &times; 2<sup>0</sup></code>
2. Calcolare i valori delle potenze e moltiplicare:
   - <code>1 &times; 32 + 0 &times; 16 + 1 &times; 8 + 1 &times; 4 + 0 &times; 2 + 1 &times; 1</code>
3. Sommare i risultati:
   - <code>32 + 0 + 8 + 4 + 0 + 1 = 45</code>

Quindi, 101101 in base 2 è 45 in base 10.

## Conversioni Veloci tra Basi Potenza di Due

Le basi potenza di due (binaria, ottale, esadecimale) permettono conversioni rapide e semplici grazie alla loro relazione diretta. Ecco come eseguire queste conversioni.

### Conversione tra Binario e Ottale

Ogni cifra in ottale corrisponde a tre cifre binarie:

- `000`<sub>2</sub> = `0`<sub>8</sub>
- `001`<sub>2</sub> = `1`<sub>8</sub>
- `010`<sub>2</sub> = `2`<sub>8</sub>
- `011`<sub>2</sub> = `3`<sub>8</sub>
- `100`<sub>2</sub> = `4`<sub>8</sub>
- `101`<sub>2</sub> = `5`<sub>8</sub>
- `110`<sub>2</sub> = `6`<sub>8</sub>
- `111`<sub>2</sub> = `7`<sub>8</sub>

#### Esempio: Convertire 101101 in binario a ottale

1. Raggruppare le cifre binarie in gruppi di tre, partendo da destra:
   - `101` `101`
2. Convertire ogni gruppo in ottale:
   - `101`<sub>2</sub> = `5`<sub>8</sub>
   - `101`<sub>2</sub> = `5`<sub>8</sub>

Quindi, 101101 in binario è 55 in ottale.

### Conversione tra Binario e Esadecimale

Ogni cifra in esadecimale corrisponde a quattro cifre binarie:

- `0000`<sub>2</sub> = `0`<sub>16</sub>
- `0001`<sub>2</sub> = `1`<sub>16</sub>
- `0010`<sub>2</sub> = `2`<sub>16</sub>
- `0011`<sub>2</sub> = `3`<sub>16</sub>
- `0100`<sub>2</sub> = `4`<sub>16</sub>
- `0101`<sub>2</sub> = `5`<sub>16</sub>
- `0110`<sub>2</sub> = `6`<sub>16</sub>
- `0111`<sub>2</sub> = `7`<sub>16</sub>
- `1000`<sub>2</sub> = `8`<sub>16</sub>
- `1001`<sub>2</sub> = `9`<sub>16</sub>
- `1010`<sub>2</sub> = `A`<sub>16</sub>
- `1011`<sub>2</sub> = `B`<sub>16</sub>
- `1100`<sub>2</sub> = `C`<sub>16</sub>
- `1101`<sub>2</sub> = `D`<sub>16</sub>
- `1110`<sub>2</sub> = `E`<sub>16</sub>
- `1111`<sub>2</sub> = `F`<sub>16</sub>

#### Esempio: Convertire 101101 in binario a esadecimale

1. Raggruppare le cifre binarie in gruppi di quattro, partendo da destra. Aggiungere zeri a sinistra se necessario:
   - `0010` `1101`
2. Convertire ogni gruppo in esadecimale:
   - `0010`<sub>2</sub> = `2`<sub>16</sub>
   - `1101`<sub>2</sub> = `D`<sub>16</sub>

Quindi, 101101 in binario è 2D in esadecimale.

### Conversione tra Ottale e Esadecimale

Per convertire tra ottale e esadecimale, si passa attraverso il binario:

#### Esempio: Convertire 55 in ottale a esadecimale

1. Convertire l'ottale a binario:
   - `5`<sub>8</sub> = `101`<sub>2</sub>
   - `5`<sub>8</sub> = `101`<sub>2</sub>
   - Quindi, 55 in ottale è 101101 in binario.
2. Convertire il binario a esadecimale:
   - `101101`<sub>2</sub> = `2D`<sub>16</sub>

Quindi, 55 in ottale è 2D in esadecimale.

## Considerazioni Finali

Questi metodi sono generali e possono essere applicati a qualsiasi base \( b \) maggiore di 1. Per basi superiori a 10, si utilizzano lettere dell'alfabeto per rappresentare i valori delle cifre superiori a 9 (ad esempio, A per 10, B per 11, ecc.).

Comprendere e padroneggiare queste tecniche è essenziale per lavorare con diversi sistemi numerici, particolarmente nei campi dell'informatica e dell'ingegneria, dove basi come 2 (binaria), 8 (ottale) e 16 (esadecimale) sono comunemente utilizzate.

# Rappresentazione degli Interi

La rappresentazione degli interi nei computer è fondamentale per lo sviluppo di software e l'implementazione di algoritmi. Gli interi possono essere rappresentati in vari modi, ognuno con le proprie caratteristiche e utilizzi. Ecco una panoramica delle principali rappresentazioni degli interi:

## Rappresentazione Binaria

Gli interi sono rappresentati in forma binaria, utilizzando solo due cifre: 0 e 1. Questa rappresentazione è naturale per i computer, che operano con circuiti digitali basati su stati di alta e bassa tensione, corrispondenti a 1 e 0 rispettivamente.

### Interi Senza Segno

Gli interi senza segno (unsigned integers) possono rappresentare solo valori positivi e zero. La loro rappresentazione binaria è semplice e diretta, dove ogni bit rappresenta una potenza di 2.

Per un intero senza segno di \( n \) bit, i valori rappresentabili vanno da \( 0 \) a \( 2^n - 1 \).

### Interi Con Segno

Per rappresentare numeri negativi, esistono diverse convenzioni, tra cui:

1. **Segno e Magnitudine (Sign and Magnitude)**:

   - Il bit più significativo (MSB) indica il segno (0 per positivo, 1 per negativo).
   - I restanti bit rappresentano la magnitudine (valore assoluto) del numero.
   - Esempio (8 bit): +5 = `00000101`, -5 = `10000101`
   - Svantaggi: Esistono due tipi di zero, la computazione delle operazioni aritmetiche non è immediata. Occorre differenziare il modo di usare le operazioni aritmetiche in base al segno degli operandi.

2. **Complemento a Uno (One's Complement)**:

   - Il numero negativo è ottenuto invertendo tutti i bit del numero positivo.
   - Ha due rappresentazioni per lo zero: +0 (`00000000`) e -0 (`11111111`).
   - Esempio (8 bit): +5 = `00000101`, -5 = `11111010`
   - Vantaggi: La somma si puo’ effettuare nel modo classico.
   - Svantaggi: Esistono due tipi di zero.

3. **Complemento a Due (Two's Complement)**:
   - Il numero negativo è ottenuto invertendo tutti i bit del numero positivo e aggiungendo 1 al risultato.
   - Ha una sola rappresentazione per lo zero.
   - Esempio (8 bit): +5 = `00000101`, -5 = `11111011`
   - Per un intero con segno di \( n \) bit, i valori rappresentabili vanno da \( -2<sup>n-1</sup> \) a \( 2<sup>n-1</sup> - 1 \).
   - Esiste un solo zero.
   - E' compatibile con la somma.

Il complemento a due è il metodo più utilizzato nei moderni computer per rappresentare numeri interi con segno, poiché semplifica le operazioni aritmetiche e logiche.

## Estensione del Segno

Quando si converte un numero intero con segno di una dimensione minore a una dimensione maggiore, si utilizza l'estensione del segno (sign extension). In questo processo, il bit di segno viene copiato nei bit più significativi della nuova rappresentazione per preservare il valore del numero.

Esempio: Convertire un numero a 4 bit in un numero a 8 bit:

- +5 (4 bit): `0101` -> (8 bit): `00000101`
- -5 (4 bit): `1011` -> (8 bit): `11111011`

## Rappresentazione in Virgola Mobile

Per numeri molto grandi o molto piccoli, si utilizzano le rappresentazioni in virgola mobile (floating-point), che permettono di rappresentare un ampio intervallo di valori con una precisione limitata. Gli standard più comuni per la rappresentazione in virgola mobile sono definiti dall'IEEE (Institute of Electrical and Electronics Engineers).

### Standard IEEE 754

Lo standard IEEE 754 definisce formati per numeri in virgola mobile, i più comuni dei quali sono:

- **Singola Precisione (32 bit)**:

  - 1 bit per il segno
  - 8 bit per l'esponente (con bias di 127)
  - 23 bit per la mantissa (con un bit implicito)

- **Doppia Precisione (64 bit)**:
  - 1 bit per il segno
  - 11 bit per l'esponente (con bias di 1023)
  - 52 bit per la mantissa (con un bit implicito)

La rappresentazione in virgola mobile include un bit di segno, un esponente (che determina l'ordine di grandezza del numero) e una mantissa (che rappresenta la precisione del numero).

## Rappresentazione Decimale

In alcuni contesti, come nei calcoli finanziari, si preferisce la rappresentazione decimale per evitare errori di arrotondamento associati alla rappresentazione binaria. Gli standard IEEE 754 includono anche formati per la rappresentazione decimale.

### Decimal Floating-Point

I formati a virgola mobile decimali rappresentano i numeri utilizzando una base 10, anziché una base 2. Questo permette di rappresentare esattamente numeri decimali come 0.1, che non possono essere rappresentati con precisione in binario.

## Considerazioni Finali

La scelta della rappresentazione degli interi dipende dall'applicazione specifica e dai requisiti di precisione e intervallo di valori. Comprendere le diverse rappresentazioni è essenziale per scrivere software efficiente e corretto, specialmente in campi come l'informatica, l'ingegneria e la scienza dei dati.
