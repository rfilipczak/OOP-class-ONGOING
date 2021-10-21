## Requirements

* g++ version with c++17 features available
* make

## QuickStart

```console
$ make

$ ./complex "23+2j * -12+-3j"
Complex{23 + 2j} * Complex{-12 + -3j} = Complex{-270 + -93j}

$ ./list ./exampleList.txt
List{
Node{-23979}<->Node{34576}<->Node{18451}<->Node{14564}<->Node{8345}<->Node{24133}<->Node{14948}<->Node{-11384}<->Node{5858}<->Node{-12779}
}
Would you like to edit the list [y/n]?: 
...

$ ./personal ./exampleData.txt
PersonalDataBank {
	PersonalData{Julek,Kaczmarek,Pulaskiego Kazimierza 86 30-305 Krakow,47020286216},
	PersonalData{Grzegorz,Wisniewski,Piastow 126 40-869 Katowice,74041138930},
	PersonalData{Tekla,Majewska,Kajki Michala 99 60-545 Poznan,00291077484},
}
Would you like to edit the databank [y/n]?: 
...
```
