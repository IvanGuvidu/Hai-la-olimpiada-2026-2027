# Sliding Window

O problemă des întâlnită este să aflăm maximul sau minimul într-o secvență de dimensiune fixă, care se deplasează de-a lungul unui șir de numere. Această problemă poate fi rezolvată eficient folosind o structură de date numită [deque](https://en.cppreference.com/cpp/container/deque) (double-ended queue). Vom ține spre varful deque-ului elementele care sunt potențiale pentru a fi maximul sau minimul ferestrei curente. Pe măsură ce fereastra se deplasează, vom elimina elementele care nu mai sunt relevante și vom adăuga la finalul deque-ului noi elemente în deque, eliminând elementele care nu mai pot fi maximul sau minimul ferestrei curente. Această abordare permite obținerea maximului sau minimului într-o fereastră de dimensiune fixă în timp O(N), unde N este lungimea șirului de numere.

* [Deque](https://infoarena.ro/problema/deque)
* [Secvența](https://infoarena.ro/problema/secventa)
* [Sum2](https://infoarena.ro/problema/sum2)
* [Drept2](https://infoarena.ro/problema/drept2)
* [Struți](https://infoarena.ro/problema/struti)
* [Secvența2](https://infoarena.ro/problema/secv2)

#### Cursul de azi a fost ținut de Marciuc Andrei.
