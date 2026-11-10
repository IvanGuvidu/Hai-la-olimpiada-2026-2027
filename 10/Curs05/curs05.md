# Aritmetică modulară, Combinatorică

De acum încolo, o parte bună din probleme vor avea un element de combinatorică / numărare în ele. Înainte de a discuta despre combinatorică, vom discuta despre câteva noțiuni de aritmetică modulară, care ne vor fi utile în rezolvarea problemelor de combinatorică.

## Aritmetica modulară

Rezultatele din problemele de numărare pot fi foarte mari, astfel încât este necesar să le afișăm modulo o valoare dată. Pentru simplitate, **vom presupune că valoarea M (modulul) este un număr prim** și că valorile $0 \leq a, b < M$. Să vedem cum se compoară operatiile de bază în aritmetica modulară:

* Adunarea: este suficient să adunăm cele două numere și să luăm rezultatul modulo M: (a + b) % M.
* Scaderea: trebuie avut grija la rezultatul scăderii, deoarece acesta poate fi negativ. Astfel, putem folosi formula: (a - b + M) % M.
* Înmulțirea: este suficient să înmulțim cele două numere și să luăm rezultatul modulo M: (a * b) % M.
* Împărțirea: are sens împărțirea a două numere, nu neapărat divizibile între ele, modulo ceva? mai ales ca nu avem notiunea de număr zecimal în aritmetica modulară?

Împărțirea este mai complicată, deoarece nu putem folosi împărțirea clasică. În schimb, putem folosi [inversul modular](https://infoarena.ro/problema/inversmodular): dacă vrem să calculăm $\frac{a}{b} \pmod{M}$, putem calcula $a \cdot b^{-1} \pmod{M}$, unde $b^{-1}$ este **inversul modular** al lui $b$ ($b^{-1} \cdot b \equiv 1 \pmod{M}$).

Ținând cont că M este prim, ne folosim de [Mica Teoremă a lui Fermat](https://ro.wikipedia.org/wiki/Mica_teorem%C4%83_a_lui_Fermat) pentru a calcula inversul modular: $b^{-1} \equiv b^{M-2} \pmod{M}$. Pentru a calcula $b^{M-2} \pmod{M}$, putem folosi [exponențierea rapidă](https://infoarena.ro/problema/lgput).

## Combinatorică & Probleme de numărare

Combinatorica este ramura matematicii care se ocupă cu studiul modurilor de a selecta, aranja și combina obiecte. În problemele de combinatorică ne interesează să numărăm câte moduri există de a realiza anumite configurații sau aranjamente.

### Noțiuni elementare de combinatorică

La baza combinatoricii stau câteva noțiuni elementare:

* **Permutări**: O permutare este o aranjare a unui set de obiecte într-o anumita ordine. De exemplu, permutările unui set de n obiecte sunt toate aranjamentele posibile ale acestora. Numărul de permutări ale unui set de n obiecte distincte este dat de factorialul lui n, notat $n!$ (n factorial).
* **Aranjamente**: Un aranjament este o selecție de obiecte dintr-un set, care ține cont de ordinea lor. Numărul de aranjamente de k obiecte dintr-un set de n obiecte distincte este dat de formula: $A(n, k) = \frac{n!}{(n-k)!}$.
* **Combinări**: O combinarie este o selecție de obiecte dintr-un set, care nu ține cont de ordinea lor. Numărul de combinari de k obiecte dintr-un set de n obiecte distincte este dat de formula: $C(n, k) = \frac{n!}{k!(n-k)!}$.
* **Numărul de submulțimi**: Numărul de submulțimi ale unui set cu n elemente este $2^n$, deoarece fiecare element poate fi fie inclus, fie exclus din submulțime.

Formule importante:

* $C(n, k) + C(n, k + 1) = C(n + 1, k + 1)$ ([Triunghiul lui Pascal](https://ro.wikipedia.org/wiki/Triunghiul_lui_Pascal))
* $C(n, k) = C(n, n - k)$ (simetria combinărilor)
* $C(n, 0) + C(n, 1) + ... + C(n, n) = 2^n$

### Truc pentru a calcula combinările rapid

În multe probleme, vom avea nevoie sa calculăm combinările la foc automat. O primă optimizare este să ne precalculăm factorialele, și de fiecare dată, ne folosim de exponențierea rapidă pentru a calcula inversul modular al factorialelor, în complexitate $O(\log M)$. Pentru a putea precalcula și inversul factorialelor în timp liniar, ne vom folosi de următoarea relație: fie $invfact[i] = (i!)^{-1} \pmod{M} = 1 / (1 \cdot 2 \cdot ... \cdot i) \pmod{M}$. Atunci, putem calcula inversul factorialelor astfel: $invfact[n] = (fact[n])^{-1} \pmod{M}$, iar pentru $i < n$, avem: $invfact[i] = invfact[i + 1] \cdot (i + 1) \pmod{M}$. Astfel, facem un singur calcul de exponențiere rapidă pentru a calcula inversul factorialului maxim, iar apoi, în timp liniar, calculăm toate inversurile factorialelor.

* [Stars and Bars](https://www.pbinfo.ro/articole/25586/stars-and-bars)
* [Spion](https://kilonova.ro/problems/1443/)
* [Functii](https://infoarena.ro/problema/functii)
* [Nmult](https://kilonova.ro/problems/1468)
* [Fotbal](https://kilonova.ro/problems/505)
* [Transport](https://kilonova.ro/problems/286/)
* [Nozero](https://kilonova.ro/problems/1565)


#### Cursul de azi a fost ținut de Ivan Andrei-Cristian.
