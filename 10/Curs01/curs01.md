# Intro

Salutare și bine ați venit la o nouă ediție a cursurilor _Hai la Olimpiadă!_

Anul acesta vom parcurge împreună materia pentru clasa a 10a. Programa pentru olimpiadă se poate găsi [aici](https://cdn.sepi.ro/oni2024/Programa%20pentru%20olimpiada%20de%20informatica_gimnaziu%20si%20liceu.pdf).

În principiu, noi vom lucra probleme de pe următoarele site-uri:

* [Infoarena](https://infoarena.ro/)
* [Kilonova](https://kilonova.ro/)
* [Codeforces](https://codeforces.com/)
* [CSES](https://cses.fi/)

Suportul teoretic pentru curs va fi inspirat din următoarele resurse:

* [Infoarena - Arhiva Educațională](https://infoarena.ro/arhiva-educationala)
* [CP-algorithms](https://cp-algorithms.com/)
* [USACO guide](https://usaco.guide/)

Listele cu toate probleme pentru OJI/ONI le găsiți mai jos:

* [OJI](https://kilonova.ro/problem_lists/458/progress)
* [ONI](https://kilonova.ro/problem_lists/555/progress)

Stilul nostru de predare este să acoperim noțiuni teoretice la curs, discutăm probleme, iar implementările de la problemele discutate vă rămân vouă ca temă pentru acasă. Consider că în acest mod putem să abordăm mai multe probleme în cele două ore pe care le avem noi săptămânal.

O să încercăm (sperăm) lunar să vă dăm câte o simulare cu probleme adecvate de OJI-ONI.

# Stiva

Stiva este o structură de date liniară care respectă principiul LIFO (Last In First Out). Aceasta înseamnă că ultimul element introdus în stivă va fi primul care va fi scos (de exemplu, o stivă de vase). Stiva poate fi implementată în mai multe moduri, atât cu ajutorul unui vector, cât și cu ajutorul unei liste înlănțuite. De obicei, în probleme, vom folosi `std::stack <T>` din STL.

Stiva poate fi folosită pentru a rezolva probleme de tip backtracking (simularea apelurilor recursive), pentru a evalua expresii matematice, pentru a verifica parantezarea corectă a unei expresii și multe altele. Astăzi, ne vom concentra pe un caz particular de utilizare a stivei, și anume când vrem să determinăm, în timp liniar, pentru fiecare element dintr-un vector, pe ce întreaga secvență de elemente consecutive, acesta este cel mai mic/mare element.

Enunț problemă: [Skyline](https://www.pbinfo.ro/probleme/2728/skyline)

Problema se rezolvă prin a determina, pentru fiecare bloc de clădire, pe ce secvență de clădiri consecutive, aceasta este minimă. Vom ține în stivă indicii blocurilor de clădire, iar pentru fiecare bloc de clădire, vom elimina din stivă toate blocurile care sunt mai înalte decât blocul curent. În acest fel, vom putea determina rapid care este blocul cel mai apropiat care este mai mic decât blocul curent.

```cpp
// foarte important de verificat că stiva nu este goală înainte de a apela top() sau pop()!!!
while (!stiva.empty() && h[stiva.top()] >= h[i])
    stiva.pop();

if (stiva.empty())
    st[i] = 0;
else
    st[i] = stiva.top();

stiva.push(i);
```

Pentru a face pentru partea dreaptă, se procedează similar. La final, pentru fiecare bloc de clădire, știm pe ce secvență de clădiri consecutive, acesta este cel mai mic element. În final, putem calcula aria maximă a unui dreptunghi care poate fi format din aceste blocuri de clădire folosind [sumele parțiale](https://www.pbinfo.ro/articole/5615/sume-partiale-in-tablouri). Astfel, problema poate fi rezolvată în timp liniar $\mathcal{O}(n)$. Soluția poate fi găsită [aici](skyline.cpp).

* [Fadema](https://kilonova.ro/problems/891)
* [Bmatrix](https://infoarena.ro/problema/bmatrix)
* [Leftmax](https://kilonova.ro/problems/929)
* [Dreptunghiuri5](https://infoarena.ro/problema/dreptunghiuri5)

#### Cursul de azi a fost ținut de Ivan Andrei-Cristian.
