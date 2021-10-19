## QuickStart

```console
$ make

$ ./complex "23+2j * -12+-3j"
Complex{23 + 2j} * Complex{-12 + -3j} = Complex{-270 + -93j}

$ ./list 23 213 213 321 -12 31212 -132 312 -1
List {
    Node{23}<->Node{213}<->Node{213}<->Node{321}<->Node{-12}<->Node{31212}<->Node{-132}<->Node{312}<->Node{-1}
}

$ ./personal ./data.txt
PersonalDataBank {
	PersonalData{Julek, Kaczmarek, Pulaskiego Kazimierza 86 30-305 Krakow, 47020286216},
	PersonalData{Grzegorz, Wisniewski, Piastow 126 40-869 Katowice, 74041138930},
	PersonalData{Tekla, Majewska, Kajki Michala 99 60-545 Poznan, 00291077484},
}
```
