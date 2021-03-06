# Kopiec -- Heap

Ten dokumaent jest również dostępny na [hackmd.io](https://hackmd.io/_76DTW1vRxewe-M3eBSjpA). Oczywiście oprawa graficzna tam jest o wiele lepsza :P

## Co znajdziemy w tym dokumencie
  - ***[Motywacja](#motywacja)***
    - ***[Przykład](#przykład)***
    - ***[Ważne](#ważne)***
  - ***[Struktura](#struktura)***
    - ***[Wysokość](#wysokość)***
    - ***[Uzupełnianie](#uzupełnianie)***
  - ***[Implementacja](#implementacja)***
  - ***[Porządek Kocpowy](#porządek-kopcowy)***
    - ***[Kryterium](#kryterium)***
  - ***[Operacje](#operacje)***
    - ***[Minimum](#minimum)***
      - ***[Złożoność-minimum](#złożoność-minimum)***
    - ***[Insert](#insert)***
      - ***[Złożoność-insert](#złożoność-insert)***
    - ***[Delete_min](#delete_min)***
      - ***[Co chcemy zrobić?](#co-chcemy-zrobić)***
      - ***[Usuwanie przez zastąpienie ostatnim elementem](#usuwanie-przez-zastąpienie-ostatnim-elementem)***
      - ***[Usuwanie z użyciem dziury](#usuwanie-z-użyciem-dziury)***
      - ***[Złożoność-delete_min](#złożoność-delete_min)***
  - ***[Przywracanie porządku](#przywracanie-porządku)***
  - ***[Budowanie kopca z dostępnej tablicy](#budowanie-kopca-z-dostępnej-tablicy)***
      - ***[Złożoność-budowanie_kopca_z_tablicy](#złożoność-budowanie_kopca_z_tablicy)***
  - ***[Heap Sort](#heap-sort)***
    - ***[Jak tego dokonać?](#jak-tego-dokonać)***
  - ***[Kopiec MIN-MAX](#kopiec-min-max)***
  - ***[Struktura Kopca MIN-MAX](#struktura-kopca-min-max)***
  - ***[Porządek Kocpowy w Kopcu MIN-MAX](#porządek-kopcowy-w-kopcu-min-max)***
  - ***[Operacje-MIN-MAX](#operacje-min-max)***
    - ***[Minimum-MIN-MAX](#minimum-min-max)***
    - ***[Maximum-MIN-MAX](#maximum-min-max)***
    - ***[Insert-MIN-MAX](#insert-min-max)***
    - ***[Delete_min Delete_max](#delete_min-delete_max)***

## Motywacja

Potrzebna nam __kolejka priorytetowa__ - struktura danych, która będzie zachowywała porządek względem ustalonego kryterium 
(na przykład kolejka priorytetowa przechowująca liczby całkowite, zwracająca przy operacji `pop` najmniejszą z dostępnych liczb).  
  
Pobierany element za pomocą operacji `pop` to element z korzenia kopca.  



### Przykład

Kolejka priorytetowa z posortowanymi rosnąco elementami.  

**Możliwa Implementacja:**  
    `Kopiec MIN` - korzeń drzewa jest najmniejszym elementem w strukturze.   



### WAŻNE  
 Mimo, iż do implementacji kolejki priorytetowej możemy użyć kopca, to kopiec nie jest kolejką priorytetową!  
 Kopiec to kopiec :)
  

  
## Struktura

Kopiec jest jednym z przykładów **drzewa binarnego**.  

Składa się z **korzenia - root** (zaznaczonego niebieską strzałką) oraz conajwyżej dwóch synów: lewego (kolor zielony) i prawego (kolor czerwony).    
<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/struktury_danych/heap--kopiec/images/heap_root.png" />

Każdy wierzchołek i jego całe potomstwo - synowie synów, ich synowie, synowie tych synów synów synów itd. tworzą poddrzewo, które również jest kopcem.  

### Wysokość  

Każdy wierzchołek ma 2-ch synów, stąd każdy kolejny poziom ma 2 razy więcej wierzchołków.  
Oznacza to że liczba takich poziomów wynosi `floor( log n ) + 1` (podłoga z logarytmu o podstawie 2 z liczby elementów kopca plus 1, bo liczymy, że drzewo jednoelementowe ma wysokość 1).

***Wniosek***   
Wysokość drzewa wynosi `O(log n)`, dlatego operacje `przejścia po drzewie w górę czy w dół` mają złożoność `O(log n)`.


### Uzupełnianie  

Kopiec uzupełniany jest ***`w dół od lewej strony do prawej`*** (dodawanie ukazane poniżej oraz w pliku [heap_insert.png](https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/heap--kopiec/images/heap_insert.png) ).  
Do poziomu **k+1** można dodać element dopiero gdy poziom **k** jest cały zapełniony.  

Przykładwe kopce __niepoprawne__ _(oznaczone czerwonym znakiem `X`)_ oraz **poprawne** *(oznaczone zielonym znakiem `V`)*:  


<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/struktury_danych/heap--kopiec/images/heap_wrong_and_correct.png"/>

## Implementacja

Chcemy, aby kopiec był jak najbardziej wydajny czasowo i pamięciowo. W związku z tym kopiec powinien opierać się na tablicy.  
Dostęp do danych węzłów opiera się na dostępie do odpowiednich komórek.  
Jeśli `i` to indeks wierzchołka wówczas:
  - `lewy_syn(kopiec, i)  =>  kopiec [ (i+1)*2 - 1 ]`
  - `prawy_syn(kopiec, i)  =>  kopiec [ (i+1)*2 ]`
  - `ojciec(kopiec, i)  =>  jeśli i!=0 => kopiec [ (i-1)//2 ]`
  
 Gdzie operator `//` oznacza dzielenie całkowite.  
 Operacje przesunięć bitowych pomogą szybko dostać sie do poszczególnych elementów.   
 ```cpp
 // dzielenie całkowite przez 2 określimy jako przesunięcie bitowe o 1 bit w prawo
 (i-1) >> 1
 // mnożenie razy 2 określimy jako przesunięcie bitowe o 1 bit w lewo
 (i+1) << 1
 ```
   
 Mała wizualizacja:    
 
 <img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/struktury_danych/heap--kopiec/images/heap_array.png" />

## Porządek Kopcowy

Każdy kopiec jest zaprojektowany według porządku kopcowego.  
Każdy wierzchołek, powinien spełniać pewne kryterium względem swego potomstwa.  

### Kryterium

**Przykład:** wspomniany wcześniej `KOPIEC MIN` - `heap MIN`.  

W Kopcu tym korzeń drzewa powinien mieć najmniejszą możliwą wartość z całej struktury.

Zatem kryterium brzmi mniej więcej tak:
```
Każdy wierzchołek posiada klucz (wartość w węźle) mniejszy niż jego potomstwo.  
```
Można zatem zauważyć, ze wtedy **korzeń kopca (root)** ma najmniejszą wartośc spośród wszystkich węzłów.  

## Operacje 

Oznaczymy nasz kopiec MIN jako H.  

### Minimum

```cpp
  return H[0];
```

#### Złożoność-minimum
Czas wykonania **stały**  `O(1)`, potrzebujemy tylko dostęu do `H[0]`.  

### Insert

Dodawanie elementów do kopca:  
 
<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/struktury_danych/heap--kopiec/images/gif-insert/insert_heap.gif"/>
Kolorem czerwonym zaznaczony został nowo dodany element.   
Dla osób, które nie przepadają za obrazkami GIF: 
[heap_insert.png](https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/struktury_danych/heap--kopiec/images/heap_insert.png)

Dodawanie polega na włożeniu elementu tak jak zostało to pokazane powyżej, a następnie "przejściu przez drzewo w górę" w celu umiejscowienia dodanego elementu tak, aby został zachwany porządek kopcowy.  
  
 Co to oznacza?  
  
Dla ułatwienia załóżmy, ze operujemy na `kopcu MIN` *(analogicznie postępujemy na `kopcu MAX`)*.  
Dodany element zostaje porównywany z ojcem, a następnie, jeśli jego wartość jest mniejsza to zamieniają się miejscami.  
Następnie element ten, będąc na miejscu swojego poprzedniego ojca jest porównywany i ewentualnie zamieniany z nowym ojcem.  
Ta sytuacja powtarza się dopóki syn jest mniejszy od ojca lub dopóki nie dojdziemy do korzenia, który ojca już nie ma ;_;  

Mały przykład:  
```cpp
heap_min H;
std::vector<int> ints = {10, 7, 8, 9, 4, 2, 6, 1}; 

for (int i : ints) 
  H.insert(i);
```

Mniej więcej będzie wyglądać tak:  

<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/struktury_danych/heap--kopiec/images/heap_insert_example.png" />

#### Złożoność-insert

Dodawanie elementu odbywa się w czasie logarytmicznym `O(log n)`, gdzie podstawą logarytmu jest `2`, a `n` oznacza liczbę elementów w kopcu.  


### Delete_min

Możemy już dodawać elementy do naszej struktury, a zatem możemy łatwo zaimplemmentować operację `push` w naszej kolejce priorytetowej.   
Potrzebna będzie nam jeszcze funkcja `pop`, która zwraca i usuwa z kolejki pierwszy względem ustalonego porządku element.  

Pomoże nam w tym operacja na kopcu - ***delete_min***.  

#### ***Co chcemy zrobić?***

Chcemy zwrócić korzeń struktury i go usunąć, a następnie przywrócić porządek kopcowy.  

Możemy to zrobić na dwa sposoby:  
```
Pobieranie elementu na samym dole na prawo (ostatni z tablicy)  -> dodanie do korzenia ->  "jazda w dół"
```
lub  
```
Usunięcie korzenia i pozostawienie dziury -> "jazda z dziurą w dół" -> pobranie elementu na samym dole na prawo -> wstawienie go zamiast dziury -> "jazda w górę"
```

`n` - liczba elementów w kopcu

#### Usuwanie przez zastąpienie ostatnim elementem 

Pierwszy sposób brzmi dość prosto i w miarę intuicyjnie. Chcemy po prostu mieć jak najmniej zaburzeń, więc element ostatni z tablicy jest najlepszą opcją, aby struktura i porządek kopcowy poza korzeniem pozostali nienaruszeni.  
**Ilość porównań** będzie wynosić `2 * log n`, ponieważ najpierw porównamy synów pomiędzy sobą, a następnie ojca i mniejszego syna.   
<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/struktury_danych/heap--kopiec/images/heap_delete_min.png"/>

#### Usuwanie z użyciem dziury

Drugi sposób teoretycznie jest bardziej skomplikowany, ale przekonamy się, że może być lepszy.  
Mamy diurę, pusty element, który "idzie w dół" drzewa, a my ignorujemy póki co fakt, że naruszona zostaje struktura kopca. Z każdym krokiem staje się ojcem dla dwóch wierzchołków. Porównujemy te dwa wierzchołki i mniejszy z nich staje się ojcem, a dziura przechodzi na jego miejsce. Dzieje się tak, dopóki ten pusty element nie dojdze, gdzie już synów mieć nie będzie. Po dotarciu tam nagle zauważamy, że nasza struktura zostaje naruszona, a więc któryś element musi wejść na jej miejsce. Na ochotnika zgłasza się ostatni element `v` z tablicy (prawy dolny na ostatnim poziomie), ale może zdarzyć się, że będzie on zbyt mały, aby pozostać w tym miejscu, dlatego "idziemy z nim w górę".  
Teoretycznie **ilość porównań** wynosić będzie `2 * log n`, ponieważ "idąc w dół" dziurą porównujemy ze sobą tylko jej kolejnych synów, natomiast "idąc w górę" naszym ochotnikiem `v` porównujemy go z kolejnymi ojcami.  
<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/struktury_danych/heap--kopiec/images/heap_delete_min_hole.png"/>

```
- Czy zatem są one równe pod względem ilości porównań?

- Nie.
```

Zauważmy, że "idąc w górę z dołu" elementem `v` w zasadzie nie zajdziemy za daleko. Prawdopodobieństwo, że ten element będzie wystarczająco mały, żeby pójść wysoko w górę (na szczyt na pewno nie dojdzie, bo inaczej nie byłby na dole) jest znikome, dlatego złożoność drugiego sposobu będzie dużo niższa.

#### Złożoność-delete_min

Usunięcie elementu wynosi `O(1)`, natomiast wstawianie na jego miejsce, któregoś z istniejących już wierzchołków wiąże się z kosztem `O(log n)`, stąd operacja **delete_min** ma złożoność `O(log n)`.

### Przywracanie porządku

Jak powyżej można przeczytać, Kopiec potrzebuje swojego porządku, aby prawidłowo i szybko funkcjonować.  

Przywracanie porządku dla danego elementu `e` polega na:
1) "pójściu w górę" :  
  Sprawdzeniu, czy jest on na odpowiednim miejscu, to znaczy, czy jego ojciec jest od niego mniejszy.  
  Jeśli tak to zamieniają się miejscami i procedura przywracania porządku wywoływana jest dla `e`, które teraz jest już na miejscu swojego ojca.  
  Idziemy w ten sposób *"do góry"* dopóki każdy kolejny ojciec jest większy lub do korzenia.

2) "pójściu w dół" :  
  Sprawdzeniu, który syn jest mniejszy, a następnie czy dany wierzchołek `e` jest mniejszy od mniejszego z nich.  
  Jeśli jest większy, to zamieniamy je miejscami. W ten sposób najmniejszy z danej trójki (ojca i synów) zostaje ojcem.
  Idziemy w ten sposób *"w dół"* dopóki któryś z synów będzie mniejszy od danego wierzchołka, lub dopóki nie dojdziemy do najniższego poziomu drzewa.   
  
Tak przywracamy porządek dla danego `v`. Używamy przywracania porządku w operacjach takich jak ***`insert`***, ***`delete_min`***, czy zmiany wartosci danego wierzchołka (przy zmianie wartości możemy "iść w górę", ale też mozemy "iść w dół", bo wartość może być za duża na swoje miejsce. Warto o tym pamiętać.  

Jednak przywracanie porządku moze dotyczyć nie tylko pojedyńczego elementu, ale o tym za chwilę. ;)  



## Budowanie kopca z dostępnej tablicy

Dobrze. Mamy nasz kopiec, umiemy dodawać do niego elementy metodą ***insert*** oraz pobierać minimalny element i go usuwać za pomocą funkcji ***delete_min***. Jednak dotyczy to sytuacji, w której mamy pusty kopiec i chcemy na nim operować i budować go poprzez wstawianie elementów.  

Musimy jednak wiedzieć, że kopiec da się zbudować z już istniejącej tablicy.  

Jak?  

Tutaj już potrzebne będzie przywrócenie porządku kopcowego.  

Mamy tablicę. Chcemy potraktować ją jako kopiec, ale nie pasuje nam ustawienie jej elementów. Żadnego porządku! (oczywiście mówię o przypadku, w którym elementy w tablicy sa losowe).  

Mówiliśmy wcześniej o tym, że wierzchołek wraz ze swoim potomstwem tworzy poddrzewo, które też ma porządek kopcowy.  
Zatem może warto zacząć z tej strony?  
<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/struktury_danych/heap--kopiec/images/heap_unordered_array.png"/>

Możemy zauważyć, że nasz wierzchołek bez żadnego potomstwa jest już drzewem, a nawet kopcem.  
Zatem potraktujemy tak liście naszego kopca, wierzchołki z najniższego poziomu.  
<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/struktury_danych/heap--kopiec/images/heap_one-element_heaps.png"/>

Wiemy, że moze ich byc nawet połowa wszystkich elementów! 

Dobrze. mamy nasze poddrzewa jednoelementowe. Chcemy dołączyć do nich odpowiadających im ojców. Każdy ojciec ma dwóch synów, więc o ile to możliwe dobieramy w pary sąsiadów i dobieramy ich ojca względem pozycji w tablicy.  
Nie każdy będzie dobrym ojcem. Ten z wierzchołków `v_i-1`, `v_i` *(i= 1, 2, ..., N-1)*, którego wartość będzie najmniejsza spośród danej trójki wierzchołków (ojciec i synowie) staje się teraz ojcem.  
<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/struktury_danych/heap--kopiec/images/heap_small_heaps.png"/>  

Będziemy krok ten powtarzać. Musimy jednak pamiętać, że zmiany nie tylko będą wprowadzane w danej trójce, ale w całym poddrzewie. Dlatego po dodaniu ojca musimy "zjechać nim w dół".    
<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/struktury_danych/heap--kopiec/images/heap_bigger_heaps.png"/>  

Dodanie korzenia sprawi, że mamy już cały kopiec.  
<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/struktury_danych/heap--kopiec/images/heap_biggest_heaps.png"/>

A tak wygląda nasza tablica:  
<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/struktury_danych/heap--kopiec/images/heap_ordered_array.png"/>   


#### Złożoność-budowanie_kopca_z_tablicy

```
przejście wierzchołka ' v ' z jednego poziomu w drugi (w dół) kosztuje 2 porównania: 
  - porównanie dwóch synów 
  - porównanie mniejszego syna i ojca 
```

| Krok  | Złożoność |
| --- | --- |
| Najpierw ustalamy, że liście dostępnego drzewa (tablicy) to małe kopce. | `2*log 1` |
| Dołączamy ojca dla każdej pary (i jeśli liści była nieparzysta ilość to dla jednego wierzchołka - samotnika) i idziemy z nim w dół | `2*log 2` |
| ... | ... | 
| Do utworzonych drzew (k wszystkich wierzchołków) dodajemy ojców łączących sąsiadujące ze sobą pary drzew i "idziemy nim w dół" | `2*log k` |
| ... | ... |
| Dodajemy korzeń i "idziemy nim w dół" | `2*log n` |

 ***Razem***  
```
2 ( log 1 + log 2 + ... + log k + ... + log n )  =  O(n) 
```

A zatem szacowana złożoność wynosi ` O(n) `.

## Heap Sort

No dobrze, mamy kopiec, wiemy jak działa i jak wykonywać na nim potrzebne operacje.  
Kopiec nasz działa dość szybko, a więc nasuwa się pytanie:
```
Czy nie możemy użyć kopca do sortowania tablicy?
```
Odpowiedź jest dość pozytywna:
```
Owszem, możemy.
```

### Jak tego dokonać?

Specyfikujmy problem.  

***Dane***: tablica **n**-elementowa `T [1 .. n]` z losowo rozmieszczonymi w niej elementami   
***Zadanie***: uporządkowana tablica `T` według określonego porządku  


Algorytm:

1) Zbuduj kopiec z `T` ( [Budowanie kopca z dostępnej tablicy](#budowanie-kopca-z-dostępnej-tablicy) )
2) **n** razy wykonaj **delete_min**, a następnie wstaw dane *minimum* na koniec tablicy (gdy już uporządkujemy drzewo i ostatnie miejsce w tablicy będzie puste).

```cpp
for (int i = n; i!=1; i--){
  swap( T[1], T[i] );
  przesun_w_dol( T, 1 ); // argumenty: kopiec, indeks
}
```

#### Złożoność 
`O( n log n )`.

***Jak można trochę to przyspieszyć?***   
Możemy starać się o to, żeby ***stała***, która towarzyszy `n log n` w szacowaniu `O(n log n)` była możliwie jak najmniejsza.  
Do tego celu użyjemy opcji **delete_min** używającą [dziurę](#usuwanie-z-użyciem-dziury).  


## Kopiec MIN-MAX

Dobrze by było, gdyby nasza **kolejka priorytetowa** posiadała równocześnie operację `pop_min` i `pop_max`.  

***Jak moglibyśmy skonstruować naszą kolejkę, aby umożliwić jej usuwanie najmniejszego i największego elementu?***  

***Naiwne rozwiązanie***   
Utworzyć 2 kopce: MIN i MAX  
Usuwanie i dodawanie elementów powinno odbywać się dla obu kopców  
```
Zbyt duże koszty! Chcemy minimalizować czas i pamięć...
```

***Lepsze rozwiązanie***  
Z pomocą przychodzi nam `kopiec MIN-MAX`.  


## Struktura Kopca MIN-MAX

Kopiec MIN-MAX składa się z **`kopca MIN`** zawierającego `floor( n/2 )` elementów,  
oraz **`kopca MAX`** zawierającego `ceil( n/2 )` elementów.  
Są one ułożone tak, że **kopiec MAX** jest "do góry nogami" połączony do **kopca MIN**.  

<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/struktury_danych/heap--kopiec/images/heap_min_max.png" />

## Porządek Kopcowy w Kopcu MIN-MAX

Porządek kopcowy polega na tym, aby porządek względem wierzchołków zachowywany był pionowo (tak jak w kopcu MIN czy kopcu MAX oddzielnie).  

Na każdej ścieżce od korzenia do korzenia powinien zostać zachowany porządek kopcowy.   

**Co to oznacza?**

Na samej górze (górny korzeń) mamy element minimalny, natomiast na samym dole (dolny korzeń) mamy element maksymalny.  
Kopce zaczynają się od korzeni aż do połowy struktury.  

Porządek tej struktury polega na tym, że element `v` jest większy od swojego poprzednika (wierzchołka umiejscowionego wyżej) i mniejszy od następnika (wierchołka umiejscowionego niżej).    

**Jak przebiega porządek na granicy kopców?**

Wyobraźmy sobie, puste liście będące potomkami liści obu kopców:

<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/struktury_danych/heap--kopiec/images/heap_min-max_empty_elements.png" />

które są łączone w taki sposób: 

<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/struktury_danych/heap--kopiec/images/heap_min-max_connetions.png" />

Po dodaniu elementów łączone są one przebiegiem porządku następująco:

<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/struktury_danych/heap--kopiec/images/heap_min-max_insert.png" />

## Operacje-MIN-MAX

Operacje wykonywane na kopcu MIN-MAX są zbliżone do tych wykonywanych na kopcu MIN i kopcu MAX.

### Minimum-MIN-MAX

Zwracanie wartości elementu najmniejszego (korzenia MIN).

#### Złożoność 
Potrzebujemy tylko dostępu do wartości elementu kopca `H`, stąd złożoność wynosi: `O(1)`.

### Maximum-MIN-MAX

Zwracanie wartości elementu największego (korzenia MAX).

#### Złożoność 
Potrzebujemy tylko dostępu do wartości elementu kopca `H`, stąd złożoność wynosi: `O(1)`.

### Insert-MIN-MAX

Dodawanie odbywa się na przemian do kopca MIN i kopca MAX.  
Na początku chcemy dodać element do kopca MAX, ponieważ dla nieparzystej liczby elementów to ten kopiec powinien zawierać więcej elementów.  

Dodawanie odbywa się od lewej do prawej, tak jak w kopcu MIN i kopcu MAX.  

<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/struktury_danych/heap--kopiec/images/gif-insert/min-max/insert_min-max.gif" />

Po każdym dodaniu elementu `v` porównywane są wierzchołki:  

<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/struktury_danych/heap--kopiec/images/heap_min-max_check.png" />  

```
Jeśli  v  jest mniejszy od  l  to  v  "idze w górę" (wgłąb kopca MIN).
W przeciwnym wypadku jeśli  v  jest większy od  h  to  v  "idzie w dół" (wgłąb kopca MAX).
```

### Delete_min Delete_max

**Delete_min** przebiega podobnie jak do [zwykłego kopca MIN](#usuwanie-przez-zastąpienie-ostatnim-elementem) z tym, że element, który jest dostarczany na miejsce usuniętego korzenia to albo element maksymalny z kopca MIN (jeśli oba kopce mają tyle samo elementów), albo minimalny element z kopca MAX (jeśli kopiec MAX zawierał więcej elementów).  
