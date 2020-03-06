# Kopiec -- Heap

## Motywacja

Potrzebna nam __kolejka priorytetowa__ - struktura danych, która będzie zachowywała porządek względem ustalonego kryterium 
(na przykład kolejka priorytetowa przechowująca liczby całkowite, zwracająca przy operacji `pop` najmniejszą z dostępnych liczb).  
  
Pobierany element za pomocą operacji `pop` to element z korzenia kopca.  



### Przykład

Kolejka priorytetowa z posortowanymi rosnąco elementami.  

**Możliwa Implementacja:**  
    `Kopiec MIN` - korzeń drzewa jest najmniejszym elementem w strukturze.   



___WAŻNE___  
 
 Mimo, iż do implementacji kolejki priorytetowej możemy użyć kopca, to kopiec nie jest kolejką priorytetową!  
 Kopiec to kopiec :)
  
.  
  
## Struktura

Kopiec jest jednym z przykładów **drzewa binarnego**.  

Składa się z **korzenia - root** (zaznaczonego niebieską strzałką) oraz conajwyżej dwóch synów: lewego (kolor zielony) i prawego (kolor czerwony).  
<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/heap--kopiec/heap_root.png" />

Każdy wierzchołek i jego całe potomstwo - synowie synów, ich synowie, synowie tych synów synów synów itd. tworzą poddrzewo, które również jest kopcem.  


### Uzupełnianie  

Kopiec uzupełniany jest ***`w dół od lewej strony do prawej`*** (dodawanie ukazane poniżej oraz w pliku [heap_insert.png](https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/heap--kopiec/heap_insert.png) ).  
Do poziomu **k+1** można dodać element dopiero gdy poziom **k** jest cały zapełniony.  

Przykładwe kopce __niepoprawne__ _(oznaczone czerwonym znakiem `X`)_ oraz **poprawne** *(oznaczone zielonym znakiem `V`)*:  


<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/heap--kopiec/heap_wrong_and_correct.png"/>

## Implementacja

Chcemy, aby kopiec był jak najbardziej wydajny czasowo i pamięciowo. W związku z tym kopiec powinien opierać się na tablicy.  
Dostęp do danych węzłów opiera się na dostępie do odpowiednich komórek.  
Jeśli `i` to indeks wierzchołka wówczas:
  - `lewy_syn(kopiec, i) => kopiec[ (i+1)*2 - 1 ]`
  - `prawy_syn(kopiec, i) => kopiec[ (i+1)*2 ]`
  - `ojciec(kopiec, i) => jeśli i!=0 => kopiec[ (i-1)//2 ]`
  
 Gdzie operator `//` oznacza dzielenie całkowite.  
 Operacje przesunięć bitowych pomogą szybko dostać sie do poszczególnych elementów.   
   
 Mała wizualizacja:  
 <img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/heap--kopiec/heap_array.png" />

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

#### Złożoność
Czas wykonania **stały**  `O(1)`, potrzebujemy tylko dostęu do `H[0]`.  

### Insert

Dodawanie elementów do kopca:  

<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/heap--kopiec/heap_insert.png"/>   

Kolorem czerwonym zaznaczony został nowo dodany element.  

Dodawanie polega na włożeniu elementu tak jak zostało to pokazane powyżej, a następnie "przejściu przez drzewo w górę" w celu umiejscowienia dodanego elementu tak, aby został zachwany porządek kopcowy.  
  
 Co to oznacza?  
  
Dla ułatwienia załóżmy, ze operujemy na `kopcu MIN` *(analogicznie postępujemy na `kopcu MAX`)*.  
Dodany element zostaje porównywany z ojcem, a następnie, jeśli jego wartość jest mniejsza to zamieniają się miejscami.  
Następnie element ten, będąc na miejscu swojego poprzedniego ojca jest porównywany i ewentualnie zamieniany z teraźniejszym ojcem.  
Ta sytuacja powtarza się dopóki syn jest mniejszy od ojca lub dopóki nie dojdzeimy do korzenia, który ojca już nie ma ;_;  

Mały przykład:  

<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/heap--kopiec/heap_insert_example.png" />

#### Złożoność

Dodawanie elementu odbywa się w czasie logarytmicznym `O(log n)`, gdzie podstawą logarytmu jest `2`, a `n` oznacza liczbę elementów w kopcu.  

### Przywracanie porządku

Jak powyżej można przeczytać, Kopiec potrzebuje swojego porządku, aby prawidłowo i szybko funkcjonować.  

Przywracanie porządku dla danego elementu `e` polega na sprawdzeniu, czy jest on na odpowiednim miejscu, to znaczy, czy jego ojciec jest od niego mniejszy (działamy na kopcu MIN). Jeśli tak to zamieniamy się miejscami i procedura przywracania porządku wywoływana jest dla `v`, które teraz jest już na miejscu swojego ojca. Idziemy w ten sposób *"do góry"* dopóki każdy kolejny ojciec jest większy lub do korzenia.

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
<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/heap--kopiec/heap_unordered_array.png"/>

Możemy zauważyć, że nasz wierzchołek bez żadnego potomstwa jest już drzewem, a nawet kopcem.  
Zatem potraktujemy tak liście naszego kopca, wierzchołki z najniższego poziomu.  
<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/heap--kopiec/heap_one-element_heaps.png"/>

Wiemy, że ich moze byc nawet połowa wszystkich elementów! 

Dobrze. mamy nasze poddrzewa jednoelementowe. Chcemy dołączyć do nich odpowiadających im ojców. Każdy ojciec ma dwóch synów, więc o ile to możliwe dobieramy w pary sąsiadów i dobieramy ich ojca względem pozycji w tablicy.  
Nie każdy będzie dobrym ojcem. Ten z wierzchołków `v_i-1`, `v_i` *(i= 1, 2, ..., N)*, którego wartość będzie najmniejsza spośród danej trójki wierzchołków (ojciec i synowie) staje się teraz ojcem.  
<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/heap--kopiec/heap_small_heaps.png"/>  

Będziemy krok ten powtarzać. Musimy jednak pamiętać, że zmiany nie tylko będą wprowadzane w danej trójce, ale w całym poddrzewie. Dlatego po dodaniu ojca musimy "zjechać nim w dół".    
<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/heap--kopiec/heap_bigger_heaps.png"/>  

Dodanie korzenia sprawi, że mamy już cały kopiec.  
<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/heap--kopiec/heap_biggest_heaps.png"/>

A tak wygląda nasza tablica:  
<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/heap--kopiec/heap_ordered_array.png"/>   
