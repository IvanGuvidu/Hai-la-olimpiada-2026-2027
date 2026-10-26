# Funcții Recursive, Evaluare de Expresii

## Funcții Recursive

O funcție recursivă este o funcție care se apelează pe ea însăși pentru a rezolva o problemă. Recursivitatea este un concept fundamental în programare și poate fi utilizată pentru a simplifica soluțiile la probleme complexe.

Functiile recursive sunt adesea folosite pentru a rezolva probleme care pot fi împărțite în subprobleme mai mici, care sunt similare cu problema originală. Fiecare apel recursiv va crea o structură (arborescentă) de apeluri, iar fiecare apel își va crea propriul cadru pe stiva programului. O funcție recursivă trebuie să aibă definită o condiție de oprire (cazul de bază) pentru a evita apelurile infinite.

* [Covorul lui Sierpinski](https://www.pbinfo.ro/probleme/2082/sierpinski)
* [Turnurile din Hanoi](https://www.pbinfo.ro/probleme/2527/hanoi)
* [Pav](https://kilonova.ro/problems/1653)
* [Permavg](https://www.infoarena.ro/problema/permavg)
* [Inv](https://www.infoarena.ro/problema/inv)


## Evaluare de Expresii

O problemă clasică pe la județeane este evaluarea expresiilor aritmetice. Aceasta presupune calcularea valorii unei expresii matematice date sub formă de șir de caractere. Evaluarea expresiilor poate fi realizată folosind diferite metode, atât iterative, cât și recursive. Pentru simplitate, vom discuta despre evaluarea expresiilor folosind recursivitate.

Ca concept, vom încerca la fiecare pas să identificăm primul termen al expresiei, fie prin parsarea unui număr, fie prin identificarea unei subexpresii între paranteze. După ce am identificat primul termen, vom extrage operatorul și vom evalua restul expresiei și vom combina rezultatele pentru a obține valoarea finală. O sursă care rezolvă problema [Evaluare](https://infoarena.ro/problema/evaluare) de pe [Infoarena](https://infoarena.ro) poate fi găsită [aici](evaluare.cpp).

* [Compresie](https://infoarena.ro/problema/compresie)
* [Bool](https://infoarena.ro/problema/bool)
* [Expresii min-max](https://infoarena.ro/problema/emm)
* [Logic](https://infoarena.ro/problema/logic)
* [Arh](https://infoarena.ro/problema/arh)
* [Multimi4](https://infoarena.ro/problema/multimi4)

#### Cursul de azi a fost ținut de Marciuc Andrei.
