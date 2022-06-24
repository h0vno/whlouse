
##  przykłady:
 przykład problemu:
 ![problem01](images/problem01.png) 
 
 przykład problemu wież Hanoi
 ![wieże hanoi](images/przyklad-problem-wiez.png) 
 ![wieże hanoi](images/przyklad-problem-wiez2.png) 
 
 bubble sort - złożoność czasowa średnia,
 [przykład](#bubble-przyklad01) wniosek
 
##  problem jako zbiór zadań:
**zadanie** - szczegóły dotyczące wejścia funkcji / dane z którymi
musimy coś zrobić
 * zadanie problemu jest konkretnym zadaniem do rozwiązania
 * problem pierwszości - zadaniem jest liczba naturalna których jest
   nieskończenie wiele, </br>
   zadanie to szczegóły dotyczące wejścia funkcji?
   
 * przykładowe zadania różnych problemów:
 ![problem02](images/problem02.png) 
 
 ## algorytm
 ![algorytm](images/algorytm.png) 
 
 ## przykład: sformułować algorytm wyszukiwania maksymalnego
 ![algorytm sformulowany](images/algorytm-sformulowany01.png) 
 
 ## złożoność pamięciowa
 złożonośc pamięciowa to funkcja której argumentami są rozmiary zadań

 ## operacje elementarne i złożone
 niektóre z tych operacji są operacjami elementarnymi, tzn. operacjami
 których nie da się rozłożyc na prostsze, natomiast niektóre są operacjami
 złożonymi, możemy je rozłożyc na operacje prostsze
 ![lista operacji elementarnych](images/operacje-elementarne01.png) 
 ![przykład w algorytmie](images/operacje-elementarne02.png) 
 ![przykład w algorytmie - opis](images/operacje-elementarne03.png) 
 
 ## operacje dominujące
 ![operacje dominujące](images/operacje-dominujace01.png) 
 ![operacje dominujące przykład](images/operacje-dominujace02.png) 
 operacje w ostatniej linijce zaznaczone na czerwono nie są operacjami
 dominującymi ponieważ nie zawsze się wykonają
 
 dlaczego więc operacje w pierwszej linijce nie są operacjami
 dominującymi? wykład 3, ~43 min
 
 "Jeżeli mamy w algorytmie dwie zagnieżdżone pętle, tak jak tutaj ^
  to operacja wykonująca się w ostatniej pętli jest operacją dominującą"
 
 ### <a name="bubblesort-O2">znajdowanie wzoru na liczbę operacji dominujących</a>
 
 ![operacje dominujące przykład](images/operacje-dominujace03.png) 
 
 ## złożonośc algorytmu
 ![złożoność algorytmu definicja](images/zlozonosc-algorytmu01.png) 
 
 ### złożoność pamięciowa
 ![Złożoność pamięciowa](images/zlozonosc-algorytmu02.png) 
 
 ### złożoność czasowa pesymistyczna
 ![Złożoność czasowa](images/zlozonosc-algorytmu03.png) 
 
 co ważne: C<sub>2</sub> to liczba operacji, nie wykonań
 ![liczba operacji elementarnych](images/zlozonosc-algorytmu04.png) 
 ![uwaga](images/zlozonosc-algorytmu05.png) 
 ![wnioski](images/zlozonosc-algorytmu06.png) 
 
 przykłady sortowania ze złożonością O(n<sup>2</sup>):
 ![przykłady](images/zlozonosc-algorytmu07.png) 
 
 [Bubble sort - liczenie złożoności pesymistycznej](#bubblesort-O2)
 
 
 ### złożoność czasowa średnia
 ![złożoność czasowa średnia](images/zlozonosc-algorytmu08.png) 
 ![złożoność czasowa średnia 2](images/zlozonosc-algorytmu09.png) 
 tzn. **złożoność czasowa średnia = liczba wykonań operacji dominującej**
 
 <a name="bubble-przyklad01">złożonośc czasowa średnia</a>
 ![bubble](images/zlozonosc-algorytmu10.png) 
 
 ## Podsumowanie
 ![podsumowanie](images/podsumowanie31.png) 
 
 --- 
  
 # Wykład 4