# Kopiec -- Heap

## Motywacja

Potrzebna nam __kolejka priorytetowa__ - struktura danych, która będzie zachowywała porządek względem ustalonego kryterium 
(na przykład kolejka priorytetowa przechowująca liczby całkowite, zwracająca przy operacji `pop` najmniejszą z dostępnych liczb).  
  
Pobierany element za pomocą operacji `pop` to element z korzenia kopca.  

### Przykład

Kolejka priorytetowa z posortowanymi rosnąco elementami:  
**Możliwa Implementacja:** `Kopiec MIN` - korzeń drzewa jest najmniejszym elementem w strukturze.   

___WAŻNE___  

Mimo, iż do implementacji kolejki priorytetowej możemy użyć kopca, to kopiec nie jest kolejką priorytetową!  
Kopiec to kopiec :)

## Struktura

Korzeń jest jednym z przykłądów **drzewa binarnego**.  

Składa się z **korzenia - root** (zaznaczonego niebieską strzałką) oraz conajwyżej dwóch synów: lewego (kolor zielony) i prawego (kolor czerwony).  
<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/heap--kopiec/heap_root.png" />

Każdy wierzchołek i jego całe potomstwo - synowie synów, ich synowie, synowie tych synów synów synów itd. tworzą poddrzewo, które również jest kopcem.  

Kopiec uzupełniany jest ***`w dół od lewej strony do prawej`*** (dodawanie ukazane poniżej oraz w pliku [heap_insert.png](https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/heap--kopiec/heap_insert.png) ).  

Przykładwe kopce __niepoprawne__ _(oznaczone czerwonym znakiem `X`)_ oraz **poprawne** *(oznaczone czerwonym znakiem `V`)*:  


<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/heap--kopiec/heap_wrong_and_correct.png"/>

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

### Insert
Dodawanie elementów do kopca:

<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/heap--kopiec/heap_insert.png"/>

Kolorem czerwonym zaznaczony został nowo dodany element.  

