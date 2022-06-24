

 # Zaliczenie przedmiotu za pomocą projektu

 * **Analiza empiryczna złożoności algorytmów sortowania i wyszukiwania**:
   * dwa z algorytmów:
     * [ ]   sortowania bąbelkowego (bubble),
     * [X]   przez wstawianie (insertion),
     * [X]   przez wybór (selection),
   * jeden z algorytmów:
     * [ ]   szybkiego (quick),
     * [X]   przez scalanie (merge):
   * [X] algorytmy wyszukiwania liniowego i binarnego,
   * trzy typy danych wejściowych: posortowane, posortowane w
     kolejności odwrotnej, kolejność losowa,
   * rozmiary danych wejściowych: n, 2n, 3n, 4n, 5n, 6n, ... gdzie n = rozmiar
    
 * **sprawozdanie**:
   * dokładna informacja o autorstwie programu (można korzystać z
     materiałów z Internetu i z pomocy kolegów, ale konieczna będzie
     dokładna znajomość programu),
   * instrukcja kompilacji i uruchomienia,
   * opis realizacji części źródeł programu odpowiedzialnych za
     analizowane algorytmy i za empiryczną analizę złożoności algorytmów,
   * tabelki/wykresy zależności liczb wykonań operacji od rozmiaru zadania
    
 * programy w C/C++ w tym analizowane algorytmy w czystym C,
   kompilowane w Visual Studio 2019, oddajemy źródła wszystkich części
   programu (wyjątek stanowią funkcje pomocnicze, np. użyte do
   rysowania wykresów, jeśli zostały użyte),
  
 * **struktura projektu, 4 foldery**:
   * źródła programu z plikiem projektu do kompilacji / budowy programu,
   * program wykonywalny (wersja Release) i konieczne biblioteki,
   * dane wejściowe (ten folder pewnie będzie pusty, generowanie),
   * dokumentacja (jedno sprawozdanie wspomniane wyżej, preferowany
     format pdf),
  
 * program uruchamialny na komputerze z "czystym" systemem Windows,
   tzn. bez konieczności instalacji kompilatora, środowiska
   programistycznego itp.,
 * termin przesłania pliku zip z czterema folderami: 25 czerwca;
   zachęcam do wcześniejszego oddawania programów.
 * **Uwaga**: to są ogólne założenia zaliczenia
   na ocenę bdb, szczegółowe ustalenia pozostawiam Państwu, wszystkie
   rozsądne ustalenia zaakceptuję, zaakceptuję również rozsądną
   modyfikację powyższych założeń. W przypadku watpliwości zapraszam na
   konsultacje.
     
 * **Sprawozdanie musi zawierać następujące elementy**:
   * sformułowanie problemu,
   * opis problemu,
   * opis rozwiązania,
   * prezentacja wyników,
   * wnioski.

 Sprawozdanie powinno być adresowane do czytelników z ogólną wiedzą
 informatyczną, opisy muszą byc jednozncze. Źródła programu należy
 komentować jednoznacznie, ale oszczędnie.

--- 

# Informacje o projekcie z wykładów

* **wykład 3**, 01:36:00:
  * Napisać program zliczający liczbę wszystkich operacji elementarnych
    w algorytmie, liczby wykonań operacji dominującej w każdym algorytmie
  * efektem projektu powinny być wykresy liczb w zależności od pewnych
    rozmiarów
  * przykład: dla algorytmu sortowania będziemy sortować ciągi o długości
    "10, 20, 30, 40 i tak dalej", liczby zapisywać i to w wykres
  * wykres liczb w zależności od długości ciągu
  * sprawozdanie:
    * omówić co obliczamy, podać podstawowe dane techniczne, 
      w jakim środowisku zrobione, 

---

 ## Todo
 ### Program:
 * liczenie operacji - porównanie, przypisanie wartości,
   deklaracja pamięci
 * złożoność średnia insert sort jest "bardzo trudna",
   możliwa zmiana na bubble sort
 
 
 ### Sprawozdanie:
 * przy każdym algorytmie zapisać:
   * złożoność pamięciowa
   * złożoność obliczeniowa
   * element dominujący, wzór na liczbę jego wykonań

---

# [Notatki](Notatki.md)

---

# Sprawozdanie
## 1. sformułowanie problemu 
**TODO**: wyszukiwanie i sortowanie?
1. Problem wyszukiwania
  * Zadaniem jest zbiór elementów i element wyszukiwany.
  * Pytanie - czy element należy do zbioru.
  * Umieć porównać dwa elementy
2. Problem sortowania

## 2. opis problemu
## 3. opis rozwiązania
## 4. prezentacja wyników
## 5. wnioski
