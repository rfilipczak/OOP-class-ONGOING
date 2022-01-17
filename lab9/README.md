# STL

Zadanie 1: Napisz program, który wczytuje ze standardowego wejścia liczbę całkowitą dodatnią N a następnie wczytuje N par liczb całkowitych i wstawia je do listy (liczby nieujemne program powinien wstawiać na koniec listy, a ujemne na początek listy). Na końcu program powinien wypisać na standardowym wyjściu wszystkie wczytane elementy w kolejności ich występowania na liście. W rozwiązaniu wykorzystaj kontener list.

Zadanie 2: Napisz klasę macierz, która służy do przechowywania macierzy liczb wymiernych. Klasa macierz powinna udostępniać następujące publiczne metody: — konstruktor, który otrzymuje dwie liczby całkowite i inicjuje macierz o wymiarach podanych w argumentach, — przeciążony operator (), który dla liczb całkowitych i, j podanych jako argumenty zwraca referencję do elementu macierzy znajdującego się i-tej kolumnie i j-wierszu. Do implementacji klasy macierz wykorzystaj typ vector.

Zadanie Extra 1: Napisz funkcję, która otrzymuje jako argument referencję do obiektu klasy vector<int> i: a) odwraca kolejność elementów w otrzymanym w argumencie kontenerze, b) sortuje rosnąco elementy otrzymanego w argumencie kontenera, c) sortuje malejąco elementy otrzymanego w argumencie kontenera, d) sortuje rosnąco elementy otrzymanego w argumencie kontenera względem ich wartości bezwzględnych, e) sortuje rosnąco elementy otrzymanego w argumencie kontenera względem ich reszty z dzielenia przez 1000.

## Zadanie 1
```console
$ cd zad1
$ make
$ ./zad1
Zadanie 1

Podaj N: 5
Podaj 5 liczb (odzielone spacja): -1 231 32 132 -12    
Liczby w liscie:
-12 -1 231 32 132
```

## Zadanie 2
```console
$ cd zad2
$ make
$ ./zad2
  0   1   2   3   4   5   6   7   8   9  10 
  1   1   2   3   4   5   6   7   8   9  10 
  2   2   4   6   8  10  12  14  16  18  20 
  3   3   6   9  12  15  18  21  24  27  30 
  4   4   8  12  16  20  24  28  32  36  40 
  5   5  10  15  20  25  30  35  40  45  50 
  6   6  12  18  24  30  36  42  48  54  60 
  7   7  14  21  28  35  42  49  56  63  70 
  8   8  16  24  32  40  48  56  64  72  80 
  9   9  18  27  36  45  54  63  72  81  90 
 10  10  20  30  40  50  60  70  80  90 100
```

## Zadanie Extra 1
```console
$ cd zad_extra
$ make
$ ./zadanie_extra 

Zadanie Extra 1

Wektor wejsciowy:
213 -321 123 0 0 1000 1 1002 123 
Po odwroceniu:
123 1002 1 1000 0 0 123 -321 213 
Po posortowaniu(rosnacym):
-321 0 0 1 123 123 213 1000 1002 
Po posortowaniu(malejacym):
1002 1000 213 123 123 1 0 0 -321 
Po posortowaniu(rosnacym wg wart. absolutnej):
0 0 1 123 123 213 -321 1000 1002 
Po posortowaniu(rosnacym wg reszty z dzielenia przez 1000):
-321 0 0 1000 1 1002 123 123 213
```
