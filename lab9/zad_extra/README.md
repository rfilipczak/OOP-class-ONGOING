# STL

## Zadanie Extra 1

Napisz funkcję, która otrzymuje jako argument referencję do obiektu klasy vector<int> i: a) odwraca kolejność elementów w otrzymanym w argumencie kontenerze, b) sortuje rosnąco elementy otrzymanego w argumencie kontenera, c) sortuje malejąco elementy otrzymanego w argumencie kontenera, d) sortuje rosnąco elementy otrzymanego w argumencie kontenera względem ich wartości bezwzględnych, e) sortuje rosnąco elementy otrzymanego w argumencie kontenera względem ich reszty z dzielenia przez 1000.

```console
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
