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

Parlare della rappresentazione dell'informazione nei calcolatori è affascinante! Ne discutiamo?

La rappresentazione dell'informazione nei calcolatori è fondamentale perché tutto ciò che un computer elabora, memorizza o comunica deve essere convertito in una forma che la macchina possa comprendere e manipolare. Ci sono diversi aspetti cruciali da considerare:

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

### Calcolo del numero di bit necessari per la rappresentazione binaria di un numero decimale:

Per determinare quanti bit sono necessari per rappresentare un numero decimale \( n \) in binario, possiamo utilizzare il seguente approccio:

1. Troviamo il numero di bit necessari per rappresentare il numero più grande possibile inferiore a \( n \). Questo sarà il numero binario più lungo che può rappresentare \( n \) senza superarlo.
2. Aggiungiamo uno a questo numero di bit per assicurarci di coprire anche \( n \).

La formula per calcolare il numero di bit necessari per rappresentare un numero decimale \( n \) in binario è:

\[ \text{Bit necessari} = \lceil \log_2(n + 1) \rceil \]

Dove \( \lceil x \rceil \) indica l'arrotondamento per eccesso di \( x \) all'intero più vicino.

Ad esempio, per rappresentare il numero decimale 10 in binario, possiamo fare quanto segue:

\[ \text{Bit necessari} = \lceil \log_2(10 + 1) \rceil = \lceil \log_2(11) \rceil = \lceil \approx 3.459 \rceil = 4 \]

Quindi, sono necessari 4 bit per rappresentare il numero decimale 10 in binario.
