# Dziel i Zwyciężaj

# Idea 

Idea tej metody programowania polega na tym, aby dany problem podzielić na **mniejsze podproblemy**, na których będziemy mogli operować.
Podział problemu na mniejsze sprawia, że nieraz czas wykonania (ilość wykonywanych operacji) się zmniejsza, w porównaniu do sytuacji w której byśmy operowali na całym problemie.

```
Dane: X

1) Transformacja X na X_1, X_2, ..., X_k
2) Dla każdego X_i (i = 1, 2, 3, ..., k) oblicz wynik W_i danego problemu
3) Skonstruuj wynik W dla X z W_1, W_2, ..., W_k
```

# Przykłady

## Merge Sort

```
Dane: 
  X = a_1, a_2, a_3, ..., a_n/2, a_(n/2)+1, ..., a_n
  
1) 
  X_1 = a_1, a_2, ..., a_n/2
  X_2 = a_(n/2)+1, a_(n/2)+2, ..., a_n
  
2) 
  sortuj(X_1)
  sortuj(X_2)

3)
  scal(X_1, X_2)
```
**Złożoność czasowa**:  
*O(n log n)*

Instrukcja `sortuj(X_1)` wywołuje merge sort na `X_1`, dzieli je ponownie na małe części jeśli `X_1` jest dostatecznie duże (do ustalenia), a w przeciwnym wypadku (dla małych danych) możemy użyć prostszego sortowania, np `InsertSort`.  

**Złożoność czasowa - sortuj(X_1)**:  
*O( n/2 log n/2 )*

Instrukcja `scal(X_1, X_2)` przechodzi po posortowanych tablicach `X_1`i `X_2` po kolei przyrównując elementy i wstawiając je do tablicy wynikowej odpowiednio, aby była ona już posortowana.  

**Złożoność czasowa - scal(X_1, X_2)**:  
*O( n )*
