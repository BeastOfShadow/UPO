# Architettura degli elaboratori I

## 1 Sistema posizionale

> [!IMPORTANT] Sistema posizionale
>
> Ogni simbolo ha un proprio **valore** (peso) che dipende dalla **posizione** in cui si trova all'interno di un numero.

## 2 Basi più utilizzate

La rappresentazione più importante è quella **binaria**, ma vedremo anche la base ottale, decimale ed esadecimale.

### 2.1 Base binaria

Cifre utilizzate: $\{ 0, 1 \}$.

Formula generale: $b_{n}*2^{n-1}+b_{n-1}*2^{n-2}+ \dots +b_{n}*2^{0}$

Ad esempio: $11001_{(2)} = 1*2^{4}+1*2^{3}+0*2^{2}+0*2^{1}+1*2^{0} = 25_{(10)}$

### 2.2 Base ottale

Cifre utilizzate: $\{0,1,2,3,4,5,6,7\}$.

Formula generale: $b_{n}*8^{n-1}+b_{n-1}*8^{n-2}+\dots +b_{n}*8^{0}$

Ad esempio: $51_{(8)}=5*8^{1}+1*8^{0}=41_{(10)}$

### 2.3 Base decimale

Cifre utilizzate: $\{ 0,1,2,3,4,5,6,7,8,9 \}$.

Formula generale: $V(N_{(r)})= \sum_i ^ {n-1} = -m^{r^{i}d_{I}}$

Ad esempio: $210_{(10)}=2*10^2+1*10+0*10^0$

### 2.4 Base esadecimale

Cifre utilizzate: $\{ 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F \}$.

Formula generale: $b_{n}*16^{n-1}+b_{n-1}*16^{n-2}+ \dots +b_{n}*16^{0}$

Ad esempio: $5A_{(16)}=5*16^{1}+A*16^{0}=5*16+10*1=90_{(10)}$
