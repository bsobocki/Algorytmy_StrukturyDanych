# Algorytmy Zachłanne

# Idea

Idea algorytmów zachłannych polega na tworzeniu algorytmów takich, które w danej iteracji dokonują najbardziej trafnego wyboru. 

# Przykłady

## Problem Wydawania Reszty
---

Przykładem może być ***problem wydawania reszty***:


***Dane***:  
    `c1`, `c2`, `c3`, ..., `ci`, ..., `cn` - liczby naturalne, nominały  
    `R` - reszta, kwota do wydania przez automat  

***Zadanie***:  
  1) czy `R` można przedstawić jako sumę (kombinację liniową)   
    składników w taki sposób, że  `ci`  może się powtarzać  
    dla `i = 1, 2, 3, ..., n ` 
    
  2) chcemy przedstawić `R` jako *kombinację liniową* składników  `ci`  
    w taki sposób, aby tych składników było możliwie jak najmniej  

  Innymi słowy: znaleźć wielozbiór S elementów  `ci`,   
    którego suma elementów wynosi `R`, a *moc zbioru* `S` jest minimalna  


Możliwe rozwiązanie:  

Zakładając, że `R` ***można*** przedstawić jako *kombinację liniową* elementów `ci`:  
```
    S <- Ø
    dopóki R > 0:
       wybierz największy możliwy element ci mniejszy lub równy R
       R <- R - ci
       S <- S ∪ { ci }
    zwróć S
```  
* bierzemy zbiór pusty S  
* chcemy za pomocą jak największych nominałów wyznaczyć resztę **R**  
* do tego celu bierzemy największy możliwy (mniejszy równy) nominał **ci**  
* wrzucimy go do naszej sumy, a zatem chcemy pomniejszyć **R** o **ci**, aby poprawnie szukać dalszych nominałów  
* wrzucamy go do naszego zbioru **S**  
* akcję powtarzamy dopóki możemy znaleźć jakiś nominał *(zakładając, ze możemy wyznaczyć **R** jako kombinację liniową nominałów to możemy znaleźć nominał dopóki **R>0**)*  
* zwracamy wynik - zbiór **S**  
 

Algorytm zachłanny nie zawsze jednak potrafi znaleźć rozwiązanie i przedstawić resztę `R` za pomocą *kombinacji liniowej* elementów `ci`. 

**Przykład**:
```
    c = { 50, 51 }
    R = 100 
    
    Algorytm zachłanny weźmie na początku liczbę 51, 
    a następnie będzie chciał liczbę 49 przedstawić za pomocą tych nominałów.
```
Algorytm zachłanny również nie zawsze znajdzie rozwiązanie optymalne (`S` z najmniejszą możliwą liczbą elementow):

**Przykład**:
```
    c = {1, 7, 9}
    R = 14
    
    Algorytm zachłanny weźmie na początku liczbę 9, 
    a następnie 5 razy liczbę 1, 
    natomiast algorytm optymalny weźmie dwa razy liczbę 7.
```

## Problem MST - Minimalne Drzewo Rozpinające
---

Przykładem mogą być algorytmy:  
* [Algorytm Prima](https://pl.wikipedia.org/wiki/Algorytm_Prima)
* [Algorytm Kuskala](https://pl.wikipedia.org/wiki/Algorytm_Kruskala)
* [Algorytm Borůvki](https://pl.wikipedia.org/wiki/Algorytm_Bor%C5%AFvki)
  
### Algorytm Kruskala
--- 

**Dowód poprawności algorytmu Kruskala**:
```
    Zostanie uzupełniony :D
```

### Algorytm Borůvki
---

**Dowód poprawności algorytmu Borůvki**:
```
    Zostanie uzupełniony :D 
    Póki co zajrzyj na wikipedię ;)
```

**Informacja na temat algorutmu Borůvki**:
```
    Liczba faz algorytmu Borůvki jest logarytmiczna.
    
    Bierze się to z tego faktu, że za każdym razem (w każdej fazie) 
    dla każdego wierzchołka wybieramy krawędź incydentną z tym wierzchołkiem
    łączącą go z innym wierzchołkiem bądź superwierzchołkiem.
    Powstaje wtedy superwierzchołek zawierający te dwa (super)wierzchołki.
    A Zatem liczba wierzchołków zmiejszyła się conajmniej dwukrotnie 
    (conajmniej, bo mogliśmy połączyć przecież więcej wierzchołków w jeden,
    wtedy zmniejszy się jeszcze bardziej).
```
