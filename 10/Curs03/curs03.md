# Algoritmi pentru parcurgerea matricelor (Fill, Lee)

## Algoritmul pentru "umplerea" unei matrice (Fill)

O problemă des întâlnită este să vrem sa umplem o "insulă" de celule dintr-o matrice cu o anumită valoare, pornind de la o celulă inițială. Aceasta este cunoscută sub numele de algoritmul "Fill" sau "Flood Fill".

Data trecută am discutat despre funcțiile recursive și cum putem folosi recursivitatea pentru a rezolva probleme. Algoritmul Fill poate fi implementat recursiv, unde pentru fiecare celulă vizitată, verificăm vecinii săi și îi umplem cu valoarea dorită dacă îndeplinesc anumite condiții (de exemplu, dacă au aceeași valoare).

```cpp
const int maxSize = 1005;

int a[maxSize][maxSize], viz[maxSize][maxSize], n, m;

// Direcțiile de deplasare în matrice (sus, dreapta, jos, stânga)
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// consideram o functie care umple o "insulă" de celule cu valoarea 1, pornind de la celula (i, j)
void umplere (int i, int j)
{
    viz[i][j] = 1;
    for(int k = 0; k < 4; k++)
    {
        int iv = i + dx[k], jv = j + dy[k];
        // Verificăm dacă noua celulă este în interiorul matricei și nu a fost vizitată
        if(iv > 0 && jv > 0 && iv <= n && jv <= m && viz[iv][jv] == 0 && a[iv][jv] == 1)
            umplere(iv, jv);
    }
}
```

Acest algoritm poate fi apelat pentru fiecare celulă care nu a fost vizitată și care are valoarea 1, astfel încât să umplem întreaga "insulă" de celule conectate. Algoritmul are o complexitate de timp $O(n \cdot m)$, unde n și m sunt dimensiunile matricei, deoarece fiecare celulă este vizitată o singură dată.

O observație importantă este că, dacă matricea este foarte mare, recursivitatea poate duce la depășirea limitei de stivă. În astfel de cazuri, putem implementa algoritmul Fill folosind o coadă (vezi mai jos!) pentru a evita problemele legate de recursivitate.

De asemenea, a se observa ca aici ordinea de vizitare a celulelor depinde de ordinea în care sunt parcurși vecinii, deci nu putem garanta că ordinea de vizitare a celulelor va fi aceeași pentru toate implementările algoritmului Fill, dar, mai ales, **nu vom obține drumul minim** de la celula inițială la celelalte celule din "insulă". Algoritmul Fill este doar pentru a umple o regiune, nu pentru a găsi drumuri minime.

* [Fill](https://www.pbinfo.ro/probleme/2082/sierpinski)
* [Tsunami](https://infoarena.ro/problema/tsunami)
* [Castel](https://kilonova.ro/problems/900)

## Algoritmul lui Lee pentru determinarea drumului minim într-o matrice

Problema drumului minim o vom rezolva folosind o observație greedy: dacă am procesat toate celulele care se află la distanță $K$ de celula inițială, atunci

* Dacă destinația se află la distanță $K$, atunci am găsit drumul minim.
* Dacă destinația se află la distanță mai mare decât $K$, atunci trebuie să procesăm toate celulele care se află la distanță $K + 1$ de celula inițială.

În acest fel, vom procesa celulele în ordinea distanței lor față de celula inițială, ceea ce ne va permite să găsim drumul minim către destinație.

Algoritmul descris mai sus este cunoscut sub numele de algoritmul lui Lee și poate fi implementat folosind o coadă pentru a gestiona celulele care trebuie procesate.

```cpp
int a[max_size][max_size], n,
    di[] = {-1, 0, 1, 0},
    dj[] = {0, 1, 0, -1};
queue <pair <int,int>> coada;

void lee (int is, int js)
{
    a[is][js] = 1;
    coada.push(make_pair(is, js));
    while (!coada.empty())
    {
        int i = coada.front().first, j = coada.front().second;
        for (int k = 0; k < max_dir; k++)
        {
            int iv = i + di[k], jv = j + dj[k];
            if (iv >= 1 && iv <= n && jv >= 1 && jv <= n && a[iv][jv] == 0)
            {
                coada.push(make_pair(iv, jv));
                a[iv][jv] = a[i][j] + 1;
            }
        }
        coada.pop();
    }
}
```

Similar cu algoritmul Fill, algoritmul lui Lee parcurge matricea și vizitează fiecare celulă o singură dată, având o complexitate de timp $O(n \cdot m)$. Cu toate acestea, spre deosebire de Fill, Lee garantează că atunci când ajungem la destinație, am găsit drumul minim datorită modului în care celulele sunt procesate în funcție de distanța lor față de celula inițială.

* [Alee](https://infoarena.ro/problema/alee)
* [RJ](https://infoarena.ro/problema/rj)
* [Muzeu](https://infoarena.ro/problema/muzeu)
* [Barbar](https://infoarena.ro/problema/barbar)
* [Labirint2](https://infoarena.ro/problema/labirint2)
* [Pulsar](https://kilonova.ro/problems/285)

### Caz special Lee - matrice unde costurile de deplasare sunt fie 0, fie 1

Vom analiza problema [Rover](https://infoarena.ro/problema/rover). Aici, dacă avem o greutate fixată, celulele în matrice devin fie "sigure" (cost 0), fie "periculoase" (cost 1). În acest caz, putem folosi un `deque` pentru a implementa o versiune modificată a algoritmului lui Lee, care să țină cont de costurile diferite de deplasare. Când procesăm o celulă sigură, o adăugăm la începutul cozii, pentru a o procesa cât mai repede, întrucât știm că deplasarea către celula respectivă nu adaugă cost suplimentar. În schimb, celulele periculoase sunt adăugate la sfârșitul cozii, deoarece acestea implică un cost suplimentar. Când epuizăm toate celulele aflate la distanța curentă, trecem la celulele aflate la distanța următoare, asigurându-ne astfel că găsim drumul minim către destinație. Astfel, menținem complexitatea de timp $O(n \cdot m)$.

#### Cursul de azi a fost ținut de Ivan Andrei-Cristian.
