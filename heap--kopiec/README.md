# Kopiec -- Heap

## Motywacja

Potrzebna nam __kolejka priorytetowa__ - struktura danych, która będzie zachowywała porządek względem ustalonego kryterium 
(na przykład kolejka priorytetowa przechowująca liczby całkowite, zwracająca przy operacji `pop` najmniejszą z dostępnych liczb).  
  
Pobierany element za pomocą operacji `pop` to element z korzenia kopca.  

.  

### Przykład

Kolejka priorytetowa z posortowanymi rosnąco elementami.  

**Możliwa Implementacja:**  
    `Kopiec MIN` - korzeń drzewa jest najmniejszym elementem w strukturze.   

.  

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

Przykładwe kopce __niepoprawne__ _(oznaczone czerwonym znakiem `X`)_ oraz **poprawne** *(oznaczone czerwonym znakiem `V`)*:  


<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/heap--kopiec/heap_wrong_and_correct.png"/>

## Implementacja

Chcemy, aby kopiec był jak najbardziej wydajny czasowo i pamięciowo. W związku z tym kopiec powinien opierać się na tablicy.  
Dostęp do danych węzłów opiera się na dostępie do odpowiednich komórek.  
Jeśli `i` to indeks wierzchołka wówczas:
  - `lewy_syn(kopiec, i) => kopiec[ (i+1)*2 - 1 ]`
  - `prawy_syn(kopiec, i) => kopiec[ (i+1)*2 ]`
  - `ojciec(kopiec, i) => jeśli i!=0 => kopiec[ (i-1)//2 ]`
  
 Gdzie operator `//` oznacza dzielenie całkowite.  
   
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

### Insert
Dodawanie elementów do kopca:

<img src="https://github.com/bsobocki/Algorytmy_StrukturyDanych/blob/master/heap--kopiec/heap_insert.png"/>

Kolorem czerwonym zaznaczony został nowo dodany element.  

